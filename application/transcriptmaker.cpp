#include "transcriptmaker.h"

#include "datapersist.h"
#include "importer.h"
#include "mainwindow.h"
#include "exporter.h"

#include <QMessageBox>
#include <QPushButton>

TranscriptMaker::TranscriptMaker(QObject *parent) :
    QObject(parent),
    m_mainWindow(),
    m_index(0)
{
    connect(this->m_mainWindow.getTree(), &QTreeWidget::itemClicked,
            this, &TranscriptMaker::displayStudent);
}

void TranscriptMaker::startApp()
{
    makeConnections();
    initUi();
    m_studentManager.insertStudents(DataPersist::loadData());
    populateTree();
}

void TranscriptMaker::initUi()
{
    m_mainWindow.showMaximized();
}

void TranscriptMaker::makeConnections()
{
    //Importação dos dados de uma pasta
    connect(&m_mainWindow, &MainWindow::folderSelected, [this] (QString folderName)
    {
        QList<IndividualSheet> studentsSheet = Importer::importStudentsFrom(folderName);
        for (const IndividualSheet &indSheet : studentsSheet)
        {
            m_studentManager.insertStudentData(indSheet);
        }
        populateTree();
    });

    //Importação dos dados de um arquivo
    connect(&m_mainWindow, &MainWindow::fileSelected, [this] (QString fileName)
    {
        IndividualSheet studentSheet = Reader::getStudentsDataFrom(fileName);
        m_studentManager.insertStudentData(studentSheet);
        populateTree();
    });

    //Edição de estudantes
    connect(this->m_mainWindow.getEditStudentButton(), &QPushButton::clicked, [this] ()
    {
        if(!(this->m_mainWindow.nameLineEditText() == "")){
            this->m_mainWindow.editStudent();
        }else{
            QMessageBox::about(&m_mainWindow, "Erro", "Não há informações de alunos \n      para serem editadas!");
        }
    });

    //Salvar dados editados do estudante
    connect(this->m_mainWindow.getSaveStudentButton(), &QPushButton::clicked, [this] ()
    {
        if(!(this->m_mainWindow.nameLineEditText() == ""))
        {
            for(int i = 0; i < this->m_studentManager.students().size(); i++)
            {
                if(this->m_studentManager.students().at(i).name() == this->m_mainWindow.nameStudentForEdit())
                {
                    Student student = this->m_studentManager.students().at(i);
                    this->m_mainWindow.saveStudent(student);
                    this->m_studentManager.replaceStudent(i, student);
                    m_index = 0;
                    this->m_mainWindow.getTree()->clear();
                    populateTree();
                }
            }

            qDebug() << "Nomes dos estudantes: ";
            for(int i = 0; i < this->m_studentManager.students().size(); i++)
            {
                qDebug() << "\t" << this->m_studentManager.students().at(i).name();
            }

        }else{
            QMessageBox::about(&m_mainWindow, "Erro", "Não há alunos para salvar informações!");
        }
    });

    // Exportar e Salvar dados
    connect(&m_mainWindow, &MainWindow::exportTranscripts, [this] ()
    {
        if(this->m_mainWindow.getTree()->topLevelItemCount() > 0){
            Exporter::exportHistoric(m_studentManager.students(), QDir::home());
            DataPersist::saveData(m_studentManager.students());
            QMessageBox::about(&m_mainWindow, "Históricos exportados", "Os históricos foram exportados para o diretório " + QDir::homePath());
        }else{
            QMessageBox::about(&m_mainWindow, "Erro", "Não há alunos para criação de históricos!");
        }
    });
}

void TranscriptMaker::tests()
{
    QList<IndividualSheet> studentsSheet = Importer::importStudentsFrom(":/samples");

    for (const IndividualSheet &indSheet : studentsSheet) {
        m_studentManager.insertStudentData(indSheet);
    }
    Exporter::exportHistoric(m_studentManager.students());

    DataPersist::saveData(m_studentManager.students());
}

void TranscriptMaker::populateTree()
{
    int index = 0;
    int sizeStudents = m_studentManager.students().size();

    for(index = m_index; index < sizeStudents; index++)
    {
        QString itemName = m_studentManager.students().at(index).name().toUpper();
        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setText(0, itemName);
        this->m_mainWindow.getTree()->insertTopLevelItem(index, item);
    }
    m_index = index;
}

void TranscriptMaker::displayStudent(QTreeWidgetItem *item, int column)
{
    for(Student st : this->m_studentManager.students())
        if(st.name() == item->text(column))
        {
            m_mainWindow.setNameStudentEdit(st.name());
            this->m_mainWindow.showStudent(st);
            this->m_mainWindow.gradesDisplay(st);
        }
}
