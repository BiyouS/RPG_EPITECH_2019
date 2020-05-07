/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** create the struct game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "structs.h"
#include "func.h"
#include "my.h"

static char **get_nb_and_file(char *filepath, int *nb)
{
    char **file = load_file_in_mem(filepath);
    int length = 0;

    if (file == NULL)
        return (NULL);
    while (file[length] != NULL)
        length++;
    if (length < 3) {
        free_char_arr(file);
        return (NULL);
    }
    (*nb) = my_getnbr(file[0]);
    if ((*nb) <= 0) {
        free_char_arr(file);
        return (NULL);
    }
    return (file);
}

int get_but_img(but_t *but, char **file, int idx)
{
    sfTexture *tex = sfTexture_createFromFile(file[idx + 1], NULL);
    sfSprite *spr = NULL;

    if (tex == NULL)
        return (-1);
    spr = sfSprite_create();
    if (spr == NULL) {
        sfTexture_destroy(tex);
        return (-1);
    }
    sfSprite_setTexture(spr, tex, sfTrue);
    but->sprite = spr;
    but->tex_norm = tex;
    tex = sfTexture_createFromFile(file[idx + 2], NULL);
    if (tex == NULL) {
        sfTexture_destroy(but->tex_norm);
        sfSprite_destroy(but->sprite);
        return (-1);
    }
    but->tex_hoover = tex;
    return (0);
}

static but_t *fill_but_arr(char **file, int idx)
{
    but_t *but = NULL;
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};

    if (file[idx] == NULL || file[idx + 1] == NULL || file[idx + 2] == NULL)
        return (NULL);
    pos.x = (float)my_get_next_nb(file[idx]);
    pos.y = (float)my_get_next_nb(file[idx]);
    size.x = (float)my_get_next_nb(file[idx]);
    size.y = (float)my_get_next_nb(file[idx]);
    but = malloc(sizeof(but_t));
    if (size.x < 0 || size.y < 0 || pos.x < 0 || pos.y < 0 || !but)
        return (NULL);
    init_button(but, pos, size);
    if (get_but_img(but, file, idx) == -1) {
        sfRectangleShape_destroy(but->rec);
        return (NULL);
    }
    sfSprite_setPosition(but->sprite, pos);
    return (but);
}

but_t **get_but_from_file(char *filepath)
{
    but_t **but = NULL;
    int nb = 0;
    char **file = get_nb_and_file(filepath, &nb);

    if (file == NULL)
        return (NULL);
    but = malloc(sizeof(but_t *) * (nb + 1));
    if (!but)
        return (NULL);
    for (int i = 0; i < nb; i++) {
        but[i] = fill_but_arr(file, (i * 3) + 1);
        if (but[i] == NULL) {
            free_char_arr(file);
            return (NULL);
        }
        but[i + 1] = NULL;
    }
    free_char_arr(file);
    return (but);
}