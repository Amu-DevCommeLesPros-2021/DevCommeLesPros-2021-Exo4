#include "functions.h"

#include <stdbool.h>

bool is_even(void const* data)
{
    return *(int*)data % 2 == 0;
}

bool less_than_five(void const* data)
{
    return *(int*)data < 5;
}

bool only_vowels(void const* data)
{
    return false;
}

void negate(void* data)
{}
