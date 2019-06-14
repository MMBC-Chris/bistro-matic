/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** test number.c
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"
#include "../include/operations.h"

Test(step_div, test_div)
{
    pair_t div;
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};

    div = step_div(strton("5", &bis), strton("4", &bis), &bis);
    cr_assert_eq(div.q->digit, 1);
}
