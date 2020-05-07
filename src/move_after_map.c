/*
** EPITECH PROJECT, 2020
** fdsfs
** File description:
** sdfs
*/

#include "rpg.h"


static void part_one(game_t *game, coll_t *coll)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfSprite_move(game->sprite[0]->sprite, (sfVector2f){0, -17});
        for (int i = 0; coll->sprite[i] != NULL; i++)
            sfSprite_move(coll->sprite[i]->sprite, (sfVector2f){0, -17});
        for (int i = 0; i != 3; i++)
            sfRectangleShape_move(game->donjon.rec[i], (sfVector2f){0, -17});
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfSprite_move(game->sprite[0]->sprite, (sfVector2f){0, 17});
        for (int i = 0; coll->sprite[i] != NULL; i++)
            sfSprite_move(coll->sprite[i]->sprite, (sfVector2f){0, 17});
        for (int i = 0; i != 3; i++)
            sfRectangleShape_move(game->donjon.rec[i], (sfVector2f){0, 17});
    }
}

static void part_two(game_t *game, coll_t *coll)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfSprite_move(game->sprite[0]->sprite, (sfVector2f){17, 0});
        for (int i = 0; coll->sprite[i] != NULL; i++)
            sfSprite_move(coll->sprite[i]->sprite, (sfVector2f){17, 0});
        for (int i = 0; i != 3; i++)
            sfRectangleShape_move(game->donjon.rec[i], (sfVector2f){17, 0});
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfSprite_move(game->sprite[0]->sprite, (sfVector2f){-17, 0});
        for (int i = 0; coll->sprite[i] != NULL; i++)
            sfSprite_move(coll->sprite[i]->sprite, (sfVector2f){-17, 0});
        for (int i = 0; i != 3; i++)
            sfRectangleShape_move(game->donjon.rec[i], (sfVector2f){-17, 0});
    }
}

void move_after_map(game_t *game, coll_t *coll)
{
    part_one(game, coll);
    part_two(game, coll);
}
