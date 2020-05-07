/*
** EPITECH PROJECT, 2019
** BSQ Bootstrap
** File description:
** load contain of a file in a char * and return it
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char **my_str_to_line(char *);

static int get_file_len(int fd)
{
    int check = 1;
    int len = 0;
    int temp = 0;
    char buffer[500];

    if (fd < 0)
        return (-1);
    while (check == 1) {
        temp = read(fd, buffer, 500);
        len += temp;
        if (temp < 500)
            check = 0;
    }
    close(fd);
    return (len);
}

char **load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int len = get_file_len(fd);
    char *str = NULL;
    char **arr = NULL;

    if (len == -1)
        return (NULL);
    fd = open(filepath, O_RDONLY);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    read(fd, str, len);
    close(fd);
    arr = my_str_to_line(str);
    free(str);
    return (arr);
}
