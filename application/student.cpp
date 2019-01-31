#include "student.h"

Student::Student(QString name, QString father, QString mother, QString naturalness,
                 QString IDNumber, QString IDissuingInstituation, QString IDissueDate)
{
    m_stdDate = new StandartDate(name, father, mother, naturalness,
                                 IDNumber, IDissuingInstituation, IDissueDate);
    m_ManagerMattersAndNotes = new ManagerMattersAndNotes();
}

StandartDate Student::getStdDate()
{
    return *m_stdDate;
}

ManagerMattersAndNotes Student::getManagerMattersAndNotes()
{

}
