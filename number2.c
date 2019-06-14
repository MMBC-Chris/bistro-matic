/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** create a double of a list
*/

#include <stdlib.h>
#include "include/bistro.h"
#include "include/number.h"

number_t *num_dup(number_t *num)
{
    number_t *tmp = NULL;

    for (; num != NULL; num = num->next)
        num_push_back(&tmp, num->digit);
    return tmp;
}

number_t *num_append(number_t **src, number_t *appendice)
{
    number_t *tmp = *src;
    number_t *tmp2 = appendice;

    if (*src == NULL) {
        tmp = malloc(sizeof(number_t));
        tmp->next = NULL;
        tmp->prev = NULL;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    for (; tmp2 != NULL; tmp2 = tmp2->next) {
        tmp->next = tmp2;
        tmp2->prev = tmp;
        tmp = tmp->next;
    }
    return *src;
}

int is_greater(number_t *n1, number_t *n2)
{
    for (; n1->digit == 0 && n1->next != NULL; n1 = n1->next);
    for (; n2->digit == 0 && n2->next != NULL; n2 = n2->next);
    if (num_size(n1) > num_size(n2))
        return 1;
    if (num_size(n2) > num_size(n1))
        return 0;
    for (; n1 != NULL; n1 = n1->next, n2 = n2->next) {
        if (n1->digit > n2->digit)
            return 1;
        else if (n2->digit > n1->digit)
            return 0;
    }
    return 0;
}

int is_equal(number_t *n1, number_t *n2)
{
    if (is_greater(n1, n2))
        return 0;
    if (is_greater(n2, n1))
        return 0;
    return 1;
}
