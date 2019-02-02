#include "managerstudents.h"

ManagerStudents::ManagerStudents()
{

}

Student ManagerStudents::student(QString name) const
{
    for(int i = 0; i < m_managerStudents.size(); ++i)
    {
        if(m_managerStudents[i].stdDate().studentName() == name)
        {
            return m_managerStudents[i];
        }
    }
}

void ManagerStudents::addStudent(QString studentName, QString fatherName, QString motherName,
                                 QString dateOfBirth, QString naturalness, QString IDNumber,
                                 QString IDissuingInstituation, QString IDissueDate)
{
    m_managerStudents.append(Student(studentName, fatherName, motherName, dateOfBirth,
                                     naturalness, IDNumber, IDissuingInstituation, IDissueDate));
}

void ManagerStudents::addStudent(Student studentObject)
{
    m_managerStudents.append(studentObject);
}
