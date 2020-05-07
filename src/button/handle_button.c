/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** handle_button effect and call functionassociate to button
*/

#include "rpg.h"

static void hoover(but_t *but, int opt)
{
    if (opt == 1)
        sfSprite_setTexture(but->sprite, but->tex_hoover, sfTrue);
    else
        sfSprite_setTexture(but->sprite, but->tex_norm, sfTrue);
}

static void click_fx(but_t *but, int opt)
{
    sfVector2f scale1 = {0.8, 0.8};
    sfVector2f scale2 = {1, 1};
    sfVector2f cur_scale = sfSprite_getScale(but->sprite);

    if (opt == 1)
        sfSprite_setScale(but->sprite, scale1);
    else if (opt == 0 && (cur_scale.x == scale1.x && cur_scale.y == scale1.y))
        sfSprite_setScale(but->sprite, scale2);
}

static void exec_func(game_t *game, int i)
{
    if (i < (int) game->scene[game->idx_sce]->nb_func)
        game->scene[game->idx_sce]->func_arr[i](game);
}

int handle_button(game_t *game, int i, sfVector2f mouse)
{
    if (game->scene[game->idx_sce]->but[i] == NULL)
        return (0);
    if (button_is_clicked(game->scene[game->idx_sce]->but[i], mouse)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            click_fx(game->scene[game->idx_sce]->but[i], 1);
            exec_func(game, i);
            return (1);
        } else
            click_fx(game->scene[game->idx_sce]->but[i], 0);
        hoover(game->scene[game->idx_sce]->but[i], 1);
    } else {
        hoover(game->scene[game->idx_sce]->but[i], 0);
    }
    return (0);
}
