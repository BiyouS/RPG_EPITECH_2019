/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** init one turn of fight
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

static int verif_classe(player_t *pl)
{
    int card = 0;
    int classe_neutre = 0;
    int classe_player = 0;

    card = rand() % 21;

    while (1) {
        classe_neutre = my_strcmp("Neutre", pl->deck[card]->class);
        classe_player = classe(pl->deck[card]->class);
        if (classe_neutre == 0)
            return (card);
        else if (classe_player == pl->class)
            return (card);
        else
            card = rand() % 21;
    }
}

int start_turn(game_t *game, int *card, int save_mana, int turn)
{
    for (int n = 0; turn == -1 && n != 4; n++)
        card[n] = verif_classe(game->player);
    if (turn == -1) {
        game->player->protec = 0;
        game->player->mana = save_mana;
    }
    return (0);
}