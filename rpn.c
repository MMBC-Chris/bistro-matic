/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** eval rpn
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/bistro.h"
#include "include/number.h"
#include "include/number_stack.h"
#include "include/token.h"
#include "include/pre_operations.h"
#include "include/rpn.h"

number_t *make_operation(number_t *n1, number_t *n2, token_t *t, bistro_t *bis)
{
    number_t *result = NULL;
    char op = *((char *)(t->tok));

    if (op == bis->op[2])
        result = make_add(n1, n2, bis, 1);
    if (op == bis->op[3])
        result = make_sub(n1, n2, bis);
    if (op == bis->op[4])
        result = make_mul(n1, n2, bis);
    if (op == bis->op[5])
        result = make_div(n1, n2, bis);
    if (op == bis->op[6])
        result = make_mod(n1, n2, bis);
    return result;
}

number_t *eval_rpn(token_list_t *rpn, bistro_t *bis)
{
    number_t *operand_1 = NULL;
    number_t *operand_2 = NULL;
    number_t *result = NULL;
    number_stack_t stack = number_create_stack(1000);

    for (; rpn != NULL; rpn = rpn->next) {
        if (rpn->token.type == NUMBER)
            number_stack_push(&stack, num_dup(rpn->token.tok));
        else if (rpn->token.type == OPERATOR) {
            operand_2 = number_stack_pop(&stack);
            operand_1 = number_stack_pop(&stack);
            result = make_operation(operand_1, operand_2, &rpn->token, bis);
            number_stack_push(&stack, result);
        }
    }
    return number_stack_pop(&stack);
}
