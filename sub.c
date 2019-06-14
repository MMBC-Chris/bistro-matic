/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** complement
*/

#include <stdlib.h>
#include "include/bistro.h"
#include "include/number.h"
#include "include/pre_operations.h"

number_t *cmpl(number_t *num, bistro_t *bis)
{
    number_t *res = NULL;
    number_t *one = NULL;

    num_push_back(&one, 1);
    for (; num != NULL; num = num->next)
        num_push_back(&res, bis->base_len - num->digit - 1);
    return make_add(res, one, bis, 0);
}

number_t *negate(number_t *num, bistro_t *bis)\
{
    number_t *neg = cmpl(num, bis);

    num_push_front(&neg, bis->op[3]);
    return neg;
}
