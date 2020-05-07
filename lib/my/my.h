/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** list of my lib prototype
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
void my_put_in_x(size_t nb);
void my_put_in_bigx(int nb);
void my_put_s(char const *str);
void my_put_in_bin(int nb);
int my_printf(char const *format, ...);
void my_put_in_x_p(size_t nb);
void my_put_p(char *str);
void my_put_in_oct(int nb);
int my_put_u(unsigned int nb);
struct info_params *my_params_to_array(int ac, char **av);
char *my_int_to_str(int nb);
int my_nbrlen(int nb);
int my_get_next_nb(char *str);
int my_fd_writer(char *str, int fd);
char **my_str_to_arr(char *str, char *sep);
char **my_str_to_line(char *str);
int **char_arr_to_int_arr(char **arr);
void free_char_arr(char **);
char **load_file_in_mem(char const *);

#endif /* MY_H_ */
