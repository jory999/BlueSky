run : loader.bin
    dd if=loader.bin of=loader.img bs=512 count=1
    dd if=/dev/zero of=zero.img bs=1474048 count=1 conv=sync
    dd if=zero.img of=loader.img bs=512 seek=1 
    qemu-system-i386 -fda loader.img -boot a

loader.bin : loader.o Makefile loader.lds
    ld -M --oformat binary -m elf_i386 -o loader.bin loader.o -T loader.lds

loader.o : loader.s Makefile
    as --32 loader.s -o loader.o 

clean :
    rm *.bin *.o *.img