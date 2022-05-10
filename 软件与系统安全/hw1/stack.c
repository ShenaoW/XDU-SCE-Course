/* stack.c */
/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 517 // Represent the size of the buffer

int bof(char *str) {
    char buffer[24];
//	printf("buffer addr (%p)\n", buffer);
    /* The following statement has a buffer overflow problem */
    strcpy(buffer, str);
    return 1;
}

int main(int argc, char **argv) {
    char str[BUFFER_SIZE];
//	printf("str addr (%p)\n", str);
    FILE *badfile;
    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), 517, badfile);
    bof(str);
    printf("Returned Properly\n");
    return 1;
}
