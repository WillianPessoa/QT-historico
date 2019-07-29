#ifndef STUDENT_H
#define STUDENT_H

#include "grades.h"
#include "individualsheet.h"

#include <QDate>
#include <QJsonObject>
#include <QList>
#include <QString>
#include <QDebug>

class Student
{
public:
    Student();

    Student(QJsonObject aluno);

    Student(const IndividualSheet &studentSheet);

    Student(const QString &name, const QDate &dateOfBirth, const QString &fatherName,
            const QString &motherName, const QString &naturalness, const QString &IDNumber,
            const QString &IDissuingInstituation, const QString &IDissueDate, const QString &remarks);

    QString name() const;
    void setName(const QString &name);

    QDate dateOfBirth() const;
    void setDateOfBirth(const QDate &dateOfBirth);

    QString fatherName() const;
    void setFatherName(const QString &fatherName);

    QString motherName() const;
    void setMotherName(const QString &motherName);

    QString nationality() const;
    void setNationality(const QString &nationality);

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

    QString remarks() const;
    void setRemarks(const QString &remarks);

    Grades firstYearGrades() const;
    Grades secondYearGrades() const;
    Grades thirdYearGrades() const;

    void insertGrades(const IndividualSheet &studentSheet);

    Grades &getGradesRef(const QString gradeYear);

    Grades getGrades(const QString &gradeYear) const;

    void writeInJsonObject(QJsonObject &obj) const;

    QString firstYearEducationalEstablishment() const;
    void setFirstYearEducationalEstablishment(const QString &firstYearEducationalEstablishment);

    QString secondYearEducationalEstablishment() const;
    void setSecondYearEducationalEstablishment(const QString &secondYearEducationalEstablishment);

    QString thirdYearEducationalEstablishment() const;
    void setThirdYearEducationalEstablishment(const QString &thirdYearEducationalEstablishment);

    QString firstYearState() const;
    void setFirstYearState(const QString &firstYearState);

    QString secondYearState() const;
    void setSecondYearState(const QString &secondYearState);

    QString thirdYearState() const;
    void setThirdYearState(const QString &thirdYearState);

    double firstYearFrequency() const;
    void setFirstYearFrequency(double firstYearFrequency);

    double secondYearFrequency() const;
    void setSecondYearFrequency(double secondYearFrequency);

    double thirdYearFrequency() const;
    void setThirdYearFrequency(double thirdYearFrequency);

    int firstYearConclusion() const;
    void setFirstYearConclusion(int firstYearConclusion);

    int secondYearConclusion() const;
    void setSecondYearConclusion(int secondYearConclusion);

    int thirdYearConclusion() const;
    void setThirdYearConclusion(int thirdYearConclusion);

private:

    //Dados pessoais
    QString m_name;
    QDate m_dateOfBirth;
    QString m_fatherName;
    QString m_motherName;
    QString m_nationality;
    QString m_naturalness;

    //Dados da identidade
    QString m_IDNumber;
    QString m_IDIssuingInstitution;
    QString m_IDIssueDate;

    //Estabelecimento de ensino
    QString m_firstYearEducationalEstablishment;
    QString m_secondYearEducationalEstablishment;
    QString m_thirdYearEducationalEstablishment;

    //Município/Estado dos anos de ensino médio
    QString m_firstYearState;
    QString m_secondYearState;
    QString m_thirdYearState;

    //Frequência anual de cada série
    double m_firstYearFrequency;
    double m_secondYearFrequency;
    double m_thirdYearFrequency;

    //Anos de conclusão das séries
    int m_firstYearConclusion;
    int m_secondYearConclusion;
    int m_thirdYearConclusion;

    //Grades com notas de cada série do aluno
    Grades m_firstYearGrades;
    Grades m_secondYearGrades;
    Grades m_thirdYearGrades;

    QString m_institutionBack;
    QString m_remarks;
};

#endif // STUDENT_H
