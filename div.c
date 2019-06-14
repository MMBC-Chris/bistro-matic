/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** division usefull functions
*/

#include <stdlib.h>
#include "include/bistro.h"
#include "include/number.h"
#include "include/pre_operations.h"
#include "include/operations.h"

number_t *find_greater_dividend(number_t *n1, number_t *n2) {
    number_t *dividend = NULL;
    number_t *zero = NULL;

    num_push_back(&zero, 0);
    if (!is_greater(n1, n2))
        return is_greater(n2, n1) ? zero : n1;
    num_push_back(&dividend, n1->digit);
    n1 = n1->next;
    for (; !is_greater(dividend, n2); n1 = n1->next)
        num_push_back(&dividend, n1->digit);
    return is_greater(dividend, n2) ? dividend : zero;
}

pair_t step_div(number_t *n1, number_t *n2, bistro_t *bis) {
    pair_t r = {NULL, NULL};
    number_t *one = NULL;

    num_push_back(&one, 1);
    num_push_back(&r.q, 0);
    r.r = n1;
    for (; !is_greater(n2, r.r); r.r = make_sub(r.r, n2, bis))
        r.q = make_add(r.q, one, bis, 1);
    return r;
}
