/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** get mouse position in sfVectof2f
*/

#include "rpg.h"

sfVector2f get_mouse_pos(sfRenderWindow *window)
{
    sfVector2i vec1 = sfMouse_getPositionRenderWindow(window);
    sfVector2f vec2 = {(float)vec1.x, (float)vec1.y};

    return (vec2);
}