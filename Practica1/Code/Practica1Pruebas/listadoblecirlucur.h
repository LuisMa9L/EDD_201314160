#ifndef LISTADOBLECIRLUCUR_H
#define LISTADOBLECIRLUCUR_H

#include <stdlib.h>
#include <time.h>
#include<iostream>

using namespace std;

typedef struct ListaDobleCirlucur ListaDobleCirlucur;
typedef struct Maleta Maleta;

struct Maleta
{
    Maleta();
    Maleta * Siguiete;
    Maleta * Anterior;
    string Nombre;
};

struct ListaDobleCirlucur
{
    ListaDobleCirlucur();
    Maleta * Principal;
    void Inserta();
    Maleta *Sacar();
    int Contador;
};

#endif // LISTADOBLECIRLUCUR_H
