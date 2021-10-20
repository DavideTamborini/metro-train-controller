#include <stdio.h>
#include <rt_misc.h>

#pragma import(__use_no_semihosting_swi)


extern int  SER_PutChar(int c);                               /* see Serial.c */
extern int  SER_GetChar(void);                                /* see Serial.c */


struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;
FILE __stderr;


int fputc(int c, FILE *f) {
  if (c == '\n')  {
    SER_PutChar('\r');
  }
  return (SER_PutChar(c));
}


int fgetc(FILE *f) {
  return (SER_PutChar(SER_GetChar()));
}


int ferror(FILE *f) {
  return EOF;
}


void _ttywrch(int c) {
  SER_PutChar(c);
}


void _sys_exit(int return_code) {
label:  goto label;  /* endless loop */
}
