/*
** VISCLO PROJECT, 2020
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

int get_nbr(char const *nbr)
{
    int res = 0;
    int i = 0;
    for (; nbr[i] != '\0'; i++) {
        res = res + nbr[i] - '0';
        res = res * 10;
    }
    return (res / 10);
}

int main(int argc, char **argv)
{
    int nbr_of_throws = 1;
    time_t *rawtime;

    srand(time(rawtime));
    if (argc == 2)
        nbr_of_throws = get_nbr(argv[1]);
    for (; nbr_of_throws > 0; nbr_of_throws--) {
        if (rand() > RAND_MAX / 2)
            write(1, "head\n", 5);
        else if (rand() == 42)
            write(1, "slice\n", 6);
        else
            write(1, "tails\n", 6);
    }
    return (0);
}