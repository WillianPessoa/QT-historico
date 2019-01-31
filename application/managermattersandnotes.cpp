#include "managermattersandnotes.h"

ManagerMattersAndNotes::ManagerMattersAndNotes()
{

}

void ManagerMattersAndNotes::addMatterAndNote(QString matter, QString note)
{
    m_MattersAndNotes.append(MatterAndNote(matter, note));
}

MatterAndNote ManagerMattersAndNotes::getMatterAndNote(QString matter)
{
    for(int i = 0; i < m_MattersAndNotes.size(); ++i)
    {
        if(m_MattersAndNotes[i].getMatter() == matter)
        {
            return m_MattersAndNotes[i];
        }
    }
}
