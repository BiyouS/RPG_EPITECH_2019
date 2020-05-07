/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** first_donjon.c
*/

#include "rpg.h"

static void init_bos(game_t *game)
{
    game->ennemi->texture = sfTexture_createFromFile("Assets/IMG/mage_1.png",
    NULL);
    sfSprite_setTexture(game->ennemi->sprite, game->ennemi->texture, sfFalse);
    game->ennemi->pv = 25;
    game->ennemi->mana = 3;
    game->ennemi->class = 1;
}

static void init_ennemi(game_t *game)
{
    game->player->rect.top = 192;
    game->player->rect.left = 0;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    game->ennemi->texture = sfTexture_createFromFile("Assets/IMG/gollem_2.png",
    NULL);
    sfSprite_setTexture(game->ennemi->sprite, game->ennemi->texture, sfFalse);
    game->ennemi->pv = 15;
    game->ennemi->mana = 3;
    game->ennemi->class = 4;
}

static void first_init_ennemi(game_t *game)
{
    game->ennemi = malloc(sizeof(ennemi_t));
    game->ennemi->sprite = sfSprite_create();
    game->ennemi->texture = sfTexture_createFromFile("Assets/IMG/gollem_2.png",
    NULL);
    game->player->rect.top = 192;
    game->player->rect.left = 0;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    sfSprite_setTexture(game->ennemi->sprite, game->ennemi->texture, sfFalse);
    game->ennemi->pv = 15;
    game->ennemi->mana = 3;
    game->ennemi->class = 4;
    game->ennemi->protec = 0;
}

int first_donjon(game_t *game)
{
    first_init_ennemi(game);
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
    game->player->mana = game->player->max_mana;
    game->donjon.art_1 = 1;
    game->player->max_mana = 5;
    game->player->max_pv = 15;
    if (game->player->pv > game->player->max_pv)
        game->player->pv = game->player->max_pv;
    add_item(game->player->inventory, ID_ARTEFECT_1, -1);
    game->quest[1] = 1;
    return (-2);
}