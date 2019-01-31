#include "matterandnotes.h"

MatterAndNote::MatterAndNote(QString matter,
                             QString note)
{
    m_matter = matter;
    m_note = note;
}

//Métodos getters
QString MatterAndNote::getMatter()
{
    return m_matter;
}

QString MatterAndNote::getNote()
{
    return m_note;
}

//Métodos setters
void MatterAndNote::setNote(QString note)
{
    m_note = note;
}
