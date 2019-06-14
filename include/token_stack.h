/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** token stack header
*/

#ifndef _TOKEN_STACK_H_
#define _TOKEN_STACK_H_

#include "token.h"

typedef struct token_stack
{
    int max_size;
    token_t *stack;
    int index;
} token_stack_t;

token_stack_t create_stack(int);
token_t stack_top(token_stack_t *);
void stack_push(token_stack_t *, token_t *);
token_t *stack_pop(token_stack_t *);

#endif