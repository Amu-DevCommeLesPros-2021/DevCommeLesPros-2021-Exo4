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

size_t count_if(iterator first, iterator last, bool (*unary_operation)(void* data))
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

iterator transform(iterator first, iterator last, iterator destination, void* (*unary_operation)(void* data))
{
    return destination;
}

void generate(iterator first, iterator last, void* (*generator)())
{}

void reverse(iterator first, iterator last)
{}

iterator rotate(iterator first, iterator n_first, iterator last)
{
    return n_first;
}

void sort(iterator first, iterator last)
{}

iterator unique(iterator first, iterator last)
{
    return last;
}

bool binary_search(iterator first, iterator last, void const* value, bool (*compare)(void const* a, void const* b))
{
    return false;
}

iterator_interval equal_range(iterator first, iterator last, void const* value, bool (*compare)(void const* a, void const* b))
{
    return (iterator_interval){
        .begin = first,
        .end = last
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
