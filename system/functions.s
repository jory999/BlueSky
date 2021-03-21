.code32
.section .text
.global FunctionHlt
.global FunctionOut8, FunctionOut16, FunctionOut32
.global FuntionIn8, FuntionIn16, FuntionIn32
.global FunctionCli, FuntionSti
.global FunctionLoadEflags, FunctionStoreEflags

FunctionHlt:    #void FunctionHlt(void)
    hlt
    ret

FunctionOut8:   #void FunctionOut8(int port, int data)
    movl    4(%esp),    %edx
    movb    8(%esp),    %al
    outb    %al,        %dx
    ret

FunctionOut16:  #void FunctionOut16(int port, int data)
    movl    4(%esp),    %edx
    movw    8(%esp),    %ax
    outw    %ax,        %dx
    ret

FunctionOut32:  #void FunctionOut32(int port, int data)
    movl    4(%esp),    %edx
    movl    8(%esp),    %eax
    outl    %eax,       %dx
    ret

FuntionIn8: #int FunctionIn8(int port)
    movl    4(%esp),    %edx
    movb    $0,        %al
    inb %dx,        %al
    ret

FuntionIn16:    #int FunctionIn16(int port)
    movl    4(%esp),    %edx
    movw    $0,        %ax
    inw %dx,        %ax
    ret

FuntionIn32:    #int FunctionIn32(int port)
    movl    4(%esp),    %edx
    movl    $0,        %eax
    inl %dx,        %eax
    ret

FunctionCli:    #void FunctionCli(void)
    cli
    ret

FuntionSti: #void FunctionSti(void)
    sti
    ret

FunctionLoadEflags: #int FunctionLoadEflags(void)
    pushf
    pop %eax
    ret

FunctionStoreEflags:    #void FunctionStoreEflags(int eflags)
    mov 4(%esp),    %eax
    push    %eax
    popf
    ret