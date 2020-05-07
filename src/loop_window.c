/*
** EPITECH PROJECT, 2020
** loop window
** File description:
** boucle de la fenêtre
*/

#include "rpg.h"

void loop_window(game_t *game, coll_t *coll)
{
    create_my_window("--- RPG GAME ---", game);
    sfRenderWindow_setMouseCursorVisible(game->window.window, false);
    if (before_menu(game) == -1) {
        sfRenderWindow_destroy(game->window.window);
        return;
    }
    while (sfRenderWindow_isOpen(game->window.window)) {
        close_window(game);
        display(game, coll, game->player);
        handle_event(game, game->player, coll);
        d(1, game);
    }
    after_game(game, game->player, coll);
    sfRenderWindow_destroy(game->window.window);
}