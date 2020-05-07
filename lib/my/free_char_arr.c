/*
** EPITECH PROJECT, 2020
** lib my
** File description:
** free a char **
*/

#include <stdlib.h>

void free_char_arr(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}
