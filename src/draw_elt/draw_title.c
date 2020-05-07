/*
** EPITECH PROJECT, 2020
** draw_title.c
** File description:
** draw title
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

void draw_title(game_t* game)
{
    sfVector2u vec_origin;
    sfVector2f origin;

    game->sprite[2]->scale = (sfVector2f){1, 0.7};
    vec_origin = sfTexture_getSize(game->sprite[2]->texture);
    sfSprite_setScale(game->sprite[2]->sprite, game->sprite[2]->scale);
    origin = (sfVector2f){vec_origin.x / 2, vec_origin.y / 2};
    sfSprite_setOrigin(game->sprite[2]->sprite, origin);
    game->sprite[2]->pos = (sfVector2f){WIN_W / 2, 50};
    sfSprite_setPosition(game->sprite[2]->sprite, game->sprite[2]->pos);
}
