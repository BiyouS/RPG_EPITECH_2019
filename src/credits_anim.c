/*
** EPITECH PROJECT, 2020
** credits_anim.c
** File description:
** credits anime
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

int credits_anim(game_t *game)
{
    sfSprite_move(game->sprite[4]->sprite, (sfVector2f){0, -0.1});
    sfRenderWindow_drawSprite(game->window.window,
    game->sprite[4]->sprite, NULL);
    game->sprite[4]->pos.y = sfSprite_getPosition(game->sprite[4]->sprite).y;
    if (game->sprite[4]->pos.y <= -400)
        return 1;
    return 0;
}