/*
** EPITECH PROJECT, 2020
** draw crédits
** File description:
** draw crédits
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

void draw_ending(game_t *game)
{
    sfVector2u vec_origin;
    sfVector2f origin;

    game->sprite[8]->scale = (sfVector2f){1, 1};
    vec_origin = sfTexture_getSize(game->sprite[8]->texture);
    sfSprite_setScale(game->sprite[8]->sprite, game->sprite[8]->scale);
    origin = (sfVector2f){vec_origin.x / 2, vec_origin.y / 2};
    sfSprite_setOrigin(game->sprite[8]->sprite, origin);
    game->sprite[8]->pos = (sfVector2f){WIN_W / 2, WIN_H * 2};
    sfSprite_setPosition(game->sprite[8]->sprite, game->sprite[8]->pos);
}
