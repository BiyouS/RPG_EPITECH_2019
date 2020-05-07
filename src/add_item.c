/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** add an item to inventory
*/

#include "rpg.h"

void add_item(int *inventory, int id_item, int pos)
{
    if (pos >= 0 && inventory[pos] <= 0) {
        inventory[pos] = id_item;
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (inventory[i] <= 0) {
            inventory[i] = id_item;
            return;
        }
    }
}