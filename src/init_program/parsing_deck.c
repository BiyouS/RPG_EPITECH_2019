/*
** EPITECH PROJECT, 2020
** parsing deck
** File description:
** Parseur de fichier carte.txt
*/

#include "rpg.h"

const char possible_class[5][10] = {
    "Guerrier",
    "Druide",
    "Assassin",
    "Mage",
    "Neutre",
};

static int get_arr_len(char **arr)
{
    int count = 0;

    while (arr[count] != NULL)
        count++;
    return (count);
}

static int get_img_t(card_t *buf, char *filepath)
{
    sfTexture *tex = sfTexture_createFromFile(filepath, NULL);
    sfSprite *spr = NULL;

    if (tex == NULL)
        return (-1);
    spr = sfSprite_create();
    if (spr == NULL) {
        sfTexture_destroy(tex);
        return (-1);
    }
    sfSprite_setTexture(spr, tex, sfTrue);
    buf->img.spr = spr;
    buf->img.tex = tex;
    return (0);
}

static int check_class_and_nb(char **file)
{
    char buf[200] = {0};
    int mana = 0;
    int type = 0;
    int pow = 0;

    for (int i = 0; i < 6; i++) {
        if (i == 5)
            return (-1);
        if (my_strcmp(file[2], possible_class[i]) == 0)
            break;
    }
    my_strcpy(buf, file[1]);
    pow = my_get_next_nb(buf);
    mana = my_get_next_nb(buf);
    type = my_getnbr(file[4]);
    if (pow < 0 || mana < 0 || (type < 1 || type > 3))
        return (-1);
    return (0);
}

static int parse_file(char **file, card_t *buf)
{
    if (check_class_and_nb(file) == -1)
        return (-1);
    buf->pow = my_get_next_nb(file[1]);
    buf->mana = my_get_next_nb(file[1]);
    buf->type = my_getnbr(file[4]);
    buf->name = my_strdup(file[0]);
    if (buf->name == NULL)
        return (-1);
    buf->class = my_strdup(file[2]);
    if (buf->class == NULL) {
        free(buf->name);
        return (-1);
    }
    if (get_img_t(buf, file[3]) == -1) {
        free(buf->name);
        free(buf->class);
        return (-1);
    }
    return (0);
}

card_t *parsing_deck(const char *filepaht)
{
    char **file = load_file_in_mem(filepaht);
    card_t buf = {NULL, 0, NULL, {NULL, NULL}, 0, 0};
    card_t *card = NULL;

    if (!file)
        return (NULL);
    if (get_arr_len(file) != 5) {
        free_char_arr(file);
        return (NULL);
    }
    if (parse_file(file, &buf) == -1) {
        free_char_arr(file);
        return (NULL);
    }
    card = malloc(sizeof(card_t));
    if (card)
        (*card) = buf;
    free_char_arr(file);
    return card;
}