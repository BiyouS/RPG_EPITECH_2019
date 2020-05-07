/*
** EPITECH PROJECT, 2020
** credits_anim.c
** File description:
** credits anime
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

static int animation(game_t *game)
{
    sfSprite_move(game->sprite[7]->sprite, (sfVector2f){0, -0.08});
    sfRenderWindow_drawSprite(game->window.window,
    game->sprite[7]->sprite, NULL);
    game->sprite[7]->pos.y = sfSprite_getPosition(game->sprite[7]->sprite).y;
    if (game->sprite[7]->pos.y <= -300)
        return 1;
    return 0;
}

static int start_generique_anim(game_t *game)
{
    int check = 0;

    do {
        if (close_window(game) == -1)
            return (-1);
        sfRenderWindow_clear(game->window.window, sfBlack);
        check = animation(game);
        sfRenderWindow_display(game->window.window);
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            break;
    } while (check != 1);
    game->sprite[7]->pos = (sfVector2f){WIN_W / 2, WIN_H * 2};
    sfSprite_setPosition(game->sprite[7]->sprite, game->sprite[7]->pos);
    return 0;
}

int generique_anim(game_t *game)
{
    if (start_generique_anim(game) == -1)
        return (-1);
    sfSleep(sfMilliseconds(60));
    return 0;
}