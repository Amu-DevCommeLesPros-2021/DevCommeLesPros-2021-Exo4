#include "algorithm.h"
#include "functions.h"
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

    // Quelques vecteurs qui seront réutilisés pour les tests.

    // even_suite = [2, 4, 8]
    vector even_suite = make_vector(sizeof(int), 3, growth_factor_doubling);
    int n = 2;
    for(iterator i = begin(&even_suite); compare(i, end(&even_suite)) != 0; increment(&i, 1))
    {
        set(i, &n);
        n *= 2;
    }

    // strings = ["Peau", "Eau", "Peau de Banane"]
    size_t const longueur_chaine = 32;
    vector strings = make_vector(sizeof(char[longueur_chaine]), 0, growth_factor_doubling);

    push_back(&strings, "Peau");
    push_back(&strings, "Eau");
    push_back(&strings, "Peau de Banane");


    // Tests des fonctions 'all_of', 'any_of' et 'none_of'.
    {
        iterator b = begin(&even_suite), e = end(&even_suite);
        TEST(all_of(b, e, is_even) == true);
        TEST(any_of(b, e, is_even) == true);
        TEST(none_of(b, e, is_even) == false);

        TEST(all_of(b, e, is_odd) == false);
        TEST(any_of(b, e, is_odd) == false);
        TEST(none_of(b, e, is_odd) == true);

        TEST(all_of(b, e, less_than_five) == false);
        TEST(any_of(b, e, less_than_five) == true);
        TEST(none_of(b, e, less_than_five) == false);


        b = begin(&strings), e = end(&strings);
        TEST(all_of(b, e, only_vowels) == false);
        TEST(any_of(b, e, only_vowels) == true);
        TEST(none_of(b, e, only_vowels) == false);
    }

    // Tests de la fonction 'for_each'.
    {
        vector switches = make_vector(sizeof(bool), 0, growth_factor_doubling);

        // on_off_on_off = [true, false, true, false]
        bool flip = true;
        push_back(&switches, &flip);
        flip = !flip;
        push_back(&switches, &flip);
        flip = !flip;
        push_back(&switches, &flip);
        flip = !flip;
        push_back(&switches, &flip);

        // on_off_on_off = [false, true, false, true]
        iterator b = begin(&switches), e = end(&switches);
        for_each(b, e, negate);

        TEST(*(bool*)value(at(&switches, 0)) == false);
        TEST(*(bool*)value(at(&switches, 1)) == true);
        TEST(*(bool*)value(at(&switches, 2)) == false);
        TEST(*(bool*)value(at(&switches, 3)) == true);

        destroy(&switches);
    }

    // Tests des fonctions 'count_if' et 'find_if'.
    {
        iterator b = begin(&even_suite), e = end(&even_suite);
        TEST(count_if(b, e, less_than_five) == 2);

        iterator f = find_if(b, e, less_than_five);
        TEST(compare(f, begin(&even_suite)) == 0);

        f = find_if(b, e, is_odd);
        TEST(compare(f, end(&even_suite)) == 0);


        b = begin(&strings), e = end(&strings);
        TEST(count_if(b, e, only_vowels) == 1);

        f = find_if(b, e, only_vowels);
        TEST(compare(f, at(&strings, 1)) == 0);
    }

    // Tests des fonctions 'copy' et 'copy_if'.
    {
        vector copy_even_suite = make_vector(sizeof(int), size(even_suite), growth_factor_doubling);

        copy(begin(&even_suite), end(&even_suite), begin(&copy_even_suite));
        for(size_t i = 0; i != size(even_suite); ++i)
        {
            TEST(*(int*)value(at(&copy_even_suite, i)) == *(int*)value(at(&even_suite, i)));
        }

        size_t const small_count = count_if(begin(&even_suite), end(&even_suite), less_than_five);
        vector small_even_suite = make_vector(sizeof(int), small_count, growth_factor_doubling);

        copy_if(begin(&even_suite), end(&even_suite), begin(&small_even_suite), less_than_five);
        TEST(*(int*)value(at(&small_even_suite, 0)) == *(int*)value(at(&even_suite, 0)));
        TEST(*(int*)value(at(&small_even_suite, 1)) == *(int*)value(at(&even_suite, 1)));

        vector just_vowels = make_vector(sizeof(char[longueur_chaine]), 1, growth_factor_doubling);
        copy_if(begin(&strings), end(&strings), begin(&just_vowels), only_vowels);

        TEST(strcmp((char*)value(at(&strings, 1)), (char*)value(at(&just_vowels, 0))) == 0);
    }

    // Tests de la fonction 'fill'.
    {
        vector tens_and_twenties = make_vector(sizeof(int), 6, growth_factor_doubling);

        int const ten = 10, twenty = 20;
        iterator half_way = at(&tens_and_twenties, size(tens_and_twenties) / 2);
        fill(begin(&tens_and_twenties), half_way, &ten);
        fill(half_way, end(&tens_and_twenties), &twenty);

        for(size_t n = 0; n != size(tens_and_twenties) / 2; ++n)
        {
            TEST(*(int*)value(at(&tens_and_twenties, n)) == 10);
        }
        for(size_t n = size(tens_and_twenties) / 2; n != size(tens_and_twenties); ++n)
        {
            TEST(*(int*)value(at(&tens_and_twenties, n)) == 20);
        }

    }

    // Tests de la fonction 'transform'.
    {
        vector bizarro = make_vector(sizeof(char[longueur_chaine]), size(strings), growth_factor_doubling);

        transform(begin(&strings), end(&strings), begin(&bizarro), flip_case);
        TEST(strcmp((char*)value(at(&bizarro, 0)), "pEAU") == 0);
        TEST(strcmp((char*)value(at(&bizarro, 1)), "eAU") == 0);
        TEST(strcmp((char*)value(at(&bizarro, 2)), "pEAU DE bANANE") == 0);

        // 'strings' doit rester intact.
        TEST(strcmp((char*)value(at(&strings, 0)), "Peau") == 0);
        TEST(strcmp((char*)value(at(&strings, 1)), "Eau") == 0);
        TEST(strcmp((char*)value(at(&strings, 2)), "Peau de Banane") == 0);
    }

    // Tests de la fonction 'generate'.
    {
        vector linear_suite = make_vector(sizeof(int), 5, growth_factor_doubling);

        // linear_suite = [1, 2, 3, 4, 5]
        generate(begin(&linear_suite), end(&linear_suite), counter);
        for(int n = 0; n != size(linear_suite); ++n)
        {
            TEST(*(int*)value(at(&linear_suite, n)) == n + 1);
        }
    }

    destroy(&even_suite);
    destroy(&strings);

    print_summary();

    return tests_executed - tests_successful;
}
