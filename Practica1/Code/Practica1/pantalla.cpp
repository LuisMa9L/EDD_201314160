#include "pantalla.h"
#include "ui_pantalla.h"

Pantalla::Pantalla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pantalla)
{
    ui->setupUi(this);
    this->colaaviones = new ColaDobleAviones;
    this->colapasajeros = new ColaSimplePasajeros;
    this->listamaletas = new ListaDobleCirlucur;
    this->listaescritorios = new ListaDobleOrdenada;
    this->listaestaciones = new ListaSimple;
}

Pantalla::~Pantalla()
{
    delete ui;
}

void Pantalla::on_BTurno_clicked()
{
    //Revisar por aviones pendientes

    if (this->Aviones != 0) {
        this->colaaviones->Insertar();
        this->Aviones--;
    }

    //Ver Si el avion esta listo para desabordar

    Avion * cola_actual = this->colaaviones->VerCola();
    if (cola_actual != nullptr) {

        if (cola_actual->Desabordaje==0) {
            //desabordar, crear pasajeros
            for (int var = 0; var < cola_actual->Pasajeros; ++var) {
                this->colapasajeros->Insertar();
            }
            //sacar avion de la cola
            Avion * avion_fuera = this->colaaviones->Sacar();
            this->listaestaciones->ColaSimple->Insertar(avion_fuera);

        }
        cola_actual->Desabordaje--;
    }
    //Sacar pasajero 1 x 1
    Pasajero *actual_pasajero = this->colapasajeros->Sacar();
    if (actual_pasajero != nullptr) {
        this->listaescritorios->InsertarPasajero(actual_pasajero);
    }
}

void Pantalla::on_BOk_clicked()
{
    this->Aviones = ui->CAviones->text().toInt();
    int NoEstaciones = ui->CEstaciones->text().toInt();
    for (int var = 0; var < NoEstaciones; ++var) {
        listaestaciones->Insertar();
    }
    int NoEscritorios = ui->CEscritorios->text().toInt();
    for (int var = 0; var < NoEscritorios; ++var) {
        listaescritorios->Insertar();
    }
}
