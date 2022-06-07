/*
** EPITECH PROJECT, 2022
** print_env.
** File description:
** print_env
*/

#include <stdlib.h>
#include "minishell.h"

int print_env(char **env)
{
    if (env[0] == NULL)
        return (1);
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return (1);
}
