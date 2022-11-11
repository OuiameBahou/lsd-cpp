#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define BUFFER_SIZE 1
#define MAX 1000
static char  fixed[MAX];
void strconcatenate (char* s1, char* s2);
int check(char* s2);
void read_file(int fd );
char* get_line ();
char* keep() ;
char* get_next_line(int fd);
#endif
