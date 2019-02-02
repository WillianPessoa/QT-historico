#ifndef STANDARTDATE_H
#define STANDARTDATE_H

#include <QDate>
#include <QString>

class StandartDate
{
    QString m_dateOfBirth;
    QString m_studentName;
    QString m_fatherName;
    QString m_motherName;
    QString m_naturalness;
    QString m_IDNumber;
    QString m_IDissuingInstituation;
    QString m_IDissueDate;

public:

    StandartDate(QString studentName, QString fatherName, QString motherName,
                 QString dateOfBirth, QString naturalness, QString IDNumber,
                 QString IDissuingInstituation, QString IDissueDate);

    //Métodos gettes
    QString dateOfBirth() const;
    QString studentName() const;
    QString fatherName() const;
    QString motherName() const;
    QString naturalNess() const;
    QString IDNumber() const;
    QString IDIssuingInstituation() const;
    QString IDIssueDate() const;

    //Métodos setters
    void setDateOfBirth(const QString &dateOfBirth);
    void setStudentName(const QString &studentName);
    void setFatherName(const QString &fatherName);
    void setMotherName(const QString &motherName);
    void setNaturalNess(const QString &naturalNess);
    void setIDNumber(const QString &IDNumber);
    void setIDIssuingInstituation(const QString &IDIssuingInstituation);
    void setIDIssueDate(const QString &IDIssueDate);
};

#endif // STANDARTDATE_H
