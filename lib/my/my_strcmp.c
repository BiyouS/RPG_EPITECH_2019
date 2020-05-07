/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** compare two string and retrun 0 is they are equal
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int tot = 0;
    int c1 = 0;
    int c2 = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (-1);
    for (int n = 0; s1[n] != '\0' && s2[n] && tot == 0; n++) {
        c1 = s1[n];
        c2 = s2[n];
        tot += c1 - c2;
    }
    if (tot == 0)
        return (0);
    else if (tot < 0)
        return (-1);
    else
        return (1);
}
