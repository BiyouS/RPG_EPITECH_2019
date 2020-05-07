/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** get a nbr
*/

int my_getnbr(char const *str)
{
    int beg = 0;
    int nb = 0;
    int size = 1;
    int idx = 0;

    for (int i = 0; (str[i] < '0' || str[i] > '9') && str[i] != '\0'; i++)
        beg++;
    if (str[beg] == '\0')
        return (-1);
    idx = beg;
    for (int n = beg + 1; str[n] >= '0' && str[n] <= '9'; n++)
        size *= 10;
    while (size >= 1) {
        nb += (str[idx] - '0') * size;
        size /= 10;
        idx++;
    }
    if (beg != 0 && str[beg - 1] == '-')
        nb *= -1;
    return (nb);
}
