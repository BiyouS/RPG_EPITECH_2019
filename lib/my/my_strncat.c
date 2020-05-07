/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** cat two string from beg to n-ieme char
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i= 0;

    while (dest[i] != '\0')
        i++;
    for (int n = 0; src[n] != '\0' && n < nb; n++) {
        dest[i] = src[n];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
