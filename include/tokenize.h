/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** tokenize header
*/

#ifndef _TOKENIZE_H_
#define _TOKENIZE_H_

#include "bistro.h"
#include "token.h"

token_type_t get_token_type(char, bistro_t *bis, token_type_t old);
token_list_t *tokenize_expr(bistro_t *);

#endif
