#include "algorithm.h"
#include "vector.h"

#include <ctype.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nombre total de tests.
int const tests_total = 124;

// Nombre total de tests exécutés. 
int tests_executed = 0;

// Pour chaque test qui réussi, cette variable sera incrémentée de 1.
// Le but est de la garder égale à test_executes.
int tests_successful = 0;

// Incrémente le nombre de test exécutés de 1.
// Si le test réussi, incrémente le nombre de tests réussis de 1.
#define TEST(x) printf("%s:%d:0 %*s : ", __FILE__, __LINE__, __LINE__ < 100 ? -41 : -40, #x); \
                tests_executed += 1;        \
                if(x)                       \
                {                           \
                    tests_successful += 1;  \
                    printf("[SUCCES]\n");   \
                }                           \
                else                        \
                {                           \
                    printf("[ECHEC]\n");    \
                }

// Incrémente le nombre de test exécutés de 1.
// Compare le contenu de deux fichiers aux chemins a et b avec la commande diff.
// Si les fichiers sont pareils, incrémente le nombre de tests réussis de 1.
#define TEST_FILE(a, b) printf("%s:%d:0 %s %s %s : ", __FILE__, __LINE__, "diff --text --strip-trailing-cr", a, b);   \
                        tests_executed += 1;            \
                        {                               \
                            int const r = system("diff --text --strip-trailing-cr " a " " b " > /dev/null");    \
                            if(!WEXITSTATUS(r))         \
                            {                           \
                                tests_successful += 1;  \
                                printf("[SUCCES]\n");   \
                            }                           \
                            else                        \
                            {                           \
                                printf("[ECHEC]\n");    \
                            }                           \
                        }

// Affiche le sommaire des résultats des tests.
void print_summary()
{
    printf("---\n%-20s : %d\n%-20s : %3d\n%-20s : %3d\n", "Nombre de tests", tests_total, "Tests executes", tests_executed, "Tests reussis", tests_successful);
}

// Fonction à executer lors d'une segmentation fault.
// On imprime les résultats obtenus jusqu'à lors et on arrête immédiatement le programme.
void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    printf("[SEGFAULT]\n");
    print_summary();
    exit(tests_executed - tests_successful);
}

// Présume que 'data' contient un 'int'.
bool is_even(void const* data)
{
    return *(int*)data % 2 == 0;
}

// Présume que 'data' contient un 'int'.
bool less_than_five(void const* data)
{
    return *(int*)data < 5;
}

// Présume que 'data' contient une chaîne de caractères.
bool only_vowels(void const* data)
{
    for(char c = tolower(*(char*)data); c != '\0'; c = tolower(*(char*)++data))
    {
        if(!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // Mise en place de la fonction à exécuter lors d'une segmentation fault.
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    float const growth_factor_doubling = 2.;

    // Tests des fonctions 'all_of', 'any_of' et 'none_of'.
    {
        vector even_suite = make_vector(sizeof(int), 3, growth_factor_doubling);

        // even_suite = [2, 4, 8]
        int n = 2;
        for(iterator i = begin(&even_suite); compare(i, end(&even_suite)) != 0; increment(&i, 1))
        {
            set(i, &n);
            n *= 2;
        }

        iterator b = begin(&even_suite), e = end(&even_suite);
        TEST(all_of(b, e, is_even) == true);
        TEST(any_of(b, e, is_even) == true);
        TEST(none_of(b, e, is_even) == false);

        TEST(all_of(b, e, less_than_five) == false);
        TEST(any_of(b, e, less_than_five) == true);
        TEST(none_of(b, e, less_than_five) == false);

        destroy(&even_suite);


        vector strings = make_vector(sizeof(char[10]), 3, growth_factor_doubling);

        set(at(&strings, 0), "abcde");
        set(at(&strings, 1), "aaaaaaaa");
        set(at(&strings, 2), "banane");

        b = begin(&strings), e = end(&strings);
        TEST(all_of(b, e, only_vowels) == false);
        TEST(any_of(b, e, only_vowels) == true);
        TEST(none_of(b, e, only_vowels) == false);

        destroy(&strings);
    }

    print_summary();

    return tests_executed - tests_successful;
}
