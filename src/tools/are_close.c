/*
** EPITECH PROJECT, 2020
** lib graph
** File description:
** take two point and return 1
** if they are close else 0
*/

#include <SFML/Graphics.h>

int are_close(sfVector2f point1, sfVector2f point2, float rad)
{
    if ((point1.x >= point2.x - rad && point1.x <= point2.x + rad)
        && (point1.y >= point2.y - rad && point1.y <= point2.y + rad))
        return (1);
    else
        return (0);
}
