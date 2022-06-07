/*
** EPITECH PROJECT, 2022
** echo_dollar.c
** File description:
** echo_dollar.c
*/

#include <stddef.h>
#include "minishell.h"

int echo_dollar(mini_t *m)
{
    char *dest =  get_var_env(m->env, "DISPLAY");

    if (dest == NULL)
        return (1);
    if (dest[0] == ':')
        dest += 1;
    my_putstr(dest);
    my_putchar('\n');
    return (1);
}

char **change_display(char **env, char *value)
{
    int c = 0;

    c = get_index_var(env, "DISPLAY");
    if (c == -1)
        return (env);
    env[c] = my_strcat("DISPLAY=", value);
    return (env);
}