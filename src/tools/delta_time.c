/*
** EPITECH PROJECT, 2020
** delta_time.c
** File description:
** delta_time.c
*/

#include "rpg.h"

float d(int pass, game_t *game)
{
    static sfTime time;
    static float frames = 0;

    if (pass == 1) {
        time = sfClock_getElapsedTime(game->clock);
        frames = time.microseconds / (1.0f / 15.0f);
        frames /= 100000;
        sfClock_restart(game->clock);
    }
    return frames;
}