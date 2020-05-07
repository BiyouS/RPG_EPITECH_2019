/*
** EPITECH PROJECT, 2020
** close window
** File description:
** fermer la fenêtre 
*/

#include "rpg.h"

int close_window(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window.window, &game->window.event)) {
        if (game->window.event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window.window);
            return -1;
        }
    }
    return 0;
}