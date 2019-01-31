#ifndef MATTERANDNOTES_H
#define MATTERANDNOTES_H

#include <QString>

class MatterAndNote
{
private:
    QString m_matter;
    QString m_note;

public:
    MatterAndNote(QString matter,
                  QString note);

    //Métodos getters
    QString getMatter();
    QString getNote();

    //Métodos setters
    void setNote(QString note);
};

#endif // MATTERANDNOTES_H
