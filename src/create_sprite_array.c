/*
** EPITECH PROJECT, 2020
** create sprite
** File description:
** create srpite
*/

#include "rpg.h"

extern const int NB_ASSETS;
extern const char *FILEPATHS[];

static int create_sprite(char const *name, int i, game_t *game)
{
    game->sprite[i] = malloc(sizeof(sprite_t));

    if (game->sprite[i] == NULL || name == NULL)
        return 84;
    game->sprite[i]->sprite = sfSprite_create();
    if (game->sprite[i]->sprite == NULL)
        return 84;
    game->sprite[i]->texture = sfTexture_createFromFile(name, NULL);
    if (game->sprite[i]->texture == NULL)
        return 84;
    sfSprite_setTexture(game->sprite[i]->sprite,
    game->sprite[i]->texture, sfFalse);
    return 0;
}

int create_sprite_array(game_t *game)
{
    game->sprite = malloc(sizeof(sprite_t *) * (NB_ASSETS + 1));

    if (game->sprite == NULL || NB_ASSETS <= 0)
        return 84;
    for (int i = 0; i < NB_ASSETS; i++)
        if (create_sprite(FILEPATHS[i], i, game) == 84)
            return 84;
    game->sprite[NB_ASSETS] = NULL;
    return 0;
}
