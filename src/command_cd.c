/*
** EPITECH PROJECT, 2022
** cd
** File description:
** cd
*/

#include <unistd.h>
#include "minishell.h"

int cd_home(char **env, char **comand)
{
    int c = 0;

    if ((comand[1] == NULL || (str_compare(comand[1], "~") == 1))) {
        c = get_index_var(env, "HOME");
        if (c == -1) {
            comand = free_list(comand);
            return (1);
        }
        chdir(get_var_env(env, "HOME"));
        c = get_index_var(env, "OLDPWD");
        if (c == -1) {
            comand = free_list(comand);
            return (1);
        }
        env[c] = my_strcat("OLDPWD=", get_var_env(env, "PWD"));
        c = get_index_var(env, "PWD");    
        if (c == -1) {
            comand = free_list(comand);
            return (1);
        }
        env[c] = my_strcat("PWD=", get_var_env(env, "HOME"));
        comand = free_list(comand);
        return (1);
    }
    return (0);
}

int cd_old(char **env, char **comand)
{
    int c = 0;
    char *tmp = "";

    if (cd_home(env, comand) == 1)
        return (1);
    if (str_compare(comand[1], "-") == 1) {
        c = get_index_var(env, "OLDPWD");
        if (c == -1)
            return (1);
        tmp = env[c];
        chdir(get_var_env(env, "OLDPWD"));
        env[c] = my_strcat("OLDPWD=", get_var_env(env, "PWD"));
        c = get_index_var(env, "PWD");
        env[c] = tmp;
        comand = free_list(comand);
        return (1);
    }
    return (0);
}

int cd(char **env, char **comand)
{
    int c = 0;
    char s[100];

    if (cd_old(env, comand) == 0) {
        c = get_index_var(env, "PWD");
        if (c == -1) {
            comand = free_list(comand);
            return (1);
        }
        if (comand[1][my_strlen(comand[1])] != '/')
            comand[1] = my_strcat(comand[1], "/");
        if (chdir(comand[1]) == 0) {
            env[c] = my_strcat("PWD=", getcwd(s, 100));
            comand = free_list(comand);
            return (1);
        }
        for (int i = 0; comand[1][i] != '/'; i++)
            my_putchar(comand[1][i]);
        my_putstr(": No such file or directory.\n");
        comand = free_list(comand);
        return (1);
    }
    return (1);
}
