/*
** EPITECH PROJECT, 2019
** lib my
** File description:
** get len of a number
*/

int my_nbrlen(int nb)
{
    int i = 1;
    int count = 1;

    while ((nb / i) > 9) {
        i = i * 10;
        count++;
    }
    return (count);
}
