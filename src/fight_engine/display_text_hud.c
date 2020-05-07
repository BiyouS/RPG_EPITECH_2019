/*
** EPITECH PROJECT, 2020
** disaplay_text_hud
** File description:
** hud.c
*/

#include "rpg.h"

const sfVector2f pos_hud[5] = {
    (sfVector2f){50, 650},
    (sfVector2f){1205, 655},
    (sfVector2f){135, 645},
    (sfVector2f){715, 95},
    (sfVector2f){790, 85}
};

static void create_text(char *name, text_t *text, sfVector2f pos)
{
    sfText_setString(text->text, name);
    sfText_setPosition(text->text, pos);
    sfText_setColor(text->text, sfWhite);
}

void display_text_hud(game_t *game, player_t *player)
{
    char *info[6] = {
        my_int_to_str(player->pv),
        my_int_to_str(player->mana),
        my_int_to_str(player->protec),
        my_int_to_str(game->ennemi->pv),
        my_int_to_str(game->ennemi->protec),
        NULL,
    };

    for (int i = 0; info[i] != NULL; i++) {
        create_text(info[i], &game->text, pos_hud[i]);
        sfRenderWindow_drawText(game->window.window, game->text.text, NULL);
    }
}