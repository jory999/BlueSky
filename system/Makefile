system.bin : system.o Makefile system.ld
	ld -M --oformat binary -m elf_i386 -o system.bin system.o -T system.ld

system.o : system.s Makefile
	as --32 system.s -o system.o

clean:
	rm *.bin *.o *.img