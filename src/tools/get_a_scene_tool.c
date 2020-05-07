/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** function use for get_a_scene
*/

#include "rpg.h"

const char *tab_music[8] = {
    "Assets/music/musique_menu.ogg",
    "Assets/music/musique_village.ogg",
    "Assets/music/musique_combat1.ogg",
    "Assets/music/musique_donjon1.ogg",
    "Assets/music/musique_donjon2.ogg",
    "Assets/music/musique_donjon3.ogg",
    "Assets/music/musique_boss.ogg",
    NULL,
};

void init_scene_var(scene_t *sce, int nb_but)
{
    sce->but = NULL;
    sce->bg.spr = NULL;
    sce->func_arr = NULL;
    sce->nb_func = nb_but;
}

int load_but_to_sce(scene_t *sce, char *but_path)
{
    sce->but = get_but_from_file(but_path);
    if (sce->but == NULL)
        return (-1);
    return (0);
}

int verif_scene(game_t *game)
{
    for (int i = 0; i < 10; i++) {
        if (game->scene[i] == NULL)
            return (-1);
    }
    if (init_music_scene(tab_music, game->scene) == -1)
        return (-1);
    return (0);
}