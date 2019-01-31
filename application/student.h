#ifndef STUDENT_H
#define STUDENT_H

#include <standartdate.h>
#include <managermattersandnotes.h>
#include <QString>

class Student
{
private:
    StandartDate *m_stdDate;
    ManagerMattersAndNotes *m_ManagerMattersAndNotes;

public:
    Student(QString name, QString father, QString mother,
            QString naturalness, QString IDNumber,
            QString IDissuingInstituation, QString IDissueDate);

    StandartDate getStdDate();
    ManagerMattersAndNotes getManagerMattersAndNotes();

};

#endif // STUDENT_H
