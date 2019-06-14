/*
** EPITECH PROJECT, 2018
** Bistro-matic
** File description:
** main source
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/bistro.h"
#include "include/number.h"
#include "include/check.h"
#include "include/tokenize.h"
#include "include/shunting_yard.h"
#include "include/rpn.h"
#include "include/pre_operations.h"

int check_result(number_t *result, bistro_t *bis)
{
    number_t *tmp = result;

    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->digit == bis->base_len) {
            my_errstr(ERROR_MSG);
            return 84;
        }
    show_num(result, bis);
    return 0;
}

char get_digit(char c, bistro_t *bis)
{
    int i = 0;

    for (; bis->base[i] != c; i++);
    return i;
}

number_t *strton(char const *str, bistro_t *bis)
{
    int i = 0;
    number_t *list = NULL;

    if (str[i] == bis->op[3]) {
        num_push_front(&list, bis->op[3]);
        i++;
    }
    for (; str[i]; i++) {
        if (!is_in_string(str[i], bis->base))
            return list;
        num_push_back(&list, get_digit(str[i], bis));
    }
    return list;
}

int usage(char **av)
{
    my_putstr("USAGE\n");
    my_putstr(av[0]);
    my_putstr(" base operators size_read\n\nDESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n- operators:");
    my_putstr(" the symbols for the parentheses and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
    return 0;
}

int bistro(char *base, char *operators, char *size)
{
    bistro_t bis;
    token_list_t *infix_expr;
    token_list_t *rpn_expr = NULL;

    if (check_base(base) || check_ops(operators)) {
        my_errstr(SYNTAX_ERROR_MSG);
        return 84;
    }
    bis.base = base;
    bis.base_len = my_strlen(base);
    bis.op = operators;
    bis.expr_size = my_getnbr(size);
    infix_expr = tokenize_expr(&bis);
    shunting_yard(infix_expr, &bis, &rpn_expr);
    return check_result(eval_rpn(rpn_expr, &bis), &bis);
}
