#ifndef PANTALLA_H
#define PANTALLA_H

#include <QMainWindow>

#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <coladobleaviones.h>
#include <colasimplepasajeros.h>
#include <listadoblecircular.h>
#include <listadobleordenada.h>
#include <listasimple.h>

using namespace std;

namespace Ui {
class Pantalla;
}

class Pantalla : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pantalla(QWidget *parent = 0);
    ~Pantalla();
    ColaDobleAviones * colaaviones;
    ColaSimplePasajeros * colapasajeros;
    ListaDobleCirlucur * listamaletas;
    ListaDobleOrdenada * listaescritorios;
    ListaSimple * listaestaciones;

    void VerGraphviz();
    int turno;
    int Aviones;

private slots:
    void on_BTurno_clicked();

    void on_BOk_clicked();

    void on_BVer_clicked();

private:
    Ui::Pantalla *ui;
};

#endif // PANTALLA_H
