/*
** EPITECH PROJECT, 2020
** draw_name_of_game.c
** File description:
** Affiche le titre du jeu
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

void draw_name_of_game(game_t *game)
{
    sfVector2u vec_origin;
    sfVector2f origin;

    game->sprite[2]->scale = (sfVector2f){1, 1};
    vec_origin = sfTexture_getSize(game->sprite[2]->texture);
    sfSprite_setScale(game->sprite[2]->sprite, game->sprite[2]->scale);
    origin = (sfVector2f){vec_origin.x / 2, vec_origin.y / 2};
    sfSprite_setOrigin(game->sprite[2]->sprite, origin);
    game->sprite[2]->pos = (sfVector2f){WIN_W / 2, WIN_H / 2};
    sfSprite_setPosition(game->sprite[2]->sprite, game->sprite[2]->pos);
    game->sprite[3]->scale = (sfVector2f){1, 1};
    vec_origin = sfTexture_getSize(game->sprite[3]->texture);
    sfSprite_setScale(game->sprite[3]->sprite, game->sprite[3]->scale);
    origin = (sfVector2f){vec_origin.x / 2, vec_origin.y / 2};
    sfSprite_setOrigin(game->sprite[3]->sprite, origin);
    game->sprite[3]->pos = (sfVector2f){WIN_W / 2, WIN_H / 2};
    sfSprite_setPosition(game->sprite[3]->sprite, game->sprite[3]->pos);
}