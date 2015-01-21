format ELF64
include "syscalls.inc" ; links to correct syscalls for OSX/linux
public start           ; so that loader can start the program, using call [a fn]

msg db 'Hello world!',0xA  ; db is = (define byte); 0xA is \n
                           ; post db is in objf, but msg is assembler lang var
msg_size = $-msg           ; = is only for #DEFINE, so doesn't happen in obj f
                           ; $ is current addr
                           ; then it subtracts address of message, to get size
                           ; - = $ and db are in the "language" of the assembler 

; C VERSION
; char* msg      = "Hello world!\n"
; int   msg_size = ~~~~~sizeof(msg)
; void start() {
;    write(1, msg, msg_size);
;    exit(0);
; } 

start:
	mov	edi,1		        ; stdout
	lea	rsi,[msg]       ; [] like * makes less of a ptr; but lea gets addr (&)
                      ; can't mov rsi, msg b/c on osx
	mov	edx,msg_size
	mov	eax, SYSCALL_WRITE
	syscall             ; looks at rax and dispatches corr syscall, which then
                      ; looks for its arguments in appr registers, which can be
                      ; set before or after rax is set

	xor	edi,edi         ; set to 0 fast
	mov	eax, SYSCALL_EXIT
	syscall
