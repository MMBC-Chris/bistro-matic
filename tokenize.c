/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** turn str into tokens
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/bistro.h"
#include "include/tokenize.h"
#include "include/token.h"
#include "include/number.h"
#include "include/check.h"

token_type_t get_token_type(char c, bistro_t *bis, token_type_t old)
{
    if (c == bis->op[3]) {
        if (old == NUMBER || old == RIGHTP)
            return OPERATOR;
        else
            return NUMBER;
    }
    if (is_in_string(c, bis->base))
        return NUMBER;
    if (is_in_string(c, bis->op + 2))
        return OPERATOR;
    if (c == bis->op[0])
        return LEFTP;
    if (c == bis->op[1])
        return RIGHTP;
    return UNKNOWN;
}

token_list_t *tokens(char const *str, bistro_t *bis)
{
    unsigned int i = 0;
    unsigned int j = 0;
    token_list_t *list = NULL;
    token_t *push;
    token_type_t old = UNKNOWN;
    token_type_t current = UNKNOWN;

    for (; str[i]; i++) {
        current = get_token_type(str[i], bis, old);
        if (current != NUMBER)
            token_push_back(&list, token_dup(str + i, bis));
        else {
            push = create_token(NUMBER, strton(str + i, bis));
            for (j = 0; j < num_size(push->tok); j++, i++);
            i--;
            token_push_back(&list, push);
        }
        old = current;
    }
    return list;
}

token_list_t *tokenize_expr(bistro_t *bis)
{
    char *in_expr = malloc(sizeof(char) * (bis->expr_size + 1));

    in_expr[bis->expr_size] = '\0';
    if (read(0, in_expr, bis->expr_size) != bis->expr_size) {
        my_putstr(ERROR_MSG);
        return NULL;
    }
    return tokens(in_expr, bis);
}
