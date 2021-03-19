system.bin : system.o Makefile system.ld
	#ld -M --oformat binary -m elf_i386 -o system.bin system.o -T system.ld
	ld -M -m elf_i386 -o $(BIN_DIR)/system $(OBJ_DIR)/system.o -T system.ld
	objcopy -O binary $(BIN_DIR)/system $(BIN_DIR)/system.bin 

system.o : system.s Makefile
	as --32 system.s -o $(OBJ_DIR)/system.o

#clean:
	#rm *.bin *.o *.img

