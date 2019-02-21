#include "transcriptmaker.h"

#include "importer.h"
#include "mainwindow.h"

TranscriptMaker::TranscriptMaker(QObject *parent) :
    QObject(parent),
    m_mainWindow()
{

}

void TranscriptMaker::startApp()
{
    tests();
    m_mainWindow.show();
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
}


