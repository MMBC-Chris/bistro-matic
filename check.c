/*
** EPITECH PROJECT, 2018
** Bistro-matic
** File description:
** checking functions
*/

#include <stdio.h>
#include "include/my.h"
#include "include/check.h"

int is_in_string(char c, char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (c == str[i])
            return 1;
    return 0;
}

int check_base(char const *str)
{
    int i = 0;

    if (my_strlen(str) < 2)
        return 1;
    for (; i < my_strlen(str) - 1; i++)
        if (is_in_string(str[i], str + i + 1))
            return 1;
    return 0;
}

int check_ops(char const *str)
{
    int i = 0;

    if (my_strlen(str) != 7)
        return 1;
    for (; i < 6; i++)
        if (is_in_string(str[i], str + i + 1))
            return 1;
    return 0;
}