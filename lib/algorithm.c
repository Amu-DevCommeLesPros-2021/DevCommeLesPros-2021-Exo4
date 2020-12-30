#include "algorithm.h"

#include "vector_types.h"

#include <stdbool.h>
#include <stddef.h>

bool all_of(iterator first, iterator last, bool (*predicate)(void const* data))
{
    return false;
}

bool any_of(iterator first, iterator last, bool (*predicate)(void const* data))
{
    return false;
}

bool none_of(iterator first, iterator last, bool (*predicate)(void const* data))
{
    return false;
}

void for_each(iterator first, iterator last, void (*unary_operation)(void* data))
{}

size_t count_if(iterator first, iterator last, bool (*unary_operation)(void const* data))
{
    return 0;
}

iterator find_if(iterator first, iterator last, bool (*predicate)(void const* data))
{
    return last;
}

iterator copy(iterator first, iterator last, iterator destination)
{
    return destination;
}

iterator copy_if(iterator first, iterator last, iterator destination, bool (*predicate)(void const* data))
{
    return destination;
}

void fill(iterator first, iterator last, void const* data)
{}

iterator transform(iterator first, iterator last, iterator destination, void (*unary_operation)(void* data))
{
    return destination;
}

void generate(iterator first, iterator last, void* (*generator)())
{}

iterator rotate(iterator first, iterator n_first, iterator last)
{
    return last;
}

void reverse(iterator first, iterator last)
{}

int compare_int(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

void sort(iterator first, iterator last)
{}

void sort_by(iterator first, iterator last, int (*comparator)(void const* a, void const* b))
{}

iterator unique(iterator first, iterator last, int (*comparator)(void const* a, void const* b))
{
    return last;
}

bool binary_search(iterator first, iterator last, void const* value, int (*comparator)(void const* a, void const* b))
{
    return false;
}

iterator_interval equal_range(iterator first, iterator last, void const* value, int (*comparator)(void const* a, void const* b))
{
    return (iterator_interval){
        .begin = (iterator){.element = NULL},
        .end = (iterator){.element = NULL}
    };
}

iterator set_difference(iterator first1, iterator last1, iterator first2, iterator last2, iterator destination, bool (*compare)(void const* a, void const* b))
{
    return destination;
}

iterator set_intersection(iterator first1, iterator last1, iterator first2, iterator last2, iterator destination, bool (*compare)(void const* a, void const* b))
{
    return destination;
}
