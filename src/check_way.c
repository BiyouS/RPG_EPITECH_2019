/*
** EPITECH PROJECT, 2020
** check_way
** File description:
** check_way.c
*/

#include "rpg.h"

static void create_text(char *name, text_t *text, sfVector2f pos)
{
    sfText_setString(text->text, name);
    sfText_setPosition(text->text, pos);
    sfText_setColor(text->text, sfBlack);
}

static void check_permission(game_t *game, int i, donjon_t dj)
{
    sfVector2f pos = {380, 560};

    create_text("Appuyer sur E pour utiliser/interagir.", &game->text, pos);
    sfRenderWindow_drawText(game->window.window, game->text.text, NULL);
    if (i == 0 && dj.art_1 == 0 && dj.art_2 == 0 && dj.art_3 == 0
    && sfKeyboard_isKeyPressed(sfKeyE) && game->quest[0] != -1) {
        game->idx_sce = 3;
    }
    if (i == 1 && dj.art_1 == 1 && dj.art_2 == 0 &&
    dj.art_3 == 0 && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->idx_sce = 4;
    }
    if (i == 2 && dj.art_1 == 1 && dj.art_2 == 1 &&
    dj.art_3 == 0 && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->idx_sce = 5;
    }
    if (i == 3 && dj.art_1 == 1 && dj.art_2 == 1 &&
    dj.art_3 == 1 && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->idx_sce = 7;
    }
}

void check_way(game_t *game)
{
    sfVector2f rec_pos;
    sfVector2f rec_size;
    sfVector2f pos = game->player->pos;

    for (int i = 0; i != 4; i++) {
        rec_pos = sfRectangleShape_getPosition(game->donjon.rec[i]);
        rec_size = sfRectangleShape_getSize(game->donjon.rec[i]);
        if ((pos.x >= rec_pos.x && pos.x <= (rec_pos.x + rec_size.x))
            && (pos.y >= rec_pos.y && pos.y <= (rec_pos.y + rec_size.y + 100)))
            check_permission(game, i, game->donjon);
    }
}
