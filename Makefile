PREFIX = /home/wzg/opt/riscv32/bin/riscv32-unknown-elf-
#PREFIX = /home/wzg/opt/Nuclei/rv_linux_bare_19-12-12-13-12/bin/riscv-nuclei-elf-
CC  = $(PREFIX)gcc
CXX = $(PREFIX)g++
AS  = $(PREFIX)as
AR  = $(PREFIX)ar
LD  = $(PREFIX)ld
NM  = $(PREFIX)nm
OBJCOPY = $(PREFIX)objcopy
OBJDUMP = $(PREFIX)objdump

OUTPUT_PATH = ./build

INC_PATH := $(patsubst ./%, -I./%, $(shell find ./ -type d))
SRC_PATH := $(patsubst ./%, ./%, $(shell find ./ -type d))

VPATH := $(SRC_PATH) 	#the system VPATH


CFLAGS = -O0 -g --compile -march=rv32imac -mabi=ilp32 -std=gnu11 -fno-builtin -fmessage-length=0 -fsigned-char
AFLAGS = -g -march=rv32imac -mabi=ilp32
DEFINES =
LFLAGS = -Wl,-build-id=none -nostartfiles -march=rv32imac -mabi=ilp32 -nostdlib -nostdinc -fmessage-length=0


#---------------------------------------------------------
#Collect All object files

C_FILES := $(foreach dir, $(SRC_PATH), $(wildcard $(dir)/*.c))
C_OBJS := $(addprefix $(OUTPUT_PATH)/, $(patsubst %.c, %.o, $(notdir $(C_FILES))))

A_FILES := $(foreach dir, $(SRC_PATH), $(wildcard $(dir)/*.s))
A_OBJS := $(addprefix $(OUTPUT_PATH)/, $(patsubst %.s, %.o, $(notdir $(A_FILES))))

OBJS := $(C_OBJS) $(A_OBJS)


#---------------------------------------------------------
#Generate Target ELF file

.PHONY: all
all : CHECKDIR  $(OUTPUT_PATH)/test  $(OUTPUT_PATH)/test-dumped.S

$(OUTPUT_PATH)/test : $(OBJS)
	@echo "\n"
	@echo "####################"
	@echo "start to linking ..."
	$(CC) -o $@  $^  $(INC_PATH) $(LFLAGS) $(DEFINES) -T GD32VF103xB.lds -Xlinker -Map -Xlinker  $(OUTPUT_PATH)/1.map 


# Generate Output Foler if not existed
CHECKDIR:
	mkdir -p $(OUTPUT_PATH)

# Generate asm file from ELF file for analysis
$(OUTPUT_PATH)/test-dumped.S : $(OUTPUT_PATH)/test
	@echo "\n"
	@echo "####################"
	@echo "dump asm file from ELF"
	$(OBJDUMP) -S $<  >  $@


#---------------------------------------------------------
#Generate *.doj file

$(OUTPUT_PATH)/%.o : %.c			#the make file will search "%.c" files in "VPATH" path 
	@echo "###################"
	@echo "c file compile: $<"
	$(CC) -c $(INC_PATH) $(CFLAGS) $(DEFINES) $< -o $@

$(OUTPUT_PATH)/%.o : %.s			#the make file will search "%.s" files in "VPATH" path
	@echo "##################"
	@echo "s file compile: $<"
	$(AS) -c $(INC_PATH) $(AFLAGS) $(DEFINES) $< -o $@


#---------------------------------------------------------
#Clean Operation

.PHONY: clean
clean:
	rm -f $(OUTPUT_PATH)/*.map
	rm -f $(OUTPUT_PATH)/test
	rm -f $(OUTPUT_PATH)/*.o
	rm -rf $(OUTPUT_PATH)


