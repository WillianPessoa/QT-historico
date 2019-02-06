#include "mainwindow.h"
#include <QApplication>

#include "student.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Student *felipe = new Student();
    felipe->firstYearGrades().setArtGrade(10);

    qDebug() << felipe->firstYearGrades().artGrade();

    return a.exec();
}
