/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** multiplication
*/

#include <stdlib.h>
#include "include/bistro.h"
#include "include/number.h"

number_t *digit_mul(number_t *n1, char factor, bistro_t *bis)
{
    number_t *result = NULL;
    int carry = 0;
    int tmp = 0;

    for (; n1->next != NULL; n1 = n1->next);
    for (; n1 != NULL; n1 = n1->prev) {
        tmp = (n1->digit * factor + carry);
        carry = 0;
        if (tmp >= bis->base_len) {
            carry = tmp / bis->base_len;
            tmp = tmp % bis->base_len;
        }
        num_push_front(&result, tmp);
    }
    if (carry != 0)
        num_push_front(&result, carry);
    return result;
}
