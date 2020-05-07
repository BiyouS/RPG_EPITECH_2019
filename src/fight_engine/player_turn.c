/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** player turn in fight algo
*/

#include "rpg.h"

static void setup_shield(game_t *game, int card)
{
    int damage = 0;

    damage = game->ennemi->protec - game->player->deck[card]->pow;
    if (damage >= 0) {
        game->ennemi->protec -= damage;
    } else {
        damage = damage * (-1);
        game->ennemi->pv -= damage;
        game->ennemi->protec = 0;
    }
}

static int player_attack(game_t *game, int card)
{
    if (game->player->mana >= game->player->deck[card]->mana) {
        if (game->player->deck[card]->type == 1)
            game->player->pv += game->player->deck[card]->pow;
        if (game->player->deck[card]->type == 2)
            game->player->protec += game->player->deck[card]->pow;
        if (game->player->deck[card]->type == 3)
            setup_shield(game, card);
        game->player->mana -= game->player->deck[card]->mana;
        return 0;
    }
    return -1;
}

static int is_it_on(sfVector2f pos, sfVector2f size, sfVector2f obj)
{
    if ((obj.x >= pos.x && obj.x <= (pos.x + size.x))
    && (obj.y >= pos.y && obj.y <= (pos.y + size .y))) {
        return (1);
    } else
        return (0);
}

static int choose_card(int *idx_card, game_t *game, card_t **deck, int *arr)
{
    sfVector2f pos = {300, 450};
    sfVector2f m_pos = get_mouse_pos(game->window.window);

    if (is_it_on((sfVector2f){1000, 640}, (sfVector2f){100, 50}, m_pos) == 1
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        return 2;
    }
    for (int i = 0; i < 4; i++) {
        if (arr[i] != -1 && is_it_on(pos, (sfVector2f){150, 250}, m_pos) == 1
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            sfSprite_setScale(deck[arr[i]]->img.spr, (sfVector2f){0.45, 0.45});
            (*idx_card) = i;
        } else if (arr[i] != -1)
            sfSprite_setScale(deck[arr[i]]->img.spr, (sfVector2f){0.5, 0.5});
        pos.x += 175;
    }
    return (0);
}

void player_turn(game_t *game, int *card, int *turn)
{
    int idx_card = -1;

    (*turn) = choose_card(&idx_card, game, game->player->deck, card);
    if (idx_card != -1) {
        if (player_attack(game, card[idx_card]) == 0) {
            card[idx_card] = -1;
            idx_card = -1;
        }
    }
}