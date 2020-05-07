/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** function link to button of opt_scene
*/

#include "rpg.h"

int diminue_vol(game_t *game)
{
    if (game->volume <= 0 || game->play_music < 0)
        return (0);
    game->volume -= 1;
    for (int i = 0; i < 5; i++)
        sfMusic_setVolume(game->scene[i]->music, game->volume);
    sfSleep(sfMilliseconds(100));
    return (0);
}

int up_vol(game_t *game)
{
    if (game->volume >= 100 || game->play_music < 0)
        return (0);
    game->volume += 1;
    for (int i = 0; i < 5; i++)
        sfMusic_setVolume(game->scene[i]->music, game->volume);
    sfSleep(sfMilliseconds(100));
    return (0);
}