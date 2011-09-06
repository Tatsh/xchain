	.text
.globl _main
_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	call	L_foo$stub
	movl	$0, %eax
	leave
	ret
	.section __IMPORT,__jump_table,symbol_stubs,self_modifying_code+pure_instructions,5
L_foo$stub:
	.indirect_symbol _foo
	hlt ; hlt ; hlt ; hlt ; hlt
	.subsections_via_symbols
