#pragma once

#include <stdbool.h>

// Présume que 'data' contient un 'int'.
// Renvoie 'vrai' is la valeur est paire, sinon 'faux'.
bool is_even(
    void const* data);

// Présume que 'data' contient un 'int'.
// Renvoie 'vrai' is la valeur est impaire, sinon 'faux'.
bool is_odd(
    void const* data);

// Présume que 'data' contient un 'int'.
// Renvoie 'vrai' si la valeur est inférieure à 5, sinon 'faux'.
bool less_than_five(
    void const* data);

// Présume que 'data' contient une chaîne de caractères terminée par '\0'.
// Renvoie 'vrai' si 'data' ne contient que des voyelles minuscules ou majuscules.
bool only_vowels(
    void const* data);

// Présume que 'data' contient un 'bool'.
// Modifie la valeur de 'data' pour son contraire.
void negate(
    void* data);

// Présume que 'data' contient une chaîne de caractères terminée par '\0'.
// Modifie la chaîne donnée avec les minuscules changées pour des majuscules et 
// les majuscules changées pour des minuscules.
void flip_case(
    void* data);

// Renvoie le nombre renvoyé lors d'un précédent appel à 'counter' incrémenté de 1.
// Le premier appel de 'counter' renvoie '1'.
void* counter();

// Présume que 'a' et 'b' contiennent des 'int'.
// Renvoie un nombre négatif si 'a' précède 'b' dans l'ordre numérique.
// Renvoie un nombre positif si 'b' précède 'a' dans l'ordre numérique.
// Renvoie zéro si 'a' et 'b' sont égaux.
int numerical_compare(
    void const* a,
    void const* b);

// Présume que 'a' et 'b' contiennent des chaînes de caractères terminée par '\0'.
// Renvoie un nombre négatif si 'a' précède 'b' dans l'ordre lexicographique.
// Renvoie un nombre positif si 'b' précède 'a' dans l'ordre lexicographique.
// Renvoie zéro si 'a' et 'b' sont identiques.
// P. ex. : 'compare("banane", "bananeraie")' -> négatif.
int lexicographical_compare(
    void const* a,
    void const* b);
