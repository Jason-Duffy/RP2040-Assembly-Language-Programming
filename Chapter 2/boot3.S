@
@ Assembler program print out "Hello World"
@ using the Pico SDK.
@
@ R0 - first parameter to printf
@ R1 - second parameter to printer
@ R7 - index counter
@

.section .boot3,"ax"
.thumb_func		    @ Necessary because sdk uses BLX
.global main	            @ Provide program starting address to linker

main:
	BL	stdio_init_all	@ initialize uart or usb

	LDR	R0, =init_msg	@ load address of string
	BL	printf		@ Call pico_printf

jump:
    LDR	R0, =jump_msg	@ load address of string
	BL	printf		@ Call pico_printf
	ldr r3, =main_start_addr     // Load the address of main, +1 for thumb instruction set
	bx r3               // Branch to main
		
.data
	       .align  4	@ necessary alignment
init_msg: .asciz    "\nboot3: UART & Clocks Initialised\n"
jump_msg: .asciz    "boot3: jumping to main_program\n"

.equ main_start_addr, 0x10002215 // pointer to main program start