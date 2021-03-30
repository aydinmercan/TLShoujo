.intel_syntax

.global _shoujo_core_lock
.global _shoujo_core_unlock

.data

_shoujo_core_lock:
    mov edx, 1
    jmp .check_available

.pause:
    pause

.check_available:
    mov eax, edx
    xchg eax, DWORD PTR _core_lock[rip]
    test eax, eax
    jne .pause
    ret

_shoujo_core_unlock:
    mov DWORD PTR _core_lock[rip], 0
    ret
