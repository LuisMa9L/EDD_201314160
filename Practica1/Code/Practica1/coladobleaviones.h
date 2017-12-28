#ifndef COLADOBLEAVIONES_H
#define COLADOBLEAVIONES_H

#include <stdlib.h>
#include <time.h>
#include<iostream>

using namespace std;

typedef struct Avion Avion;
typedef struct ColaDobleAviones ColaDobleAviones;

struct Avion
{
    Avion(string tipo_, int pasajeros_, int desabordaje_, int mantenimiento_, string nombre_);
    string Tipo;
    int Pasajeros;
    int Desabordaje;
    int Mantenimiento;
    Avion * Siguiente;
    Avion * Anterior;
    string Nombre;
};

struct ColaDobleAviones
{
    ColaDobleAviones();
    Avion * Principal;
    Avion * Final;
    void Insertar();
    Avion * Sacar();
    int Contador;
    Avion * VerCola();
    string VerGraphviz();
};

#endif // COLADOBLEAVIONES_H
