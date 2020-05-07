/*
** EPITECH PROJECT, 2020
** lib my
** File description:
** take a sting, return first nb in and replace it by space
*/

int my_getnbr(char const *str);

int my_get_next_nb(char *str)
{
    int nb = my_getnbr(str);
    int cursor = 0;

    while (!(str[cursor] >= '0' && str[cursor] <= '9')
        && str[cursor] != '\0')
        cursor++;
    if (str[cursor] == '\0')
        return (-1);
    while (str[cursor] >= '0' && str[cursor] <= '9') {
        str[cursor] = ' ';
        cursor++;
    }
    return (nb);
}
