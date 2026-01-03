/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** setting_up
*/

#include "../include/my.h"

char **make_the_pattern(int argc, char **argv, bsq_t *bsq)
{
    int y = 0;
    int calcul_algo = 0;
    int line = my_getnbr(argv[1]);
    char *patern = argv[2];
    int len_patern = my_strlen(patern);
    char **array = malloc(sizeof(char *) * (line + 1));

    if (handle_error_patern(array, len_patern, patern, argv) == -1)
        return NULL;
    for (int x = 0; x < line; x++) {
        array[x] = malloc(sizeof(char) * (line + 1));
        y = 0;
        calcul_algo = (x * line) % len_patern;
        for (; y < line; y++)
            array[x][y] = patern[(calcul_algo + y) % len_patern];
        array[x][y] = '\0';
    }
    array[line] = NULL;
    bsq->taillemap = line;
    return array;
}

char * rturn_and_close(int *fd, char *str)
{
    free(str);
    close(*fd);
    return NULL;
}

char **give_array(char **argv, bsq_t *bsq)
{
    char *str = NULL;
    char **array_recup = NULL;
    struct stat file_drop;
    int nb_line = 0;
    int fd = 0;

    if (stat(argv[1], &file_drop) == -1 || file_drop.st_size == 0)
        return NULL;
    str = str_error(&file_drop, &nb_line, argv, &fd);
    if (str == NULL)
        return NULL;
    array_recup = my_str_to_word_array(str);
    array_recup[nb_line + 1] = NULL;
    if (str_error3(array_recup, &fd, str, nb_line) == NULL) {
        free_array(array_recup);
        return NULL;
    }
    bsq->taillemap = nb_line;
    free(str);
    return array_recup;
}

int half_circle_check(char **array, int temp, int y, int x)
{
    for (int a = x; a <= temp + x; a++) {
        if (array[y] == NULL ||
            array[y][a] == '\0' || array[y][a] != '.') {
            x = a;
            return temp;
        }
    }
    for (int z = y; z >= y - temp; z--) {
        if (array[z] == NULL ||
            array[z][x + temp] == '\0' || array[z][x + temp] != '.')
            return temp;
    }
    return temp + 1;
}

static void algo_map2(char **array, bsq_t *bsq, int y, int x)
{
    int temp = 0;
    int old_y = y;

    for (; array[y] != NULL; y++) {
        if (temp == half_circle_check(array, temp, y, x))
            break;
        temp++;
    }
    if (temp > bsq->best_size) {
        bsq->best_size = temp;
        bsq->y = old_y;
        bsq->x = x;
    }
}

static void display_new_map(char **array, bsq_t *bsq)
{
    for (int y = 0; y < bsq->best_size; y++) {
        for (int x = 0; x < bsq->best_size; x++)
            array[bsq->y + y][bsq->x + x] = 'x';
    }
    for (int y = bsq->y_start; array[y] != NULL; y++)
        mini_printf("%s\n", array[y]);
}

static void algo_map
(char **array, bsq_t *bsq, int x, int y)
{
    if (array[y][x] == '.')
        algo_map2(array, bsq, y, x);
}

static void algo_map1(char **array, bsq_t *bsq)
{
    for (int y = bsq->y_start; array[y] != NULL; y++) {
        for (int x = 0; array[y][x] != '\0'; x++) {
            algo_map(array, bsq, x, y);
        }
    }
    display_new_map(array, bsq);
}

int main(int argc, char **argv)
{
    bsq_t bsq = {0};
    char **map = NULL;

    if (argc == 3) {
        map = make_the_pattern(argc, argv, &bsq);
        if (map == NULL)
            return 84;
        algo_map1(map, &bsq);
        free_array(map);
    } else {
        map = give_array(argv, &bsq);
        if (map == NULL)
            return 84;
        bsq.y_start = 1;
        algo_map1(map, &bsq);
        free_array(map);
    }
    return 0;
}
