#include "transcriptmaker.h"

#include "datapersist.h"
#include "importer.h"
#include "mainwindow.h"
#include "exporter.h"


TranscriptMaker::TranscriptMaker(QObject *parent) :
    QObject(parent),
    m_mainWindow()
{
    connect(this->m_mainWindow.getTree(), &QTreeWidget::itemClicked,
            this, &TranscriptMaker::displayStudent);
}

void TranscriptMaker::startApp()
{
    tests();
    m_mainWindow.show();
    populateTree();
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
