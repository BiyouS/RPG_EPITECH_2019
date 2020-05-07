/*
** EPITECH PROJECT, 2020
** check_collisions
** File description:
** collisions check
*/

#include "rpg.h"

bool check_collision(coll_t *coll, player_t *player, game_t *game)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(player->hitbox);
    sfFloatRect pos = sfSprite_getGlobalBounds(coll->sprite[0]->sprite);

    (void)game;
    for (int i = 0; coll->sprite[i] != NULL; i++) {
        pos = sfSprite_getGlobalBounds(coll->sprite[i]->sprite);
        if (sfFloatRect_intersects(&hitbox, &pos, NULL) == sfTrue) {
            return false;
        }
    }
    return true;
}