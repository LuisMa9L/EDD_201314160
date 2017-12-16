#include "listadobleordenada.h"

ListaDobleOrdenada::ListaDobleOrdenada()
{
    this->Contador = 'A';
    this->Principal = nullptr;
}

void ListaDobleOrdenada::Insertar()
{
    Escritorio * nuevo = new Escritorio();
    nuevo->Nombre = (this->Contador)++;
    if (this->Principal == nullptr) {
        this->Principal = nuevo;
        return;
    }
    if (this->Principal->Nombre > nuevo->Nombre) {
        nuevo->Siguiente = this->Principal;
        this->Principal->Anterior = nuevo;
        this->Principal =nuevo;
    }
    Escritorio * Actual = this->Principal;
    while (Actual->Siguiente != nullptr) {
        if (Actual->Siguiente->Nombre > nuevo->Nombre) {
            nuevo->Siguiente = Actual->Siguiente;
            nuevo->Anterior = Actual;
            Actual->Siguiente->Anterior = nuevo;
            Actual->Siguiente = nuevo;
            return;
        }
        Actual = Actual->Siguiente;
    }
    Actual->Siguiente = nuevo;
    nuevo->Anterior = Actual;
}

Escritorio::Escritorio()
{
    this->Anterior = nullptr;
    this->Siguiente = nullptr;
    this->Nombre = 0;
    this->Ocupados = 0;
    this->Cola = nullptr;//Cabecera
    this->Pila = nullptr;//Cabecera
}

void Escritorio::InsertarCola(Pasajero *pasajero_)
{
    if (this->Cola == nullptr) {
        this->Cola = pasajero_;
        return;
    }
    Pasajero * actual = this->Cola;
    while (actual->Siguiente != nullptr) {
        actual = actual->Siguiente;
    }
    actual->Siguiente = pasajero_;
}

void Escritorio::SacarCola()
{
    if (this->Cola == nullptr) return;
    Pasajero * aux = this->Cola;
    this->Cola = this->Cola->Siguiente;
    //Sacar Maletas
    delete(aux);
}
