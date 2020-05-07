/*
** EPITECH PROJECT, 2020
** draw_menu.c
** File description:
** draw menu
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

void draw_menu_map(game_t* game)
{
    sfVector2u vec_origin;
    sfVector2f origin;

    game->sprite[1]->scale = (sfVector2f){1, 1};
    vec_origin = sfTexture_getSize(game->sprite[1]->texture);
    sfSprite_setScale(game->sprite[1]->sprite, game->sprite[1]->scale);
    origin = (sfVector2f){vec_origin.x / 2, vec_origin.y / 2};
    sfSprite_setOrigin(game->sprite[1]->sprite, origin);
    game->sprite[1]->pos = (sfVector2f){WIN_W / 2, WIN_H / 2};
    sfSprite_setPosition(game->sprite[1]->sprite, game->sprite[1]->pos);
    sfRenderWindow_drawSprite(game->window.window,
    game->sprite[1]->sprite, NULL);
}
