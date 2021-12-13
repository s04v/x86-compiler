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


write_wrapper:
    push ebp
    mov ebp, esp
    push eax
    push ebx
    push ecx
    push edx

    mov eax, 0x4
    mov ebx, 0x1
    mov ecx, DWORD [ebp + 8]
    mov edx, DWORD [ebp + 12]
    int 80h

    pop edx
    pop ecx
    pop ebx
    pop eax
    mov esp, ebp
    pop ebp
    ret


