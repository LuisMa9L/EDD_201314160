#ifndef LISTADOBLEORDENADA_H
#define LISTADOBLEORDENADA_H

#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <colasimplepasajeros.h>

using namespace std;

typedef struct ListaDobleOrdenada ListaDobleOrdenada;
typedef struct Escritorio Escritorio;
typedef struct Documento Documento;

struct Documento
{
    Documento();
    Documento * Suguiente;
    string Nombre;
};

struct Escritorio
{
    Escritorio();
    Escritorio * Siguiente;
    Escritorio * Anterior;
    char Nombre;
    int Ocupados;
    Pasajero * EnTurno;
    Documento * Pila;
    Pasajero * Cola;

    //Metodos para la cola
    void InsertarCola(Pasajero * pasajero_);
    void SacarCola();

    //Metodos para la pila
    void InsertarPila(Documento);
    void SacarPila();

};

struct ListaDobleOrdenada
{
    ListaDobleOrdenada();
    Escritorio * Principal;
    void Insertar();
    char Contador;

    void InsertarPasajero(Pasajero * pasajero_);
};

#endif // LISTADOBLEORDENADA_H
