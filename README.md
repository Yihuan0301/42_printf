### printf:
introduce [va_list]:
https://hackernoon.com/what-is-va_list-in-c-exploring-the-secrets-of-ft_printf
<stdarg.h> 
There are a few key macros that come into play when using va_list:
    va_start: Think of this as "starting the list". It initialises the list to point to the first variable argument.
    va_arg: This is how you get the next argument from the list.
    va_end: This "ends the list" and  cleans up the memory associated with va_lis
    va_copy: This is for copying the list.

int type???

 int
 unsigned int
 unsigned long int
 long int
 unsigned long long int
 * uintptr_t
 An unsigned integer type guaranteed able to hold a pointer (from <stdint.h>). Use when you need to convert a pointer to an integer for printing or arithmetic. It is portable across platforms where pointers may be 32 or 64 bits. For printf, use PRIuPTR/PRIxPTR from <inttypes.h> or cast to unsigned long long and print with %llu if you know sizes.

 ### get_next_line
 ssize_t read(int files, void *buf, size_t nbyte);
