/*
** EPITECH PROJECT, 2022
** free_str_or_list
** File description:
** free_str_or_list.c
*/

#include <stdlib.h>

char **free_list(char **arr)
{
    for (int i = 0; arr[i] != NULL ; i++)
        free(arr[i]);
    free(arr);
    return (arr);
}
