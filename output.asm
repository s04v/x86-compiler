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


; Syscalls
sys_write:
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



main:
push ebp
mov ebp, esp
sub esp, 16
mov DWORD [ebp-4], 8
mov DWORD [ebp-8], 1
mov eax, DWORD [ebp-4]
cmp eax, 1
je .L0
mov ebx, DWORD [ebp-8]
cmp ebx, 0
je .L0
mov ecx, DWORD [ebp-8]
cmp ecx, 1
jne .L1
.L0:
push 5
push S2
call sys_write
.L1:
nop
leave
ret


section .data
S2 db "hello"
