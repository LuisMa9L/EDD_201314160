#include "listadoblecirlucur.h"

ListaDobleCirlucur::ListaDobleCirlucur()
{
    this->Principal = nullptr;
    this->Contador = 0;
}

void ListaDobleCirlucur::Inserta()
{
    Maleta * nueva = new Maleta();
    nueva->Nombre = "Maleta_" +to_string((Contador)++);
    if (this->Principal == nullptr) {
        this->Principal = nueva;
        nueva->Siguiete = nueva;
        nueva->Anterior = nueva;
        return;
    }
    nueva->Siguiete = this->Principal;
    nueva->Anterior = this->Principal->Anterior;
    this->Principal->Anterior->Siguiete = nueva;
    this->Principal->Anterior = nueva;
    this->Principal = nueva;
}

Maleta *ListaDobleCirlucur::Sacar()
{
    if (this->Principal == nullptr) return nullptr;
    if (this->Principal->Siguiete == this->Principal) {
        Maleta * aux = this->Principal;
        this->Principal = nullptr;
        return aux;
    }
    Maleta * aux = this->Principal->Anterior;
    this->Principal->Anterior->Anterior->Siguiete = this->Principal;
    this->Principal->Anterior = aux->Anterior;
    return aux;
}

Maleta::Maleta()
{
    this->Anterior = nullptr;
    this->Siguiete = nullptr;
    this->Nombre = "";
}
