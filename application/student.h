#ifndef STUDENT_H
#define STUDENT_H

#include "grades.h"
#include "individualsheet.h"

#include <QDate>
#include <QString>

class Student
{
public:
    Student();

    Student(const IndividualSheet &studentSheet);

    Student(const QString &name, const QDate &dateOfBirth, const QString &fatherName,
            const QString &motherName, const QString &naturalness, const QString &IDNumber,
            const QString &IDissuingInstituation, const QString &IDissueDate);

    QString name() const;
    void setName(const QString &name);

    QDate dateOfBirth() const;
    void setDateOfBirth(const QDate &dateOfBirth);

    QString fatherName() const;
    void setFatherName(const QString &fatherName);

    QString motherName() const;
    void setMotherName(const QString &motherName);

    QString naturalness() const;
    void setNaturalness(const QString &naturalness);

    QString IDNumber() const;
    void setIDNumber(const QString &IDNumber);

    QString IDIssuingInstitution() const;
    void setIDIssuingInstitution(const QString &IDissuingInstitution);

    QString IDIssueDate() const;
    void setIDIssueDate(const QString &IDissueDate);

    QString institutionBack() const;
    void setInstitutionBack(const QString &institutionBack);

    Grades firstYearGrades() const;
    Grades secondYearGrades() const;
    Grades thirdYearGrades() const;

    void insertGrades(const IndividualSheet &studentSheet);

    Grades &getGradesRef(const QString gradeYear);

    Grades getGrades(const QString &gradeYear) const;

private:
    QString m_name;
    QDate m_dateOfBirth;
    QString m_fatherName;
    QString m_motherName;
    QString m_naturalness;
    QString m_IDNumber;
    QString m_IDIssuingInstitution;
    QString m_IDIssueDate;
    QString m_institutionBack;

    //TODO: Criar variavel para armazenar instituição de ensino

    Grades m_firstYearGrades;
    Grades m_secondYearGrades;
    Grades m_thirdYearGrades;
};

#endif // STUDENT_H
