/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** display the cursor
*/

#include "rpg.h"

void display_cursor(sprite_t *spr, window_t wind)
{
    sfVector2f mouse_pos = get_mouse_pos(wind.window);

    sfSprite_setPosition(spr->sprite, mouse_pos);
    sfRenderWindow_drawSprite(wind.window, spr->sprite, NULL);
}