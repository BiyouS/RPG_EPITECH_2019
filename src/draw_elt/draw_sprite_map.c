/*
** EPITECH PROJECT, 2020
** draw sprite map
** File description:
** draw sprite map
*/

#include "rpg.h"

extern const unsigned int WIN_W;
extern const unsigned int WIN_H;
extern const sfVector2f scale[];
extern const sfVector2f pos[];

void draw_sprite_map(coll_t *sprite_coll)
{
    sfSprite *sprite;

    for (int i = 0; sprite_coll->sprite[i] != NULL; i++) {
        sprite_coll->sprite[i]->scale = scale[i];
        sprite_coll->sprite[i]->pos = pos[i];
    }
    for (int i = 0; sprite_coll->sprite[i] != NULL; i++) {
        sprite = sprite_coll->sprite[i]->sprite;
        sfSprite_setScale(sprite, sprite_coll->sprite[i]->scale);
        sfSprite_setPosition(sprite, sprite_coll->sprite[i]->pos);
    }
}
