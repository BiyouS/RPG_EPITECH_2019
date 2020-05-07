/*
** EPITECH PROJECT, 2020
** fsdf
** File description:
** sdfs
*/

#include "rpg.h"

int init_music_scene(const char **tab_music, scene_t **scene)
{
    for (int i = 0; i != 6; i++) {
        scene[i]->music = sfMusic_createFromFile(tab_music[i]);
        if (scene[i]->music == NULL)
            return (-1);
        sfMusic_setVolume(scene[i]->music, 8.0f);
    }
    return (0);
}