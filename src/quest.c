/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** quest_scene
*/

#include "rpg.h"

/*
    1: aller parler au doyen
    2: recuper l'artefatc de feu
    3: "" terre
    4: "" eau
    5: retourne parler au doyen
*/

#include "rpg.h"

static void display_quest(int quest, game_t *game, window_t window)
{
    if (quest == -1)
        sfText_setColor(game->text.text, sfWhite);
    else
        sfText_setColor(game->text.text, sfGreen);
    sfRenderWindow_drawText(window.window, game->text.text, NULL);
}

void quest(int *quest, game_t *game, window_t window)
{
    const char *goal[] = {
        "Aller parler au doyen, il est bleu.",
        "Recuperer l'artefact de feu au Nord.",
        "Recuper l'artefact de la terre a l'Est.",
        "Recuper l'artefact de l'eau au Sud.",
        "Retourner parler au doyen.",
    };
    sfVector2f pos[] = {
        (sfVector2f){350, 150},
        (sfVector2f){350, 250},
        (sfVector2f){350, 350},
        (sfVector2f){350, 450},
        (sfVector2f){350, 550},
    };

    for (int i = 0; i < 5; i++) {
        sfText_setPosition(game->text.text, pos[i]);
        sfText_setString(game->text.text, goal[i]);
        display_quest(quest[i], game, window);
    }
    sfText_setColor(game->text.text, sfBlack);
}