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

string ListaDobleOrdenada::VerGraphviz()
{
    if (this->Principal == nullptr) return "";
    Escritorio * actual = this->Principal;
    string SubGraph = "subgraph cluster_GFEscritorios{\nlabel = \"Escritorios\"\n;";
    string SEnlaces = "";
    string SEtiquetas = "{ rank=same\n";

    string SEnlacespj = "";
    string SEtiquetaspj = "";

    while (actual!= nullptr) {
        string letra1 = "";
        letra1.push_back(actual->Nombre);
        SEtiquetas += "Escritorio_" + letra1 + "[label=\"Escritorio: " + letra1 + "\\n";
        if (actual->EnTurno != nullptr) {
            SEtiquetas += "Estado: Ocupado \\n";
            SEtiquetas += "Cliente: " + actual->EnTurno->Id+"\\n";
            SEtiquetas += "Restantes: "+ to_string(actual->EnTurno->Turnos)+", "+to_string(actual->Ocupados)+"\\n";
            SEtiquetas += "Documentos: " + to_string(actual->EnTurno->Documentos);
        } else{
            SEtiquetas += "Estado: Libre";
        }
        SEtiquetas += "\"];\n";
        if (actual->Siguiente != nullptr) {
            string letra2 = "";
            letra2.push_back(actual->Siguiente->Nombre);
            SEnlaces += "Escritorio_"+ letra1 + " -> " + "Escritorio_"+ letra2 +";\n";
            SEnlaces += "Escritorio_"+ letra2 + " -> " + "Escritorio_"+ letra1 +";\n";
        }
        if (actual->PrincipalCola != nullptr) {
            Pasajero * actualjp = actual->PrincipalCola;
            SEnlaces += "Escritorio_" +letra1 + " -> "+"Pasajdk_"+actualjp->Id+"\n";

            while (actualjp != nullptr) {
                SEtiquetaspj += "Pasajdk_" + actualjp->Id + "[label=\"Pasajero: " + actualjp->Id + "\\n"
                        + "Maletas: " + to_string(actualjp->Maletas) + "\\n"
                        + "Documentos:" + to_string(actualjp->Documentos) + "\\n"
                        + "Turnos: " + to_string(actualjp->Turnos)
                        + "\"];\n";
                if (actualjp->Siguiente != nullptr) {
                    SEnlacespj += "Pasajdk_"+actualjp->Id + " -> " + "Pasajdk_"+actualjp->Siguiente->Id + ";\n";
                }
                actualjp = actualjp->Siguiente;
            }
        }
        actual = actual->Siguiente;
    }


    SubGraph+= SEtiquetas+ "};\n" + "\n" + SEtiquetaspj;
    SubGraph+= SEnlaces + "\n" + SEnlacespj;
    SubGraph+= "}";
    return SubGraph;
}

void ListaDobleOrdenada::InsertarPasajero(Pasajero *pasajero_)
{
    if (this->Principal == nullptr) return;
    Escritorio * actual = this->Principal;
    while (actual != nullptr) {
        if (actual->EnTurno == nullptr) {
            actual->EnTurno = pasajero_;
            return;
        }
        if (actual->Ocupados < 10) {
            actual->InsertarCola(pasajero_);
            return;
        }
        actual = actual->Siguiente;
    }
}

Escritorio::Escritorio()
{
    this->Anterior = nullptr;
    this->Siguiente = nullptr;
    this->Nombre = 0;
    this->Ocupados = 0;
    this->PrincipalCola = nullptr;//Cabecera
    this->PrincipalPila = nullptr;//Cabecera
    this->EnTurno = nullptr;
}

void Escritorio::InsertarCola(Pasajero *pasajero_)
{
    if (this->PrincipalCola == nullptr) {
        this->PrincipalCola = pasajero_;
        this->Ocupados++;
        return;
    }
    Pasajero * actual = this->PrincipalCola;

    while (actual->Siguiente != nullptr) {
        actual = actual->Siguiente;
    }
    actual->Siguiente = pasajero_;
    this->Ocupados++;
}

Pasajero *Escritorio::SacarCola()
{
    if (this->PrincipalCola == nullptr) return nullptr;
    Pasajero * aux = this->PrincipalCola;
    this->PrincipalCola = this->PrincipalCola->Siguiente;
    //Sacar Maletas
    this->Ocupados--;
    return aux;
}
