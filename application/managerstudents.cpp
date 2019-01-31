#include "managerstudents.h"

ManagerStudents::ManagerStudents()
{

}

Student ManagerStudents::getStudent(QString name)
{
    for(int i = 0; i < m_managerStudents.size(); ++i)
    {
        if(m_managerStudents[i].getStdDate().getName() == name)
        {
            return m_managerStudents[i];
        }
    }
}

void ManagerStudents::addStudent(QString name, QString father, QString mother,
                                 QString naturalness, QString IDNumber,
                                 QString IDissuingInstituation, QString IDissueDate)
{
    m_managerStudents.append(Student(name, father, mother, naturalness, IDNumber,
                                     IDissuingInstituation, IDissueDate));
}

void ManagerStudents::addStudent(Student student)
{
    m_managerStudents.append(student);
}
