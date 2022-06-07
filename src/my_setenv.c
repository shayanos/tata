/*
** EPITECH PROJECT, 2022
** setenv.c
** File description:
** setenv.c
*/

#include <stdlib.h>
#include "minishell.h"

int var_access_or_not(char **env, char *str)
{
    int c = 0;

    while (env[c] != NULL) {
        if (!(env[c][0] == str[0] && \
        env[c][1] == str[1] && env[c][2] == str[2]))
            c++;
        else
            break;
    }
    if (env[c] == NULL)
        return (-1);
    else
        return (c);
}

char **my_setenv(char **env, char **argv)
{
    int count_env = 0;
    int len_env = 0;

    if (argv[1] == NULL) {
        print_env(env);
        return env;
    }
    if ((count_env = var_access_or_not(env, argv[1])) == -1) {
        for (len_env = 0; env[len_env] != NULL; len_env++);
        env[len_env] = my_strcat(argv[1], "=");
        if (argv[1][0] >= '0' && argv[1][0] <= '9') {
            my_putstr("setenv: Variable name must begin with a letter.\n");
            return env;
        }
        if (argv[2] != NULL)
            env[len_env] = my_strcat(env[len_env], argv[2]);
        env[len_env + 1] = NULL;
        return (env);  
    } else {
        env[count_env] = my_strcat(argv[1], "=");
        if (argv[2] != NULL)
            env[count_env] = my_strcat(env[count_env], argv[2]);
    }
    return (env);
}
