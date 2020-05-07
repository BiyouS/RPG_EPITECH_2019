/*
** EPITECH PROJECT, 2020
** anim_perso.c
** File description:
** anime perso
*/

#include "rpg.h"

static void move_rect(player_t *player)
{
    int max_value = 567;
    int offset = 64;

    player->rect.left += offset;
    if (player->rect.left >= max_value)
        player->rect.left = 10;
}

static bool clock_prog(sfSprite *sprite, game_t *game, player_t *player)
{
    sfTime time = sfClock_getElapsedTime(game->clock_perso);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > (1.0f / 15.0f)) {
        sfClock_restart(game->clock_perso);
        move_rect(player);
    }
    sfSprite_setTextureRect(sprite, player->rect);
    return false;
}

void anime_perso(player_t *player, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        player->rect.top = 0;
        clock_prog(player->sprite, game, player);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        player->rect.top = 64;
        clock_prog(player->sprite, game, player);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        player->rect.top = 130;
        clock_prog(player->sprite, game, player);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        player->rect.top = 192;
        clock_prog(player->sprite, game, player);
    }
}