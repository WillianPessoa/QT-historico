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

    for(int i = 0; i < /*subjects->size()*/ 12; i++)
    {
        ui->gradesTable->insertRow(i);
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(subjects[i]);
        ui->gradesTable->setVerticalHeaderItem(i, item);
    }

    connect(ui->exportPushButton, &QPushButton::clicked, this, &MainWindow::exportTranscripts);
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

void MainWindow::generateTree(const Student &student)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, student.name());
    ui->studentsTree->insertTopLevelItem(ui->studentsTree->topLevelItemCount() ,item);
}

void MainWindow::gradesDisplay(const Student &student)
{
    Grades yearGrades[3] ={ student.firstYearGrades(),
                            student.secondYearGrades(),
                            student.thirdYearGrades() };
    unsigned int n = 0;

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].biologyGrade()>=0? QString::number(yearGrades[i].biologyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].physicalEducationGrade()>=0? QString::number(yearGrades[i].physicalEducationGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].philosophyGrade()>=0? QString::number(yearGrades[i].philosophyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].physicsGrade()>=0? QString::number(yearGrades[i].physicsGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].geographyGrade()>=0? QString::number(yearGrades[i].geographyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].historyGrade()>=0? QString::number(yearGrades[i].historyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].englishGrade()>=0? QString::number(yearGrades[i].englishGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].mathGrade()>=0? QString::number(yearGrades[i].mathGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].portugueseGrade()>=0? QString::number(yearGrades[i].portugueseGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].textProductionGrade()>=0? QString::number(yearGrades[i].textProductionGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].chemistryGrade()>=0? QString::number(yearGrades[i].chemistryGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].sociologyGrade()>=0? QString::number(yearGrades[i].sociologyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }
}

QTreeWidget *MainWindow::getTree()
{
    return ui->studentsTree;
}






