/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** main func
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/bistro.h"
#include "include/number.h"
#include "include/token_stack.h"

int main(int ac, char **av)
{
    if (ac != 4)
        return usage(av);
    return bistro(av[1], av[2], av[3]);
}
