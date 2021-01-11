![](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo4/workflows/Run%20tests/badge.svg)

# DevCommeLesPros-2021-Exo4

Modèle de départ pour les exercices de synthèse du cours.

<!-- TOC depthfrom:2 -->

- [Préparation](#pr%C3%A9paration)
- [Objectif](#objectif)
- [Instructions de travail](#instructions-de-travail)
- [Évaluation](#%C3%A9valuation)
- [Questions-Réponses](#questions-r%C3%A9ponses)
    - [«J'ai un problème !»](#%C2%ABjai-un-probl%C3%A8me-%C2%BB)
    - [«J'ai des problèmes avec la manipulation de mémoire dynamique.»](#%C2%ABjai-des-probl%C3%A8mes-avec-la-manipulation-de-m%C3%A9moire-dynamique%C2%BB)

<!-- /TOC -->

## Préparation

Ces intructions présupposent que vous avez déjà suivi les instructions du [zérotième exercice](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo0) pour la création d'un compte GitHub et l'installation des programmes et extensions nécéssaires.

suivez les mêmes instructions de travail que pour l'[exercice précédent](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo3#instructions-de-travail).

## Objectif

En C++, vous aurez accès au ficher d'en-tête [`<algorithm>`](https://en.cppreference.com/w/cpp/header/algorithm).
Ce fichier contient des fonctions telles que «[chercher](https://en.cppreference.com/w/cpp/algorithm/find)», «[compter](https://en.cppreference.com/w/cpp/algorithm/count)», «[trier](https://en.cppreference.com/w/cpp/algorithm/sort)», etc.
Ces fonctions sont implémentées de telle sorte, leurs paramètres étant des itérateurs, qu'elles puissent opérer sur n'importe quel type de structure de donnée comme `vector<>`, `list<>`, `stack<>`, etc. et sur n'importe quel type de données comme `list<int>`, `list<float>`, `list<char[32]>`, etc.
Ces justement l'abstraction qu'offre les itérateurs qui permet de décupler l'utilité de ces fonctions.
En effet, ces fonctions ne sont implémentées qu'une seule fois et non pas une fois pour chaque type de données !
Cet exercice vous propose de plonger dans ce petit univers des fonctions génériques et d'implémenter quelques unes de ces fonctions.

Pour commencer, le programme de test de cet exercice a tous ses tests commentés.
Il vous faudra les décommenter à mesure qui vous implémenterez les fonctionalités des bibliothèques `libalgorithm`, `libdb`, `libfunctions` et `libvector`.

Vous devrez :
1. Modifier l'URL en tête de ce document `README.md` pour refléter l'URL de votre dépôt.
    - L'URL doit ressembler à `https://github.com/[nom-de-votre-compte]/[nom-de-votre-depot]/workflows/Run%20tests/badge.svg`.
    - Cet URL présente un «badge» qui réflete l'état de santé de votre dépôt.
1. Compléter le fichier `makefile` :
    - Compléter les cibles déjà définies.
        - La cible `check` doit dépendre de la cible `build/test` et doit lancer le programme de test.
        - **Il est impératifs que les cibles `build/test` et `check` soient définies pour la bonne exécution de cet exercice.**
    - Ajouter d'autres cibles à votre guise.
1. Implémenter correctement toutes les fonctions des bibliothèques logicielles `libalgorithm`, `libdb`, `libfunctions` et `libvector` pour que le programme `build/test` affiche que tous les tests passent et retourne `0` à l'invite de commande.

## Instructions de travail

Pour cet exercice, suivez les mêmes instructions de travail que pour l'[exercice précédent](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo3#instructions-de-travail).

Il vous est permis :
- De modifier le fichier `README.md` pour modifier l'URL du badge en en-tête.
- De modifier le fichier `makefile` pour compiler et lier les cibles prédéfinies et ajouter d'autres cibles si nécessaire.
- De reprendre les fichier `lib/vector_types.h` et `lib/vector_api.c` de votre exercice précédent.
- De modifier les fichiers `lib/algorithm.c`, `lib/db.c` et `lib/functions.c` afin d'implémenter les fonctions qu'il contiennent.
- De modifier le fichier `test/main.c` pour activer (décommenter) le plus de tests possible.

Il ne vous est pas permis :
- De modifier les fichiers d'en-tête `lib/algorithm.h`, `lib/db.h`, `lib/functions.h`, `lib/vector.h` et `lib/vector_api.h`.

En tout temps:
- Votre code doit réussir 100% des tests activés (décommentés), même si ce n'est pas l'entièreté des tests, avant d'être intégré dans la branche `master`.
- Le badge apparaissant tout en haut de ce document doit afficher `passing`.

## Évaluation

L'évaluation portera sur :
1. Le suivi des instructions de travail.
    - Je dois voir des contributions à la base de code par tous les membres de votre groupe.
1. Le nombre de tests réussis.
    - Vos fichiers `lib/algorithm.c`, `lib/db.c`, `lib/functions.c`, `lib/vector_types.h` et `lib/vector_api.c` seront compilés et liés avec les fichiers d'en-tête correspondants intacts et avec le fichier `test/main.c` ayant tous ses tests activés (décommentés).
1. La qualité des modifications apportées.

Attention !
*Seul le code de la branche `master` de votre dépôt commun sur [GitHub](https://github.com) compte !*

## Questions-Réponses

### «J'ai un problème !»

Voyez les indications données dans le [premier exercice](https://github.com/Amu-DevCommeLesPros-2021/DevCommeLesPros-2021-Exo1#jai-un-probl%C3%A8me-) à ce sujet.

### «J'ai des problèmes avec la manipulation de mémoire dynamique.»

Un excellent outil disponible pour Linux est [`valgrind`](https://valgrind.org/).
En autres choses, `valgrind` peut faire une analyse de possibles erreurs de mémoires de notre programme.
Ce n'est pas une analsye du code mais une analyse ex post facto une fois que notre programme a terminé son exécution.
Un bon petit tuto se trouve [ici](https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks).
