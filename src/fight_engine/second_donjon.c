/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** second_donjon.c
*/

#include "rpg.h"

static void init_ennemi(game_t *game)
{
    game->ennemi->texture = sfTexture_createFromFile("Assets/IMG/mage_2.png",
    NULL);
    sfSprite_setTexture(game->ennemi->sprite, game->ennemi->texture, sfFalse);
    game->ennemi->pv = 20;
    game->ennemi->mana = 5;
    game->ennemi->class = 1;
}

static void init_bos(game_t *game)
{
    game->player->rect.top = 192;
    game->player->rect.left = 0;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    game->ennemi->texture = sfTexture_createFromFile("Assets/IMG/warrior1.png",
    NULL);
    sfSprite_setTexture(game->ennemi->sprite, game->ennemi->texture, sfFalse);
    game->ennemi->pv = 35;
    game->ennemi->mana = 5;
    game->ennemi->class = 2;
}

static void up_level(game_t *game)
{
    game->player->mana = game->player->max_mana;
    game->donjon.art_2 = 1;
    game->player->max_mana = 7;
    game->player->max_pv = 20;
    if (game->player->pv > game->player->max_pv)
        game->player->pv = game->player->max_pv;
}

int second_donjon(game_t *game)
{
    init_ennemi(game);
    if (fight(game) == -1)
        return (-1);
    game->player->mana = game->player->max_mana;
    init_ennemi(game);
    if (fight(game) == -1)
        return (-1);
    game->player->mana = game->player->max_mana;
    init_bos(game);
    if (fight(game) == -1)
        return (-1);
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    add_item(game->player->inventory, ID_ARTEFECT_2, -1);
    up_level(game);
    game->quest[2] = 1;
    return (-2);
}