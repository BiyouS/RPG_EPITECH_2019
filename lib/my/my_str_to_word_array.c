/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** function spliting a string by word, 
** return NULL in case of error
*/

#include <stdlib.h>

static int count_word(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
            i++;
        if (str[i] == '\0')
            break;
        while (!(str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
            i++;
        count++;
        if (str[i] == '\0')
            break;
    }
    return (count);
}

static int get_beg(char const *str, int end)
{
    int beg = end;

    while ((str[beg] == ' ' || str[beg] == '\t') && str[beg] != '\0')
        beg++;
    return (beg);
}

static int get_end(char const *str, int beg)
{
    int end = beg;

    while (!(str[end] == ' ' || str[end] == '\t') && str[end] != '\0')
        end++;
    return (end);
}

static int fill_arr(char **arr, char const *str)
{
    int beg = 0;
    int end = 0;

    for (int j = 0, i = 0; str[end] != '\0'; j = 0, i++) {
        j = 0;
        beg = get_beg(str, end);
        end = get_end(str, beg);
        if (str[beg] == '\0')
            break;
        arr[i] = malloc(sizeof(char) * (end - beg + 1));
        if (!arr[i])
            return (-1);
        while (beg != end) {
            arr[i][j] = str[beg];
            beg++;
            j++;
        }
        arr[i][j] = '\0';
        arr[i + 1] = NULL;
    }
    return (0);
}

char **my_str_to_word_array(char const *str)
{
    char **arr = malloc(sizeof(char *) * (count_word(str) + 1));

    if (!arr)
        return (NULL);
    else if (count_word(str) == 0) {
        free(arr);
        return (NULL);
    }
    if (fill_arr(arr, str) == -1) {
        for (int i = 0; arr[i] != NULL; i++)
            free(arr[i]);
        free(arr);
        return (NULL);
    } else
        return (arr);
}
