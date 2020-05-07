/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init a button in struct button
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "structs.h"

void init_button(but_t *but, sfVector2f pos, sfVector2f size)
{
    sfColor but_color = {152, 224, 45, 255};
    sfColor transparent = {0, 0, 0, 0};

    but->rec = sfRectangleShape_create();
    if (!but->rec)
        return;
    sfRectangleShape_setPosition(but->rec, pos);
    sfRectangleShape_setSize(but->rec, size);
    sfRectangleShape_setFillColor(but->rec, but_color);
    sfRectangleShape_setOutlineThickness(but->rec, 2);
    sfRectangleShape_setOutlineColor(but->rec, transparent);
}