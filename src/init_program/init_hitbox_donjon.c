/*
** EPITECH PROJECT, 2020
** sdfsd
** File description:
** sfd
*/

#include "rpg.h"

int init_hitbox_donjon(game_t *game)
{
    sfColor but_color = {152, 224, 45, 255};
    sfColor transparent = {0, 0, 0, 0};
    sfVector2f pos[4] = {(sfVector2f){940, -700}, (sfVector2f){2230, 220},
        (sfVector2f){930, 930}, (sfVector2f){-850, 200}};
    sfVector2f size[4] = {(sfVector2f){300, 100}, (sfVector2f){100, 300},
        (sfVector2f){300, 100}, (sfVector2f){100, 300}};

    game->donjon.rec = malloc(sizeof(sfRectangleShape *) * 4);
    if (game->donjon.rec == NULL)
        return (-1);
    for (int i = 0; i != 4; i++) {
        game->donjon.rec[i] = sfRectangleShape_create();
        if (!game->donjon.rec[i])
            return 84;
        sfRectangleShape_setPosition(game->donjon.rec[i], pos[i]);
        sfRectangleShape_setSize(game->donjon.rec[i], size[i]);
        sfRectangleShape_setFillColor(game->donjon.rec[i], but_color);
        sfRectangleShape_setOutlineThickness(game->donjon.rec[i], 2);
        sfRectangleShape_setOutlineColor(game->donjon.rec[i], transparent);
    }
    return (0);
}