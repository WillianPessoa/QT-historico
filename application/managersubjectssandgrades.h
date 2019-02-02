#ifndef GENERALMATTERSANDNOTES_H
#define GENERALMATTERSANDNOTES_H

#include <subjectandgrade.h>
#include <QList>

class ManagerSubjectsAndGrades
{
private:
    QList<SubjectAndGrade> m_subjectAndGrade;

public:
    ManagerSubjectsAndGrades();

    SubjectAndGrade subjectAndGrade(QString subject) const;
    void addSubjectAndGrade(QString subject, QString grade);
};

#endif // GENERALMATTERSANDNOTES_H
