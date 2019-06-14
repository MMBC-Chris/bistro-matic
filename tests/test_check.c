/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** test number.c
*/

#include <criterion/criterion.h>
#include "../include/check.h"

Test(check_base, test_check)
{
    cr_assert_eq(check_base("0023"), 1);
    cr_assert_eq(check_base("0"), 1);
}
