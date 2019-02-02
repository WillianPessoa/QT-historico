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

    Student student(QString studentName) const;
    void addStudent(QString studentName, QString fatherName, QString motherName,
                    QString dateOfBirth, QString naturalness, QString IDNumber,
                    QString IDissuingInstituation, QString IDissueDate);
    void addStudent(Student studentObject);
};

#endif // MANAGERSTUDENT_H
