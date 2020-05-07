/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** write a string
*/

#include <unistd.h>

static int my_len(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_putstr(char const *str)
{
    write(1, str, my_len(str));
    return (0);
}
