/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** setting_up
*/

#include "../include/my.h"

int handle_error_patern
(char **array, int len_patern, char *patern, char **argv)
{
    if (array == NULL || len_patern == 0)
        return -1;
    for (int i = 0; patern[i] != '\0'; i++)
        if (patern[i] != '.' && patern[i] != 'o')
            return -1;
    for (int i = 0; argv[1][i] != '\0'; i++)
        if (47 >= argv[1][i] || 58 <= argv[1][i])
            return -1;
    return 0;
}

char *str_error2(char *str, int *fd, int *nb_line)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if (47 >= str[i] || 58 <= str[i])
            return rturn_and_close(fd, str);
        *nb_line = my_getnbr(str);
    }
    if (str[my_strlen(str) - 1] != '\n')
        return rturn_and_close(fd, str);
    return str;
}

char *str_error
(struct stat *file_drop, int *nb_line, char **argv, int *fd)
{
    char *str = NULL;
    int cpt = 0;

    str = malloc(sizeof(char) * file_drop->st_size + 1);
    if (str == NULL)
        return NULL;
    for (int i = 0; i <= file_drop->st_size; i++)
        str[i] = '\0';
    *fd = open(argv[1], O_RDONLY);
    if (*fd == -1 || read(*fd, str, file_drop->st_size) == -1)
        return rturn_and_close(fd, str);
    if (str_error2(str, fd, nb_line) == NULL)
        return NULL;
    str[file_drop->st_size] = '\0';
    for (int debut = 0; str[debut] != '\0'; debut++)
        if (str[debut] == '\n')
            cpt++;
    if (cpt - 1 != *nb_line)
        return rturn_and_close(fd, str);
    return str;
}

int str_error4(char *str, int cptverif, int *fd)
{
    for (; str[cptverif] != '\0'; cptverif++) {
        if (str[cptverif] != '.'
            && str[cptverif] != 'o') {
            return -1;
        }
    }
    return cptverif;
}

char *str_error3(char **array_recup, int *fd, char *str, int nb_line)
{
    int i = 1;
    int temp = my_strlen(array_recup[1]);
    int cptverif = 0;

    for (; array_recup[i] != NULL; i++) {
        cptverif = 0;
        cptverif = str_error4(array_recup[i], cptverif, fd);
        if (cptverif == -1)
            return rturn_and_close(fd, str);
        if (temp != cptverif)
            return rturn_and_close(fd, str);
    }
    if (i != nb_line + 1)
        return rturn_and_close(fd, str);
    return str;
}
