/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** handle_the_inventory
*/

#include "rpg.h"

const char assets_path[4][27] = {
    "Assets/IMG/heal_potion.png",
    "Assets/IMG/artefact_1.png",
    "Assets/IMG/artefact_2.png",
    "Assets/IMG/artefact_3.png",
};

const sfVector2f pos_back[3] = {
    {25, 635},
    {1170, 620},
    {115, 630},
};

static sfRectangleShape **create_inv(sfTexture ***tex_arr)
{
    sfRectangleShape **arr = malloc(sizeof(sfRectangleShape *) * 10);
    sfVector2f pos = {400, 250};

    (*tex_arr) = malloc(sizeof(sfTexture *) * 4);
    if ((*tex_arr) == NULL || arr == NULL)
        return (NULL);
    for (int i = 0; i < 10; i++) {
        arr[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(arr[i], pos);
        sfRectangleShape_setSize(arr[i], (sfVector2f){75, 75});
        sfRectangleShape_setFillColor(arr[i], (sfColor){91, 60, 17, 150});
        sfRectangleShape_setOutlineThickness(arr[i], 2);
        sfRectangleShape_setOutlineColor(arr[i], (sfColor){88, 41, 0, 255});
        pos.x += 100;
        (i == 4) ? (pos.y += 100) : (0);
        (i == 4) ? (pos.x = 400) : (0);
    }
    for (int i = 0; i < 4; i++)
        (*tex_arr)[i] = sfTexture_createFromFile(assets_path[i], NULL);
    return (arr);
}

static void use_item(player_t *pl, sfRectangleShape *rec,
sfVector2f m_pos, int i)
{
    sfVector2f pos = sfRectangleShape_getPosition(rec);
    sfVector2f size = sfRectangleShape_getSize(rec);

    if ((m_pos.x >= pos.x && m_pos.x <= (pos.x + size.x))
    && (m_pos.y >= pos.y && m_pos.y <= (pos.y + size .y))
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        if (pl->inventory[i] == ID_POTION_HEAL && pl->pv < pl->max_pv) {
            pl->pv += 5;
            pl->inventory[i] = -1;
        }
    }
}

static void destroy_inv(sfSprite *spr, sfRectangleShape **rec, sfTexture **tex)
{
    for (int i = 0; i < 10; i++)
        sfRectangleShape_destroy(rec[i]);
    for (int j = 0; j < 4; j++)
        sfTexture_destroy(tex[j]);
    sfSprite_destroy(spr);
    free(rec);
    free(tex);
}

int inventory(game_t *game)
{
    sfSprite *spr = sfSprite_create();
    sfTexture **tex_arr = NULL;
    sfRectangleShape **arr = create_inv(&tex_arr);

    sfSleep(sfMilliseconds(100));
    while (!sfKeyboard_isKeyPressed(sfKeyI) &&
    sfRenderWindow_isOpen(game->window.window)) {
        if (sfTime_asMilliseconds(\
sfClock_getElapsedTime(game->clock_particle)) > 25) {
            display_inventory(game, spr, tex_arr, arr);
            sfClock_restart(game->clock_particle);
        }
        for (int j = 0; j < 10; j++)
            use_item(game->player, arr[j], \
get_mouse_pos(game->window.window), j);
    }
    destroy_inv(spr, arr, tex_arr);
    sfSleep(sfMilliseconds(60));
    for (int i = 0; i != 3; i++)
        sfSprite_setPosition(game->hud.sprites[i + 3], pos_back[i]);
    return (0);
}