	.file	"164541_rakesh_ex5-3.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Error: Invalid input entered."
.LC1:
	.string	"Error: Input out of range."
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Error: Step size greater than upper bound."
	.align 8
.LC3:
	.string	"Error %d: Zero devision error\n"
	.section	.rodata.str1.1
.LC4:
	.string	"Error: Unknown error."
	.text
	.globl	handle_error
	.type	handle_error, @function
handle_error:
.LFB23:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	cmpl	$4, %edi
	ja	.L2
	movl	%edi, %edi
	leaq	.L4(%rip), %rdx
	movslq	(%rdx,%rdi,4), %rax
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L1-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
.L7:
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
.L1:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	jmp	.L1
.L5:
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	jmp	.L1
.L3:
	movl	$4, %edx
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	jmp	.L1
.L2:
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	jmp	.L1
	.cfi_endproc
.LFE23:
	.size	handle_error, .-handle_error
	.globl	my_strcat
	.type	my_strcat, @function
my_strcat:
.LFB25:
	.cfi_startproc
	endbr64
	cmpb	$0, (%rdi)
	je	.L11
.L12:
	addq	$1, %rdi
	cmpb	$0, (%rdi)
	jne	.L12
.L11:
	movzbl	(%rsi), %eax
	testb	%al, %al
	je	.L13
.L14:
	movb	%al, (%rdi)
	addq	$1, %rdi
	addq	$1, %rsi
	movzbl	(%rsi), %eax
	testb	%al, %al
	jne	.L14
.L13:
	movb	$0, (%rdi)
	ret
	.cfi_endproc
.LFE25:
	.size	my_strcat, .-my_strcat
	.section	.rodata.str1.1
.LC5:
	.string	"Enter the source string"
.LC6:
	.string	"Enter the destination string"
	.section	.rodata.str1.8
	.align 8
.LC7:
	.string	"after string concatenation --> %s\n"
	.align 8
.LC8:
	.string	"do you want to concatenate another string(y / n)"
	.section	.rodata.str1.1
.LC9:
	.string	" %c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$248, %rsp
	.cfi_def_cfa_offset 304
	movq	%fs:40, %rax
	movq	%rax, 232(%rsp)
	xorl	%eax, %eax
	leaq	.LC5(%rip), %r12
	leaq	.LC6(%rip), %r13
	leaq	.LC7(%rip), %r15
	leaq	.LC8(%rip), %r14
	jmp	.L28
.L31:
	movslq	%ebp, %rax
	movb	$0, 16(%rsp,%rax)
	cmpl	$100, %ebp
	jg	.L36
	movq	%r13, %rdi
	call	puts@PLT
	movl	$0, %ebx
.L23:
	movl	%ebx, %ebp
	movq	stdin(%rip), %rdi
	call	getc@PLT
	cmpb	$10, %al
	je	.L32
	cmpb	$-1, %al
	je	.L32
	movb	%al, 128(%rsp,%rbx)
	addq	$1, %rbx
	jmp	.L23
.L36:
	movl	$2, %edi
	call	handle_error
.L29:
	movq	232(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L37
	movl	$0, %eax
	addq	$248, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L32:
	.cfi_restore_state
	movslq	%ebp, %rax
	movb	$0, 128(%rsp,%rax)
	cmpl	$100, %ebp
	jg	.L38
	leaq	128(%rsp), %rsi
	leaq	16(%rsp), %rbx
	movq	%rbx, %rdi
	call	my_strcat
	movq	%rbx, %rdx
	movq	%r15, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%r14, %rdi
	call	puts@PLT
	leaq	15(%rsp), %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
.L27:
	movq	stdin(%rip), %rdi
	call	getc@PLT
	cmpb	$10, %al
	jne	.L27
	movzbl	15(%rsp), %eax
	andl	$-33, %eax
	cmpb	$89, %al
	jne	.L29
.L28:
	movq	%r12, %rdi
	call	puts@PLT
	movl	$0, %ebx
.L18:
	movl	%ebx, %ebp
	movq	stdin(%rip), %rdi
	call	getc@PLT
	cmpb	$10, %al
	je	.L31
	cmpb	$-1, %al
	je	.L31
	movb	%al, 16(%rsp,%rbx)
	addq	$1, %rbx
	jmp	.L18
.L38:
	movl	$2, %edi
	call	handle_error
	jmp	.L29
.L37:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
