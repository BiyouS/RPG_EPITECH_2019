/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** destroy
*/

#include "rpg.h"

void destroy(sfSprite *ciel, sfTexture *texture)
{
    sfSprite_destroy(ciel);
    sfTexture_destroy(texture);
}

static void destroy_sprite(game_t *game, coll_t *coll)
{
    for (int i = 0; game->sprite[i] != NULL; i++) {
        sfSprite_destroy(game->sprite[i]->sprite);
        sfTexture_destroy(game->sprite[i]->texture);
        free(game->sprite[i]);
    }
    for (int i = 0; coll->sprite[i] != NULL; i++) {
        sfSprite_destroy(coll->sprite[i]->sprite);
        sfTexture_destroy(coll->sprite[i]->texture);
        free(coll->sprite[i]);
    }
    free(game->sprite);
    free(coll->sprite);
}

void free_player(player_t *player)
{
    if (player->name != NULL)
        free(player->name);
    if (player->sprite != NULL) {
        sfSprite_destroy(player->sprite);
    }
    free(player);
}

static void destroy_scene(scene_t **scene)
{
    for (int i = 0; i < 9; i++) {
        if (scene[i]->bg.spr != NULL) {
            sfSprite_destroy(scene[i]->bg.spr);
            sfTexture_destroy(scene[i]->bg.tex);
        }
        if (i < 6) {
            sfMusic_stop(scene[i]->music);
            sfMusic_destroy(scene[i]->music);
        }
        if (scene[i]->but != NULL)
            destroy_button_arr(scene[i]->but);
        free(scene[i]);
    }
    free(scene);
}

void after_game(game_t *game, player_t *player, coll_t *coll)
{
    free_rain(game->dropplet, game->framebuffer);
    destroy_sprite(game, coll);
    free_player(player);
    destroy_scene(game->scene);
    sfText_destroy(game->text.text);
    sfFont_destroy(game->text.font);
    sfClock_destroy(game->clock);
    sfClock_destroy(game->clock_perso);
}