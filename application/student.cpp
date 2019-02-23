#include "student.h"

namespace {
   const QString KEY_NAME = "Nome";
   const QString KEY_MOTHER = "Mãe";
   const QString KEY_FATHER = "Pai";
   const QString KEY_NATURALNESS = "Naturalidade";
   const QString KEY_ID_NUMBER = "RG";
   const QString KEY_ID_ISSUING_INSTITUTION = "Órgão Emissor";
   const QString KEY_ID_ISSUE_DATE = "Data de Emissão";

   const QString KEY_DATE_BIRTH = "Nascimento";

   const QString KEY_PORTUGUESE = "Português";
   const QString KEY_ART = "Arte";
   const QString KEY_PHYSICAL_EDUCATION = "Educação Física";
   const QString KEY_MATH = "Matemática";
   const QString KEY_CHEMISTRY = "Química";
   const QString KEY_PHYSICS = "Física";
   const QString KEY_BIOLOGY = "Biologia";
   const QString KEY_HISTORY = "História";
   const QString KEY_GEOGRAPHY = "Geografia";
   const QString KEY_SOCIOLOGY = "Sociologia";
   const QString KEY_PHILOSOPHY = "Filosofia";
   const QString KEY_ENGLISH = "Inglês";
   const QString KEY_RELIGIOUS = "Religião";
   const QString KEY_PROJECT = "Projeto de Inglês";
   const QString KEY_MATH_PROBLEM = "RPM";
   const QString KEY_TEXT_PRODUCTION = "Produção Textual";

}

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

Grades &Student::getGrades(const QString gradeYear)
{
    Grades &grades = m_firstYearGrades;
    if (gradeYear == "2") {
        grades = m_secondYearGrades;
    } else if (gradeYear == "3") {
        grades = m_secondYearGrades;
    }
    return grades;
}

void Student::insertGrades(const IndividualSheet &studentSheet)
{
    Grades &grades = getGrades(studentSheet.grade());
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

void Student::writeInJsonObject(QJsonObject &obj) const
{
    obj.insert(KEY_NAME, m_name);
    obj.insert(KEY_FATHER, m_fatherName);
    obj.insert(KEY_MOTHER, m_motherName);
    obj.insert(KEY_ID_NUMBER, m_IDNumber);
    obj.insert(KEY_NATURALNESS, m_naturalness);
    obj.insert(KEY_ID_ISSUING_INSTITUTION, m_IDIssuingInstitution);
    obj.insert(KEY_ID_ISSUE_DATE, m_IDIssueDate);
    obj.insert(KEY_DATE_BIRTH, m_dateOfBirth.toString("dd/MM/yyyy"));

    QJsonObject portugueseObj;
    portugueseObj.insert("1", m_firstYearGrades.portugueseGrade());
    portugueseObj.insert("2", m_secondYearGrades.portugueseGrade());
    portugueseObj.insert("3", m_thirdYearGrades.portugueseGrade());
    obj.insert(KEY_PORTUGUESE, portugueseObj);

    //TODO: Fazer inclusão das outras notas
}
