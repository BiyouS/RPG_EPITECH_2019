/*
** EPITECH PROJECT, 2020
** func prototype
** File description:
** prototype func
*/

#ifndef func
#define func

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"

void help(void);
bool game_starter(void);
void loop_window(game_t *game, coll_t *c);
int close_window(game_t *game);
int are_close(sfVector2f point1, sfVector2f point2, float rad);
char *strcat_dup(char *str1, char *str2);
void check_npc(game_t *game, player_t *player, coll_t *coll);
void check_way(game_t *game);
int inventory(game_t *game);
void display_inventory(game_t *game, sfSprite *spr, sfTexture **tex_arr,
sfRectangleShape **inv);
sfVector2f get_mouse_pos(sfRenderWindow *window);
void quest(int *quest, game_t *game, window_t window);

//draw
int draw_button(game_t* game, but_t **button);
void draw_title(game_t *game);
void draw_menu_map(game_t *game);
void draw_sprite_map(coll_t *sprite_coll);
void draw_menu(game_t *game, but_t **button_menu);
void anime_perso(player_t *player, game_t *game);
void display_card(card_t **deck, int *tab, window_t window);
int display(game_t *game, coll_t *coll, player_t *player);
void draw_map(game_t *game);
void draw_perso(game_t *game);
void display_text(game_t *game, int i);
void draw_option(game_t *game);
void draw_ending(game_t *game);
void display_text_hud(game_t *game, player_t *player);
void draw_name_of_game(game_t *game);
void draw_credits(game_t *game);
void display_cursor(sprite_t *spr, window_t wind);
void draw_generique(game_t *game);
void display_map(game_t *game, coll_t *coll, player_t *player);
int display_option(game_t *game);

//init
int create_array_of_sprite(coll_t *sprite_arr);
player_t *init_perso(void);
int init_game(game_t *game);
but_t **get_but_from_file(char *filepath);
void init_button(but_t *but, sfVector2f pos, sfVector2f size);
int init_genre(player_t *player, int genre);
card_t *parsing_deck(const char *filepaht);
int create_sprite_array(game_t *game);
int init_music_scene(const char **tab_music, scene_t **scene);
void create_my_window(char *name, game_t *game);
int init_hitbox_donjon(game_t *game);
int choose_player_sex(game_t *game, player_t *player, int check);
int choose_player_name(game_t *game, player_t *player, int check);
int choose_player_class(game_t *game, player_t *player, int check);
int init_hud(game_t *game);
void init_scene_var(scene_t *sce, int nb_but);
int load_but_to_sce(scene_t *sce, char *but_path);
int verif_scene(game_t *game);

bool check_collision(coll_t *coll, player_t *player, game_t *game);
int handle_event(game_t *game, player_t *pl, coll_t *coll);
int handle_button(game_t *game, int i, sfVector2f mouse);

//animation
void move_camera(game_t *game, coll_t *coll, player_t *player);
int before_menu(game_t *game);
int credits_anim(game_t *game);
float d(int pass, game_t *game);
void move_after_map(game_t *game, coll_t *coll);
void rain(sfRenderWindow *window_str, game_t *game);
void heal(sfRenderWindow *window_str, game_t *game, sfIntRect extract);
void put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);
void display_framebuffer(framebuffer_t *framebuffer, sfRenderWindow *window);
int generique_anim(game_t *game);
int ending_anim(game_t *game);
dropplet_t **init_rain(void);
dropplet_t **init_heal(void);
void moving(dropplet_t **rain, int i);
void create_dropplet(framebuffer_t *framebuffer, dropplet_t **rain, int i);
framebuffer_t *create_framebuffer(int height, int width);
void moving_heal(dropplet_t **heal, int i);
void create_dropplet_heal(framebuffer_t *fbuffer, \
dropplet_t **heal, int i, sfIntRect extract);
void anime_sprite(sfSprite *sprite, int max_value, int offset, game_t *game);

//Destroy function
void destroy_button_arr(but_t **but);
void destroy(sfSprite *ciel, sfTexture *texture);
void after_game(game_t *game, player_t *player, coll_t *coll);
void free_player(player_t *player);
void free_rain(dropplet_t **rain, framebuffer_t *framebuffer);

//button function
int button_is_clicked(but_t *but, sfVector2f click_pos);
int get_but_img(but_t *but, char **file, int idx);

//menu
int go_to_new_game(game_t *game);
int go_to_credits(game_t *game);
int quit_game(game_t *game);
int start_credit_anim(game_t *game);
int go_to_option(game_t *game);

//pause
int go_to_menu(game_t *game);
int continue_game(game_t *game);

//game
int go_to_help(game_t *game);

//opt
int up_vol(game_t *game);
int diminue_vol(game_t *game);

//npc
void npc_1(game_t *game, int i);
void npc_2(game_t *game, int i);
void npc_3(game_t *game, int i);
void npc_4(game_t *game, int i);
void npc_win(game_t *game, int i);
void create_text_npc(char *name, text_t *text, sfVector2f pos);

//combat
int fight(game_t *game);
int ia_fight(game_t *game);
void player_turn(game_t *game, int *card, int *turn);
int start_turn(game_t *game, int *card, int save_mana, int turn);
int first_donjon(game_t *game);
int second_donjon(game_t *game);
int third_donjon(game_t *game);

//inventory
int get_nb_item(int *inventory, int id_item);
void add_item(int *inventory, int id_item, int pos);

#endif /* !func */
