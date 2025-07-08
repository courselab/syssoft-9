# T1: Hello
Done

# T2: Quiz


**Exercice p1:** 
Executing the same code repeatedly, we found out that the memory address of the main function changes between executions. This can be explained by the Address Space Layout Randomization, a feature used to randomize the address where many things(eg. functions and libraries), used mainly for security regions.

---

**Exercice p2:** 
The vulnerability in the code is a Buffer overflow, and it's main cause is the input handling.
Since the "%s" reads the input until a "\n" we can input string longer than 9 character as a password, in order to rewrite the value of the variable "verified" from zero to a char value that belongs in long password.

We changed the "-stack-protector" compiler flag so that we have stack protaction aggainst this vunlerability, but the access was still granted, because(maybe) the verified value is before the canary of the stack. To fix it, we changed the input on line 23, so that the code respects the max lenght of the char array.

---
**Exercice p3:**
-- First, the p3 was built and the hexdump was send to p3_dump.

a) The instruction push %eax puts the bar's argument in the stack, after that, the call "804919f \<bar\>" calls the function.

```assembly
804918e:	50                   	push   %eax
804918f:	e8 0b 00 00 00       	call   804919f <bar>
```

b) The bar return is moved to the eax register.
```assembly
80491ae:	8b 45 fc             	mov    -0x4(%ebp),%eax
80491b1:	c9                   	leave
80491b2:	c3                   	ret
```

c) The first 2 instructions set up a new stack frame for the fuunction foo. the push saves the last base pinter and the mov sets the base pointer to the new value.

The leave instruction returns the base pointer value to the last stack pointer address.

In relation to a), this ensures that the function calls and returns work correctly, and the changes to the arguments/registers inside the function do not change the overall code behaviour. 

d) These instructions subtracts a value from the stack pointer, to allocate space inside the stack for the local variables.

The third line of the main is used to align the stack to a 16-bit boundary.

e) After changing and compiling the code, the hexdump was directed to the p3_char_dump file.

After compiling the changes, we found out that the new version didn't use the eax to return the values. The new version, the compilter adds the ```movsbl %al, %eax``` that extends the 8-bit char value to a 32 bit value, this because the x86 convetions define the return of fuctions as a 32-bit value.

With this in mind, the declaration of the return type is needed so that the compiler knows the correct types and the generated code respect the correct memory size and variable-type behaviour.
