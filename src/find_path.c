/*
** EPITECH PROJECT, 2022
** find_path.c
** File description:
** find_path.c
*/

#include <unistd.h>
#include "minishell.h"

char *find_path(char **env, char *str)
{
    int c = 0;
    char *path;
    char **arr_path;
    int z = 1;
    char work_directory[256];

    c = get_index_var(env, "PATH");
    if (c == -1)
        return (".");
    getcwd(work_directory, sizeof(work_directory));
    arr_path = my_str_to_word_arr(env[c], ":");
    arr_path[0] += 5;
    for (int i = 0; arr_path[i] != NULL; i++) {
        chdir(arr_path[i]);
        if (access(str, F_OK) == 0) {
            chdir(work_directory);
            path = my_strcat(arr_path[i], "/");
            path = my_strcat(path, str);
            return (path);
        }
    }
    chdir(work_directory);
    return (".");
}
