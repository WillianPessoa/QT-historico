#include "managersubjectssandgrades.h"

ManagerSubjectsAndGrades::ManagerSubjectsAndGrades()
{

}

void ManagerSubjectsAndGrades::addSubjectAndGrade(QString subject, QString grade)
{
    m_subjectAndGrade.append(SubjectAndGrade(subject, grade));
}

SubjectAndGrade ManagerSubjectsAndGrades::subjectAndGrade(QString subject) const
{
    for(int i = 0; i < m_subjectAndGrade.size(); ++i)
    {
        if(m_subjectAndGrade[i].subject() == subject)
        {
            return m_subjectAndGrade[i];
        }
    }
}
