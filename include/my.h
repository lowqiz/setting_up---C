/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** Task02
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>

typedef struct bsq_s
{
    int x;
    int y;
    int y_start;
    int best_size;
    int size;
    int taillemap;
} bsq_t;

int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_putnbr_base(unsigned long long nb, char const *base,
    int precision, int specifier);
char **my_str_to_word_array(char const *str);
int my_getnbr(char const *str);
char * my_revstr(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
char *my_strcapitalize(char *str);
char * my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char * my_strcpy(char *dest, char const *src);
char * my_strdup(char const *src);
int my_strlen(char const *str);
char * my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char * my_strncpy(char *dest, char const *src, int n);
char * my_strstr(char *str, char const *to_find);
void my_swap(int *a, int *b);
int mini_printf(const char *format, ...);
int my_show_word_array(char *const *tab);
void free_array(char **map);
int handle_error_patern(char **array, int len_patern,
    char *patern, char **argv);
char *str_error(struct stat *file_drop, int *nb_line,
    char **argv, int *fd);
int str_error4(char *str, int cptverif, int *fd);
char *str_error3(char **array_recup, int *fd, char *str, int nb_line);
char *str_error2(char *str, int *fd, int *nb_line);
char * rturn_and_close(int *fd, char *str);
#endif
