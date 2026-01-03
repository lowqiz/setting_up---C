/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** Task04
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

static int separateur(char c)
{
    if (!((48 <= c && c <= 57) ||
            (65 <= c && c <= 90) || (97 <= c && c <= 122)))
        return 0;
    return 1;
}

static int comptage_mot2(char const *str, int i, int ctgmots)
{
    while (separateur(str[i]) == 1 && str[i] != '\0')
        i++;
    if (str[i] == '\0')
        return ctgmots;
    return ctgmots;
}

static int comptage_mot(char const *str)
{
    int ctgmots = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (separateur(str[i]) == 1){
            ctgmots++;
            ctgmots = comptage_mot2(str, i, ctgmots);
        }
    }
    return ctgmots;
}

static int comptage_lettres(char const *str, int i)
{
    int compteur = 0;

    for (; separateur(str[i]) != 0; i++) {
        compteur++;
    }
    return compteur;
}

char **arraynul(char const *str, char **array, int nbmots, int i)
{
    if (str[i] == '\0') {
        array[nbmots] = NULL;
        return array;
    }
    return array;
}

char **arraynul2(char **array, int z)
{
    if (array[z] == NULL){
        return NULL;
    }
    return array;
}

static int remplir_tableau(char const *str, char **array, int i, int z)
{
    int q = 0;
    int nblettres = comptage_lettres(str, i);

    for (int k = 0; (k < nblettres) && (str[i] != '\0'); i++) {
        array[z][q] = str[i];
        q++;
        k++;
    }
    array[z][nblettres] = '\0';
    return i;
}

char **my_str_to_word_array(char const *str)
{
    int nbmots = comptage_mot(str);
    char **array = malloc(sizeof(char*) * (nbmots + 1));
    int nblettres = 0;
    int z = 0;
    int q = 0;
    int mots = 0;

    for (int i = 0; str[i] != '\0'; i++){
        for (; separateur(str[i]) == 0; i++)
            array = arraynul(str, array, nbmots, i);
        nblettres = comptage_lettres(str, i);
        array[z] = malloc(sizeof(char) * (nblettres + 1));
        array = arraynul2(array, z);
        i = remplir_tableau(str, array, i, z);
        z++;
    }
    array[nbmots] = NULL;
    return array;
}

