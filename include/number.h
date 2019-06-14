/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** struct
*/

#ifndef _NUMBER_H_
#define _NUMBER_H_

#include "bistro.h"

typedef struct number
{
    char digit;
    struct number *next;
    struct number *prev;
}              number_t;

number_t *num_push_back(number_t **, char);
number_t *num_push_front(number_t **, char);
void show_num(number_t *, bistro_t *);
char num_at(number_t *, unsigned long int);
unsigned long int num_size(number_t *);
number_t *num_dup(number_t *);
int is_greater(number_t *, number_t *);
int is_equal(number_t *, number_t *);
number_t *num_append(number_t **, number_t *);

#endif
