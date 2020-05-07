/*
** EPITECH PROJECT, 2020
** fdsf
** File description:
** fsdf
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

static int create_text(text_t *text)
{
    text->text = sfText_create();
    text->font = sfFont_createFromFile("Assets/FONT/dungeon.TTF");

    if (text->text == NULL || text->font == NULL)
        return (-1);
    sfText_setPosition(text->text, (sfVector2f){WIN_W / 2 - 100, WIN_H / 2});
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 50);
    sfText_setStyle(text->text, sfTextRegular);
    sfText_setColor(text->text, sfBlack);
    return (0);
}

static void init_game_next(game_t *game)
{
    game->clock_perso = sfClock_create();
    game->rect = (sfIntRect){0, 0, 110, 110};
    game->text.yes = 0;
    game->donjon.art_1 = 0;
    game->donjon.art_2 = 0;
    game->donjon.art_3 = 0;
}

int init_game(game_t *game)
{
    game->framebuffer = create_framebuffer(720, 1280);
    if (game->framebuffer == NULL)
        return (-1);
    if (create_sprite_array(game) == 84 ||
        create_array_of_sprite(&(game->sprite_coll)) == 84)
        return -1;
    game->clock_particle = sfClock_create();
    game->dropplet = init_rain();
    game->dropplet_heal = init_heal();
    game->clock = sfClock_create();
    if (create_text(&(game->text)) == -1 || init_hitbox_donjon(game) == -1
        || init_hud(game) == -1)
        return (-1);
    game->player = init_perso();
    if (game->player == NULL)
        return (-1);
    init_game_next(game);
    return (0);
}