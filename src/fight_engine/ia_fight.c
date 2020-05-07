/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** ia_fight.c
*/

#include "rpg.h"

static int classe(char *classe)
{
    const char arr[4][9] = {
        "Mage",
        "Guerrier",
        "Assasin",
        "Druide",
    };

    for (int i = 0; i != 4; i++) {
        if (my_strcmp(arr[i], classe) == 0)
            return (i + 1);
    }
    return (0);
}

static int verif_classe(game_t *game)
{
    int card = 0;
    int classe_neutre = 0;
    int classe_player = 0;

    card = rand()%21;

    while (1) {
        classe_neutre = my_strcmp("Neutre", game->player->deck[card]->class);
        classe_player = classe(game->player->deck[card]->class);
        if (classe_neutre == 0)
            return (card);
        else if (classe_player == (int) game->ennemi->class)
            return (card);
        else
            card = rand()%21;
    }
    return (0);
}

static void setup_shield(game_t *game, int card)
{
    int damage = 0;

    damage = game->player->protec - game->player->deck[card]->pow;
    if (damage >= 0) {
        game->player->protec -= damage;
    } else {
        damage = damage * (-1);
        game->player->pv -= damage;
        game->player->protec = 0;
    }
}

static void attack(game_t *game, int card)
{
    if (game->ennemi->mana >= game->player->deck[card]->mana) {
        if (game->player->deck[card]->type == 1)
            game->ennemi->pv += game->player->deck[card]->pow;
        if (game->player->deck[card]->type == 2)
            game->ennemi->protec += game->player->deck[card]->pow;
        if (game->player->deck[card]->type == 3)
            setup_shield(game, card);
        game->ennemi->mana -= game->player->deck[card]->mana;
    }
}

int ia_fight(game_t *game)
{
    int i = 0;
    int save_mana = game->ennemi->mana;

    i = verif_classe(game);
    game->ennemi->protec = 0;
    game->ennemi->mana = save_mana;
    attack(game, i);
    if (game->ennemi->mana >= 1) {
        i = verif_classe(game);
        attack(game, i);
    }
    return -1;
}