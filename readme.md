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