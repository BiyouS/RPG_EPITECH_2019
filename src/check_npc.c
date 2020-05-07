/*
** EPITECH PROJECT, 2020
** check_npc.c
** File description:
** chac_npc.c
*/

#include "rpg.h"

static bool npc(int num, game_t *game, sfVector2f perso, sfVector2f vieux)
{
    if (game->text.yes == 1 && are_close(perso, vieux, 100) == 1)
        return false;

    if (are_close(perso, vieux, 100) == 1 && sfKeyboard_isKeyPressed(sfKeyE)) {
        display_text(game, num);
        return true;
    }
    return false;
}

static void init_pos(sfVector2f *ps, sfVector2f *vx, player_t *pl, coll_t *col)
{
    ps[0] = sfSprite_getPosition(pl->hitbox);
    vx[0] = sfSprite_getPosition(col->sprite[17]->sprite);
    ps[1] = sfSprite_getPosition(pl->hitbox);
    vx[1] = sfSprite_getPosition(col->sprite[18]->sprite);
    ps[2] = sfSprite_getPosition(pl->hitbox);
    vx[2] = sfSprite_getPosition(col->sprite[19]->sprite);
    ps[3] = sfSprite_getPosition(pl->hitbox);
    vx[3] = sfSprite_getPosition(col->sprite[20]->sprite);
}

static void if_chech_npc(game_t *game, sfVector2f *perso, sfVector2f *vieux)
{
    if (game->text.yes == 17 && are_close(perso[0], vieux[0], 120) == 0) {
        game->text.yes = 0;
        return;
    }else if (game->text.yes == 18 && are_close(perso[1], vieux[1], 120) == 0) {
        game->text.yes = 0;
        return;
    }
    if (game->text.yes == 19 && are_close(perso[2], vieux[2], 120) == 0) {
        game->text.yes = 0;
        return;
    }else if (game->text.yes == 20 && are_close(perso[3], vieux[3], 120) == 0) {
        game->text.yes = 0;
        return;
    }
}

void check_npc(game_t *game, player_t *player, coll_t *coll)
{
    sfVector2f perso[4] = {{0, 0}};
    sfVector2f vieux[4] = {{0, 0}};

    init_pos(perso, vieux, player, coll);
    if_chech_npc(game, perso, vieux);
    if (npc(17, game, perso[0], vieux[0]) == true)
        return;
    if (npc(18, game, perso[1], vieux[1]) == true)
        return;
    if (npc(19, game, perso[2], vieux[2]) == true)
        return;
    if (npc(20, game, perso[3], vieux[3]) == true)
        return;
}