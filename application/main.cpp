#include "mainwindow.h"
#include <QApplication>

#include <QDebug>
#include <Qt>

#include <iostream>

#include "student.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
