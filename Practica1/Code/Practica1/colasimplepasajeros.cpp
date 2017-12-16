#include "colasimplepasajeros.h"

ColaSimplePasajeros::ColaSimplePasajeros()
{
    this->Contador = 0;
    this->Principal = nullptr;
}

void ColaSimplePasajeros::Insertar()
{
    Pasajero * nuevo = new Pasajero();
    nuevo->Id = "P"+to_string((this->Contador)++);
    if (this->Principal == nullptr) {
        this->Principal = nuevo;
        return;
    }
    Pasajero * actual = this->Principal;
    while (actual->Siguiente != nullptr) {
        actual = actual->Siguiente;
    }
    actual->Siguiente = nuevo;
}

Pasajero *ColaSimplePasajeros::Sacar()
{
    if (this->Principal == nullptr) return nullptr;
    Pasajero * aux = this->Principal;
    this->Principal = this->Principal->Siguiente;
    aux->Siguiente = nullptr;
    return aux;
}

Pasajero::Pasajero()
{
    this->Siguiente = nullptr;
    this->Maletas = 1+rand()%(5-1);
    this->Documentos = 1+rand()%(11-1);
    this->Turnos = 1+rand()%(4-1);
    this->Id = "";
}
