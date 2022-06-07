/*
** EPITECH PROJECT, 2022
** verif_seg
** File description:
** verif_seg
*/

#include "minishell.h"
#include <signal.h>

void verif_seg(int state, mini_t *m)
{
    if (getfile_type(m->argv[0]) == 2) {
        if (m->argv[0][0] == '.' && m->argv[0][1] == '/') {
            my_putstr(m->argv[0]);
            my_putstr(": Permission denied.\n");
            m->env = change_display(m->env, "1");
        }
    }
    if (state == 139) {
        my_putstr("Segmentation fault (core dumped)\n");
        m->env = change_display(m->env, "139");
    }
    if (state == 11) {
        my_putstr("Segmentation fault\n");
        m->env = change_display(m->env, "11");
    }
    //if (state = SIGFPE) {
    //    my_putstr("Floating exception (core dumped)\n");
    //    m->env = change_display(m->env, "139");
    //}
    free_list(m->argv);
}
