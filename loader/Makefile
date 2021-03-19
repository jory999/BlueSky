
run:loader.bin
	dd if=loader.bin of=loader.img bs=512 count=1
	dd if=system.bin of=system.img bs=1474048 count=1 conv=sync
	dd if=system.img of=loader.img bs=512 seek=1 
	qemu-system-i386 -fda loader.img -boot a

loader.bin : loader.o Makefile kernel.ld
	ld -M --oformat binary -m elf_i386 -o loader.bin loader.o -T kernel.ld

loader.o : bootasm.s Makefile
	as --32 bootasm.s -o loader.o 

 # dd if=/dev/zero of=zero.img bs=1474048 count=1 conv=sync
 #qemu-system-i386 -hda loader.img -boot a
clean :
	rm *.bin *.o *.img
