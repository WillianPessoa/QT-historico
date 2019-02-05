#ifndef STUDENT_H
#define STUDENT_H

#include <QDate>
#include <QString>

class Student
{
public:
    Student(QString name, QString dateOfBirth, QString fatherName, QString motherName,
            QString naturalness, QString IDNumber, QString IDissuingInstituation,
            QString IDissueDate);

    Student();

    QString name() const;
    void setName(const QString &name);

    QDate dateOfBirth() const;    //Esse método vai ser do tipo QDate
    void setDateOfBirth(const QString &dateOfBirth);

    QString fatherName() const;
    void setFatherName(const QString &fatherName);

    QString motherName() const;
    void setMotherName(const QString &motherName);

    QString naturalness() const;
    void setNaturalness(const QString &naturalness);

    QString IDNumber() const;
    void setIDNumber(const QString &IDNumber);

    QString IDIssuingInstituation() const;
    void setIDIssuingInstituation(const QString &IDissuingInstituation);

    QString IDIssueDate() const;
    void setIDIssueDate(const QString &IDissueDate);

private:
    QString m_name;
    QDate m_dateOfBirth;
    QString m_fatherName;
    QString m_motherName;
    QString m_naturalness;
    QString m_IDNumber;
    QString m_IDIssuingInstituation;
    QString m_IDIssueDate;
};

#endif // STUDENT_H
