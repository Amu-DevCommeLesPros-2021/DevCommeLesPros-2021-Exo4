#pragma once

#include <stdbool.h>

// Présume que 'data' contient un 'int'.
// Renvoie 'vrai' is la valeur est paire, sinon faux.
bool is_even(void const* data);

// Présume que 'data' contient un 'int'.
// Renvoie 'vrai' si la valeur est inférieure à 5, sinon 'faux'.
bool less_than_five(void const* data);

// Présume que 'data' contient une chaîne de caractères terminée par '\0'.
// Renvoie 'vrai' si 'data' ne contient que des voyelles minuscules ou majuscules.
bool only_vowels(void const* data);

// Présume que 'data' contient un 'bool'.
// Modifie la valeur de 'data' pour son contraire.
void negate(void* data);
