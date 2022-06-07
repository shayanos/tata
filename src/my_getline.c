/*
** EPITECH PROJECT, 2022
** my_getline
** File description:
** my_getline
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

void pwd(char **env)
{
    int c = 0;
    int m = 0;
    char *pwd;

    pwd = get_var_env(env, "PWD");
    if (pwd[0] != '-' && pwd[1] != '1') {
        for (m = my_strlen(pwd); pwd[m] != '/'; m--);
        m++;
        my_putchar(' ');
        for (; pwd[m] != '\0'; m++)
            my_putchar(pwd[m]);
    }
    return;
}

char *my_getline(char **env, mini_t *m)
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;
    int i = 0;

    buffer = malloc(sizeof(char) * bufsize);
    my_putstr("[Najmadiin fedora");
    pwd(env);
    my_putstr("]$ ");
    if ((characters = getline(&buffer, &bufsize, stdin)) == EOF) {
        my_putstr("exit\n");
        exit(0);
    }
    buffer[characters - 1] = '\0';
    if (my_strlen(buffer) == 0)
        buffer = my_getline(env, m);
    return (buffer);
}
