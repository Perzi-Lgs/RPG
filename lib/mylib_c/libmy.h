/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** libmy.h
*/

#ifndef _LIB_MY_
#define _LIB_MY_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
** Void returns functions
*/
void free_tab(char **);
void my_memset(char *, int);
void my_memset_array(char **);

/*
** Char * returns functions
*/
char *get_next_line(int);
char *my_pass_charac(char *, char);
char *my_strcat(char *, char *);
char *my_strcpy(char *, char const *);
char *my_strmcpy(char *);
char *my_revstr(char *);
char *my_ctof(float);
char *my_itoa(int);

/*
** Char ** returns functions
*/
char **my_str_word_tab(char *, char *);

/*
** Size_t returns functions
*/
size_t my_arraylen(char **);
size_t my_strlen(char *);
size_t my_intlen(int);

/*
** Int returns functions
*/
int my_strscmp(char *, char*);
int my_strcmp(char *, char*);
int my_atoi(char *);

/*
** Float returns functions
*/
float my_atof(char *);

/*
** Printf
*/
void my_printf(char *, ...);

#endif /* _LIB_MY_ */
