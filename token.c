/*
** EPITECH PROJECT, 2018
** Bistro-Matic
** File description:
** token managing
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/bistro.h"
#include "include/token.h"
#include "include/tokenize.h"

token_t *token_dup(char const *str, bistro_t *bis)
{
    token_t *tok = malloc(sizeof(token_t));

    tok->tok = my_calloc(sizeof(char), 2);
    my_strncpy(tok->tok, str, 1);
    tok->type = get_token_type(str[0], bis, NUMBER);
    return tok;
}

token_t *create_token(token_type_t type, void *content)
{
    token_t *tok = malloc(sizeof(token_t));

    tok->type = type;
    tok->tok = content;
    return tok;
}

token_list_t *token_push_front(token_list_t **list, token_t *tok)
{
    token_list_t *tmp = NULL;

    tmp = malloc(sizeof(token_list_t));
    tmp->token = *tok;
    tmp->next = *list;
    *list = tmp;
    return (tmp);
}

token_list_t *token_push_back(token_list_t **list, token_t *tok)
{
    token_list_t *elem = NULL;
    token_list_t *tmp = *list;

    elem = malloc(sizeof(token_list_t));
    elem->token = *tok;
    elem->next = NULL;
    while (tmp != NULL && tmp->next != NULL)
        tmp = tmp->next;
    if (tmp == NULL)
        *list = elem;
    else
        tmp->next = elem;
    return (*list);
}
