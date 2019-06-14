/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** test number.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "../include/bistro.h"
#include "../include/token.h"
#include "../include/rpn.h"

Test(test_result, test_res)
{
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};
    number_t *n = strton("234", &bis);

    cr_assert_eq(check_result(n, &bis), 0);
    n->digit = 10;
    cr_assert_eq(check_result(n, &bis), 84);
}

Test(get_digit, test_digit)
{
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};

    cr_assert_eq(get_digit('0', &bis), 0);
}

Test(strton, test_invalid)
{
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};
    number_t *n = strton("1h", &bis);

    cr_assert_eq(n->next, NULL);
}

Test(bistro, test)
{
    bistro_t bis = {"0123456789", 10, "()+-*/%", 3};
    token_list_t *expr = NULL;
    number_t *n1 = strton("1", &bis);
    number_t *n2 = strton("9", &bis);
    number_t *n3 = NULL;
    token_t *tok = create_token(NUMBER, n1);
    token_t *tok2 = create_token(OPERATOR, "-");
    token_t *tok3 = create_token(NUMBER, n2);

    token_push_back(&expr, tok);
    token_push_back(&expr, tok3);
    token_push_back(&expr, tok2);
    n3 = eval_rpn(expr, &bis);
    cr_assert_eq(n3->digit, '-');
}
