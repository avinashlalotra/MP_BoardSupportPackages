# Export vars for child makefiles
export CC=riscv32-unknown-elf-gcc
export AS=riscv32-unknown-elf-as
export AR=riscv32-unknown-elf-ar
DUMP = riscv32-unknown-elf-objdump
export ARCH=-march=rv32imc
export ABI=-mabi=ilp32

INCDIR = ./include
LIBDIR = ./lib
LINKERSCRIPT=./linker/linker.ld
STARTUP = ./boot/startup.s
FIRMWARE=./artifacts/firmware
LIBS=-lbsp

ELF2HEX=riscv32-unknown-elf-elf2hex
FILE ?= main.c
FILE_PATH=src_user/$(FILE)



all : src_bsp firmware

firmware :
	mkdir -p ./artifacts
	$(CC) $(ARCH) $(ABI) -nostartfiles -Wl,--no-relax -T $(LINKERSCRIPT) -L$(LIBDIR) -I$(INCDIR)  $(FILE_PATH) $(STARTUP) $(LIBS) -o $(FIRMWARE)
	$(ELF2HEX) --bit-width 32 --input $(FIRMWARE) --output ./artifacts/firmware.mem
	$(DUMP) -D -M no-aliases $(FIRMWARE) > ./artifacts/firmware_dissasm.log
	./firminfo.sh

src_bsp:
	$(MAKE) -C src_bsp all

example : $(FILE)
	echo "we will add this feature soon"

.PHONY: all src_bsp example clean distclean

clean :
	rm ./artifacts/* log

distclean :
	-$(MAKE) clean
	$(MAKE) -C src_bsp clean