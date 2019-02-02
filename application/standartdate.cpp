#include "standartdate.h"

StandartDate::StandartDate(QString studentName, QString fatherName, QString motherName,
                           QString dateOfBirth, QString naturalness, QString IDNumber,
                           QString IDissuingInstituation, QString IDissueDate)
{
    m_dateOfBirth = dateOfBirth;
    m_studentName = studentName;
    m_fatherName = fatherName;
    m_motherName = motherName;
    m_naturalness = naturalness;
    m_IDNumber = IDNumber;
    m_IDissuingInstituation = IDissuingInstituation;
    m_IDissueDate = IDissueDate;
}

//Métodos gettes
QString StandartDate::dateOfBirth() const
{
    return m_dateOfBirth;
}

QString StandartDate::studentName() const
{
    return m_studentName;
}

QString StandartDate::fatherName() const
{
    return m_fatherName;
}

QString StandartDate::motherName() const
{
    return m_motherName;
}

QString StandartDate::naturalNess() const
{
    return m_naturalness;
}
QString StandartDate::IDNumber() const
{
    return m_IDNumber;
}

QString StandartDate::IDIssuingInstituation() const
{
    return m_IDissuingInstituation;
}

QString StandartDate::IDIssueDate() const
{
    return m_IDissueDate;
}

//Métodos Setters
void StandartDate::setStudentName(const QString &name)
{
    m_studentName = name;
}

void StandartDate::setFatherName(const QString &father)
{
    m_fatherName = father;
}

void StandartDate::setMotherName(const QString &mother)
{
    m_motherName = mother;
}

void StandartDate::setNaturalNess(const QString &naturalNess)
{
    m_naturalness = naturalNess;
}

void StandartDate::setIDNumber(const QString &IDNumber)
{
    m_IDNumber = IDNumber;
}

void StandartDate::setIDIssuingInstituation(const QString &IDIssuingInstituation)
{
    m_IDissuingInstituation = IDIssuingInstituation;
}

void StandartDate::setIDIssueDate(const QString &IDIssueDate)
{
    m_IDissueDate = IDIssueDate;
}
