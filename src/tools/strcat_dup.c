/*
** EPITECH PROJECT, 2020
** minishell 1
** File description:
** malloc a new string an concat to string into it
*/

#include <stdlib.h>
#include "my.h"

char *strcat_dup(char *str1, char *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *new_str = malloc(sizeof(char) * (len + 1));

    if (!new_str)
        return (NULL);
    my_strcpy(new_str, str1);
    my_strcat(new_str, str2);
    free(str1);
    return (new_str);
}
