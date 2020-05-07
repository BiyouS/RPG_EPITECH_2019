/*
** EPITECH PROJECT, 2020
** draw_bouton_menu.c
** File description:
** draw bouton of menu
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

int draw_button(game_t* game, but_t **button)
{
    if (!button)
        return 84;
    for (int i = 0; button[i] != NULL; i++) {
        sfSprite_setScale(button[i]->sprite, (sfVector2f){1.3, 1.3});
        sfRenderWindow_drawSprite(game->window.window, button[i]->sprite, NULL);
    }
    return 0;
}

