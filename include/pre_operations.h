/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** operation preparation
*/

#ifndef _PRE_OPERATIONS_H_
#define _PRE_OPERATIONS_H_

#include "bistro.h"
#include "number.h"
#include "operations.h"

number_t *make_add(number_t *, number_t *, bistro_t *, int);
number_t *make_sub(number_t *, number_t *, bistro_t *);
number_t *make_mul(number_t *, number_t *, bistro_t *);
number_t *make_div(number_t *, number_t *, bistro_t *);
number_t *make_mod(number_t *, number_t *, bistro_t *);
int deal_neg(number_t **, number_t **, bistro_t *);
number_t *cmpl(number_t *, bistro_t *bis);
number_t *negate(number_t *, bistro_t *bis);

#endif
