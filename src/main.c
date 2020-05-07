/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "rpg.h"

static bool parsing_arg(char **av, int ac)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
        return true;
    }
    return false;
}

int main(int ac, char **av)
{
    if (ac > 2)
        return 84;
    if (parsing_arg(av, ac) == true)
        return 0;
    if (game_starter() == false)
        return (84);
    return 0;
}
