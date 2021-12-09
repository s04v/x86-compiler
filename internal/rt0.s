section .text
global _start
_start:
    push ebp
    sub ebp, esp
    call main
    xor ebx, ebx
    mov eax, 0x1
    int 80h
    ret

