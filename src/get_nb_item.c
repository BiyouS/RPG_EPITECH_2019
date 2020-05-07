/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** get nb of an item in inventory
*/

#include "rpg.h"

int get_nb_item(int *inventory, int id_item)
{
    int count = 0;

    for (int i = 0; i < 10; i++) {
        if (inventory[i] == id_item)
            count++;
    }
    return (count);
}