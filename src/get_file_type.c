/*
** EPITECH PROJECT, 2022
** getfiletype
** File description:
** getfiletype
*/

#include <sys/stat.h>

int getfile_type(char *filename)
{
    struct stat buf;

    if (filename[0] == '.' && filename[1] == '/')
        filename += 2;
    stat(filename, &buf);
    if (S_ISREG(buf.st_mode))
        return 1;
    if (S_ISDIR(buf.st_mode))
        return 2;
    return 0;
}
