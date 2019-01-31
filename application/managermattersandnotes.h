#ifndef GENERALMATTERSANDNOTES_H
#define GENERALMATTERSANDNOTES_H

#include <matterandnotes.h>
#include <QList>

class ManagerMattersAndNotes
{
private:
    QList<MatterAndNote> m_MattersAndNotes;

public:
    ManagerMattersAndNotes();

    //Métodos
    MatterAndNote getMatterAndNote(QString matter);
    void addMatterAndNote(QString matter, QString note);
};

#endif // GENERALMATTERSANDNOTES_H
