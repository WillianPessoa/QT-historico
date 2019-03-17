#include "student.h"

#include <QDebug>
#include <QStringList>

namespace {

   const QString KEY_NAME = "Nome";
   const QString KEY_DATE_BIRTH = "Nascimento";
   const QString KEY_MOTHER = "Mae";
   const QString KEY_FATHER = "Pai";
   const QString KEY_NATURALNESS = "Naturalidade";
   const QString KEY_ID_NUMBER = "RG";
   const QString KEY_ID_ISSUING_INSTITUTION = "Orgao Emissor";
   const QString KEY_ID_ISSUE_DATE = "Data de Emissao";

   const QString KEY_PORTUGUESE = "Portugues";
   const QString KEY_ART = "Arte";
   const QString KEY_PHYSICAL_EDUCATION = "Educacao Fisica";
   const QString KEY_MATH = "Matematica";
   const QString KEY_CHEMISTRY = "Quimica";
   const QString KEY_PHYSICS = "Fisica";
   const QString KEY_BIOLOGY = "Biologia";
   const QString KEY_HISTORY = "Historia";
   const QString KEY_GEOGRAPHY = "Geografia";
   const QString KEY_SOCIOLOGY = "Sociologia";
   const QString KEY_PHILOSOPHY = "Filosofia";
   const QString KEY_ENGLISH = "Ingles";
   const QString KEY_RELIGIOUS = "Religiao";
   const QString KEY_PROJECT = "Projeto";
   const QString KEY_MATH_PROBLEM = "RPM";
   const QString KEY_TEXT_PRODUCTION = "Producao Textual";

   const QString KEY_REMARKS = "Observações";
}

Student::Student()
{

}

Student::Student(QJsonObject aluno)
{
    QString strDate = aluno.value(KEY_DATE_BIRTH).toString();

    m_name = aluno.value(KEY_NAME).toString();
    m_dateOfBirth = QDate::fromString(strDate, "dd/MM/yyyy");
    m_fatherName = aluno.value(KEY_MOTHER).toString();
    m_motherName = aluno.value(KEY_FATHER).toString();
    m_naturalness = aluno.value(KEY_NATURALNESS).toString();
    m_IDNumber = aluno.value(KEY_ID_NUMBER).toString();
    m_IDIssuingInstitution = aluno.value(KEY_ID_ISSUING_INSTITUTION).toString();
    m_IDIssueDate = aluno.value(KEY_ID_ISSUE_DATE).toString();
    m_remarks = aluno.value(KEY_REMARKS).toString();

    QJsonObject art = aluno.value(KEY_ART).toObject();
    QJsonObject math = aluno.value(KEY_MATH).toObject();
    QJsonObject biology = aluno.value(KEY_BIOLOGY).toObject();
    QJsonObject english = aluno.value(KEY_ENGLISH).toObject();
    QJsonObject history = aluno.value(KEY_HISTORY).toObject();
    QJsonObject physics = aluno.value(KEY_PHYSICS).toObject();
    QJsonObject project = aluno.value(KEY_PROJECT).toObject();
    QJsonObject chemisty = aluno.value(KEY_CHEMISTRY).toObject();
    QJsonObject geography = aluno.value(KEY_GEOGRAPHY).toObject();
    QJsonObject religious = aluno.value(KEY_RELIGIOUS).toObject();
    QJsonObject sociology = aluno.value(KEY_SOCIOLOGY).toObject();
    QJsonObject philosofy = aluno.value(KEY_PHILOSOPHY).toObject();
    QJsonObject portuguese = aluno.value(KEY_PORTUGUESE).toObject();
    QJsonObject textProduction = aluno.value(KEY_TEXT_PRODUCTION).toObject();
    QJsonObject physicalEducation = aluno.value(KEY_PHYSICAL_EDUCATION).toObject();
    QJsonObject mathProblemSolving = aluno.value(KEY_MATH_PROBLEM).toObject();

    m_firstYearGrades.setArtGrade(art.value("1").toDouble());
    m_firstYearGrades.setMathGrade(math.value("1").toDouble());
    m_firstYearGrades.setBiologyGrade(biology.value("1").toDouble());
    m_firstYearGrades.setEnglishGrade(english.value("1").toDouble());
    m_firstYearGrades.setHistoryGrade(history.value("1").toDouble());
    m_firstYearGrades.setPhysicsGrade(physics.value("1").toDouble());
    m_firstYearGrades.setProjectGrade(project.value("1").toDouble());
    m_firstYearGrades.setChemistryGrade(chemisty.value("1").toDouble());
    m_firstYearGrades.setGeographyGrade(geography.value("1").toDouble());
    m_firstYearGrades.setReligiousGrade(religious.value("1").toDouble());
    m_firstYearGrades.setSociologyGrade(sociology.value("1").toDouble());
    m_firstYearGrades.setPhilosophyGrade(philosofy.value("1").toDouble());
    m_firstYearGrades.setPortugueseGrade(portuguese.value("1").toDouble());
    m_firstYearGrades.setTextProductionGrade(textProduction.value("1").toDouble());
    m_firstYearGrades.setPhysicalEducationGrade(physicalEducation.value("1").toDouble());
    m_firstYearGrades.setMathProblemSolvingGrade(mathProblemSolving.value("1").toDouble());

    m_secondYearGrades.setArtGrade(art.value("2").toDouble());
    m_secondYearGrades.setMathGrade(math.value("2").toDouble());
    m_secondYearGrades.setBiologyGrade(biology.value("2").toDouble());
    m_secondYearGrades.setEnglishGrade(english.value("2").toDouble());
    m_secondYearGrades.setHistoryGrade(history.value("2").toDouble());
    m_secondYearGrades.setPhysicsGrade(physics.value("2").toDouble());
    m_secondYearGrades.setProjectGrade(project.value("2").toDouble());
    m_secondYearGrades.setChemistryGrade(chemisty.value("2").toDouble());
    m_secondYearGrades.setGeographyGrade(geography.value("2").toDouble());
    m_secondYearGrades.setReligiousGrade(religious.value("2").toDouble());
    m_secondYearGrades.setSociologyGrade(sociology.value("2").toDouble());
    m_secondYearGrades.setPhilosophyGrade(philosofy.value("2").toDouble());
    m_secondYearGrades.setPortugueseGrade(portuguese.value("2").toDouble());
    m_secondYearGrades.setTextProductionGrade(textProduction.value("2").toDouble());
    m_secondYearGrades.setPhysicalEducationGrade(physicalEducation.value("2").toDouble());
    m_secondYearGrades.setMathProblemSolvingGrade(mathProblemSolving.value("2").toDouble());

    m_thirdYearGrades.setArtGrade(art.value("3").toDouble());
    m_thirdYearGrades.setMathGrade(math.value("3").toDouble());
    m_thirdYearGrades.setBiologyGrade(biology.value("3").toDouble());
    m_thirdYearGrades.setEnglishGrade(english.value("3").toDouble());
    m_thirdYearGrades.setHistoryGrade(history.value("3").toDouble());
    m_thirdYearGrades.setPhysicsGrade(physics.value("3").toDouble());
    m_thirdYearGrades.setProjectGrade(project.value("3").toDouble());
    m_thirdYearGrades.setChemistryGrade(chemisty.value("3").toDouble());
    m_thirdYearGrades.setGeographyGrade(geography.value("3").toDouble());
    m_thirdYearGrades.setReligiousGrade(religious.value("3").toDouble());
    m_thirdYearGrades.setSociologyGrade(sociology.value("3").toDouble());
    m_thirdYearGrades.setPhilosophyGrade(philosofy.value("3").toDouble());
    m_thirdYearGrades.setPortugueseGrade(portuguese.value("3").toDouble());
    m_thirdYearGrades.setTextProductionGrade(textProduction.value("3").toDouble());
    m_thirdYearGrades.setPhysicalEducationGrade(physicalEducation.value("3").toDouble());
    m_thirdYearGrades.setMathProblemSolvingGrade(mathProblemSolving.value("3").toDouble());
}

Student::Student(const IndividualSheet &studentSheet) :
    m_name(studentSheet.name()),
    m_dateOfBirth(studentSheet.dateOfBirth()),
    m_fatherName(studentSheet.fatherName()),
    m_motherName(studentSheet.motherName()),
    m_naturalness(studentSheet.naturalness()),
    m_remarks("")
{
    insertGrades(studentSheet);
}

Student::Student(const QString &name, const QDate &dateOfBirth, const QString &fatherName,
                 const QString &motherName, const QString &naturalness, const QString &IDNumber,
                 const QString &IDissuingInstituation, const QString &IDissueDate, const QString &remarks) :
    m_name(name),
    m_dateOfBirth(dateOfBirth),
    m_fatherName(fatherName),
    m_motherName(motherName),
    m_naturalness(naturalness),
    m_IDNumber(IDNumber),
    m_IDIssuingInstitution(IDissuingInstituation),
    m_IDIssueDate(IDissueDate),
    m_remarks(remarks)
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

QString Student::institutionBack() const
{
    return m_institutionBack;
}

void Student::setInstitutionBack(const QString &institutionBack)
{
    m_institutionBack = institutionBack;
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
    if (gradeYear == "1") {
        return m_firstYearGrades;
    } else if (gradeYear == "2") {
        return m_secondYearGrades;
    }
    return m_thirdYearGrades;
}

Grades Student::getGrades(const QString &gradeYear) const
{
    Grades grades = m_firstYearGrades;
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
    grades.setYear(studentSheet.year());
    grades.setSeries(studentSheet.grade());
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
    obj.insert(KEY_DATE_BIRTH, m_dateOfBirth.toString("dd/MM/yyyy"));
    obj.insert(KEY_FATHER, m_fatherName);
    obj.insert(KEY_MOTHER, m_motherName);
    obj.insert(KEY_ID_NUMBER, m_IDNumber);
    obj.insert(KEY_NATURALNESS, m_naturalness);
    obj.insert(KEY_ID_ISSUING_INSTITUTION, m_IDIssuingInstitution);
    obj.insert(KEY_ID_ISSUE_DATE, m_IDIssueDate);
    obj.insert(KEY_REMARKS, m_remarks);

    QJsonObject portugueseObj;
    portugueseObj.insert("1", m_firstYearGrades.portugueseGrade());
    portugueseObj.insert("2", m_secondYearGrades.portugueseGrade());
    portugueseObj.insert("3", m_thirdYearGrades.portugueseGrade());
    obj.insert(KEY_PORTUGUESE, portugueseObj);

    QJsonObject artObj;
    artObj.insert("1", m_firstYearGrades.artGrade());
    artObj.insert("2", m_secondYearGrades.artGrade());
    artObj.insert("3", m_thirdYearGrades.artGrade());
    obj.insert(KEY_ART, artObj);

    QJsonObject physicalEducationObj;
    physicalEducationObj.insert("1", m_firstYearGrades.physicalEducationGrade());
    physicalEducationObj.insert("2", m_secondYearGrades.physicalEducationGrade());
    physicalEducationObj.insert("3", m_thirdYearGrades.physicalEducationGrade());
    obj.insert(KEY_PHYSICAL_EDUCATION, physicalEducationObj);

    QJsonObject mathObj;
    mathObj.insert("1",m_firstYearGrades.mathGrade());
    mathObj.insert("2", m_secondYearGrades.mathGrade());
    mathObj.insert("3", m_thirdYearGrades.mathGrade());
    obj.insert(KEY_MATH, mathObj);

    QJsonObject chemistryObj;
    chemistryObj.insert("1", m_firstYearGrades.chemistryGrade());
    chemistryObj.insert("2", m_secondYearGrades.chemistryGrade());
    chemistryObj.insert("3", m_thirdYearGrades.chemistryGrade());
    obj.insert(KEY_CHEMISTRY, chemistryObj);

    QJsonObject physicsObj;
    physicsObj.insert("1", m_firstYearGrades.physicsGrade());
    physicsObj.insert("2", m_secondYearGrades.physicsGrade());
    physicsObj.insert("3", m_thirdYearGrades.physicsGrade());
    obj.insert(KEY_PHYSICS, physicsObj);

    QJsonObject biologyObj;
    biologyObj.insert("1", m_firstYearGrades.biologyGrade());
    biologyObj.insert("2", m_secondYearGrades.biologyGrade());
    biologyObj.insert("3", m_thirdYearGrades.biologyGrade());
    obj.insert(KEY_BIOLOGY, biologyObj);

    QJsonObject historyObj;
    historyObj.insert("1", m_firstYearGrades.historyGrade());
    historyObj.insert("2", m_secondYearGrades.historyGrade());
    historyObj.insert("3", m_thirdYearGrades.historyGrade());
    obj.insert(KEY_HISTORY, historyObj);

    QJsonObject geographyObj;
    geographyObj.insert("1", m_firstYearGrades.geographyGrade());
    geographyObj.insert("2", m_secondYearGrades.geographyGrade());
    geographyObj.insert("3", m_thirdYearGrades.geographyGrade());
    obj.insert(KEY_GEOGRAPHY, geographyObj);

    QJsonObject sociologyObj;
    sociologyObj.insert("1", m_firstYearGrades.sociologyGrade());
    sociologyObj.insert("2", m_secondYearGrades.sociologyGrade());
    sociologyObj.insert("3", m_thirdYearGrades.sociologyGrade());
    obj.insert(KEY_SOCIOLOGY, sociologyObj);

    QJsonObject philosophyObj;
    philosophyObj.insert("1", m_firstYearGrades.philosophyGrade());
    philosophyObj.insert("2", m_secondYearGrades.philosophyGrade());
    philosophyObj.insert("3", m_thirdYearGrades.philosophyGrade());
    obj.insert(KEY_PHILOSOPHY, philosophyObj);

    QJsonObject englishObj;
    englishObj.insert("1", m_firstYearGrades.englishGrade());
    englishObj.insert("2", m_secondYearGrades.englishGrade());
    englishObj.insert("3", m_thirdYearGrades.englishGrade());
    obj.insert(KEY_ENGLISH, englishObj);

    QJsonObject religiousObj;
    religiousObj.insert("1", m_firstYearGrades.religiousGrade());
    religiousObj.insert("2", m_secondYearGrades.religiousGrade());
    religiousObj.insert("3", m_thirdYearGrades.religiousGrade());
    obj.insert(KEY_RELIGIOUS, religiousObj);

    QJsonObject projectObj;
    projectObj.insert("1", m_firstYearGrades.projectGrade());
    projectObj.insert("2", m_secondYearGrades.projectGrade());
    projectObj.insert("3", m_thirdYearGrades.projectGrade());
    obj.insert(KEY_PROJECT, projectObj);

    QJsonObject mathProblemObj;
    mathProblemObj.insert("1", m_firstYearGrades.mathProblemSolvingGrade());
    mathProblemObj.insert("2", m_secondYearGrades.mathProblemSolvingGrade());
    mathProblemObj.insert("3", m_thirdYearGrades.mathProblemSolvingGrade());
    obj.insert(KEY_MATH_PROBLEM, mathProblemObj);

    QJsonObject textProductionObj;
    textProductionObj.insert("1", m_firstYearGrades.textProductionGrade());
    textProductionObj.insert("2", m_secondYearGrades.textProductionGrade());
    textProductionObj.insert("3", m_thirdYearGrades.textProductionGrade());
    obj.insert(KEY_TEXT_PRODUCTION, textProductionObj);
}

QString Student::getRemarks() const
{
    return m_remarks;
}

void Student::setRemarks(const QString &remarks)
{
    m_remarks = remarks;
}
