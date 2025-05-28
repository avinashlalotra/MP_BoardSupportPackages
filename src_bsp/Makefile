CC ?= riscv32-unknown-elf-gcc
ARCH ?= -march=rv32imc
ABI ?= -mabi=ilp32
CFLAGS ?=
AS ?= riscv32-unknown-elf-as
INCDIR ?= ../include
AR ?= riscv32-unknown-elf-ar
ARFLAGS ?= rcs

LIBNAME = libbsp.a

SRC_FILES = $(wildcard *.c)
OBJECTS   = $(SRC_FILES:.c=.o)

all : $(LIBNAME)


$(LIBNAME) :$(OBJECTS) 
	$(AR) $(ARFLAGS) $@ $^
	cp $(LIBNAME) ../lib/

%.o : %.c
	$(CC) $(CFLAGS) $(ARCH) $(ABI) -I$(INCDIR) -c $< -o $@


clean :
	rm -rf $(LIBNAME) $(OBJECTS) ../lib/$(LIBNAME)


.PHONY: all clean