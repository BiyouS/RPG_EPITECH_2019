/*
** EPITECH PROJECT, 2020
** move_map.c
** File description:
** bouger la map
*/

#include "rpg.h"

static bool you_can_do_it(game_t *game, player_t *player, coll_t *coll)
{
    if (check_collision(coll, player, game) == false)
        return false;
    return true;
}

static int move_map_2(game_t *g, coll_t *c, player_t *pl)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) && you_can_do_it(g, pl, c)) {
        sfSprite_move(g->sprite[0]->sprite, (sfVector2f){-2 * d(0, g), 0});
        for (int i = 0; c->sprite[i] != NULL; i++)
            sfSprite_move(c->sprite[i]->sprite, (sfVector2f){-2 * d(0, g), 0});
        for (int i = 0; i != 4; i++)
            sfRectangleShape_move(g->donjon.rec[i],
            (sfVector2f){-2 * d(0, g), 0});
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && you_can_do_it(g, pl, c)) {
        sfSprite_move(g->sprite[0]->sprite, (sfVector2f){2 * d(0, g), 0});
        for (int i = 0; c->sprite[i] != NULL; i++)
            sfSprite_move(c->sprite[i]->sprite,
            (sfVector2f){2 * d(0, g), 0});
        for (int i = 0; i != 4; i++)
            sfRectangleShape_move(g->donjon.rec[i],
            (sfVector2f){2 * d(0, g), 0});
        return 1;
    }
    return 0;
}

static int move_map(game_t *g, coll_t *c, player_t *pl)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && you_can_do_it(g, pl, c)) {
        sfSprite_move(g->sprite[0]->sprite, (sfVector2f){0, 2 * d(0, g)});
        for (int i = 0; c->sprite[i] != NULL; i++)
            sfSprite_move(c->sprite[i]->sprite, (sfVector2f){0, 2 * d(0, g)});
        for (int i = 0; i != 4; i++)
            sfRectangleShape_move(g->donjon.rec[i],
            (sfVector2f){0, 2 * d(0, g)});
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && you_can_do_it(g, pl, c)) {
        sfSprite_move(g->sprite[0]->sprite, (sfVector2f){0, -2 * d(0, g)});
        for (int i = 0; c->sprite[i] != NULL; i++)
            sfSprite_move(c->sprite[i]->sprite,
            (sfVector2f){0, -2 * d(0, g)});
        for (int i = 0; i != 4; i++)
            sfRectangleShape_move(g->donjon.rec[i],
            (sfVector2f){0, -2 * d(0, g)});
        return 1;
    }
    return move_map_2(g, c, pl);
}

static void display_map2(game_t *game, coll_t *coll, player_t *player)
{
    sfRenderWindow_drawSprite(game->window.window,
    game->sprite[0]->sprite, NULL);
    for (int i = 0; coll->sprite[i] != NULL; i++) {
        sfRenderWindow_drawSprite(game->window.window,
        coll->sprite[i]->sprite, NULL);
    }
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->donjon.rec[i], NULL);
    sfRenderWindow_drawSprite(game->window.window, player->hitbox, NULL);
    sfRenderWindow_drawSprite(game->window.window, player->sprite, NULL);
    if (game->text.yes != 0)
        sfRenderWindow_drawText(game->window.window, game->text.text, NULL);
}

void move_camera(game_t *game, coll_t *coll, player_t *player)
{
    check_npc(game, player, coll);
    if (move_map(game, coll, player) == 0)
        move_after_map(game, coll);
    anime_perso(player, game);
    display_map2(game, coll, player);
}