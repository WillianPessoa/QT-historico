#ifndef STUDENT_H
#define STUDENT_H


#include <QDate>
#include <QString>

class Student
{
public:
    Student();

private:
    QString m_name;
    QDate m_dateOfBirth;
    QString m_fatherName;
    QString m_motherName;
    QString m_naturalness;
    QString m_IDNumber;
    QString m_IDissuingInstituation;
    QString m_IDissueDate;
};

#endif // STUDENT_H
