#ifndef MANAGERSTUDENT_H
#define MANAGERSTUDENT_H

#include "student.h"

#include <QList>

class ManagerStudents
{
private:
    QList<Student> m_managerStudents;

public:
    ManagerStudents();

    Student getStudent(QString name);
    void addStudent(QString name, QString father, QString mother,
                    QString naturalness, QString IDNumber,
                    QString IDissuingInstituation, QString IDissueDate);
    void addStudent(Student student);
};

#endif // MANAGERSTUDENT_H
