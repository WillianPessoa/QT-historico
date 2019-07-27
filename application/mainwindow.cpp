#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_openFolder(QDir::homePath())
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

    //Criar colunas com titulo: 1º ano, 2º ano ...
    ui->gradesTable->setColumnCount(3);
    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();

        item->setText(QString::number(i+1) + "º ano");
        ui->gradesTable->setHorizontalHeaderItem(i, item);
    }

    //Criar linhas com titulos das materias
    for(int i = 0; i < 12; i++)   //subjects->size() = 12
    {
        ui->gradesTable->insertRow(i);
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(subjects.at(i));
        ui->gradesTable->setVerticalHeaderItem(i, item);
    }

    //Bloquear edição de todos os campos do aluno na interface gráfica
    ui->nameLine->setReadOnly(true);
    ui->birthDate->setReadOnly(true);
    ui->nameLine->setReadOnly(true);
    ui->naturalnessLine->setReadOnly(true);
    ui->fatherNameLine->setReadOnly(true);
    ui->motherNameLine->setReadOnly(true);
    ui->issuingInstitutionLine->setReadOnly(true);
    ui->remarksLine->setReadOnly(true);

    ui->gradesTable->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
    ui->gradesTable->setEditTriggers(QTableWidget::EditTrigger::NoEditTriggers);

    connect(ui->exportPushButton, &QPushButton::clicked, this, &MainWindow::exportTranscripts);
    connect(ui->selectFolderAction, &QAction::triggered, this, &MainWindow::selectFolder);
    connect(ui->selectFileAction, &QAction::triggered, this, &MainWindow::selectFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showStudent(const Student &student)
{
    ui->motherNameLine->setText(student.motherName());
    ui->fatherNameLine->setText(student.fatherName());
    ui->birthDate->setDate(student.dateOfBirth());
    ui->naturalnessLine->setText(student.naturalness());
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

QTreeWidget *MainWindow::getTree()
{
    return ui->studentsTree;
}

void MainWindow::selectFolder()
{
    //abrir janela para selecionar pasta
    QString folderName = QFileDialog::getExistingDirectory(this, tr("Open directory"), m_openFolder);

    m_openFolder = folderName;  //Salvando última pasta acessada
    emit folderSelected(folderName);
}

void MainWindow::selectFile()
{
    //open window for select file
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    m_openFolder,
                                                    tr("Excel Files (*.xlsx)"));

    //Salvando última pasta acessada
    QStringList strListFileName = fileName.split("/");
    strListFileName.removeLast();
    m_openFolder = strListFileName.join("/");

    emit fileSelected(fileName);
}

void MainWindow::setDataStudent(Student student)
{
    //Armazenando endereço das grades de cada ano do aluno
    Grades &firstYear = student.getGradesRef("1");
    Grades &secondYear = student.getGradesRef("2");
    Grades &thirdYear = student.getGradesRef("3");

    //Atualizar nome, nome do pai, nome da mãe, data de nascimento, naturalidade
    //Identidade, orgão de expedição, orgão emissor, observações, instituição anterior
    student.setName(ui->nameLine->text());
    student.setFatherName(ui->fatherNameLine->text());
    student.setMotherName(ui->motherNameLine->text());
    student.setDateOfBirth(ui->birthDate->date());
    student.setNaturalness(ui->naturalnessLine->text());
    student.setInstitutionBack(ui->issuingInstitutionLine->text());
    student.setRemarks(ui->remarksLine->text());

    /*Colocar na interface primeiro
    *student.setIDNumber();
    *student.setIDIssueDate();
    *student.setIDIssuingInstitution();
    */

    //Salvar notas
    for(int j = 1; j <= 3; j++)
    {
        for(int i = 1; i <= 12; i++)
        {
            QString value = ui->gradesTable->item(i, j)->text();

            if(value != "Sem nota"){

                //Atualiza notas do primeiro ano
                if(j == 1){
                    if(i == 1){
                        firstYear.setBiologyGrade(value.toDouble());
                    }else if(i == 2){
                        firstYear.setPhysicalEducationGrade(value.toDouble());
                    }else if(i == 3){
                        firstYear.setPhilosophyGrade(value.toDouble());
                    }else if(i == 4){
                        firstYear.setPhysicsGrade(value.toDouble());
                    }else if(i == 5){
                        firstYear.setGeographyGrade(value.toDouble());
                    }else if(i == 6){
                        firstYear.setHistoryGrade(value.toDouble());
                    }else if(i == 7){
                        firstYear.setProjectGrade(value.toDouble());
                    }else if(i == 8){
                        firstYear.setMathGrade(value.toDouble());
                    }else if(i == 9){
                        firstYear.setPortugueseGrade(value.toDouble());
                    }else if(i == 10){
                        firstYear.setTextProductionGrade(value.toDouble());
                    }else if(i == 11){
                        firstYear.setChemistryGrade(value.toDouble());
                    }else if(i == 12){
                        firstYear.setSociologyGrade(value.toDouble());
                    }
                }

                //Atualiza notas do segundo ano
                if(j == 2){
                    if(i == 1){
                        secondYear.setBiologyGrade(value.toDouble());
                    }else if(i == 2){
                        secondYear.setPhysicalEducationGrade(value.toDouble());
                    }else if(i == 3){
                        secondYear.setPhilosophyGrade(value.toDouble());
                    }else if(i == 4){
                        secondYear.setPhysicsGrade(value.toDouble());
                    }else if(i == 5){
                        secondYear.setGeographyGrade(value.toDouble());
                    }else if(i == 6){
                        secondYear.setHistoryGrade(value.toDouble());
                    }else if(i == 7){
                        secondYear.setProjectGrade(value.toDouble());
                    }else if(i == 8){
                        secondYear.setMathGrade(value.toDouble());
                    }else if(i == 9){
                        secondYear.setPortugueseGrade(value.toDouble());
                    }else if(i == 10){
                        secondYear.setTextProductionGrade(value.toDouble());
                    }else if(i == 11){
                        secondYear.setChemistryGrade(value.toDouble());
                    }else if(i == 12){
                        secondYear.setSociologyGrade(value.toDouble());
                    }
                }

                //Atualiza notas do terceiro ano
                if(j == 3){
                    if(i == 1){
                        thirdYear.setBiologyGrade(value.toDouble());
                    }else if(i == 2){
                        thirdYear.setPhysicalEducationGrade(value.toDouble());
                    }else if(i == 3){
                        thirdYear.setPhilosophyGrade(value.toDouble());
                    }else if(i == 4){
                        thirdYear.setPhysicsGrade(value.toDouble());
                    }else if(i == 5){
                        thirdYear.setGeographyGrade(value.toDouble());
                    }else if(i == 6){
                        thirdYear.setHistoryGrade(value.toDouble());
                    }else if(i == 7){
                        thirdYear.setProjectGrade(value.toDouble());
                    }else if(i == 8){
                        thirdYear.setMathGrade(value.toDouble());
                    }else if(i == 9){
                        thirdYear.setPortugueseGrade(value.toDouble());
                    }else if(i == 10){
                        thirdYear.setTextProductionGrade(value.toDouble());
                    }else if(i == 11){
                        thirdYear.setChemistryGrade(value.toDouble());
                    }else if(i == 12){
                        thirdYear.setSociologyGrade(value.toDouble());
                    }
                }
            }
        }
    }
}
