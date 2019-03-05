#include "transcriptmaker.h"

#include "datapersist.h"
#include "importer.h"
#include "mainwindow.h"

TranscriptMaker::TranscriptMaker(QObject *parent) :
    QObject(parent),
    m_mainWindow()
{

}

void TranscriptMaker::startApp()
{
    m_mainWindow.show();
    tests();
    m_mainWindow.showStudent(m_studentManger.students().first());

    for(auto student : m_studentManger.students())
        m_mainWindow.generateTree(student);

    m_mainWindow.gradesDisplay(m_studentManger.students().first());
}

void TranscriptMaker::initUi()
{

}

void TranscriptMaker::makeConnections()
{

}

void TranscriptMaker::tests()
{
    QList<IndividualSheet> studentsSheet = Importer::importStudentsFrom(":/samples");

    for (const IndividualSheet &indSheet : studentsSheet) {
        m_studentManger.insertStudentData(indSheet);
    }

    DataPersist::saveData(m_studentManger.students());
}


