/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "minishell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *my_strdup(char *str)
{
    int len_str = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len_str + 1));
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return (dest);
}

char **inti_env(char **env)
{
    char work_directory[246];

    if (env[0] == NULL) {
        env[0] = my_strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/");
        env[0] = my_strcat(env[0], "sbin:/usr/sbin:/var/lib/snapd/snap/bin");
        getcwd(work_directory, sizeof(work_directory));
        env[1] = my_strdup("PWD=");
        env[1] = my_strcat(env[1], my_strdup(work_directory));
        env[2] = NULL;
    }
    return (env);
}

int main(int ac, char **av, char **envp)
{
    mini_t my_sh;

    my_sh.env = inti_env(envp);
    minishel(&my_sh);
    return (0);
}
