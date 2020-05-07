/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.c
*/

#include "rpg.h"

static void draw_ennemie_player(game_t *game, player_t *player, window_t wind)
{
    sfVector2f pos_player = {200, 300};
    sfVector2f pos_ennemie = {650, 200};

    sfSprite_setPosition(player->sprite, pos_player);
    sfRenderWindow_drawSprite(wind.window, player->sprite, NULL);
    sfSprite_setPosition(game->ennemi->sprite, pos_ennemie);
    sfRenderWindow_drawSprite(wind.window, game->ennemi->sprite, NULL);
}

static void display_elt(game_t *game, int *card, window_t wind)
{
    close_window(game);
    sfRenderWindow_clear(wind.window, sfBlack);
    sfRenderWindow_drawSprite(wind.window,
    game->scene[game->idx_sce]->bg.spr, NULL);
    display_card(game->player->deck, card, wind);
    for (int i = 0; i != 8; i++)
        sfRenderWindow_drawSprite(wind.window, game->hud.sprites[i], NULL);
    sfRenderWindow_drawSprite(wind.window, game->sprite[6]->sprite, NULL);
    display_text_hud(game, game->player);
    draw_ennemie_player(game, game->player, wind);
    display_cursor(game->sprite[5], wind);
    sfRenderWindow_display(wind.window);
}

static int ia_turn(game_t *game)
{
    ia_fight(game);
    sfSleep(sfMilliseconds(60));
    return (-1);
}

static int is_it_finish(game_t *game)
{
    int player_pv = game->player->pv;
    int enn_pv = game->ennemi->pv;

    if (player_pv <= 0)
        return -1;
    if (enn_pv <= 0)
        return -2;
    return (0);
}

int fight(game_t *game)
{
    int card[4] = {0, 1, 2, 3};
    int save_mana = game->player->max_mana;
    int turn = -1;

    while (sfRenderWindow_isOpen(game->window.window)) {
        display_elt(game, card, game->window);
        turn = start_turn(game, card, save_mana, turn);
        if (turn == 0) {
            player_turn(game, card, &turn);
            sfSleep(sfMilliseconds(40));
        }
        if (is_it_finish(game) != 0)
            return (is_it_finish(game));
        if (turn == 2) {
            turn = ia_turn(game);
            sfSleep(sfMilliseconds(40));
        }
        if (is_it_finish(game) != 0)
            return (is_it_finish(game));
    }
    return 0;
}