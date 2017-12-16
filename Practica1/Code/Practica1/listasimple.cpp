#include "listasimple.h"

ListaSimple::ListaSimple()
{
    this->Principal = nullptr;
    this->Contador = 0;
    this->ColaSimple = new Cola;
}

void ListaSimple::Insertar()
{
    Estacion * nueva = new Estacion();
    nueva->Nombre = "Estacion_"+to_string(Contador++);
    if (this->Principal == nullptr) {
        this->Principal = nueva;
        return;
    }
    Estacion * actual = this->Principal;
    while (actual->Siguiente != nullptr) {
        actual = actual->Siguiente;
    }
    actual->Siguiente = nueva;
}

Estacion::Estacion()
{
    this->Siguiente = nullptr;
    this->Nombre = "";
}

Cola::Cola()
{
    this->Princial = nullptr;
}

void Cola::Insertar(Avion * nuevo_)
{

    if (this->Princial == nullptr) {
        this->Princial = nuevo_;
        return;
    }
    Avion * actual = this->Princial;
    while (actual->Siguiente != nullptr) {
        actual = actual->Siguiente;
    }
    actual->Siguiente = nuevo_;
}

Avion *Cola::Sacar()
{
    if (this->Princial == nullptr) {
        return nullptr;
    }
    Avion * aux = this->Princial;
    this->Princial = this->Princial->Siguiente;
    aux->Siguiente = nullptr;
    return nullptr;
}
