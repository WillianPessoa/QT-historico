#include "student.h"

Student::Student()
{

}

Student::Student(const QString &name, const QDate &dateOfBirth, const QString &fatherName,
                 const QString &motherName, const QString &naturalness, const QString &IDNumber,
                 const QString &IDissuingInstituation, const QString &IDissueDate):
    m_name(name),
    m_dateOfBirth(dateOfBirth),
    m_fatherName(fatherName),
    m_motherName(motherName),
    m_naturalness(naturalness),
    m_IDNumber(IDNumber),
    m_IDIssuingInstitution(IDissuingInstituation),
    m_IDIssueDate(IDissueDate)
{

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
    return m_dateOfBirth;
}

void Student::setDateOfBirth(const QDate &dateOfBirth)
{
    m_dateOfBirth = dateOfBirth;
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

QString Student::IDIssuingInstitution() const
{
    return m_IDIssuingInstitution;
}

void Student::setIDIssuingInstitution(const QString &IDissuingInstitution)
{
    m_IDIssuingInstitution = IDissuingInstitution;
}

QString Student::IDIssueDate() const
{
    return m_IDIssueDate;
}

void Student::setIDIssueDate(const QString &IDIssueDate)
{
   m_IDIssueDate = IDIssueDate;
}
