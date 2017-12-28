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

string ColaSimplePasajeros::VerGraphviz()
{
    if (this->Principal == nullptr) return "";
    Pasajero * actual = this->Principal;
    string SubGraph = "subgraph cluster_GFPasajeros{\nlabel = \"Pasajeros\"\n;";
    string SEnlaces = "";
    string SEtiquetas = "";
    while (actual != nullptr) {
        SEtiquetas += "Pasaj_" + actual->Id + "[label=\"Pasajero: " + actual->Id + "\\n"
                + "Maletas: " + to_string(actual->Maletas) + "\\n"
                + "Documentos:" + to_string(actual->Documentos) + "\\n"
                + "Turnos: " + to_string(actual->Turnos)
                + "\"];\n";
        if (actual->Siguiente != nullptr) {
            SEnlaces += "Pasaj_"+actual->Id + " -> " + "Pasaj_"+actual->Siguiente->Id + ";\n";
        }
        actual = actual->Siguiente;
    }
    SubGraph+= SEtiquetas;
    SubGraph+= SEnlaces;
    SubGraph+= "}";
    return SubGraph;
}

Pasajero::Pasajero()
{
    this->Siguiente = nullptr;
    this->Maletas = 1+rand()%(5-1);
    this->Documentos = 1+rand()%(11-1);
    this->Turnos = 1+rand()%(4-1);
    this->Id = "";
}
