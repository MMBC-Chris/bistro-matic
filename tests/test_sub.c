/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** test number.c
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"
#include "../include/number.h"
#include "../include/operations.h"
#include "../include/pre_operations.h"

Test(cmpl, test_cmpl)
{
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};
    number_t *n = strton("2", &bis);
    number_t *cn = strton("8", &bis);

    cr_assert_eq(is_equal(cmpl(n, &bis), cn), 1);
}

Test(negate, test_negate)
{
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};
    number_t *n = strton("5", &bis);
    number_t *nn = negate(n, &bis);

    cr_assert_eq(nn->digit, '-');
    cr_assert_eq(nn->next->digit, 5);
}
