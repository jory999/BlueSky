.code16
.global _start
.section .text
_start

    jmp entry
    .byte 0x90
    .ascii "HELlOIPL"
    .word 512
    .byte 1
    .word 1
    .byte 2
    .word 224
    .word 2880
    .byte 0xf0
    .word 9
    .word 18
    .word 2
    .long 0
    .long 2880
    .byte 0,0,0x29
    .long 0xffffffff
    .ascii "HELLO-OS"
    .ascii "FAT12   "
    .fill  18

entry:
    movl $0,      %eax
    movl %eax,    %ds
    movl %eax,    %ss
    movl $0x7c00, %esp

    movl $x0820,  %eax
    movl %eax,    %es
    movb $0,      %ch
    movb $0,      %dh
    movb $2,      %cl
 read:
    movb $0x02,   %ah
    movb $1,      %al
    movw $0,      %bx
    movb $0,      %dl
    int  $0x13

    movl %es,     %eax
    add  $0x0020, %eax
    movl %eax,    %es

    inc %cl 
    cmp $18,      %cl
    jbe read

    movb $1, %cl
    inc %dh
    cmp $1,       %dh
    jbe read

    movb $0,      %dh
    inc %ch,
    cmp $9,        %ch
    jbe read
    jmp 0x8200

 marker1:

     .fill 0x1fe-(marker1-_start)   
     .byte 0x55,  0xaa

     


