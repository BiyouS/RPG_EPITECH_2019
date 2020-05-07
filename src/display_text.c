/*
** EPITECH PROJECT, 2020
** display_text.c
** File description:
** display_text.c
*/

#include "rpg.h"

void create_text_npc(char *name, text_t *text, sfVector2f pos)
{
    sfText_setPosition(text->text, pos);
    sfText_setString(text->text, name);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 40);
    sfText_setStyle(text->text, sfTextRegular);
    sfText_setColor(text->text, sfBlack);
}

void display_text(game_t *game, int i)
{
    if (i == 17)
        npc_1(game, i);
    if (i == 18)
        npc_2(game, i);
    if (i == 19)
        npc_3(game, i);
    if (i == 20)
        npc_4(game, i);
    if (i == 42)
        npc_win(game, i);
}