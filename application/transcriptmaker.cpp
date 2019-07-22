#include "transcriptmaker.h"

#include "datapersist.h"
#include "importer.h"
#include "mainwindow.h"
#include "exporter.h"

#include <QMessageBox>


TranscriptMaker::TranscriptMaker(QObject *parent) :
    QObject(parent),
    m_mainWindow()
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

    // Exportar e Salvar dados
    connect(&m_mainWindow, &MainWindow::exportTranscripts, [this] () {
        Exporter::exportHistoric(m_studentManager.students(), QDir::home());
        DataPersist::saveData(m_studentManager.students());
        QMessageBox::about(&m_mainWindow, "Históricos exportados", "Os históricos foram exportados para o diretório " + QDir::homePath());
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
    for(Student st : this->m_studentManager.students())
    {
        QString itemName = st.name();
        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setText(0, itemName);
        this->m_mainWindow.getTree()->insertTopLevelItem(index++, item);
    }
}

void TranscriptMaker::displayStudent(QTreeWidgetItem *item, int column)
{
    for(Student st : this->m_studentManager.students())
        if(st.name() == item->text(column))
        {
            this->m_mainWindow.showStudent(st);
            this->m_mainWindow.gradesDisplay(st);
        }
}
