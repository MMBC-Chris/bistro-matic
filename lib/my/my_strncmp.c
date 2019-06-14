/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** strcmp
*/

#include <stdlib.h>

int ncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] && i < n; i++)
        if (s1[i] != s2[i])
            return -1;
    return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = 0;

    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 == NULL || s2 == NULL || n == 0)
        return -1;
    for (; s1[i]; i++);
    for (; s2[j]; j++);
    if (i != j)
        return i - j;
    else
        return ncmp(s1, s2, n);
}
