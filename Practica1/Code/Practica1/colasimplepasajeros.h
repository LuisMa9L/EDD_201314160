#ifndef COLASIMPLEPASAJEROS_H
#define COLASIMPLEPASAJEROS_H

#include <stdlib.h>
#include <time.h>
#include<iostream>

using namespace std;

typedef struct Pasajero Pasajero;
typedef struct ColaSimplePasajeros ColaSimplePasajeros;

struct Pasajero
{
    Pasajero();
    Pasajero * Siguiente;
    int Maletas;
    int Documentos;
    int Turnos;
    string Id;
};

struct ColaSimplePasajeros
{
    ColaSimplePasajeros();
    Pasajero * Principal;
    void Insertar();
    Pasajero * Sacar();
    int Contador;
    string VerGraphviz();
};

#endif // COLASIMPLEPASAJEROS_H
