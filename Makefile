CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE    = arm-none-eabi-size
OPENOCD = openocd

CPUFLAGS = -mcpu=cortex-m3 -mthumb

CFLAGS = $(CPUFLAGS) \
         -Wall -Wextra \
         -ffreestanding \
         -fno-common \
         -O0 -g3 \
         -ffunction-sections \
         -fdata-sections \
         -MMD -MP \
         -Iinclude

LDFLAGS = $(CPUFLAGS) \
          -T linker/stm32f103c8.ld \
          -nostdlib \
          -Wl,--gc-sections \
          -Wl,-Map=build/firmware.map

OPENOCD_FLAGS = -f interface/stlink.cfg \
                -f target/stm32f1x.cfg

SOURCES = $(wildcard startup/*.c) \
          $(wildcard src/*.c)

OBJECTS = $(patsubst %.c,build/%.o,$(SOURCES))
DEPS    = $(OBJECTS:.o=.d)

TARGET = build/firmware

all: $(TARGET).elf $(TARGET).bin

$(TARGET).elf: $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SIZE) $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

inspect: $(TARGET).elf
	$(OBJDUMP) -h -t $<

flash: $(TARGET).elf
	$(OPENOCD) $(OPENOCD_FLAGS) \
		-c "program $< verify reset exit"

clean:
	rm -rf build

-include $(DEPS)

.PHONY: all inspect flash clean