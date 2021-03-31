
run:loader.bin
	dd if=$(BIN_DIR)/loader.bin of=$(BIN_DIR)/loader.img bs=512 count=1
	dd if=$(BIN_DIR)/system.bin of=$(BIN_DIR)/system.img bs=1474048 count=1 conv=sync
	dd if=$(BIN_DIR)/system.img of=$(BIN_DIR)/loader.img bs=512 seek=1 
	#qemu-system-i386 -fda $(BIN_DIR)/loader.img -boot a
	qemu-system-i386 -fda $(BIN_DIR)/loader.img -boot a -gdb tcp::1234   -monitor stdio 
    #qemu-system-i386 -fda $(BIN_DIR)/loader.img -boot a -gdb tcp::1234 -monitor stdio 

loader.bin : loader.o Makefile kernel.ld
	ld -M --oformat binary -m elf_i386 -o $(BIN_DIR)/loader.bin $(OBJ_DIR)/loader.o -T kernel.ld

loader.o : bootasm.s Makefile
	as --32 bootasm.s -o $(OBJ_DIR)/loader.o 

	###################
 

	##################

 # dd if=/dev/zero of=zero.img bs=1474048 count=1 conv=sync
 #qemu-system-i386 -hda loader.img -boot a
#clean :
	#rm *.bin *.o *.img
