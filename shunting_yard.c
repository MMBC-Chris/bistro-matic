/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** Shunting_yard
*/

#include <stdlib.h>
#include "include/bistro.h"
#include "include/shunting_yard.h"
#include "include/token.h"
#include "include/token_stack.h"

token_t const N_TOKEN = {NULL, UNKNOWN};

int precedence(token_t const *tok, bistro_t *bis)
{
    if (tok->type != OPERATOR)
        return 0;
    if (*((char *)(tok->tok)) == bis->op[2]
        || *((char *)(tok->tok)) == bis->op[3])
        return 2;
    if (*((char *)(tok->tok)) == bis->op[4]
        || *((char *)(tok->tok)) == bis->op[5]
        || *((char *)(tok->tok)) == bis->op[6])
        return 3;
    return 0;
}

int need_to_pop_operator(token_t const *tok, token_stack_t *s, bistro_t *bis)
{
    int cond1 = s->stack[s->index].type == OPERATOR;

    if (!cond1)
        return 0;
    return precedence(&s->stack[s->index], bis) >=
        precedence(tok, bis);
}

void shunting_yard(token_list_t *infix, bistro_t *bis, token_list_t **rpn)
{
    token_stack_t stack = create_stack(1000);

    for (; infix != NULL; infix = infix->next) {
        if (infix->token.type == NUMBER)
            token_push_back(rpn, &infix->token);
        if (infix->token.type == OPERATOR) {
            while (need_to_pop_operator(&infix->token, &stack, bis))
                token_push_back(rpn, stack_pop(&stack));
            stack_push(&stack, &infix->token);
        }
        if (infix->token.type == LEFTP)
            stack_push(&stack, &infix->token);
        if (infix->token.type == RIGHTP) {
            while (need_to_pop_operator(&N_TOKEN, &stack, bis))
                token_push_back(rpn, stack_pop(&stack));
            stack_pop(&stack);
        }
    }
    while (stack.index > -1)
        token_push_back(rpn, stack_pop(&stack));
}
