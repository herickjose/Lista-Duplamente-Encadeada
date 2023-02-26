#ifndef NO_H
#define NO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

typedef struct no{

    int chave;
    struct no *proximo;
    struct no *anterior;

}No;

No *criaNo(int info);

#endif