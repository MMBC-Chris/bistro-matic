/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** addition usefull functions
*/

#include <stdlib.h>
#include "include/bistro.h"
#include "include/number.h"
#include "include/operations.h"

void shift(number_t **n)
{
    *n = (*n)->next;
    (*n)->prev = NULL;
}

int deal_neg(number_t **n1, number_t **n2, bistro_t *bis)
{
    number_t *tmp = *n1;

    if ((*n1)->digit == bis->op[3] && (*n2)->digit == bis->op[3]) {
        shift(n1);
        shift(n2);
        return 2;
    }
    else if ((*n1)->digit != bis->op[3] && (*n2)->digit != bis->op[3])
        return 0;
    if ((*n1)->digit == bis->op[3]) {
        *n1 = *n2;
        *n2 = tmp->next;
        (*n2)->prev = NULL;
    }
    else
        shift(n2);
    return 1;
}
