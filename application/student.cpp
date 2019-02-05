#include "student.h"

Student::Student()
{

}

Student::Student(QString name, QString dateOfBirth, QString fatherName, QString motherName,
                 QString naturalness, QString IDNumber, QString IDIssuingInstituation,
                 QString IDIssueDate)
{
    m_name = name;
    //m_dateOfBirth = dateOfBirth;
    m_fatherName = fatherName;
    m_motherName = motherName;
    m_naturalness = naturalness;
    m_IDNumber = IDNumber;
    m_IDIssuingInstituation = IDIssuingInstituation;
    m_IDIssueDate = IDIssueDate;
}

QString Student::name() const
{
    return m_name;
}

void Student::setName(const QString &name)
{
    m_name = name;
}

QDate Student::dateOfBirth() const
{
    //OBS.: Retornar QDate em formato de string
}

void Student::setDateOfBirth(const QString &dateOfBirth)
{
    //Transformar string em QDate
}

QString Student::fatherName() const
{
    return m_fatherName;
}

void Student::setFatherName(const QString &fatherName)
{
    m_fatherName = fatherName;
}

QString Student::motherName() const
{
    return m_motherName;
}

void Student::setMotherName(const QString &motherName)
{
    m_motherName = motherName;
}

QString Student::naturalness() const
{
    return m_naturalness;
}

void Student::setNaturalness(const QString &naturalness)
{
    m_naturalness = naturalness;
}

QString Student::IDNumber() const
{
    return m_IDNumber;
}

void Student::setIDNumber(const QString &IDNumber)
{
    m_IDNumber = IDNumber;
}

QString Student::IDIssuingInstituation() const
{
    return m_IDIssuingInstituation;
}

void Student::setIDIssuingInstituation(const QString &IDissuingInstituation)
{
    m_IDIssuingInstituation = IDissuingInstituation;
}

QString Student::IDIssueDate() const
{
    return m_IDIssueDate;
}

void Student::setIDIssueDate(const QString &IDIssueDate)
{
   m_IDIssueDate = IDIssueDate;
}

Grades Student::firstYearGrades() const
{
    return m_firstYearGrades;
}

Grades Student::secondYearGrades() const
{
    return m_secondYearGrades;
}

Grades Student::thirdYearGrades() const
{
    return m_thirdYearGrades;
}
