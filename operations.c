/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** operation sources
*/

#include <stdlib.h>
#include "include/bistro.h"
#include "include/pre_operations.h"
#include "include/operations.h"

number_t *b_add(number_t *n1, number_t *n2, bistro_t *bis, int add_carry)
{
    char res = 0;
    char carry = 0;
    number_t *result = NULL;

    for (; n1 != NULL; n1 = n1->prev) {
        res = carry + n1->digit;
        carry = 0;
        if (n2 != NULL) {
            res += n2->digit;
            n2 = n2->prev;
        }
        carry = res >= bis->base_len ? 1 : 0;
        if (res >= bis->base_len)
            res -= bis->base_len;
        num_push_front(&result, res);
    }
    if (carry == 1 && add_carry)
        num_push_front(&result, 1);
    return result;
}

number_t *b_mul(number_t *n1, number_t *n2, bistro_t *bis)
{
    number_t *result = NULL;
    number_t *tmp = NULL;
    int offset = 0;
    int i = 0;

    num_push_back(&result, 0);
    for (; n2 != NULL; n2 = n2->prev) {
        tmp = digit_mul(n1, n2->digit, bis);
        for (i = 0; i < offset; i++)
            num_push_back(&tmp, 0);
        result = make_add(result, tmp, bis, 1);
        offset++;
    }
    return result;
}

number_t *b_div(number_t *n1, number_t *n2, bistro_t *bis)
{
    number_t *result = NULL;
    number_t *tmp = n1;
    pair_t qr = {NULL, NULL};
    unsigned long int i = 0;

    num_push_back(&result, 0);
    if (is_equal(n2, result)) {
        num_push_back(&result, bis->base_len);
        return result;
    }
    while (n1 != NULL) {
        tmp = find_greater_dividend(tmp, n2);
        qr = step_div(tmp, n2, bis);
        for (i = 0; i < num_size(tmp) && n1 != NULL; i++)
            n1 = n1->next;
        tmp = qr.r;
        num_append(&result, qr.q);
        num_append(&tmp, n1);
    }
    return result;
}

number_t *b_mod(number_t *n1, number_t *n2, bistro_t *bis)
{
    number_t *tmp = n1;
    pair_t qr = {NULL, NULL};
    unsigned long int i = 0;
    number_t *zero = NULL;

    num_push_back(&zero, 0);
    if (is_equal(n2, zero)) {
        num_push_back(&qr.r, bis->base_len);
        return qr.r;
    }
    while (n1 != NULL) {
        tmp = find_greater_dividend(tmp, n2);
        qr = step_div(tmp, n2, bis);
        for (i = 0; i < num_size(tmp) && n1 != NULL; i++)
            n1 = n1->next;
        tmp = qr.r;
        num_append(&tmp, n1);
    }
    return qr.r;
}
