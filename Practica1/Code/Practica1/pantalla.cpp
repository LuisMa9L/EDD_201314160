#include "pantalla.h"
#include "ui_pantalla.h"

Pantalla::Pantalla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pantalla)
{
    ui->setupUi(this);

    this->colaaviones = new ColaDobleAviones();
    this->colapasajeros = new ColaSimplePasajeros();
    this->listamaletas = new ListaDobleCirlucur();
    this->listaescritorios = new ListaDobleOrdenada();
    this->listaestaciones = new ListaSimple();
    this->turno = 1;
}

Pantalla::~Pantalla()
{
    delete ui;
}

void Pantalla::VerGraphviz()
{
        FILE *ArchivoDot;
        ArchivoDot = fopen("AvionesGraphViz.dot","w");
        fprintf(ArchivoDot,"digraph grafica {\n");
        fprintf(ArchivoDot," node[shape=record, fontcolor=red,color = blue]; \n");
        fprintf(ArchivoDot,"label=");
        fprintf(ArchivoDot,"\"     lMMl     \"");
        fprintf(ArchivoDot,"\n");
        //*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v
        fprintf(ArchivoDot,this->colaaviones->VerGraphviz().c_str());
        fprintf(ArchivoDot,this->colapasajeros->VerGraphviz().c_str());
        fprintf(ArchivoDot,this->listaescritorios->VerGraphviz().c_str());
        fprintf(ArchivoDot,this->listamaletas->VerGraph().c_str());
        fprintf(ArchivoDot,this->listaestaciones->VerGraphviz().c_str());
        //*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v*****v
        fprintf(ArchivoDot,"}\n");//Final
        fclose(ArchivoDot);
        system("dot AvionesGraphViz.dot -o AvionesGraphViz.png -Tpng");

        QPixmap ImagenA;
        ImagenA.load("AvionesGraphViz.png");
        ui->LImagen->setPixmap((ImagenA).scaled(ui->LImagen->width(),ui->LImagen->height(),Qt::KeepAspectRatio));

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

        if (cola_actual->Desabordaje==1) {
            //desabordar, crear pasajeros
            for (int var = 0; var < cola_actual->Pasajeros; ++var) {
                this->colapasajeros->Insertar();
            }
            //sacar avion de la cola
            Avion * avion_fuera = this->colaaviones->Sacar();
            if ( avion_fuera != nullptr){
                this->listaestaciones->ColaSimple->Insertar(avion_fuera);
            }
        }
        cola_actual->Desabordaje--;
    }
    //Sacar pasajero 1 x 1
    Pasajero *actual_pasajero = this->colapasajeros->Sacar();
    if (actual_pasajero != nullptr) {
        this->listaescritorios->InsertarPasajero(actual_pasajero);
        // añadir maletas
        for (int var = 0; var < actual_pasajero->Maletas; ++var) {
            this->listamaletas->Inserta();
        }
    }
    //Revisar escritorios
    Escritorio * actual_escritorio = this->listaescritorios->Principal;
    if (actual_escritorio != nullptr) {
        while (actual_escritorio != nullptr) {
            if (actual_escritorio->EnTurno != nullptr) {
                if (actual_escritorio->EnTurno->Turnos == 1) {
                    //sacar maletas por pasajero
                    for (int var = 0; var < actual_escritorio->EnTurno->Maletas; ++var) {
                        this->listamaletas->Sacar();
                    }
                    delete actual_escritorio->EnTurno;
                    actual_escritorio->EnTurno = nullptr;
                    if (actual_escritorio->Ocupados!= 0) {
                        Pasajero * auxp = actual_escritorio->SacarCola();
                        actual_escritorio->EnTurno = auxp;
                    }
                }else {
                    actual_escritorio->EnTurno->Turnos--;
                }
            }
            actual_escritorio = actual_escritorio->Siguiente;
        }
    }

    this->VerGraphviz();

    string scon = "*****v*****Turno "+to_string((this->turno)++)+"*****v*****\n";
    scon += "Aviones en el Sistema: " +to_string(this->colaaviones->Contador+1) +"\n";
    scon += "Pasajeros en el Sistema: " +to_string(this->colapasajeros->Contador+1) + "\n";
    //scon += "" + + "\n";
    //scon += "" + + "\n";
    QString sali = QString::fromStdString(scon);
    ui->CConsola->setPlainText(sali);
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
    ui->BOk->setEnabled(false);
}

void Pantalla::on_BVer_clicked()
{

    system("eog AvionesGraphViz.png");
}
