/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** operations header
*/

#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include "bistro.h"
#include "number.h"

typedef struct pair
{
    number_t *r;
    number_t *q;
} pair_t;

number_t *b_add(number_t *, number_t *, bistro_t *, int);
number_t *b_mul(number_t *, number_t *, bistro_t *);
number_t *b_div(number_t *, number_t *, bistro_t *);
number_t *b_mod(number_t *, number_t *, bistro_t *);
number_t *digit_mul(number_t *, char, bistro_t *);
number_t *find_greater_dividend(number_t *, number_t *);
pair_t step_div(number_t *, number_t *, bistro_t *);
void shift(number_t **);

#endif
