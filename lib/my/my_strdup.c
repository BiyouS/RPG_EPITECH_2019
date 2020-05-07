/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** duplicate a string with a new malloc
*/

#include <stdlib.h>

int my_strlen(char const *src);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *str = NULL;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (!str)
        return (NULL);
    my_strcpy(str, src);
    return (str);
}
