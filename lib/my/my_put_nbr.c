/*
** EPITECH PROJECT, 2019
** put_nbr
** File description:
** put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int i = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / i) > 9)
        i = i * 10;
    while (i != 0) {
        my_putchar('0'+ (nb / i % 10));
        i = i / 10;
    }
    return (0);
}
