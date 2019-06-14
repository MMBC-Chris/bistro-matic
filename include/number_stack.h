/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** number stack header
*/

#ifndef _NUMBER_STACK_H_
#define _NUMBER_STACK_H_

#include "number.h"

typedef struct number_stack
{
    int max_size;
    number_t **stack;
    int index;
} number_stack_t;

number_stack_t number_create_stack(int);
number_t *number_stack_top(number_stack_t *);
void number_stack_push(number_stack_t *, number_t *);
number_t *number_stack_pop(number_stack_t *);

#endif
