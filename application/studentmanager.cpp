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
        for (Student &student : m_students) {
            if (isEqual(student, studentSheet)) {
                const QString gradeSheet = studentSheet.grade();
                if ((gradeSheet == "1" && student.firstYearGrades().wasInitialized()) ||
                    (gradeSheet == "2" && student.secondYearGrades().wasInitialized()) ||
                    (gradeSheet == "3" && student.thirdYearGrades().wasInitialized())) {
                    qDebug() << "As notas do ano " << gradeSheet << " do aluno " << student.name() << "já foram adicionadas anteriormente. "
                             << "Por favor, atualize os dados via interface";
                    return false;
                }
                student.insertGrades(studentSheet);
            }
        }
    }
    m_students.append(Student(studentSheet));
    return true;
}

bool StudentManager::insertStudents(const QList<Student> students)
{
    m_students.append(students);
}

bool StudentManager::isEqual(const Student &student, const IndividualSheet &studentSheet) const
{
    if (student.name() == studentSheet.name()) {
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
