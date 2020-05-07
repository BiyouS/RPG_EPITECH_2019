/*
** EPITECH PROJECT, 2020
** draw_menu.c
** File description:
** draw_menu
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

void draw_menu(game_t* game, but_t **button_menu)
{
    draw_menu_map(game);
    draw_title(game);
    draw_button(game, button_menu);
}
