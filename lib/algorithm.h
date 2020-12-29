// Une version 'C' des algorithmes de l'en-tête <algorithm> de C++.
// Voir https://en.cppreference.com/w/cpp/header/algorithm

#pragma once

#include "vector_types.h"

#include <stdbool.h>
#include <stddef.h>

// Renvoie 'vrai' si la fonction 'predicate' appliquée à tout les éléments de 
// 'first' à 'last' non-inclus renvoie 'vrai' (c.-à-d. predicate(i->element) == true).
bool all_of(iterator first, iterator last, bool (*predicate)(void const* data));

// Renvoie 'vrai' si la fonction 'predicate' appliquée à tout les éléments de 
// 'first' à 'last' non-inclus renvoie 'vrai' au moins un fois.
bool any_of(iterator first, iterator last, bool (*predicate)(void const* data));

// Renvoie 'vrai' si la fonction 'predicate' appliquée à tout les éléments de 
// 'first' à 'last' non-inclus renvoie 'faux'.
bool none_of(iterator first, iterator last, bool (*predicate)(void const* data));

// Applique la fonction 'unary_operation' tout les éléments de 
// 'first' à 'last' non-inclus.
void for_each(iterator first, iterator last, void (*unary_operation)(void* data));

// Renvoie le nombre d'éléments de 'first' à 'last' non-inclus pour lesquels
// 'unaray_operation(i->element)' renvoie 'vrai'.
size_t count_if(iterator first, iterator last, bool (*unary_operation)(void* data));

// Renvoie le premier itérateur entre 'first' et 'last' non-inclus pour lequel 
// la fonction 'predicate' renvoie 'vrai'.
// Si il n'y a pas d'élément pour lequel la fonction 'predicate' renvoie 'vrai',
// renvoie 'last'.
iterator find_if(iterator first, iterator last, bool (*predicate)(void const* data));

// Copie la valeur des éléments entre 'first' et 'last' non-inclus dans 
// l'élément de 'destination'.
// L'itérateur 'destination' est incrémenté de 1 à chaque fois.
// Renvoie l'itérateur 'destination' final.
iterator copy(iterator first, iterator last, iterator destination);

// Copie la valeur des éléments entre 'first' et 'last' non-inclus dans 
// l'élément de 'destination' si la fonction 'predicate' appliquée à l'élément
// renvoie 'vrai'.
// L'itérateur 'destination' est incrémenté de 1 à chaque fois.
// On présume que la destination est de taille suffisante.
// Renvoie l'itérateur 'destination' final.
iterator copy_if(iterator first, iterator last, iterator destination, bool (*predicate)(void const* data));

// Copie la valeur de 'data' à tout les éléments de 'first' à 'last' non-inclus.
void fill(iterator first, iterator last, void const* data);

// Modifie la valeur des éléments entre 'first' et 'last' non-inclus en 
// appliquant la fonction 'unary_operation' et copie le résultat dans l'élément 
// de 'destination'.
// L'itérateur 'destination' est incrémenté de 1 à chaque fois.
// On présume que la destination est de taille suffisante.
// Renvoie l'itérateur 'destination' final.
iterator transform(iterator first, iterator last, iterator destination, void* (*unary_operation)(void* data));

// Copie ce que la fonction 'generator' renvoie à tout les éléments de 'first' à 
// 'last' non-inclus.
// La fonction 'generator' est appellée une fois pour chaque élément.
void generate(iterator first, iterator last, void* (*generator)());

// Inverse l'ordre des éléments entre 'first' et 'last' non-inclus.
void reverse(iterator first, iterator last);

// Opère une rotation des éléments entre 'first' et 'last' non-inclus de sorte 
// que l'élément à 'n_first' se retrouve en premier.
// Renvoie l'élément auquel 'first' fait référence une fois la rotation opérée.
iterator rotate(iterator first, iterator n_first, iterator last);

// Trie les éléments entre 'first' et 'last' non-inclus.
void sort(iterator first, iterator last);

// Déplace tout les duplicata des éléments entre 'first' et 'last' non-inclus 
// à la fin de l'intervalle.
// Renvoie un itérateur vers le premier élément dupliqué.
iterator unique(iterator first, iterator last);

// Renvoie 'vrai' si entre 'first' et 'last' non-inclus se trouve un élément pour 
// lequel 'compare(value, i->element)' renvoie 'vrai'.
// Les éléments entre 'first' et 'last' sont triés et cette fonction opère une recherche binaire.
bool binary_search(iterator first, iterator last, void const* value, bool (*compare)(void const* a, void const* b));

typedef struct iterator_interval
{
    iterator begin, end;
} iterator_interval;

// Renvoie l'intervalle à l'intérieur de l'intervalle entre 'first et 'last' 
// non-inclus pour laquelle 'compare(value, i->element)' renvoie 'vrai'.
// Les éléments entre 'first' et 'last' sont triés.
iterator_interval equal_range(iterator first, iterator last, void const* value, bool (*compare)(void const* a, void const* b));

// Copie vers 'destination' les éléments qui se trouvent dans 
// l'intervalle 'first1' et 'last1' mais qui ne se trouvent pas dans 
// l'intervalle 'first2' et 'last2'.
// La fonction 'compare(a, b)' retourne 'vrai' si 'a < b'.
// Les éléments entre 'first1' et 'last1' sont triés.
// Les éléments entre 'first2' et 'last2' sont triés.
// On présume que la destination est de taille suffisante.
// Renvoie l'itérateur 'destination' final.
iterator set_difference(iterator first1, iterator last1, iterator first2, iterator last2, iterator destination, bool (*compare)(void const* a, void const* b));

// Copie vers 'destination' les éléments qui se trouvent à la fois dans 
// l'intervalle 'first1' et 'last1' et dans l'intervalle 'first2' et 'last2'.
// La fonction 'compare(a, b)' retourne 'vrai' si 'a < b'.
// Les éléments entre 'first1' et 'last1' sont triés.
// Les éléments entre 'first2' et 'last2' sont triés.
// On présume que la destination est de taille suffisante.
// Renvoie l'itérateur 'destination' final.
iterator set_intersection(iterator first1, iterator last1, iterator first2, iterator last2, iterator destination, bool (*compare)(void const* a, void const* b));
