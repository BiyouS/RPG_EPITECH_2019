/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** all concern display (sprite, text, ...)
*/

#include "rpg.h"

static void play_music(scene_t *scene, game_t *game)
{
    static int scene_idx = -1;

    if (scene_idx != game->idx_sce && game->idx_sce < 6) {
        if (scene_idx != -1)
            sfMusic_stop(game->scene[scene_idx]->music);
        sfMusic_setLoop(scene->music, true);
        sfMusic_play(scene->music);
        scene_idx = game->idx_sce;
    }
}

static int draw_scene(scene_t *scene, game_t *game, player_t *pl)
{
    int check = 0;

    if (game->idx_sce == 1 && pl->name == NULL) {
        check = generique_anim(game);
        check = choose_player_name(game, pl, check);
        check = choose_player_sex(game, pl, check);
        check = choose_player_class(game, pl, check);
    }
    if (check != 0)
        return 84;
    play_music(scene, game);
    if (scene->bg.spr != NULL)
        sfRenderWindow_drawSprite(game->window.window, scene->bg.spr, NULL);
    if (scene->but == NULL)
        return 84;
    for (int i = 0; scene->but[i] != NULL; i++) {
        sfRenderWindow_drawSprite(game->window.window,
        scene->but[i]->sprite, NULL);
    }
    return 0;
}

int display(game_t *game, coll_t *coll, player_t *player)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    if (game->idx_sce == 1) {
        display_map(game, coll, player);
        check_way(game);
        rain(game->window.window, game);
    }
    if (draw_scene(game->scene[game->idx_sce], game, player) == 84)
        return 84;
    if (game->idx_sce == 6)
        quest(game->quest, game, game->window);
    if (game->idx_sce == 9)
        display_option(game);
    display_cursor(game->sprite[5], game->window);
    sfRenderWindow_display(game->window.window);
    return (0);
}