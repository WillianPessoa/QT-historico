#include "subjectandgrade.h"

SubjectAndGrade::SubjectAndGrade(QString subject, QString grade)
{
    m_subject = subject;
    m_grade = grade;
}

//Métodos getters
QString SubjectAndGrade::subject() const
{
    return m_subject;
}

QString SubjectAndGrade::grade() const
{
    return m_grade;
}

//Métodos setters
void SubjectAndGrade::setGrade(const QString &grade)
{
    m_grade = grade;
}
