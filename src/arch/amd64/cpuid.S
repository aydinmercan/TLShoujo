.intel_syntax

.global _cpuid

.text

_cpuid:
    mov eax, esi
    xor ecx, ecx
    xchg rsi, rbx
    cpuid
    xchg rsi, rbx
    mov DWORD PTR [rdi], eax
    mov DWORD PTR [rdi + 4], esi
    mov DWORD PTR [rdi + 8], ecx
    mov DWORD PTR [rdi + 12], edx
    ret
