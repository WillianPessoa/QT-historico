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
    //Informações Básicas
    ui->motherNameLine->setText(student.motherName());
    ui->fatherNameLine->setText(student.fatherName());
    ui->birthDate->setDate(student.dateOfBirth());
    ui->nacionalityLineEdit->setText(student.nationality());
    ui->naturalnessLine->setText(student.naturalness());
    ui->nameLine->setText(student.name());
    ui->institutionBackLineEdit->setText(student.institutionBack().toUpper());
    ui->remarksLine->setText(student.remarks().toUpper());

    //Identidade
    ui->numberIDLineEdit->setText(student.IDNumber());
    ui->issuingInstituitionLineEdit->setText(student.IDIssuingInstitution());
    ui->issuingDateLineEdit->setDate(QDate::fromString(student.IDIssueDate(), "dd/MM/yyyy"));

    //Estabelecimentos de ensino
    ui->firstYearEstablishLineEdit->setText(student.firstYearEducationalEstablishment());
    ui->secondYearEstablishLineEdit->setText(student.secondYearEducationalEstablishment());
    ui->thirdYearEstablishLineEdit->setText(student.thirdYearEducationalEstablishment());

    //Estados/Municipios de ensino
    ui->firstStateLineEdit->setText(student.firstYearState());
    ui->secondStateLineEdit->setText(student.secondYearState());
    ui->thirdStateLineEdit->setText(student.thirdYearState());

    //Frequêcias anuais
    ui->firstYearFrequencyLineEdit->setText(int(student.firstYearFrequency()) == 0 ? "" : QString::number(student.firstYearFrequency()));
    ui->secondYearFrequencyLineEdit->setText(int(student.secondYearFrequency()) == 0 ? "" : QString::number(student.secondYearFrequency()));
    ui->thirdYearFrequencyLineEdit->setText(int(student.thirdYearFrequency()) == 0 ? "" : QString::number(student.thirdYearFrequency()));

    //Anos de conclusão
    ui->firstYearConclusionLineEdit->setText(student.firstYearConclusion() == 0 ? "" : QString::number(student.firstYearConclusion()));
    ui->secondYearConclusionLineEdit->setText(student.secondYearConclusion() == 0 ? "" : QString::number(student.secondYearConclusion()));
    ui->thirdYearConclusionLineEdit->setText(student.thirdYearConclusion() == 0 ? "" : QString::number(student.thirdYearConclusion()));
}

void MainWindow::generateTree(const Student &student)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, student.name());
    ui->studentsTree->insertTopLevelItem(ui->studentsTree->topLevelItemCount() ,item);
}

void MainWindow::gradesDisplay(const Student &student)
{
    for(int i = 0; i < 3; i++)
    {
        double grade;
        Grades yearGrade = student.getGrades(QString::number(i + 1));

        qDebug() << "\nExibindo notas " << i + 1 << "º ano do aluno na interface gráfica ..." << endl;
        for(int j = 0; j < 12; j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            if(j == 0){
                grade = yearGrade.biologyGrade();
                item->setText(grade >= 0 && grade <= 40 ? QString::number(grade) : "");
                qDebug() << "BIOLOGIA: " << grade;
            }else if(j == 1){
                grade = yearGrade.physicalEducationGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "EDUCAÇÃO FÍSICA: " << grade;
            }else if(j == 2){
                grade = yearGrade.philosophyGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "FILOSOFIA: " << grade;
            }else if(j == 3){
                grade = yearGrade.physicsGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "FÍSICA: " << grade;
            }else if(j == 4){
                grade = yearGrade.geographyGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "GEOGRAFIA: " << grade;
            }else if(j == 5){
                grade = yearGrade.historyGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "HISTÓRIA: " << grade;
            }else if(j == 6){
                grade = yearGrade.englishGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "INGLÊS: " << grade;
            }else if(j == 7){
                grade = yearGrade.mathGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "MATEMÁTICA: " << grade;
            }else if(j == 8){
                grade = yearGrade.portugueseGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "PORTUGUÊS: " << grade;
            }else if(j == 9){
                grade = yearGrade.textProductionGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "PRODUÇÃO DE TEXTO: " << grade;
            }else if(j == 10){
                grade = yearGrade.chemistryGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "QUÍMICA: " << grade;
            }else if(j == 11){
                grade = yearGrade.sociologyGrade();
                item->setText((grade >= 0 && grade <= 40) ? QString::number(grade) : "");
                qDebug() << "SOCIOLOGIA: " << grade;
            }
            ui->gradesTable->setItem(j, i, item);
        }
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), m_openFolder, tr("Excel Files (*.xlsx *.xls)"));

    if(!fileName.isEmpty())
    {
        //Salvando última pasta acessada
        QStringList strListFileName = fileName.split("/");
        strListFileName.removeLast();
        m_openFolder = strListFileName.join("/");

        emit fileSelected(fileName);
    }
}

void MainWindow::lockUi(const bool value)
{
    ui->studentsTree->setEnabled(value);
    ui->exportPushButton->setEnabled(value);
    ui->editStudentPushButton->setEnabled(value);
    ui->selectFileAction->setEnabled(value);
    ui->selectFolderAction->setEnabled(value);

    //Informações Básicas
    ui->nameLine->setReadOnly(value);
    ui->birthDate->setReadOnly(value);
    ui->nameLine->setReadOnly(value);
    ui->nacionalityLineEdit->setReadOnly(value);
    ui->naturalnessLine->setReadOnly(value);
    ui->fatherNameLine->setReadOnly(value);
    ui->motherNameLine->setReadOnly(value);
    ui->institutionBackLineEdit->setReadOnly(value);
    ui->remarksLine->setReadOnly(value);

    //Identidade
    ui->numberIDLineEdit->setReadOnly(value);
    ui->issuingInstituitionLineEdit->setReadOnly(value);
    ui->issuingDateLineEdit->setReadOnly(value);

    //Estabelecimento de ensino
    ui->firstYearEstablishLineEdit->setReadOnly(value);
    ui->secondYearEstablishLineEdit->setReadOnly(value);
    ui->thirdYearEstablishLineEdit->setReadOnly(value);

    //Estado de cada série
    ui->firstStateLineEdit->setReadOnly(value);
    ui->secondStateLineEdit->setReadOnly(value);
    ui->thirdStateLineEdit->setReadOnly(value);

    //Frequência de cada série
    ui->firstYearFrequencyLineEdit->setReadOnly(value);
    ui->secondYearFrequencyLineEdit->setReadOnly(value);
    ui->thirdYearFrequencyLineEdit->setReadOnly(value);

    //Ano de conclusão de cada série
    ui->firstYearConclusionLineEdit->setReadOnly(value);
    ui->secondYearConclusionLineEdit->setReadOnly(value);
    ui->thirdYearConclusionLineEdit->setReadOnly(value);

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

    qDebug() << "Salvando dados do aluno ... " << endl;

    const QString name = ui->nameLine->text().toUpper();
    student.setName(name);
    qDebug() << "Nome: " << name;

    const QString fatherName = ui->fatherNameLine->text().toUpper();
    student.setFatherName(fatherName);
    qDebug() << "Nome do pai: " << fatherName;

    const QString motherName = ui->motherNameLine->text().toUpper();
    student.setMotherName(motherName);
    qDebug() << "Nome da mãe: " << motherName;

    const QDate dateOfBirth = ui->birthDate->date();
    student.setDateOfBirth(dateOfBirth);
    qDebug() << "Data de nascimento: " << dateOfBirth.toString("dd/MM/yyyy");

    const QString nationality = ui->nacionalityLineEdit->text().toUpper();
    student.setNationality(nationality);
    qDebug() << "Nacionalidade: " << nationality;

    const QString naturalness = ui->naturalnessLine->text().toUpper();
    student.setNaturalness(naturalness);
    qDebug() << "Naturalidade: " << naturalness;

    const QString instituitionBack = ui->institutionBackLineEdit->text();
    student.setInstitutionBack(instituitionBack);
    qDebug() << "Instituiação anterior: " << instituitionBack;

    const QString remarks = ui->remarksLine->text();
    student.setRemarks(remarks);
    qDebug() << "Observações: " << remarks;

    const QString IDNumber = ui->numberIDLineEdit->text();
    student.setIDNumber(IDNumber);
    qDebug() << "Número da identidade: " << IDNumber;

    const QString IDIssueDate = ui->issuingDateLineEdit->date().toString("dd/MM/yyyy");
    student.setIDIssueDate(IDIssueDate);
    qDebug() << "Data de expedição: " << IDIssueDate;

    const QString IDIssuingInstituition = ui->issuingInstituitionLineEdit->text().toUpper();
    student.setIDIssuingInstitution(IDIssuingInstituition);
    qDebug() << "Orgão emissor: " << IDIssuingInstituition;

    const QString firstEducationalEstablishment = ui->firstYearEstablishLineEdit->text().toUpper();
    student.setFirstYearEducationalEstablishment(firstEducationalEstablishment);
    qDebug() << "Estabelecimento de Ensino (1º ano): " << firstEducationalEstablishment;

    const QString secondEducationalEstablishment = ui->secondYearEstablishLineEdit->text().toUpper();
    student.setSecondYearEducationalEstablishment(secondEducationalEstablishment);
    qDebug() << "Estabelecimento de Ensino (2º ano): " << secondEducationalEstablishment;

    const QString thirdEducationalEstablishment = ui->thirdYearEstablishLineEdit->text().toUpper();
    student.setThirdYearEducationalEstablishment(thirdEducationalEstablishment);
    qDebug() << "Estabelecimento de Ensino (3º ano): " << thirdEducationalEstablishment;

    const QString firstYearState = ui->firstStateLineEdit->text().toUpper();
    student.setFirstYearState(firstYearState);
    qDebug() << "Estado/Municipio (1º ano): " << firstYearState;

    const QString secondYearState = ui->secondStateLineEdit->text().toUpper();
    student.setSecondYearState(secondYearState);
    qDebug() << "Estado/Municipio (2º ano): " << secondYearState;

    const QString thirdYearState = ui->thirdStateLineEdit->text().toUpper();
    student.setThirdYearState(thirdYearState);
    qDebug() << "Estado/Municipio (3º ano): " << thirdYearState;

    const double firstYearFrequency = ui->firstYearFrequencyLineEdit->text().toDouble();
    student.setFirstYearFrequency(firstYearFrequency);
    qDebug() << "Frequência (1º ano): " << firstYearFrequency;

    const double secondYearFrequency = ui->secondYearFrequencyLineEdit->text().toDouble();
    student.setSecondYearFrequency(secondYearFrequency);
    qDebug() << "Frequência (2º ano): " << secondYearFrequency;

    const double thirdYearFrequency = ui->thirdYearFrequencyLineEdit->text().toDouble();
    student.setThirdYearFrequency(thirdYearFrequency);
    qDebug() << "Frequência (3º ano): " << thirdYearFrequency;

    const int firstYearConclusion = ui->firstYearConclusionLineEdit->text().toInt();
    student.setFirstYearConclusion(firstYearConclusion);
    qDebug() << "Ano de conclusão (1º ano): " << firstYearConclusion;

    const int secondYearConclusion = ui->secondYearConclusionLineEdit->text().toInt();
    student.setSecondYearConclusion(secondYearConclusion);
    qDebug() << "Ano de conclusão (2º ano): " << secondYearConclusion;

    const int thirdYearConclusion = ui->thirdYearConclusionLineEdit->text().toInt();
    student.setThirdYearConclusion(thirdYearConclusion);
    qDebug() << "Ano de conclusão (3º ano): " << thirdYearConclusion;

    for(int j = 0; j < 3; j++)
    {
        qDebug() << "\nSalvando notas do " << j + 1 << " ano ..." << endl;

        Grades &grade = student.getGradesRef(QString::number(j + 1));
        for(int i = 0; i < 12; i++)
        {
            QString noteText = ui->gradesTable->item(i, j)->text();

            //Primeira verificação de validade
            bool noteIsDouble;
            double note = noteText.toDouble(&noteIsDouble);

            //Segunda verificação de validade
            if(noteText.count(",") == 1){
                note = noteText.replace("," , ".").toDouble();
                noteIsDouble = true;
            }

            if(noteIsDouble && (note >= 0 && note <= 40))
            {
                if(i == 0){
                    grade.setBiologyGrade(note);
                    qDebug() << "BIOLOGIA: " << note;
                }else if(i == 1){
                    grade.setPhysicalEducationGrade(note);
                    qDebug() << "EDUCAÇÃO FÍSICA: " << note;
                }else if(i == 2){
                    grade.setPhilosophyGrade(note);
                    qDebug() << "FILOSOFIA: " << note;
                }else if(i == 3){
                    grade.setPhysicsGrade(note);
                    qDebug() << "FÍSICA: " << note;
                }else if(i == 4){
                    grade.setGeographyGrade(note);
                    qDebug() << "GEOGRAFIA: " << note;
                }else if(i == 5){
                    grade.setHistoryGrade(note);
                    qDebug() << "HISTÓRIA: " << note;
                }else if(i == 6){
                    grade.setEnglishGrade(note);
                    qDebug() << "INGLÊS: " << note;
                }else if(i == 7){
                    grade.setMathGrade(note);
                    qDebug() << "MATEMÁTICA: " << note;
                }else if(i == 8){
                    grade.setPortugueseGrade(note);
                    qDebug() << "PORTUGUÊS: " << note;
                }else if(i == 9){
                    grade.setTextProductionGrade(note);
                    qDebug() << "PRODUÇÃO DE TEXTO: " << note;
                }else if(i == 10){
                    grade.setChemistryGrade(note);
                    qDebug() << "QUÍMICA: " << note;
                }else if(i == 11){
                    grade.setSociologyGrade(note);
                    qDebug() << "SOCIOLOGIA: " << note;
                }
            }
        }
    }lockUi(true);
}
