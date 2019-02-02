#include "student.h"

Student::Student(QString studentName, QString fatherName, QString motherName,
                 QString dateOfBirth, QString naturalness, QString IDNumber,
                 QString IDissuingInstituation, QString IDissueDate)
{
    m_stdDate = new StandartDate(studentName, fatherName, motherName, dateOfBirth,
                                 naturalness, IDNumber, IDissuingInstituation, IDissueDate);
    m_managerSubjectsAndGrades = new ManagerSubjectsAndGrades();
}

StandartDate Student::stdDate() const
{
    return *m_stdDate;
}

ManagerSubjectsAndGrades Student::managerSubjectsAndGrades() const
{
    return *m_managerSubjectsAndGrades;
}
