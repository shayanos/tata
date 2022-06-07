/*
** EPITECH PROJECT, 2022
** unsetenv
** File description:
** unsetenv
*/

#include <stdlib.h>
#include "minishell.h"

char *malloc_str(char *str)
{
    int len_str = 0;
    char *dest;

    for (; str[len_str] != '\0'; len_str++);
    dest = malloc(sizeof(char) * (len_str + 1));
    for (int i = 0; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[len_str] = '\0';
    return (dest);
}

void my_unsetenv(mini_t *m)
{
    int c = 0;
    int z = 0;

    if (m->argv[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return ;
    }
    for (int i = 1; m->argv[i] != NULL; i++) {
        z = 0;
        if ((c = var_access_or_not(m->env, m->argv[i])) == -1)
            z = 1;
        if (z == 0) {
            for (; m->env[c + 1] != NULL; c++)
                m->env[c] = malloc_str(m->env[c + 1]);
            m->env[c] = NULL;
            free (m->env[c + 1]);
        }
    }
    return;
}
