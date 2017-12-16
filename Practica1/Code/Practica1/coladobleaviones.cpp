#include "coladobleaviones.h"

ColaDobleAviones::ColaDobleAviones()
{
    this->Principal = nullptr;
    Contador = 0;
}

void ColaDobleAviones::Insertar()
{
    cout << 15+rand()%(26-15) << endl;
    int tip = 1+rand()%(4-1);
    string tipo = "";
    int pasajeros = 0;
    int desabordaje = 0;
    int mantenimiento = 0;
    if (tip == 1) {
        tipo = "Pequeno";
        pasajeros = 5+rand()%(11-5);
        desabordaje = 1;
        mantenimiento = 1 + rand()%(4-1);
    }
    else if (tip == 2) {
        tipo = "Mediano";
        pasajeros = 15+rand()%(26-15);
        desabordaje = 2;
        mantenimiento = 2 + rand()%(5-2);
    }
    else if (tip == 3) {
        tipo = "Grande";
        pasajeros = 30+rand()%(41-30);
        desabordaje = 3;
        mantenimiento = 3 + rand()%(7-3);
    }

    Avion * avion_ = new Avion(tipo,pasajeros,desabordaje,mantenimiento,"Avion_"+to_string((this->Contador)++));
    if (this->Principal == nullptr) {
        this->Principal = avion_;
        return;
    }
    avion_->Siguiente = this->Principal;
    this->Principal->Anterior = avion_;
    this->Principal = avion_;
}

Avion *ColaDobleAviones::Sacar()
{
    if (this->Principal == nullptr) return nullptr;
    if (this->Principal->Siguiente == nullptr and this->Principal->Anterior == nullptr) {
        Avion * aux = this->Principal;
        this->Principal = nullptr;
        return aux;
    }
    Avion * actual = this->Principal;
    while (actual->Siguiente->Siguiente != nullptr) {
        actual = actual->Siguiente;
    }
    Avion * aux = actual->Siguiente;
    actual->Siguiente = nullptr;
    aux->Anterior = nullptr;
    return aux;
}

Avion *ColaDobleAviones::VerCola()
{
    if (this->Principal == nullptr) return nullptr;
    Avion * Actual = this->Principal;
    while (Actual->Siguiente!= nullptr) {
        Actual = Actual->Siguiente;
    }
    return Actual;
}

Avion::Avion(string tipo_, int pasajeros_, int desabordaje_, int mantenimiento_,string nombre_)
{
    this->Tipo = tipo_;
    this->Pasajeros = pasajeros_;
    this->Desabordaje = desabordaje_;
    this->Mantenimiento = mantenimiento_;
    this->Nombre = nombre_;
    this->Siguiente = nullptr;
    this->Anterior = nullptr;
}
