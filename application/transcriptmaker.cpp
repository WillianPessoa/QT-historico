#include "transcriptmaker.h"

#include "mainwindow.h"

TranscriptMaker::TranscriptMaker(QObject *parent) :
    QObject(parent),
    m_mainWindow(new MainWindow())
{

}

void TranscriptMaker::startApp()
{
    m_mainWindow->show();
}

void TranscriptMaker::initUi()
{

}

void TranscriptMaker::makeConnections()
{

}


