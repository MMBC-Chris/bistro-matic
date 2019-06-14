/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** test number.c
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"
#include "../include/number.h"
#include "../include/pre_operations.h"
#include "../include/operations.h"

Test(shift, test_shift)
{
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};
    number_t *n1 = strton("1234", &bis);
    number_t *n2 = n1->next;

    shift(&n1);
    cr_assert_eq(n1, n2);
}

Test(deal_neg, test_neg)
{
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};
    number_t *n1 = strton("1234", &bis);
    number_t *n2 = strton("-1234", &bis);
    number_t *n3 = strton("-8234", &bis);

    cr_assert_eq(deal_neg(&n1, &n1, &bis), 0);
    cr_assert_eq(deal_neg(&n1, &n2, &bis), 1);
    n2 = strton("-1234", &bis);
    cr_assert_eq(deal_neg(&n2, &n1, &bis), 1);
    n2 = strton("-1234", &bis);
    cr_assert_eq(deal_neg(&n2, &n3, &bis), 2);
}
