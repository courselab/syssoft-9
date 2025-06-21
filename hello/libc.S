#    SPDX-FileCopyrightText: 2025 KSalmaze <pedrohsalmaze@usp.br>
#   
#    SPDX-License-Identifier: GPL-3.0-or-later
#
#  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
#  and includes modifications made by the following author(s):
#  KSalmaze <pedrohsalmaze@usp.br>

	/* Suppose we receive the argument in %cx. */

	.code16gcc
	.global printf
        .global get_time

	.section .text
	
printf:	

	mov   %cx, %bx
	
        mov   $0x0e,%ah               
        mov   $0x0, %si               
loop:                                 
        mov   (%bx, %si), %al           
        cmp   $0x0, %al               
        je    end                    
        int   $0x10                   
        add   $0x1, %si               
        jmp   loop                    
get_time:
        mov   $0x02, %ah
        int   $0x1A

        mov   %dh, %al
        mov   %cl, %ah
        mov   %ch, %dl
        xor   %dh, %dh

        ret
end:
        mov %si, %ax
        ret




