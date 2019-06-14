/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** operation sources
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/bistro.h"
#include "include/number.h"
#include "include/pre_operations.h"
#include "include/operations.h"

number_t *make_add(number_t *n1, number_t *n2, bistro_t *bis, int add_carry)
{
    number_t *tmp = NULL;
    number_t *result = NULL;
    int sign = 0;

    sign = deal_neg(&n1, &n2, bis);
    tmp = n1;
    if (num_size(n2) > num_size(n1) && sign != 1) {
        n1 = n2;
        n2 = tmp;
    }
    if (sign != 1) {
        for (; n1->next != NULL; n1 = n1->next);
        for (; n2->next != NULL; n2 = n2->next);
        result = b_add(n1, n2, bis, add_carry);
    }
    else
        result = make_sub(n1, n2, bis);
    if (sign == 2)
        num_push_front(&result, bis->op[3]);
    return result;
}

number_t *make_sub(number_t *n1, number_t *n2, bistro_t *bis)
{
    number_t *cmpl_b = NULL;
    number_t *result = NULL;

    if (n2->digit == bis->op[3]) {
        shift(&n2);
        return make_add(n1, n2, bis, 1);
    }
    else if (n1->digit == bis->op[3]) {
        num_push_front(&n2, bis->op[3]);
        return make_add(n1, n2, bis, 1);
    }
    for (; num_size(n2) < num_size(n1); num_push_front(&n2, 0));
    for (; num_size(n1) < num_size(n2); num_push_front(&n1, 0));
    cmpl_b = cmpl(n2, bis);
    result = make_add(n1, cmpl_b, bis, 1);
    if (num_size(result) == num_size(n1))
        return negate(result, bis);
    else
        result->digit = 0;
    return result;
}

number_t *make_mul(number_t *n1, number_t *n2, bistro_t *bis)
{
    int sign = 0;
    number_t *result = NULL;

    if (n1->digit == bis->op[3]) {
        sign ^= 1;
        n1 = n1->next;
        n1->prev = NULL;
    }
    if (n2->digit == bis->op[3]) {
        sign ^= 1;
        n2 = n2->next;
        n2->prev = NULL;
    }
    for (; n2->next != NULL; n2 = n2->next);
    result = b_mul(n1, n2, bis);
    if (sign)
        num_push_front(&result, bis->op[3]);
    return result;
}

number_t *make_div(number_t *n1, number_t *n2, bistro_t *bis)
{
    int sign = 0;
    number_t *result = NULL;

    if (n1->digit == bis->op[3]) {
        sign ^= 1;
        n1 = n1->next;
        n1->prev = NULL;
    }
    if (n2->digit == bis->op[3]) {
        sign ^= 1;
        n2 = n2->next;
        n2-> prev = NULL;
    }
    result = b_div(n1, n2, bis);
    if (sign)
        num_push_front(&result, bis->op[3]);
    return result;
}

number_t *make_mod(number_t *n1, number_t *n2, bistro_t *bis)
{
    if (n1->digit == bis->op[3]) {
        n1 = n1->next;
        n1->prev = NULL;
    }
    if (n2->digit == bis->op[3]) {
        n2 = n2->next;
        n2-> prev = NULL;
    }
    return b_mod(n1, n2, bis);
}
