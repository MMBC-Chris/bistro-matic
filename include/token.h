/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** token header
*/

#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "bistro.h"

typedef enum
{
    UNKNOWN,
    NUMBER,
    OPERATOR,
    LEFTP,
    RIGHTP
} token_type_t;

typedef struct token
{
    void *tok;
    token_type_t type;
} token_t;

typedef struct token_list
{
    token_t token;
    struct token_list *next;
} token_list_t;

token_list_t *token_push_front(token_list_t **, token_t *);
token_list_t *token_push_back(token_list_t **, token_t *);
token_t *create_token(token_type_t , void *);
token_t *token_dup(char const *, bistro_t *);

#endif
