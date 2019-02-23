#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString subjects[] = {"BIOLOGIA",
                         "EDUCAÇÃO FÍSICA",
                         "FILOSOFIA",
                         "FÍSICA",
                         "GEOGRAFIA",
                         "HISTÓRIA",
                         "LÍNGUA ESTRANGEIRA - INGLÊS",
                         "MATEMÁTICA",
                         "LÍNGUA PORTUGUESA/LITERATURA",
                         "PRODUÇÃO TEXTUAL",
                         "QUÍMICA",
                         "SOCIOLOGIA"};

    ui->setupUi(this);

    ui->gradesTable->setColumnCount(3);
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();

        item->setText(QString::number(i+1) + "º ano");
        ui->gradesTable->setHorizontalHeaderItem(i, item);
    }

    for(int i = 0; i <= subjects->size(); i++)
    {
        ui->gradesTable->insertRow(i);
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(subjects[i]);
        ui->gradesTable->setVerticalHeaderItem(i, item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showStudent(const Student &student)
{
    ui->motherLine->setText(student.motherName());
    ui->fatherLine->setText(student.fatherName());
    ui->birthDate->setDate(student.dateOfBirth());
    ui->nationalityLine->setText(student.naturalness());
    ui->nameLine->setText(student.name());
    ui->issuingInstitutionLine->setText(student.IDIssuingInstitution()); // INSERIR BUSCA POR ÓRGAO EMISSOR
}
