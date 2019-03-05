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

    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText("dsafasdf");
    ui->gradesTable->setItem(2,2,item);

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

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(yearGrades[i].biologyGrade()) );
        ui->gradesTable->setItem(0,i,item);
    }
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(yearGrades[i].physicalEducationGrade()));
        ui->gradesTable->setItem(1,i,item);
    }
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(yearGrades[i].philosophyGrade()));
        ui->gradesTable->setItem(2,i,item);
    }
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(yearGrades[i].physicsGrade()));
        ui->gradesTable->setItem(3,i,item);
    }
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(yearGrades[i].geographyGrade()));
        ui->gradesTable->setItem(4,i,item);
    }
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(yearGrades[i].historyGrade()));
        ui->gradesTable->setItem(5,i,item);
    }
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(yearGrades[i].englishGrade()));
        ui->gradesTable->setItem(6,i,item);
    }
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(yearGrades[i].mathGrade()));
        ui->gradesTable->setItem(7,i,item);
    }
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(yearGrades[i].portugueseGrade() ));
        ui->gradesTable->setItem(8,i,item);
    }

//    portugueseGrade()
//    artGrade()physicalEducationGrade()
//    mathGrade()chemistryGrade()
//    physicsGrade()
//    biologyGrade()
//    historyGrade()
//    geographyGrade()
//    sociologyGrade()
//    philosophyGrade()
//    englishGrade()
//    religiousGrade()
//    projectGrade()
//    mathProblemSolvingGrade()
//    textProductionGrade()


}






