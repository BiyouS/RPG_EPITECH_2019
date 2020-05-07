/*
** EPITECH PROJECT, 2020
** before_menu.c
** File description:
** before menu
*/

#include "rpg.h"

static int event_window(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window.window, &game->window.event)) {
        if (game->window.event.type == sfEvtClosed)
            return -1;
    }
    return 0;
}

static void loop_1(game_t *game)
{
    sfRenderWindow_drawSprite(game->window.window,
    game->sprite[2]->sprite, NULL);
    sfRenderWindow_display(game->window.window);
}

static void loop_2(game_t *game)
{
    sfRenderWindow_drawSprite(game->window.window,
    game->sprite[3]->sprite, NULL);
    sfRenderWindow_display(game->window.window);
}

int before_menu(game_t* game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = time.microseconds / 1000000.0;

    while (seconds <= (2.5f)) {
        sfRenderWindow_clear(game->window.window, sfBlack);
        if (event_window(game) == -1)
            return -1;
        loop_1(game);
        time = sfClock_getElapsedTime(game->clock);
        seconds += time.microseconds / 1000000.0;
        sfClock_restart(game->clock);
    }
    while (seconds <= (5.0f)) {
        sfRenderWindow_clear(game->window.window, sfBlack);
        if (event_window(game) == -1)
            return -1;
        loop_2(game);
        time = sfClock_getElapsedTime(game->clock);
        seconds += time.microseconds / 1000000.0;
        sfClock_restart(game->clock);
    } return 0;
}
