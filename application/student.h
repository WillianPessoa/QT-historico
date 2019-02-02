#ifndef STUDENT_H
#define STUDENT_H

#include <standartdate.h>
#include <managersubjectssandgrades.h>
#include <QString>

class Student
{
private:
    StandartDate *m_stdDate;
    ManagerSubjectsAndGrades *m_managerSubjectsAndGrades;

public:
    Student(QString studentName, QString fatherName, QString motherName,
            QString dateOfBirth, QString naturalness, QString IDNumber,
            QString IDissuingInstituation, QString IDissueDate);

    StandartDate stdDate() const;  //retorna objeto com dados padrões do aluno
    ManagerSubjectsAndGrades managerSubjectsAndGrades() const;    //retorna objeto que gerencia as materias e notas do aluno

};

#endif // STUDENT_H
