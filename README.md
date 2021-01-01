![](https://github.com/thierryseegers/DevCommeLesPros-2021-Exo4/workflows/Run%20tests/badge.svg)

# DevCommeLesPros-2021-Exo4

Modèle de départ pour exercices de synthèse du cours.

<!-- TOC depthfrom:2 -->

- [Instructions de départ](#instructions-de-d%C3%A9part)
    - [Pour créer le dépôt un membre du binôme](#pour-cr%C3%A9er-le-d%C3%A9p%C3%B4t-un-membre-du-bin%C3%B4me)
    - [Pour cloner le dépôt deux membres du binôme](#pour-cloner-le-d%C3%A9p%C3%B4t-deux-membres-du-bin%C3%B4me)
- [Objectif](#objectif)
- [Instructions de travail](#instructions-de-travail)
- [Questions-Réponses](#questions-r%C3%A9ponses)
    - [«J'ai un problème !»](#%C2%ABjai-un-probl%C3%A8me-%C2%BB)
    - [«J'ai des problèmes avec la manipulation de mémoire dynamique.»](#%C2%ABjai-des-probl%C3%A8mes-avec-la-manipulation-de-m%C3%A9moire-dynamique%C2%BB)
- [Évaluation](#%C3%A9valuation)

<!-- /TOC -->

## Instructions de départ

Ces intructions présupposent que vous avez déjà suivi les instructions du [zérotième exercice](https://github.com/thierryseegers/DevCommeLesPros-2021-Exo0#instructions-de-d%C3%A9part) pour la création d'un compte GitHub et l'installation des programmes et extensions nécéssaires.

Pour cet exercice, vous devez travailler en binôme sur un même dépôt.
Choisissez qui du binôme créera le dépôt.
Par la suite, ce même dépôt sera cloné par les deux membres du binôme.

### Pour créer le dépôt (un membre du binôme)
1. Créez votre dépôt sur github.com en utilisant [ce dépôt-ci](https://github.com/thierryseegers/DevCommeLesPros-2021-Exo4) comme modèle.
    - Suivez ces instructions : https://docs.github.com/en/free-pro-team@latest/github/creating-cloning-and-archiving-repositories/creating-a-repository-from-a-template.
    - Choisissez l'option `Private` à l'étape 5.
1. Ajoutez le professeur comme collaborateur à votre dépôt.
    - Suivez ces instructions : https://docs.github.com/en/free-pro-team@latest/github/setting-up-and-managing-your-github-user-account/inviting-collaborators-to-a-personal-repository.
    - Nom d'utilisateur à ajouter : `thierryseegers`.
1. Ajoutez votre co-équipier·ère comme collaborateur à votre dépôt.
    - Suivez les instructions de l'étape précédente.
    - Votre co-équipier·ère recevra un mail avec un lien pour accepter votre invitation.

### Pour cloner le dépôt (deux membres du binôme)
1. Clonez le dépôt vers votre espace de travail local.
    - Suivez ces instructions : https://docs.github.com/en/free-pro-team@latest/github/creating-cloning-and-archiving-repositories/cloning-a-repository
    - Attention à ne pas cloner https://github.com/thierryseegers/DevCommeLesPros-2021-Exo4 mais bien votre dépôt nouvellement créé.
1. Lancez Visual Studio Code.
    - À l'invite de commandes:
        - `$ cd [nom de votre dépôt]`
        - `$ code .`

## Objectif

En C++, vous aurez accès au ficher d'en-tête [`<algorithm>`](https://en.cppreference.com/w/cpp/header/algorithm).
Ce fichier contient des fonctions telles que «[chercher](https://en.cppreference.com/w/cpp/algorithm/find)», «[compter](https://en.cppreference.com/w/cpp/algorithm/count)», «[trier](https://en.cppreference.com/w/cpp/algorithm/sort)», etc.
Ces fonctions sont implémentées de telle sorte, leurs paramètres étant des itérateurs, qu'elles puissent opérer sur n'importe quel type de structure de donnée comme `vector<>`, `list<>`, `stack<>`, etc. et sur n'importe quel type de données comme `list<int>`, `list<float>`, `list<char[32]>`, etc.
Ces justement l'abstraction qu'offre les itérateurs qui permet de décupler l'utilité de ces fonctions.
En effet, ces fonctions ne sont implémentées qu'une seule fois et non pas une fois pour chaque type de données !
Cet exercice vous propose de plonger dans ce petit univers des fonctions génériques et d'implémenter quelques unes de ces fonctions.

Pour commencer, le programme de test de cet exercice a tout ses tests commentés.
Il vous faudra les décommenter à mesure qui vous implémenterez les fonctionalités des bibliothèques `libalgorithm`, `libdb`, `libfunctions` et `libvector`.
Le programme de test :
- affiche le résultat de chaque test exécutés : `[SUCCES]`, `[ECHEC]` ou `[SEGFAULT]` (à `[SEGFAULT]`, le programme est stoppé).
- affiche en fin d'exécution le nombre de tests total, de tests exécutés et de tests réussis.
- retourne comme valeur la différence entre le nombre de tests total et de tests réussis (p. ex. 16 - 10 -> `6`).

Vous devrez :
1. Modifier l'URL en tête de ce document `README.md` pour refléter l'URL de votre dépôt.
    - L'URL doit ressembler à `https://github.com/[nom-de-votre-compte]/[nom-de-votre-depot]/workflows/Run%20tests/badge.svg`.
    - Cet URL présente un «badge» qui réflete l'état de santé de votre dépôt.
1. Compléter le fichier `makefile` :
    - Compléter les cibles déjà définies.
        - La cible `check` doit dépendre de la cible `build/test` et doit lancer le programme de test.
        - **Il est impératifs que les cibles `build/test` et `check` soient définies pour la bonne exécution de cet exercice.**
    - Ajouter d'autres cibles à votre guise.
1. Implémenter correctement toutes les fonctions des bibliothèques logicielles `libalgorithm`, `libdb`, `libfunctions` et `libvector` pour que le programme `build/test` affiche que tout les tests passent et retourne `0` à l'invite de commande.

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


## Instructions de travail

Pour cet exercice, suivez les mêmes instructions de travail que pour l'[exercice précédent](https://github.com/thierryseegers/DevCommeLesPros-2021-Exo3#instructions-de-travail).

## Questions-Réponses

### «J'ai un problème !»

Voyez les indications données dans le [premier exercice](https://github.com/thierryseegers/DevCommeLesPros-2021-Exo1#jai-un-probl%C3%A8me-) à ce sujet.

### «J'ai des problèmes avec la manipulation de mémoire dynamique.»

Un excellent outil disponible pour Linux est [`valgrind`](https://valgrind.org/).
En autres choses, `valgrind` peut faire une analyse de possibles erreurs de mémoires de notre programme.
Ce n'est pas une analsye du code mais une analyse ex post facto une fois que notre programme a terminé son exécution.
Un bon petit tuto se trouve [ici](https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks).

## Évaluation

L'évaluation portera sur :
1. Le suivi des instructions de travail.
    - Je dois voir des contributions à la base de code par tout les membres de votre groupe.
1. Le nombre de tests réussis.
    - Vos fichiers `lib/algorithm.c`, `lib/db.c`, `lib/functions.c`, `lib/vector_types.h` et `lib/vector_api.c` seront compilés et liés avec les fichiers d'en-tête correspondants intacts et avec le fichier `test/main.c` ayant tout ses tests activés (décommentés).
1. La qualité des modifications apportées.

Attention !
*Seul le code de votre dépôt sur [GitHub](https://github.com) compte !*
