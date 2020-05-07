/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** copy n character of a string into another
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    int count_limit = 0;

    for (int j = 0; src[j] != '\0'; j++)
        count_limit++;
    if (n > count_limit)
        n = count_limit;
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (src[count_limit] == '\0')
        dest[i] = '\0';
    return (dest);
}
