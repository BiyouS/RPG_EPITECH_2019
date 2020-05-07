/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** all function link to pause button
*/

#include "rpg.h"

int go_to_menu(game_t *game)
{
    game->idx_sce = 0;
    return (0);
}

/*
void save(game_t *game)
{
    //save_function
} */

int continue_game(game_t *game)
{
    game->idx_sce = 1;
    return (0);
}