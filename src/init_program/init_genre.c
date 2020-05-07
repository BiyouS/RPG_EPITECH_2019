/*
** EPITECH PROJECT, 2020
** sdfsd
** File description:
** sdf
*/

#include "rpg.h"

int init_genre(player_t *player, int genre)
{
    if (genre == 1)
        player->texture = sfTexture_createFromFile("Assets/IMG/Boy.png", NULL);
    if (genre == 2)
        player->texture = sfTexture_createFromFile("Assets/IMG/girl.png", NULL);
    if (player->texture == NULL)
        return (-1);
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    return (0);
}