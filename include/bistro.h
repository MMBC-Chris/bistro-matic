/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** Main header
*/

#ifndef _BISTRO_H_
#define _BISTRO_H_

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG "error"

typedef struct bistro
{
    char *base;
    int base_len;
    char *op;
    int expr_size;
} bistro_t;

#include "number.h"

int check_result(number_t *, bistro_t *);
char get_digit(char, bistro_t *);
number_t *strton(char const *, bistro_t *);
int bistro(char *, char *, char *);
int usage(char **);

#endif
