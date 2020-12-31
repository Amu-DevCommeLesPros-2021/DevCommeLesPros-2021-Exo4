#include "db.h"

#include "vector_api.h"
#include "vector_types.h"

#include <stdbool.h>
#include <stdio.h>


vector lecture_table(FILE* file)
{
    return (vector){
        .data = NULL,
        .element_size = 0
    };
}

void ecriture_table(FILE* file, vector const* db)
{}

bool est_generaliste(void const* d)
{
    return false;
}