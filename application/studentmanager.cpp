#include "studentmanager.h"

#include <QDebug>

StudentManager::StudentManager(QObject *parent) :
    QObject(parent),
    m_students()
{

}

bool StudentManager::insertStudentData(const IndividualSheet &studentSheet)
{
    if (containsStudent(studentSheet)) {
        // TODO: Inserção de novos dados
        //       Retornar falso se forem dados de um ano já inserido anteriormente
    }
    m_students.append(Student(studentSheet));
    return true;
}

bool StudentManager::isEqual(const Student &student, const IndividualSheet &studentSheet) const
{
    if (student.name() == student.name()) {
        if (student.fatherName() == studentSheet.fatherName() && student.motherName() == studentSheet.motherName()) {
            return true;
        }
    }
    return false;
}

bool StudentManager::containsStudent(const IndividualSheet &studentSheet) const
{
    for (const Student &student : m_students) {
        if (isEqual(student, studentSheet)) {
            return true;
        }
    }
    return false;
}

QList<Student> StudentManager::students() const
{
    return m_students;
}
