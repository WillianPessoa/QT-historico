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

    felipe->firstYearGrades().setMathGrade(10);
    qDebug() << felipe->firstYearGrades().mathGrade();

    return a.exec();
}
