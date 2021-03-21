#system.bin : system.o Makefile system.ld main.o functions.o font.o
	#ld -M --oformat binary -m elf_i386 -o system.bin system.o -T system.ld
system.bin : system.o Makefile system.ld main.o functions.o 	
	ld -M -m elf_i386 -o $(BIN_DIR)/system $(OBJ_DIR)/system.o $(OBJ_DIR)/functions.o  $(OBJ_DIR)/main.o  -T system.ld
	objcopy -O binary $(BIN_DIR)/system $(BIN_DIR)/system.bin 
	



system.o : system.s Makefile
	as --32 system.s -o $(OBJ_DIR)/system.o

main.o : main.c Makefile
	gcc -c main.c -o $(OBJ_DIR)/main.o -m32	

functions.o : functions.s Makefile
	as --32 functions.s -o $(OBJ_DIR)/functions.o

font.o : $(FONT_DIR)/font.c  $(FONT_DIR)/font_code.o
	gcc -c $(FONT_DIR)/font.c -o $(FONT_DIR)/font.o -m32	










#clean:
	#rm *.bin *.o *.img

