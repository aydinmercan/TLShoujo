.intel_syntax

.global _cpuid

.text

_cpuid:
    mov eax, esi
    xor ecx, ecx
    xchg rsi, rbx
    cpuid
    xchg rsi, rbx
    mov dword ptr [rdi], eax
    mov dword ptr [rdi + 4], esi
    mov dword ptr [rdi + 8], ecx
    mov dword ptr [rdi + 12], edx
    ret
