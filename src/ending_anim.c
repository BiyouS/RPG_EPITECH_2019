/*
** EPITECH PROJECT, 2020
** credits_anim.c
** File description:
** credits anime
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

const unsigned int WIN_W;
const unsigned int WIN_H;

static int animation(game_t *game)
{
    sfSprite_move(game->sprite[8]->sprite, (sfVector2f){0, -0.08});
    sfRenderWindow_drawSprite(game->window.window,
    game->sprite[8]->sprite, NULL);
    game->sprite[8]->pos.y = sfSprite_getPosition(game->sprite[8]->sprite).y;
    if (game->sprite[8]->pos.y <= -300)
        return 1;
    return 0;
}

static int start_ending_anim(game_t *game)
{
    int check = 0;

    do {
        close_window(game);
        sfRenderWindow_clear(game->window.window, sfBlack);
        check = animation(game);
        sfRenderWindow_display(game->window.window);
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            break;
    } while (check != 1);
    game->sprite[8]->pos = (sfVector2f){WIN_W / 2, WIN_H * 2};
    sfSprite_setPosition(game->sprite[8]->sprite, game->sprite[8]->pos);
    return 0;
}

int ending_anim(game_t *game)
{
    start_ending_anim(game);
    sfSleep(sfMilliseconds(60));
    return 0;
}