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

QPushButton *MainWindow::getEditStudentButton()
{
    return ui->editStudentPushButton;
}

QPushButton *MainWindow::getSaveStudentButton()
{
    return ui->saveStudentPushButton;
}

bool MainWindow::nameLineIsReadOnly()
{
    return ui->nameLine->isReadOnly();
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
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    m_openFolder,
                                                    tr("Excel Files (*.xlsx)"));

    if(!fileName.isEmpty())
    {
        //Salvando última pasta acessada
        QStringList strListFileName = fileName.split("/");
        strListFileName.removeLast();
        m_openFolder = strListFileName.join("/");

        emit fileSelected(fileName);
    }
}

void MainWindow::editStudent()
{
    //Se pelo menos o nome for somente leitura, então habilite todos os campos de edição
    if(ui->nameLine->isReadOnly())
    {
        //Bloquear árvore de estudantes e botão de exportar
        ui->studentsTree->setEnabled(false);
        ui->exportPushButton->setEnabled(false);

        //Desbloquear campos para a edição do estudante
        ui->nameLine->setReadOnly(false);
        ui->birthDate->setReadOnly(false);
        ui->nameLine->setReadOnly(false);
        ui->naturalnessLine->setReadOnly(false);
        ui->fatherNameLine->setReadOnly(false);
        ui->motherNameLine->setReadOnly(false);
        ui->issuingInstitutionLine->setReadOnly(false);
        ui->remarksLine->setReadOnly(false);

        //Desbloquear campos para colocar notas
        ui->gradesTable->setEditTriggers(QTableWidget::EditTrigger::AllEditTriggers);
    }
}

void MainWindow::saveStudent(Student &student)
{
    //Armazenando endereço das grades de cada ano do aluno
    Grades &firstYear = student.getGradesRef("1");
    Grades &secondYear = student.getGradesRef("2");
    Grades &thirdYear = student.getGradesRef("3");

    //Atualizar dados pessoais do aluno
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
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 12; i++)
        {
            QString value = ui->gradesTable->item(i, j)->text();

            if(value != "Sem nota"){

                //Atualiza notas do primeiro ano
                if(j == 0){
                    if(i == 0){
                        firstYear.setBiologyGrade(value.toDouble());
                    }else if(i == 1){
                        firstYear.setPhysicalEducationGrade(value.toDouble());
                    }else if(i == 2){
                        firstYear.setPhilosophyGrade(value.toDouble());
                    }else if(i == 3){
                        firstYear.setPhysicsGrade(value.toDouble());
                    }else if(i == 4){
                        firstYear.setGeographyGrade(value.toDouble());
                    }else if(i == 5){
                        firstYear.setHistoryGrade(value.toDouble());
                    }else if(i == 6){
                        firstYear.setProjectGrade(value.toDouble());
                    }else if(i == 7){
                        firstYear.setMathGrade(value.toDouble());
                    }else if(i == 8){
                        firstYear.setPortugueseGrade(value.toDouble());
                    }else if(i == 9){
                        firstYear.setTextProductionGrade(value.toDouble());
                    }else if(i == 10){
                        firstYear.setChemistryGrade(value.toDouble());
                    }else if(i == 11){
                        firstYear.setSociologyGrade(value.toDouble());
                    }
                }

                //Atualiza notas do segundo ano
                if(j == 1){
                    if(i == 0){
                        secondYear.setBiologyGrade(value.toDouble());
                    }else if(i == 1){
                        secondYear.setPhysicalEducationGrade(value.toDouble());
                    }else if(i == 2){
                        secondYear.setPhilosophyGrade(value.toDouble());
                    }else if(i == 3){
                        secondYear.setPhysicsGrade(value.toDouble());
                    }else if(i == 4){
                        secondYear.setGeographyGrade(value.toDouble());
                    }else if(i == 5){
                        secondYear.setHistoryGrade(value.toDouble());
                    }else if(i == 6){
                        secondYear.setProjectGrade(value.toDouble());
                    }else if(i == 7){
                        secondYear.setMathGrade(value.toDouble());
                    }else if(i == 8){
                        secondYear.setPortugueseGrade(value.toDouble());
                    }else if(i == 9){
                        secondYear.setTextProductionGrade(value.toDouble());
                    }else if(i == 10){
                        secondYear.setChemistryGrade(value.toDouble());
                    }else if(i == 11){
                        secondYear.setSociologyGrade(value.toDouble());
                    }
                }

                //Atualiza notas do terceiro ano
                if(j == 2){
                    if(i == 0){
                        thirdYear.setBiologyGrade(value.toDouble());
                    }else if(i == 1){
                        thirdYear.setPhysicalEducationGrade(value.toDouble());
                    }else if(i == 2){
                        thirdYear.setPhilosophyGrade(value.toDouble());
                    }else if(i == 3){
                        thirdYear.setPhysicsGrade(value.toDouble());
                    }else if(i == 4){
                        thirdYear.setGeographyGrade(value.toDouble());
                    }else if(i == 5){
                        thirdYear.setHistoryGrade(value.toDouble());
                    }else if(i == 6){
                        thirdYear.setProjectGrade(value.toDouble());
                    }else if(i == 7){
                        thirdYear.setMathGrade(value.toDouble());
                    }else if(i == 8){
                        thirdYear.setPortugueseGrade(value.toDouble());
                    }else if(i == 9){
                        thirdYear.setTextProductionGrade(value.toDouble());
                    }else if(i == 10){
                        thirdYear.setChemistryGrade(value.toDouble());
                    }else if(i == 11){
                        thirdYear.setSociologyGrade(value.toDouble());
                    }
                }
            }
        }
    }

    //Habilitar árvore de estudantes e botão de exportar históricos
    ui->studentsTree->setEnabled(true);
    ui->exportPushButton->setEnabled(true);

    //Bloquear campos de edição
    ui->nameLine->setReadOnly(true);
    ui->birthDate->setReadOnly(true);
    ui->nameLine->setReadOnly(true);
    ui->naturalnessLine->setReadOnly(true);
    ui->fatherNameLine->setReadOnly(true);
    ui->motherNameLine->setReadOnly(true);
    ui->issuingInstitutionLine->setReadOnly(true);
    ui->remarksLine->setReadOnly(true);

    //Bloquear tabelas de notas
    ui->gradesTable->setEditTriggers(QTableWidget::EditTrigger::NoEditTriggers);
}

QString MainWindow::nameStudentEdit() const
{
    return m_nameStudentEdit;
}

void MainWindow::setNameStudentEdit(const QString &nameStudentEdit)
{
    m_nameStudentEdit = nameStudentEdit;
}
