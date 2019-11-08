.section .rodata
align 2
.LC0:
	.string "Andes Assembly Programming\n"
	.text
	.align 2
	.global main
main:
.LFB2:
	movi $r6, 0 !Loop Counter

.L2:
	move $r7, $r6
	sltsi $r7, $r7, 5
	beqz $r7, .L3
	la $r0, .LC0 !the address of the shown string is placed in R0
	bal printf
	addi $r6,$r6, 1 !increase Loop Counter
	b .L2
.L3:
	ret
