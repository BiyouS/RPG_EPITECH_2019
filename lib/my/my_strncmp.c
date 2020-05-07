/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** compare two string fro beg to the n-ieme char
*/

static int get_len(char const *str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;
    return (count);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int tot = 0;
    int c1 = 0;
    int c2 = 0;

    if (get_len(s1) > get_len(s2))
        return (1);
    else if (get_len(s1) < get_len(s2))
        return (-1);
    for (int i = 0; s1[i] != '\0' && s2[i] && i < n; i++) {
        c1 = s1[i];
        c2 = s2[i];
        tot += c1 - c2;
        if (tot != 0)
            break;
    }
    if (tot == 0)
        return (0);
    else if (tot < 0)
        return (-1);
    else
        return (1);
}
