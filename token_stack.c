/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** tkt de rien Maxime
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/token_stack.h"
#include "include/token.h"

token_stack_t create_stack(int size)
{
    token_stack_t s;

    s.max_size = size;
    s.index = -1;
    s.stack = malloc(sizeof(token_t) * size);
    return (s);
}

token_t stack_top(token_stack_t *stack)
{
    token_t null_token = {NULL, UNKNOWN};

    if (stack->index == -1)
        return (null_token);
    else
        return (stack->stack[stack->index]);
}

void stack_push(token_stack_t *stack, token_t *tok)
{
    if (stack->index == (stack->max_size - 1))
        return;
    if (tok->type == NUMBER)
        stack->stack[++stack->index].tok = num_dup(tok->tok);
    else
        stack->stack[++stack->index].tok = my_strdup(tok->tok);
    stack->stack[stack->index].type = tok->type;
}

token_t *stack_pop(token_stack_t *stack)
{
    token_t *t = malloc(sizeof(token_t));

    t->tok = stack->stack[stack->index].tok;
    t->type = stack->stack[stack->index--].type;
    return (t);
}
