/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_hud
*/

#include "rpg.h"

static void create_positions(game_t *game)
{
    sfVector2f pos[8] = {(sfVector2f){20, 20},
        (sfVector2f){90, 20},
        (sfVector2f){170, 20},
        (sfVector2f){25, 635},
        (sfVector2f){1170, 620},
        (sfVector2f){115, 630},
        (sfVector2f){690, 80},
        (sfVector2f){770, 70}
    };
    for (int i = 0; i < 8; i++)
        sfSprite_setPosition(game->hud.sprites[i], pos[i]);
    game->hud.positions = pos;
}

static sfSprite **create_sprites(sfTexture **textures)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * (8 + 1));

    if (sprites == NULL)
        return (NULL);
    for (int i = 0; i < 9; i++) {
        sprites[i] = sfSprite_create();
        sfSprite_setTexture(sprites[i], textures[i], sfFalse);
    }
    sprites[8] = NULL;
    return (sprites);
}

static sfTexture **create_textures(char **sprites_path)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * (9 + 1));

    if (textures == NULL)
        return (NULL);
    for (int i = 0; sprites_path[i] != NULL; i++) {
        textures[i] = sfTexture_createFromFile(sprites_path[i], NULL);
        if (textures[i] == NULL) {
            free(textures);
            return (NULL);
        }
    }
    textures[8] = NULL;
    return (textures);
}

int init_hud(game_t *game)
{
    char *sprites_path[9] = {
        "Assets/IMG/artefact_1.png",
        "Assets/IMG/artefact_2.png",
        "Assets/IMG/artefact_3.png",
        "Assets/IMG/hearth.png",
        "Assets/IMG/mana_potion.png",
        "Assets/IMG/shield.png",
        "Assets/IMG/hearth.png",
        "Assets/IMG/shield.png",
        NULL,
    };
    game->hud.textures = create_textures(sprites_path);
    if (game->hud.textures == NULL)
        return (-1);
    game->hud.sprites = create_sprites(game->hud.textures);
    if (game->hud.sprites == NULL)
        return (-1);
    sfSprite_setPosition(game->sprite[6]->sprite, (sfVector2f){1000, 640});
    create_positions(game);
    return (0);
}