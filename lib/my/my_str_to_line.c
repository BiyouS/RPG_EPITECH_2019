/*
** EPITECH PROJECT, 2020
** lib my
** File description:
** take a str and parse it with specified separator
*/

#include <stdlib.h>

static int count_nb_case(char *str)
{
    int nb = 0;
    int cursor = 0;

    while (str[cursor] != '\0') {
        while (str[cursor] != '\0' && str[cursor] == '\n')
            cursor++;
        if (str[cursor] == '\0')
            break;
        while (str[cursor] != '\n' && str[cursor] != '\0')
            cursor++;
        nb++;
    }
    return (nb);
}

static char **get_arr(char **arr, char *str, int nb_case)
{
    int beg = 0;
    int end = 0;

    for (int i = 0; i < nb_case; i++) {
        for (beg = end; str[beg] == '\n' && str[beg] != '\0'; beg++);
        for (end = beg; str[end] != '\n' && str[end] != '\0'; end++);
        arr[i] = malloc(sizeof(char) * ((end - beg) + 1));
        if (!arr[i])
            return (NULL);
        for (int j = 0; beg != end; j++, beg++) {
            arr[i][j] = str[beg];
            arr[i][j + 1] = '\0';
        }
        arr[i + 1] = NULL;
    }
    return (arr);
}

char **my_str_to_line(char *str)
{
    int nb_case = count_nb_case(str);
    char **arr = NULL;
    int i = 0;

    if (nb_case == 0)
        return (NULL);
    arr = malloc(sizeof(char *) * (nb_case + 1));
    if (!arr)
        return (NULL);
    if (get_arr(arr, str, nb_case) == NULL) {
        while (arr[i]) {
            free(arr[i]);
            i++;
        }
        free(arr);
    }
    return (arr);
}
