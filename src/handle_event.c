/*
** EPITECH PROJECT, 2020
** handle_event
** File description:
** part of program whare we manage event
*/

#include "rpg.h"

static void choose_event_donjon_2(game_t *game)
{
    if (game->idx_sce == 5) {
        if (third_donjon(game) == -1) {
            game->player->pv = game->player->max_pv;
            game->player->mana =game->player->max_mana;
        }
        game->idx_sce = 1;
    }
}

static void choose_event_donjon(game_t *game)
{
    if (game->idx_sce == 3) {
        if (first_donjon(game) == -1) {
            game->player->pv = game->player->max_pv;
            game->player->mana =game->player->max_mana;
        }
        game->idx_sce = 1;
    }
    if (game->idx_sce == 4) {
        if (second_donjon(game) == -1) {
            game->player->pv = game->player->max_pv;
            game->player->mana =game->player->max_mana;
        }
        game->idx_sce = 1;
    }
    choose_event_donjon_2(game);
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    if (game->idx_sce == 7) {
        ending_anim(game);
        game->idx_sce = 0;
    }
}

int handle_event(game_t *game, player_t *pl, coll_t *coll)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window.window);
    int check = 0;

    if (game->scene[game->idx_sce]->but != NULL) {
        for (int i = 0; check == 0 && \
game->scene[game->idx_sce]->but[i] != NULL; i++)
            check = handle_button(game, i, mouse_pos);
    }
    if (game->idx_sce == 1) {
        move_camera(game, coll, game->player);
        anime_perso(game->player, game);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->idx_sce = 2;
        if (sfKeyboard_isKeyPressed(sfKeyI))
            inventory(game);
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            game->idx_sce = 6;
    }
    choose_event_donjon(game);
    (void) pl;
    return (0);
}