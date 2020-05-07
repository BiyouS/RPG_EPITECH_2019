/*
** EPITECH PROJECT, 2020
** dsfsd
** File description:
** sdfsd
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

void create_my_window(char *n, game_t *game)
{
    sfVideoMode mod = (sfVideoMode){WIN_W, WIN_H, 32};

    game->window.window = sfRenderWindow_create(mod, n, sfDefaultStyle, NULL);
}
