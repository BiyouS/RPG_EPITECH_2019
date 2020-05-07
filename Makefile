##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

DINIT	=	./src/init_program

DDRAW	=	./src/draw_elt

DTOOLS	=	./src/tools

DFIGHT	=	./src/fight_engine

DBUTTON	=	./src/button

SRCS	=	$(DDRAW)/draw_map.c					\
			$(DDRAW)/draw_menu.c				\
			$(DDRAW)/draw_menu_map.c			\
			$(DDRAW)/draw_title.c				\
			$(DDRAW)/draw_option.c				\
			$(DDRAW)/draw_credits.c				\
			$(DDRAW)/draw_button.c				\
			$(DDRAW)/draw_sprite_map.c			\
			$(DDRAW)/draw_ending.c			\
			$(DDRAW)/draw_name_of_game.c		\
			$(DDRAW)/draw_generique.c		\
			$(DDRAW)/draw_perso.c				\
			$(DINIT)/parsing_deck.c				\
			$(DINIT)/get_but_from_file.c		\
			$(DINIT)/init_button.c				\
			$(DINIT)/init_hud.c					\
			$(DINIT)/init_hitbox_donjon.c		\
			$(DINIT)/init_perso.c				\
			$(DINIT)/init_music_scene.c				\
			$(DINIT)/init_genre.c				\
			$(DINIT)/create_window.c			\
			$(DINIT)/create_framebuffer.c			\
			$(DINIT)/init_game.c				\
			$(DINIT)/game_starter.c				\
			$(DFIGHT)/display_text_hud.c		\
			$(DFIGHT)/fight.c					\
			$(DFIGHT)/ia_fight.c				\
			$(DFIGHT)/first_donjon.c				\
			$(DFIGHT)/second_donjon.c				\
			$(DFIGHT)/third_donjon.c				\
			$(DFIGHT)/player_turn.c				\
			$(DFIGHT)/start_turn.c				\
			$(DTOOLS)/are_close.c				\
			$(DTOOLS)/close_window.c			\
			$(DTOOLS)/strcat_dup.c				\
			$(DTOOLS)/delta_time.c				\
			$(DTOOLS)/get_a_scene_tool.c		\
			$(DTOOLS)/get_mouse_pos.c			\
			$(DBUTTON)/destroy_button.c			\
			$(DBUTTON)/handle_button.c			\
			$(DBUTTON)/menu_button.c			\
			$(DBUTTON)/button_is_clicked.c		\
			$(DBUTTON)/button_game.c			\
			$(DBUTTON)/pause_button.c			\
			$(DBUTTON)/opt_button.c				\
			./src/main.c						\
			./src/display_card.c				\
			./src/npc_info_text.c				\
			./src/after_game.c					\
			./src/display_text.c				\
			./src/check_npc.c					\
			./src/check_way.c					\
			./src/move_after_map.c				\
			./src/help.c						\
			./src/loop_window.c					\
			./src/move_camera.c					\
			./src/create_array_of_sprite.c		\
			./src/before_menu.c					\
			./src/credits_anim.c				\
			./src/generique_anim.c				\
			./src/ending_anim.c					\
			./src/choose_player_name.c				\
			./src/choose_player_class.c				\
			./src/choose_player_sex.c				\
			./src/glob.c						\
			./src/anime_perso.c					\
			./src/check_collision.c				\
			./src/create_sprite_array.c			\
			./src/global.c						\
			./src/display.c						\
			./src/handle_event.c				\
			./src/framebuffer_display.c			\
			./src/rain.c						\
			./src/rain_next.c					\
			./src/heal.c						\
			./src/heal_next.c					\
			./src/inventory.c					\
			./src/display_cursor.c				\
			./src/display_inventory.c			\
			./src/display_map.c					\
			./src/add_item.c					\
			./src/get_nb_item.c					\
			./src/quest.c						\
			./src/display_option.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	my_rpg

CC	=	gcc

INCLUDE	=	-I ./include/

GRAPHIQUE =	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CFLAGS	=	-g3 -Wall -Wextra $(INCLUDE) $(GRAPHIQUE)

DEBUGFLAGS	=	-g3

LIB	=	-L lib/ -lmy

LIB_P	=	-L lib/libpierre.a

all:	mylib $(NAME)

mylib:
	make -C ./lib/my/

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)

clean:
	make clean -C ./lib/my/
	rm -Rf ./src/*.o
	rm -Rf ./src/button/*.o
	rm -Rf ./src/draw_elt/*.o
	rm -Rf ./src/fight_engine/*.o
	rm -Rf ./src/init_program/*.o
	rm -Rf ./src/tools/*.o
	
fclean:	clean
	make fclean -C ./lib/my/
	rm -f $(NAME)

re:	fclean all

debug:	$(CFLAGS) += $(DEBUGFLAGS)
debug: re
