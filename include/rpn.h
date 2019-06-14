/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** Rpn managing
*/

#ifndef _RPN_H_
#define _RPN_H_

#include "bistro.h"
#include "number.h"
#include "token.h"

number_t *eval_rpn(token_list_t *, bistro_t *);

#endif
