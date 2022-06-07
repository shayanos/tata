/*
** EPITECH PROJECT, 2022
** handling var
** File description:
** handling_var
*/

#include <stdlib.h>
#include <stddef.h>
#include "minishell.h"

char *my_strncpy(char *str, int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));
    int i = 0;

    for (i = 0; (i != n && str[i] != '\0'); i++) {
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return (dest);
}

int get_index_var(char **env, char *var)
{
    int index = 0;
    int len_var = 0;

    while(env[index] != NULL) {
        for (len_var = 0; env[index][len_var] != '='; len_var++);
        if (str_compare(my_strncpy(env[index], len_var), var) == 1)
            return (index);
        index++;
    }
    return (-1);
}

char *get_var_env(char **env, char *str)
{
    int c = 0;
    char *var;
    int i = 0;
    int len_var = 0;
    int name_var = 0;

    c = get_index_var(env, str);
    if (c == -1)
        return ("-1");
    for (; env[c][name_var] != '='; name_var++);
    name_var++;
    len_var = (my_strlen(env[c]) - (name_var));
    var = malloc(sizeof(char) * (len_var + 1));
    for (; env[c][(i + name_var)] != '\0'; i++)
        var[i] = env[c][i + name_var];
    var[len_var] = '\0';
    return (var);
}

