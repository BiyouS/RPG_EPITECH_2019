/*
** EPITECH PROJECT, 2019
** structs.h
** File description:
** structs.h
*/

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <sys/types.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct {
    size_t art_1;
    size_t art_2;
    size_t art_3;
    sfRectangleShape **rec;
} donjon_t;

typedef struct framebuffer_s {
    int x;
    int y;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct dropplet_s {
    sfIntRect particle;
    int top;
    int bottom;
    int x;
    int started;
    int speed;
} dropplet_t;

typedef struct img_t {
    sfSprite *spr;
    sfTexture *tex;
} img_t;

typedef struct button_t {
    sfRectangleShape *rec;
    sfSprite *sprite;
    sfTexture *tex_norm;
    sfTexture *tex_hoover;
} but_t;

typedef struct card_t {
    char *name;
    size_t pow;
    char *class;
    img_t img;
    size_t mana;
    size_t type;
} card_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
} sprite_coll_t;

typedef struct {
    sprite_coll_t **sprite;
} coll_t;

typedef struct {
    char *name;
    size_t protec;
    size_t pv;
    size_t max_pv;
    size_t mana;
    size_t max_mana;
    size_t xp;
    size_t level;
    int class;
    card_t **deck;
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *hitbox;
    sfTexture *texture_h;
    sfIntRect rect;
    sfVector2f pos;
    int *inventory;
} player_t;

typedef struct {
    sfMusic *musique;
} musique_t;

typedef struct {
    img_t bg;
    but_t **but;
    size_t nb_func;
    int (**func_arr)();
    sfMusic *music;
} scene_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f position;
    sfVector2f scale;
    int yes;
} text_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
} sprite_t;

typedef struct {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfMouseButtonEvent mouse_evt;
} window_t;

typedef struct {
    size_t protec;
    size_t pv;
    size_t mana;
    size_t class;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} ennemi_t;

typedef struct hud_s {
    sfTexture **textures;
    sfSprite **sprites;
    sfVector2f *positions;
} hud_t;

typedef struct {
    sprite_t **sprite;
    window_t window;
    text_t text;
    musique_t musique;
    sfIntRect rect;
    sfClock *clock;
    sfClock *clock_perso;
    scene_t **scene;
    int idx_sce;
    framebuffer_t *framebuffer;
    dropplet_t **dropplet;
    dropplet_t **dropplet_heal;
    coll_t sprite_coll;
    player_t *player;
    ennemi_t *ennemi;
    donjon_t donjon;
    hud_t hud;
    int quest[5];
    int play_music;
    but_t checkbox;
    float volume;
    sfClock *clock_particle;
} game_t;


#endif /* _STRUCTS_H_ */
