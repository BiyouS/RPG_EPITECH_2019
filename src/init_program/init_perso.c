/*
** EPITECH PROJECT, 2020
** init_perso.c
** File description:
** fill struct of perso
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

const char filepath_carte[22][21] = {
    "./Decks/carte_1.txt",
    "./Decks/carte_2.txt",
    "./Decks/carte_3.txt",
    "./Decks/carte_4.txt",
    "./Decks/carte_5.txt",
    "./Decks/carte_6.txt",
    "./Decks/carte_7.txt",
    "./Decks/carte_8.txt",
    "./Decks/carte_9.txt",
    "./Decks/carte_10.txt",
    "./Decks/carte_11.txt",
    "./Decks/carte_12.txt",
    "./Decks/carte_13.txt",
    "./Decks/carte_14.txt",
    "./Decks/carte_15.txt",
    "./Decks/carte_16.txt",
    "./Decks/carte_17.txt",
    "./Decks/carte_18.txt",
    "./Decks/carte_19.txt",
    "./Decks/carte_20.txt",
    "./Decks/carte_21.txt",
    "./Decks/carte_22.txt",
};

static int *init_inventory(int *inventory)
{
    inventory = malloc(sizeof(int) * (10 + 1));
    if (!inventory)
        return NULL;
    for (int i = 0; i != 11; i++)
        inventory[i] = 0;
    return inventory;
}

static void init_stats(player_t *player)
{
    player->protec = 0;
    player->pv = 10;
    player->max_pv = 10;
    player->mana = 3;
    player->max_mana = 3;
    player->xp = 0;
    player->level = 0;
}

static void set_info_img(player_t *player)
{
    sfSprite_setTexture(player->hitbox, player->texture_h, sfFalse);
    sfSprite_setPosition(player->hitbox, player->pos);
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setTextureRect(player->sprite, player->rect);
}

static int fill_deck(player_t *player)
{
    sfVector2f scale = {0.5, 0.5};

    player->deck = malloc(sizeof(card_t *) * 23);
    if (player->deck == NULL) {
        sfTexture_destroy(player->texture_h);
        return (-1);
    }
    for (int i = 0; i != 22; i++) {
        player->deck[i] = parsing_deck(filepath_carte[i]);
        if (player->deck[i] == NULL) {
            free(player->deck);
            return (-1);
        }
        sfSprite_setScale(player->deck[i]->img.spr, scale);
        player->deck[i + 1] = NULL;
    }
    return (0);
}

player_t *init_perso(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return (NULL);
    player->texture_h = sfTexture_createFromFile("Assets/IMG/hitbox.png", NULL);
    player->sprite = sfSprite_create();
    player->hitbox = sfSprite_create();
    if (player->texture_h == NULL || fill_deck(player) == -1
    || player->sprite == NULL || player->hitbox == NULL) {
        free(player);
        return (NULL);
    }
    player->name = NULL;
    init_stats(player);
    player->pos = (sfVector2f){(WIN_W / 2), (WIN_H / 2)};
    player->rect = (sfIntRect){10, 0, 64, 64};
    set_info_img(player);
    player->inventory = init_inventory(player->inventory);
    return player;
}