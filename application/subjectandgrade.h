#ifndef MATTERANDNOTES_H
#define MATTERANDNOTES_H

#include <QString>

class SubjectAndGrade
{
private:
    QString m_subject;
    QString m_grade;

public:
    SubjectAndGrade(QString subject,
                    QString grade);

    //Métodos getters
    QString subject() const;
    QString grade() const;

    //Métodos setters
    void setGrade(const QString &grade);
};

#endif // MATTERANDNOTES_H
