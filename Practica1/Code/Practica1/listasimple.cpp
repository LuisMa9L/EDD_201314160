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

string ListaSimple::VerGraphviz()
{
    if (this->ColaSimple == nullptr) return "";
    Avion * actual = this->ColaSimple->Princial;
    Estacion * actuale = this->Principal;
    string SubGraph = "subgraph cluster_GFEstaciones{\nlabel = \"Estaciones\"\n;";
    string SEnlaces = "";
    string SEtiquetas = "";
    SEnlaces += "{ rank=same\n";
    while (actuale != nullptr) {
        if (actuale->Siguiente != nullptr) {
            SEnlaces += actuale->Nombre + " -> " + actuale->Siguiente->Nombre + ";\n";
        }
        actuale = actuale->Siguiente;
    }
    SEnlaces += "};\n";

    while (actual!= nullptr) {
        if (actual->Siguiente != nullptr) {
            SEnlaces += actual->Nombre + " ->" + actual->Siguiente->Nombre +"\n";
        }
        actual = actual->Siguiente;
    }




/*

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
    */
    SubGraph+= SEtiquetas;
    SubGraph+= SEnlaces;
    SubGraph+= "}";
    return SubGraph;
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
