/*
** EPITECH PROJECT, 2022
** minishel
** File description:
** minishel
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void input_comand(mini_t *m)
{
    m->etap = 0;
    m->buffer = my_getline(m->env, m);
    m->argv = my_str_to_word_arr(m->buffer, " ");
    m->path = find_path(m->env, m->argv[0]);
}

//struct adam {
//    *pointer;
//    char *str;
//}
//
//void create_fucnt()
//{
//    adam *p;
//    p[0].pointer = echo_dollar;
//    p[00].str = "echo";
//}
//
//void *random;
//
//while entry != p[i].str
//p[0].pointer(m)
void builtins(mini_t *m)
{
    if ((str_compare(m->argv[0], "echo") == 1)\
    && (str_compare(m->argv[1], "$?") == 1)) {
        m->etap = echo_dollar(m);
        return;
    }
    if (str_compare(m->argv[0], "env") == 1) {
        m->etap = print_env(m->env);
        return;
    }
    if (m->argv[0][1] == '/' || m->argv[0][0] == '/')
        m->path = m->argv[0];
    if (str_compare(m->argv[0], "cd") == 1)
        m->etap = cd(m->env, m->argv);
    if (str_compare(m->argv[0], "setenv") == 1) {
        m->env = my_setenv(m->env, m->argv);
        m->etap = 1;
    }
    if (str_compare(m->argv[0], "unsetenv") == 1) {
        my_unsetenv(m);
        m->etap = 1;
    }
}

void builtins_with_path(mini_t *m)
{
    int state = 0;
    pid_t id = 0;
    pid_t pid = 0;

    if ((id = fork()) == 0) {
        if (getfile_type(m->argv[0]) == 2)
            exit(1);
        if (execve(m->path, m->argv, m->env) == -1) {
            my_putstr(m->argv[0]);
            my_putstr(": Command not found.\n");
            m->env = change_display(m->env, "1");
            exit(1);
        }
        m->env = change_display(m->env, "0");
        exit(0);
    } else {
        pid = waitpid(id, &state, 0);
        verif_seg(state, m);
    }
}

void handler(int signum)
{
    if (signum == SIGINT)
        write(0, "\n[Najmadiin fedora]$ ", (22));
}

int minishel(mini_t *m)
{
    signal(SIGINT, handler);
    m->buffer = "";
    while (1) {
        input_comand(m);
        if (str_compare(m->buffer, "exit") == 1) {
            my_putstr("exit\n");
            exit(0);
        }
        builtins(m);
        if (m->etap == 0)
            builtins_with_path(m);
    }
    return (0);
}
