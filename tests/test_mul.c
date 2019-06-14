/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** test number.c
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"
#include "../include/operations.h"

Test(digit_mul, test_digit_nul)
{
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};
    number_t *n = strton("190", &bis);
    number_t *res = digit_mul(n, 9, &bis);

    cr_assert_eq(res->digit, 1);
    res = digit_mul(n, 1, &bis);
    cr_assert_eq(res->digit, 1);
}
