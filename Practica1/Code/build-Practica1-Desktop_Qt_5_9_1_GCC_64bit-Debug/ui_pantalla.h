/********************************************************************************
** Form generated from reading UI file 'pantalla.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA_H
#define UI_PANTALLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pantalla
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *BTurno;
    QWidget *tab_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *CAviones;
    QLineEdit *CEscritorios;
    QLineEdit *CEstaciones;
    QPushButton *BOk;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Pantalla)
    {
        if (Pantalla->objectName().isEmpty())
            Pantalla->setObjectName(QStringLiteral("Pantalla"));
        Pantalla->resize(775, 557);
        centralWidget = new QWidget(Pantalla);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 331, 171));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        BTurno = new QPushButton(tab);
        BTurno->setObjectName(QStringLiteral("BTurno"));
        BTurno->setGeometry(QRect(10, 10, 89, 25));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        widget = new QWidget(tab_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 308, 124));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        CAviones = new QLineEdit(widget);
        CAviones->setObjectName(QStringLiteral("CAviones"));

        verticalLayout_2->addWidget(CAviones);

        CEscritorios = new QLineEdit(widget);
        CEscritorios->setObjectName(QStringLiteral("CEscritorios"));

        verticalLayout_2->addWidget(CEscritorios);

        CEstaciones = new QLineEdit(widget);
        CEstaciones->setObjectName(QStringLiteral("CEstaciones"));

        verticalLayout_2->addWidget(CEstaciones);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        BOk = new QPushButton(widget);
        BOk->setObjectName(QStringLiteral("BOk"));

        verticalLayout_3->addWidget(BOk);

        tabWidget->addTab(tab_2, QString());
        Pantalla->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Pantalla);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 775, 22));
        Pantalla->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Pantalla);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Pantalla->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Pantalla);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Pantalla->setStatusBar(statusBar);

        retranslateUi(Pantalla);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Pantalla);
    } // setupUi

    void retranslateUi(QMainWindow *Pantalla)
    {
        Pantalla->setWindowTitle(QApplication::translate("Pantalla", "Pantalla", Q_NULLPTR));
        BTurno->setText(QApplication::translate("Pantalla", "Turno", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Pantalla", "Tab 1", Q_NULLPTR));
        label->setText(QApplication::translate("Pantalla", "N\303\272mero de Aviones", Q_NULLPTR));
        label_2->setText(QApplication::translate("Pantalla", "N\303\272mero de Escritorios", Q_NULLPTR));
        label_3->setText(QApplication::translate("Pantalla", "Numero de Estaciones", Q_NULLPTR));
        BOk->setText(QApplication::translate("Pantalla", "OK", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Pantalla", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Pantalla: public Ui_Pantalla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA_H
