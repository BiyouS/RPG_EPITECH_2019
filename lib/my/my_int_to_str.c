/*
** EPITECH PROJECT, 2020
** lib my
** File description:
** take a int and return a str of this int,
**  NULL if error
*/

#include <stdlib.h>

int my_nbrlen(int nb);

char *my_int_to_str(int nb)
{
    int len = my_nbrlen(nb);
    char *str = malloc(sizeof(char) * (len + 1));
    int pow = 1;

    if (!str)
        return (NULL);
    for (int i = 0; i < len - 1; i++)
        pow *= 10;
    for (int j = 0; j < len; j++) {
        str[j] = (nb / pow % 10) + '0';
        pow /= 10;
    }
    str[len] = '\0';
    return (str);
}
