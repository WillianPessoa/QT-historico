#include "subjectandgrade.h"

SubjectAndGrade::SubjectAndGrade(QString subject, double grade)
{
    m_subject = subject;
    m_grade = grade;
}

QString SubjectAndGrade::subject() const
{
    return m_subject;
}

void SubjectAndGrade::setSubject(const QString &subject)
{
    m_subject = subject;
}

double SubjectAndGrade::grade() const
{
    return m_grade;
}

void SubjectAndGrade::setGrade(const double &grade)
{
    m_grade = grade;
}
