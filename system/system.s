.code16
.section .text
.set    CYLS,   0X0FF0
.set    LEDS,   0X0FF1
.set    VMODE,  0X0FF2
.set    SCRNX,  0X0FF4
.set    SCRNY,  0X0FF6
.set    VRAM,   0X0FF8
start:
    movb    $0x13, %al
    movb    $0x00, %ah
    int $0x10

    movb    $8,    VMODE
    movw    $320,  SCRNX
    movw    $200,  SCRNY
    movl    $0x000a000,    VRAM

    movb    $0x02, %ah
    int $0x16
    mov %al,    LEDS

    movw    %cs,    %ax
    movw    %ax,    %ds
    movw    %ax,    %es
    movw    %ax,    %ss
    movw    $0x100,    %sp

########################################start 32
############set GDT
    #movl    gdt_base,   %eax
    movl    gdt_base+0x8200, %eax  ################修改

############0# empty GDT
    movl    $0x00000000,   0(%eax)
    movl    $0x00000000,   4(%eax)
############1# code GDT
    movl    $0x8200ffff,   8(%eax)
    movl    $0x00409a00,   12(%eax)
############2# data GDT
    movl    $0x0000ffff,   16(%eax)
    movl    $0x00cf9200,   20(%eax)
    #movl    $0x8200ffff,   16(%eax)
    #movl    $0x00cf9200,   20(%eax)
############3# stack GDT
    movl    $0x00007a00,   24(%eax)
    movl    $0x00409600,   28(%eax)

#close interrupt
    cli 

    lgdt    gdt_size+0x8200 #configuration  ################修改
    #lgdt    gdt_size     #configuration  
#turn on A2
    inb     $0x92,     %al
    orb $0x02,     %al
    outb    %al,        $0x92
#configure CR0
    movl    %cr0,       %eax
    orl $1,        %eax
    movl    %eax,       %cr0
#protect mode start
    ljmp    $0x0008,	$(start_protect-start) #16位描述子：32位位移

start_protect:
.code32
    movw    $0x0010,   %ax
    movw    %ax,        %ds

    movw    $0x0010,   %ax
    movw    %ax,        %ss

    movl    $0x00007a00,   %esp

    call    SysMain


gdt_size:   .word   31
gdt_base:   .long   0x9000 #定义GDT位置
