#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_openFolder(QDir::homePath()),
    m_nameStudentEdit()
{
    QStringList subjects = {"BIOLOGIA",
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

    for(int i = 0; i < 12; i++)
    {
        ui->gradesTable->insertRow(i);
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(subjects.at(i));
        ui->gradesTable->setVerticalHeaderItem(i, item);
    }

    lockUi(true);

    connect(ui->exportPushButton, &QPushButton::clicked, this, &MainWindow::exportTranscripts);
    connect(ui->selectFolderAction, &QAction::triggered, this, &MainWindow::selectFolder);
    connect(ui->selectFileAction, &QAction::triggered, this, &MainWindow::selectFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QTreeWidget *MainWindow::studentsTree()
{
    return ui->studentsTree;
}

QPushButton *MainWindow::editStudentPushButton()
{
    return ui->editStudentPushButton;
}

QPushButton *MainWindow::saveStudentPushButton()
{
    return ui->saveStudentPushButton;
}

void MainWindow::setNameStudent(Student &student, const QString &name)
{
    student.setName(name);
}

QString MainWindow::nameStudentForEdit() const
{
    return m_nameStudentEdit;
}

void MainWindow::setNameStudentForEdit(const QString &nameStudentForEdit)
{
    m_nameStudentEdit = nameStudentForEdit;
}

QString MainWindow::nameLineEditText() const
{
    return ui->nameLine->text();
}

void MainWindow::showStudent(const Student &student)
{
    ui->motherNameLine->setText(student.motherName());
    ui->fatherNameLine->setText(student.fatherName());
    ui->birthDate->setDate(student.dateOfBirth());
    //TODO: Colocar campo para nacionalidade
    ui->naturalnessLine->setText(student.naturalness());
    ui->nameLine->setText(student.name());
    ui->institutionBackLineEdit->setText(student.institutionBack().toUpper());
    ui->remarksLine->setText(student.remarks().toUpper());

    //TODO: Inserir número da identidade, orgão emissor e data de emissão.
}

void MainWindow::generateTree(const Student &student)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, student.name());
    ui->studentsTree->insertTopLevelItem(ui->studentsTree->topLevelItemCount() ,item);
}

void MainWindow::gradesDisplay(const Student &student)
{
    Grades yearGrades[3] = {student.firstYearGrades(),
                            student.secondYearGrades(),
                            student.thirdYearGrades()};
    unsigned int n = 0;

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].biologyGrade() >= 0 ? QString::number(yearGrades[i].biologyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].physicalEducationGrade()>=0? QString::number(yearGrades[i].physicalEducationGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].philosophyGrade()>=0? QString::number(yearGrades[i].philosophyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].physicsGrade()>=0? QString::number(yearGrades[i].physicsGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].geographyGrade()>=0? QString::number(yearGrades[i].geographyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].historyGrade()>=0? QString::number(yearGrades[i].historyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].englishGrade()>=0? QString::number(yearGrades[i].englishGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].mathGrade()>=0? QString::number(yearGrades[i].mathGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].portugueseGrade()>=0? QString::number(yearGrades[i].portugueseGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].textProductionGrade()>=0? QString::number(yearGrades[i].textProductionGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].chemistryGrade()>=0? QString::number(yearGrades[i].chemistryGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText( yearGrades[i].sociologyGrade()>=0? QString::number(yearGrades[i].sociologyGrade()) : "Sem Nota" );
        ui->gradesTable->setItem(n++/3,i,item);
    }
}

void MainWindow::selectFolder()
{
    //abrir janela para selecionar pasta
    QString folderName = QFileDialog::getExistingDirectory(this, tr("Open directory"), m_openFolder);

    if(!folderName.isEmpty())
    {
        m_openFolder = folderName;  //Salvando última pasta acessada
        emit folderSelected(folderName);
    }
}

void MainWindow::selectFile()
{
    //open window for select file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), m_openFolder, tr("Excel Files (*.xlsx)"));

    if(!fileName.isEmpty())
    {
        //Salvando última pasta acessada
        QStringList strListFileName = fileName.split("/");
        strListFileName.removeLast();
        m_openFolder = strListFileName.join("/");

        emit fileSelected(fileName);
    }
}

void MainWindow::lockUi(bool value)
{
    ui->studentsTree->setEnabled(value);
    ui->exportPushButton->setEnabled(value);
    ui->editStudentPushButton->setEnabled(value);
    ui->selectFileAction->setEnabled(value);
    ui->selectFolderAction->setEnabled(value);

    ui->nameLine->setReadOnly(value);
    ui->birthDate->setReadOnly(value);
    ui->nameLine->setReadOnly(value);
    ui->naturalnessLine->setReadOnly(value);
    ui->fatherNameLine->setReadOnly(value);
    ui->motherNameLine->setReadOnly(value);
    ui->institutionBackLineEdit->setReadOnly(value);
    ui->remarksLine->setReadOnly(value);

    //TODO: Bloquear outros campos: Identidade

    if(value){  //Bloqueia tabela com notas
        ui->gradesTable->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        ui->gradesTable->setEditTriggers(QTableWidget::EditTrigger::NoEditTriggers);
    }else{      //Desbloqueia tabela para inserção de notas
        ui->gradesTable->setEditTriggers(QTableWidget::EditTrigger::AllEditTriggers);
    }
}

void MainWindow::editStudent()  //false
{
    if(ui->nameLine->isReadOnly())  //Se pelo menos o nome for somente leitura, então habilite todos os campos de edição
    {
        lockUi(false);
    }
}

void MainWindow::saveStudent(Student &student)
{
    //Atualizar dados pessoais do aluno
    student.setName(ui->nameLine->text().toUpper());
    student.setFatherName(ui->fatherNameLine->text().toUpper());
    student.setMotherName(ui->motherNameLine->text().toUpper());
    student.setDateOfBirth(ui->birthDate->date());
    //TODO: Atualizar nacionalidade
    student.setNaturalness(ui->naturalnessLine->text().toUpper());
    student.setInstitutionBack(ui->institutionBackLineEdit->text());
    student.setRemarks(ui->remarksLine->text());

    /*Colocar na interface primeiro
    *student.setIDNumber();
    *student.setIDIssueDate();
    *student.setIDIssuingInstitution();
    */

    //Salvar notas
    for(int j = 0; j < 3; j++)
    {
        Grades &grade = student.getGradesRef(QString::number(j + 1));

        for(int i = 0; i < 12; i++)
        {
            QString value = ui->gradesTable->item(i, j)->text();

            if(value.toDouble() >= 0 && value.toDouble() <= 40 && !(value == "Sem Nota"))
            {
                if(i == 0){
                    grade.setBiologyGrade(value.toDouble());
                }else if(i == 1){
                    grade.setPhysicalEducationGrade(value.toDouble());
                }else if(i == 2){
                    grade.setPhilosophyGrade(value.toDouble());
                }else if(i == 3){
                    grade.setPhysicsGrade(value.toDouble());
                }else if(i == 4){
                    grade.setGeographyGrade(value.toDouble());
                }else if(i == 5){
                    grade.setHistoryGrade(value.toDouble());
                }else if(i == 6){
                    grade.setEnglishGrade(value.toDouble());
                }else if(i == 7){
                    grade.setMathGrade(value.toDouble());
                }else if(i == 8){
                    grade.setPortugueseGrade(value.toDouble());
                }else if(i == 9){
                    grade.setTextProductionGrade(value.toDouble());
                }else if(i == 10){
                    grade.setChemistryGrade(value.toDouble());
                }else if(i == 11){
                    grade.setSociologyGrade(value.toDouble());
                }
            }
        }
    }lockUi(true);
}
