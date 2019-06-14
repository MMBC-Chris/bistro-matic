/*
** EPITECH PROJECT, 2018
** chain
** File description:
** double_chain_list
*/

#include <stdlib.h>
#include "include/bistro.h"
#include "include/number.h"
#include "include/my.h"

number_t *num_push_front(number_t **number, char digit)
{
    number_t *tmp = NULL;

    tmp = malloc(sizeof(number_t));
    tmp->digit = digit;
    tmp->next = *number;
    tmp->prev = NULL;
    if (*number != NULL)
        (*number)->prev = tmp;
    *number = tmp;
    return (tmp);
}

number_t *num_push_back(number_t **number, char digit)
{
    number_t *elem = NULL;
    number_t *tmp = *number;

    elem = malloc(sizeof(number_t));
    elem->digit = digit;
    elem->next = NULL;
    while (tmp != NULL && tmp->next != NULL)
        tmp = tmp->next;
    elem->prev = tmp;
    if (tmp == NULL)
        *number = elem;
    else
        tmp->next = elem;
    return (*number);
}

void show_num(number_t *number, bistro_t *bis)
{
    number_t *elem = number;
    int digit_found = 0;

    if (elem == NULL)
        return;
    if (elem->digit == bis->op[3]) {
        my_putchar(bis->op[3]);
        elem = elem->next;
    }
    while (elem != NULL) {
        if (elem->digit != 0 && !digit_found)
            digit_found = 1;
        if (digit_found)
            my_putchar(bis->base[(unsigned)(elem->digit)]);
        elem = elem->next;
    }
    if (!digit_found)
        my_putchar(bis->base[0]);
}

unsigned long int num_size(number_t *number)
{
    number_t *tmp = number;
    unsigned long int size = 0;

    if (number == NULL)
        return 0;
    while (tmp->next != NULL) {
        size++;
        tmp = tmp->next;
    }
    return ++size;
}

char num_at(number_t *number, unsigned long int pos)
{
    number_t *tmp = number;
    unsigned long int i = 0;

    if (number == NULL)
        return 0;
    while (i < pos && tmp->next != NULL) {
        tmp = tmp->next;
        i++;
    }
    return tmp->digit;
}
