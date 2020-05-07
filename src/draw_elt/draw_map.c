/*
** EPITECH PROJECT, 2020
** draw map
** File description:
** draw map
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

void draw_map(game_t* game)
{
    sfVector2u vec_origin;
    sfVector2f origin;

    game->sprite[0]->scale = (sfVector2f){11, 12};
    vec_origin = sfTexture_getSize(game->sprite[0]->texture);
    sfSprite_setScale(game->sprite[0]->sprite, game->sprite[0]->scale);
    origin = (sfVector2f){vec_origin.x / 2, vec_origin.y / 2};
    sfSprite_setOrigin(game->sprite[0]->sprite, origin);
    game->sprite[0]->pos = (sfVector2f){WIN_W / 2, WIN_H / 2};
    sfSprite_setPosition(game->sprite[0]->sprite, game->sprite[0]->pos);
}
