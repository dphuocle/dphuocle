#include "suite.h"
#include "generator.h"
#include <stdio.h>

void suite_e_suite(int longeur)
{
 
    generator_generate(Debut);
    printf("(");
    while (longeur-- >= 0)
    {
        printf("%d , ", generator_generate(Suivant));
    }
    printf(")\n");
}    
