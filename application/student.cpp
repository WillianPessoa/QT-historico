#include "student.h"
#include <QDebug>

Student::Student()
{

}

Student::Student(const IndividualSheet &studentSheet) :
    m_name(studentSheet.name()),
    m_dateOfBirth(studentSheet.dateOfBirth()),
    m_fatherName(studentSheet.fatherName()),
    m_motherName(studentSheet.motherName()),
    m_naturalness(studentSheet.naturalness())
{
    insertGrades(studentSheet);
}

Student::Student(const QString &name, const QDate &dateOfBirth, const QString &fatherName,
                 const QString &motherName, const QString &naturalness, const QString &IDNumber,
                 const QString &IDissuingInstituation, const QString &IDissueDate) :
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

Grades &Student::getGradesRef(const QString gradeYear)
{
    Grades &grades = m_firstYearGrades;
    if (gradeYear == "2") {
        grades = m_secondYearGrades;
    } else if (gradeYear == "3") {
        grades = m_thirdYearGrades;
    }
    return grades;
}

Grades Student::getGrades(const QString &gradeYear) const
{
    Grades grades = m_firstYearGrades;
    qDebug() << "ATENÇÃO: " << gradeYear + "== 2" << endl;
    if (gradeYear == "2") {
        grades = m_secondYearGrades;
    } else if (gradeYear == "3") {
        grades = m_thirdYearGrades;
    }
    return grades;
}

void Student::insertGrades(const IndividualSheet &studentSheet)
{
    Grades &grades = getGradesRef(studentSheet.grade());
    grades.setArtGrade(studentSheet.artGrade());
    grades.setBiologyGrade(studentSheet.biologyGrade());
    grades.setChemistryGrade(studentSheet.chemistryGrade());
    grades.setEnglishGrade(studentSheet.englishGrade());
    grades.setHistoryGrade(studentSheet.historyGrade());
    grades.setGeographyGrade(studentSheet.geographyGrade());
    grades.setMathGrade(studentSheet.mathGrade());
    grades.setMathProblemSolvingGrade(studentSheet.mathProblemSolvingGrade());
    grades.setPhilosophyGrade(studentSheet.philosophyGrade());
    grades.setPhysicalEducationGrade(studentSheet.physicalEducationGrade());
    grades.setPhysicsGrade(studentSheet.phisicsGrade());
    grades.setPortugueseGrade(studentSheet.portugueseGrade());
    grades.setProjectGrade(studentSheet.projectGrade());
    grades.setReligiousGrade(studentSheet.religiousGrade());
    grades.setSociologyGrade(studentSheet.sociologyGrade());
    grades.setTextProductionGrade(studentSheet.textProductionGrade());
}


