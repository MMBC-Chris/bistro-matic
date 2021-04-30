/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** tkt de rien Maxime
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/bistro.h"
#include "include/number_stack.h"
#include "include/number.h"

number_stack_t number_create_stack(int size)
{
    number_stack_t s;

    s.max_size = size;
    s.index = -1;
    s.stack = malloc(sizeof(number_t *) * size);
    return (s);
}

number_t *number_stack_top(number_stack_t *stack)
{
    number_t *null_number = NULL;

    if (stack->index == -1)
        return (null_number);
    else
        return (stack->stack[stack->index]);
}

void number_stack_push(number_stack_t *stack, number_t *num)
{
    if (stack->index == (stack->max_size - 1))
        return;
    stack->stack[++stack->index] = num_dup(num);
}

number_t *number_stack_pop(number_stack_t *stack)
{
    number_t *t = NULL;

    t = num_dup(stack->stack[stack->index--]);
    return (t);
}
