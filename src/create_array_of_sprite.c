/*
** EPITECH PROJECT, 2020
** create array of sprite
** File description:
** sprite array
*/

#include "rpg.h"


static int create_sprite(char const *name, int i, coll_t *sprite)
{
    sprite->sprite[i] = malloc(sizeof(sprite_coll_t));

    if (sprite->sprite[i] == NULL || name == NULL)
        return 84;
    sprite->sprite[i]->sprite = sfSprite_create();
    if (sprite->sprite[i]->sprite == NULL)
        return 84;
    sprite->sprite[i]->texture = sfTexture_createFromFile(name, NULL);
    if (sprite->sprite[i]->texture == NULL)
        return 84;
    sfSprite_setTexture(sprite->sprite[i]->sprite,
    sprite->sprite[i]->texture, sfFalse);
    return 0;
}

int create_array_of_sprite(coll_t *sprite_arr)
{
    char *filepath[22] = {"Assets/IMG/map/house.png",
        "Assets/IMG/map/house1.png", "Assets/IMG/map/tree_fence3.png",
        "Assets/IMG/map/tree_left1.png", "Assets/IMG/map/tree_left2.png",
        "Assets/IMG/map/tree_left5.png", "Assets/IMG/map/tree_fence2.png",
        "Assets/IMG/map/tree_fence1.png", "Assets/IMG/map/tree_left6.png",
        "Assets/IMG/map/tree_left3.png", "Assets/IMG/map/tree_left4.png",
        "Assets/IMG/map/tree_fence5.png", "Assets/IMG/map/tree_fence6.png",
        "Assets/IMG/map/tree_fence7.png", "Assets/IMG/map/tree_fence8.png",
        "Assets/IMG/map/castle.png", "Assets/IMG/map/building.png",
        "Assets/IMG/NPC/Le_vieux.png", "Assets/IMG/NPC/Le_paysan.png",
        "Assets/IMG/NPC/Le_paysan.png", "Assets/IMG/NPC/Le_paysan.png", NULL};
    int i = 0;

    sprite_arr->sprite = malloc(sizeof(sprite_coll_t *) * 22);
    if (sprite_arr->sprite == NULL)
        return 84;
    for (; filepath[i] != NULL; i++)
        if (create_sprite(filepath[i], i, sprite_arr) == 84)
            return 84;
    sprite_arr->sprite[i] = NULL;
    return 0;
}
