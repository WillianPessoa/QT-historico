#include "standartdate.h"

StandartDate::StandartDate(QString name, QString father, QString mother,
                           QString naturalness, QString IDNumber,
                           QString IDissuingInstituation, QString IDissueDate)
{
    m_name = name;
    m_father = father;
    m_mother = mother;
    m_naturalness = naturalness;
    m_IDNumber = IDNumber;
    m_IDissuingInstituation = IDissuingInstituation;
    m_IDissueDate = IDissueDate;
}

QString StandartDate::getName()
{
    return m_name;
}

QString StandartDate::getFather()
{
    return m_father;
}

QString StandartDate::getMother()
{
    return m_mother;
}

QString StandartDate::getNaturalNess()
{
    return m_naturalness;
}
QString StandartDate::getIDNumber()
{
    return m_IDNumber;
}

QString StandartDate::getIDIssuingInstituation()
{
    return m_IDissuingInstituation;
}

QString StandartDate::getIDIssueDate()
{
    return m_IDissueDate;
}

void StandartDate::setName(QString name)
{
    m_name = name;
}

void StandartDate::setFather(QString father)
{
    m_father = father;
}

void StandartDate::setMother(QString mother)
{
    m_mother = mother;
}

void StandartDate::setNaturalNess(QString naturalNess)
{
    m_naturalness = naturalNess;
}

void StandartDate::setIDNumber(QString IDNumber)
{
    m_IDNumber = IDNumber;
}

void StandartDate::setIDIssuingInstituation(QString IDIssuingInstituation)
{
    m_IDissuingInstituation = IDIssuingInstituation;
}

void StandartDate::setIDIssueDate(QString IDIssueDate)
{
    m_IDissueDate = IDIssueDate;
}
