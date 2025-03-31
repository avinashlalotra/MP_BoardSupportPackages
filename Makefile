CFLAGS = -mno-save-restore -march=rv32i2p0 -mabi=ilp32 -nostartfiles -nostdlib -static -O1

CC = riscv32-unknown-elf-gcc
AS =  riscv32-unknown-elf-as
DUMP = riscv32-unknown-elf-objdump
ARCH = -march=rv32imc
ABI = -mabi=ilp32
ELF2HEX= riscv32-unknown-elf-elf2hex
file ?= main


# //////////////////////////////////////////////////////////

all : start

start : ${file}.o  linker.ld  startup.S utils.c led.c systolic.c
	$(CC) $(ARCH) $(ABI) -nostartfiles -Wl,--no-relax -T linker.ld -o ${file}.elf startup.S ${file}.o utils.o led.o systolic.o
${file}.o : ${file}.c
	$(CC) $(ARCH) $(ABI)  -c -o ${file}.o ${file}.c
utils.c : utils.o
utils.o :
	$(CC) $(ARCH) $(ABI) -c -o utils.o utils.c
led.c : led.o
led.o :
	$(CC) $(ARCH) $(ABI)  -c -o led.o led.c
systolic.c : systolic.o
systolic.o :
	$(CC) $(ARCH) $(ABI)  -c -o systolic.o systolic.c

elf2hex : convert
convert :  
	${ELF2HEX} --bit-width 32 --input ${file}.elf --output ${file}.mem
elf2dissasm : dissasm
dissasm : 
	$(DUMP) -D -M no-aliases ${file}.elf > ${file}_dissasm.log

# //////////////////////////////////////////////////////////


asm : asmfile
asmfile : 
	$(AS) -march=rv32i2p0 $(ABI) -o ${file}.elf ${file}.asm
	$(DUMP) -D -M no-aliases ${file}.elf > ${file}_dissasm.log
	$(ELF2HEX) --bit-width 32 --input ${file}.elf --output ${file}.mem


clean :
	rm *.o *.mem *.elf *.map *.log

testasm : testmmio.c 