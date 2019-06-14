/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** test number.c
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"
#include "../include/number.h"

Test(num_push_back, test_push_back)
{
    number_t *n = NULL;

    num_push_back(&n, 1);
    num_push_back(&n, 2);
    cr_assert_eq(n->digit, 1);
}
