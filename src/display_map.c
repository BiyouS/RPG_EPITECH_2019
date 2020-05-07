/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** display the map
*/

#include "rpg.h"

void display_map(game_t *game, coll_t *coll, player_t *player)
{
    sfRenderWindow_drawSprite(game->window.window,
    game->sprite[0]->sprite, NULL);
    for (int i = 0; coll->sprite[i] != NULL; i++) {
        sfRenderWindow_drawSprite(game->window.window,
        coll->sprite[i]->sprite, NULL);
    }
    sfRenderWindow_drawSprite(game->window.window, player->hitbox, NULL);
    sfRenderWindow_drawSprite(game->window.window, player->sprite, NULL);
    if (game->text.yes != 0)
        sfRenderWindow_drawText(game->window.window, game->text.text, NULL);
}