/*
** EPITECH PROJECT, 2020
** fsdf
** File description:
** dfsd
*/

#include "rpg.h"

void npc_win(game_t *game, int i)
{
    char *sentence[6] = {"Bravo ", game->player->name,
        "!\n Tu as reussi l'initiation!\n",
        "Tu peux a present rentrer chez toi.\n",
        "Tu peux y aller par le chemin a la gauche du village.",
        NULL};
    char *text = my_strdup("Doyen: ");

    for (int i = 0; sentence[i] != NULL; i++)
        text = strcat_dup(text, sentence[i]);
    create_text_npc(text, &game->text, (sfVector2f){380, 520});
    free(text);
    game->text.yes = i;
    game->quest[4] = 1;
}

void npc_4(game_t *game, int i)
{
    char *sentence[3] = {"Apres 80 ans jeune enfant, je n'ai toujours\n",
        "pas reussit l'initiation..", NULL};
    char *text = my_strdup("Sage du village: ");

    for (int i = 0; i != 2; i++)
        text = strcat_dup(text, sentence[i]);
    create_text_npc(text, &game->text, (sfVector2f){380, 550});
    free(text);
    game->text.yes = i;
}

void npc_3(game_t *game, int i)
{
    char *sentence[5] = {"Tu es un sorcier ", game->player->name,
        "! \nAh! Heu! Excusez-moi! Le Livre que je lis est palpitant..\n",
        "J'espere que votre aventure le sera tout autant.", NULL};
    char *text = my_strdup("Agrid: ");

    for (int i = 0; i != 4; i++)
        text = strcat_dup(text, sentence[i]);
    create_text_npc(text, &game->text, (sfVector2f){380, 550});
    free(text);
    game->text.yes = i;
}

void npc_2(game_t *game, int i)
{
    char *sentence[6] = {"Bonjour ", game->player->name, "!\n",
        "Je suis le Refourgeur. J'ai entendu parle\n de votre initiation.",
        " Je vous donne un petit quelque chose...", NULL};
    char *text = my_strdup("Refourgeur: ");

    for (int i = 0; i != 5; i++)
        text = strcat_dup(text, sentence[i]);
    create_text_npc(text, &game->text, (sfVector2f){380, 550});
    free(text);
    game->text.yes = i;
    if (get_nb_item(game->player->inventory, ID_POTION_HEAL) < 7)
        add_item(game->player->inventory, ID_POTION_HEAL, -1);
    sfSleep(sfMilliseconds(120));
}

void npc_1(game_t *game, int i)
{
    char *sentence[5] = {"Bonjour ", game->player->name, "!\n",
        "Trois chemins partent du village, trois artefacts.",
        NULL};
    char *text = my_strdup("Doyen: ");

    if (game->donjon.art_3 == 1) {
        npc_win(game, i);
        return;
    }
    for (int i = 0; i != 4; i++)
        text = strcat_dup(text, sentence[i]);
    create_text_npc(text, &game->text, (sfVector2f){380, 600});
    free(text);
    game->text.yes = i;
    game->quest[0] = 1;
}
