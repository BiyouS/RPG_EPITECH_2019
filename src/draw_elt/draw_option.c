/*
** EPITECH PROJECT, 2020
** draw option
** File description:
** draw option
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

void draw_option(game_t *game)
{
    but_t **button = NULL;

    button = get_but_from_file("button_option.txt");
    draw_menu_map(game);
    draw_button(game, button);
}
