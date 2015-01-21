define sorted r9
define i      r12

include "startp.inc"
  xor sorted, sorted
  lea r13, [list]
bubble:
  ;; for init
  xor i, i
  inc sorted
  runthrougharr:
    ;; for condition
    cmp i, (list_n - 1)
    jnl done
    mov rax, [r13 + 4*i]
    mov rbx, [r13 + 4*(i + 1)]
    cmp rax, rbx
    jng .end
    ;; else
    mov [r13 + 4*i],       rbx
    mov [r13 + 4*(i + 1)], rax
    xor sorted, sorted
    .end:
      inc i
      jmp runthrougharr
done:
  test sorted, sorted
  jz bubble
  ; ptr to list in r13
  lea rdi, [msg_start]
  call printf

  xor i, i
  printelem:
    cmp i, list_n
    jnl .end
    lea rdi, [list_elem_msg]
    mov rsi, [r13 + 4*i]
    call printf
    inc i
    jmp printelem
  .end:
    lea rdi, [msg_end]
    call printf
    exit_0


msg_start     db 'The list sorted is ',0xA,0x0
list_elem_msg db '%d '                    ,0x0
msg_end       db                       0xA,0x0

section 'data' writable
list dd 9,8,7,6,5,4,3,2,1 ;2,4,11,9,3,7,3
list_n = ($-list)/4 ;size of list is 4* too big cuz each number is 4 bytes long
