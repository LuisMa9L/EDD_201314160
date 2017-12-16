#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <coladobleaviones.h>

using namespace std;

typedef struct ListaSimple ListaSimple;
typedef struct Estacion Estacion;
typedef struct Cola Cola;

struct Estacion
{
    Estacion();
    Estacion * Siguiente;
    string Nombre;
};

struct Cola
{
    Cola();
    Avion * Princial;
    void Insertar(Avion *nuevo_);
    Avion * Sacar();
};

struct ListaSimple
{
    ListaSimple();
    Estacion * Principal;
    int Contador;
    void Insertar();
    Cola * ColaSimple;
};

#endif // LISTASIMPLE_H
