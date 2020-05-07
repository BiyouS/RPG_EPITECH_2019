/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** return 1 if user click on the button else 0
*/

#include "rpg.h"

int button_is_clicked(but_t *but, sfVector2f click_pos)
{
    sfVector2f but_pos = sfRectangleShape_getPosition(but->rec);
    sfVector2f size = sfRectangleShape_getSize(but->rec);

    if ((click_pos.x >= but_pos.x && click_pos.x <= (but_pos.x + size.x))
    && (click_pos.y >= but_pos.y && click_pos.y <= (but_pos.y + size .y))) {
        return (1);
    } else
        return (0);
}