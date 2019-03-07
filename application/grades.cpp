#include "grades.h"

Grades::Grades()
    :  m_portugueseGrade(-1),
       m_artGrade(-1),
       m_physicalEducationGrade(-1),
       m_mathGrade(-1),
       m_chemistryGrade(-1),
       m_physicsGrade(-1),
       m_biologyGrade(-1),
       m_historyGrade(-1),
       m_geographyGrade(-1),
       m_sociologyGrade(-1),
       m_philosophyGrade(-1),
       m_englishGrade(-1),
       m_religiousGrade(-1),
       m_projectGrade(-1),
       m_mathProblemSolvingGrade(-1),
       m_textProductionGrade(-1)
{

}

QString Grades::year() const
{
    return m_year;
}

void Grades::setYear(const QString &year)
{
    m_year = year;
}

QString Grades::series() const
{
    return m_series;
}

void Grades::setSeries(const QString &series)
{
    m_series = series;
}

double Grades::portugueseGrade() const
{
    return m_portugueseGrade;
}

void Grades::setPortugueseGrade(const double &portugueseGrade)
{
    m_portugueseGrade = portugueseGrade;
}

double Grades::artGrade() const
{
    return m_artGrade;
}

void Grades::setArtGrade(const double &artGrade)
{
    m_artGrade = artGrade;
}

double Grades::physicalEducationGrade() const
{
    return m_physicalEducationGrade;
}

void Grades::setPhysicalEducationGrade(const double &physicalEducationGrade)
{
    m_physicalEducationGrade = physicalEducationGrade;
}

double Grades::mathGrade() const
{
    return m_mathGrade;
}

void Grades::setMathGrade(const double &mathGrade)
{
    m_mathGrade = mathGrade;
}

double Grades::chemistryGrade() const
{
    return m_chemistryGrade;
}

void Grades::setChemistryGrade(const double &chemistryGrade)
{
    m_chemistryGrade = chemistryGrade;
}

double Grades::physicsGrade() const
{
    return m_physicsGrade;
}

void Grades::setPhysicsGrade(const double &physicsGrade)
{
    m_physicsGrade = physicsGrade;
}

double Grades::biologyGrade() const
{
    return m_biologyGrade;
}

void Grades::setBiologyGrade(const double &biologyGrade)
{
    m_biologyGrade = biologyGrade;
}

double Grades::historyGrade() const
{
    return m_historyGrade;
}

void Grades::setHistoryGrade(const double &storeGrade)
{
    m_historyGrade = storeGrade;
}

double Grades::geographyGrade() const
{
    return m_geographyGrade;
}

void Grades::setGeographyGrade(const double &geographyGrade)
{
    m_geographyGrade = geographyGrade;
}

double Grades::sociologyGrade() const
{
    return m_sociologyGrade;
}

void Grades::setSociologyGrade(const double &sociologyGrade)
{
    m_sociologyGrade = sociologyGrade;
}

double Grades::philosophyGrade() const
{
    return m_philosophyGrade;
}

void Grades::setPhilosophyGrade(const double &philosophyGrade)
{
    m_philosophyGrade = philosophyGrade;
}

double Grades::englishGrade() const
{
    return m_englishGrade;
}

void Grades::setEnglishGrade(const double &englishGrade)
{
    m_englishGrade = englishGrade;
}

double Grades::religiousGrade() const
{
    return m_religiousGrade;
}

void Grades::setReligiousGrade(const double &religiousGrade)
{
    m_religiousGrade = religiousGrade;
}

double Grades::projectGrade() const
{
    return m_projectGrade;
}

void Grades::setProjectGrade(const double &projectGrade)
{
    m_projectGrade = projectGrade;
}

double Grades::mathProblemSolvingGrade() const
{
    return m_mathProblemSolvingGrade;
}

void Grades::setMathProblemSolvingGrade(const double &mathProblemSolvingGrade)
{
    m_mathProblemSolvingGrade = mathProblemSolvingGrade;
}

double Grades::textProductionGrade() const
{
    return m_textProductionGrade;
}

void Grades::setTextProductionGrade(const double &textProductionGrade)
{
    m_textProductionGrade = textProductionGrade;
}

bool Grades::wasInitialized() const   //Alteração de comparação "!= -1" para ">=0"
{
    bool wasInit = false;
    if (m_portugueseGrade >= 0) wasInit = true;
    if (m_artGrade >= 0) wasInit = true;
    if (m_physicalEducationGrade >= 0) wasInit = true;
    if (m_mathGrade >= 0) wasInit = true;
    if (m_chemistryGrade >= 0) wasInit = true;
    if (m_physicsGrade >= 0) wasInit = true;
    if (m_biologyGrade >= 0) wasInit = true;
    if (m_historyGrade >= 0) wasInit = true;
    if (m_geographyGrade >= 0) wasInit = true;
    if (m_sociologyGrade >= 0) wasInit = true;
    if (m_philosophyGrade >= 0) wasInit = true;
    if (m_englishGrade >= 0) wasInit = true;
    if (m_religiousGrade >= 0) wasInit = true;
    if (m_projectGrade >= 0) wasInit = true;
    if (m_mathProblemSolvingGrade >= 0) wasInit = true;
    if (m_textProductionGrade >= 0) wasInit = true;
    return wasInit;
}
