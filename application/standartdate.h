#ifndef STANDARTDATE_H
#define STANDARTDATE_H

#include <QDate>
#include <QString>

class StandartDate
{
    //QDate m_birth; --> Olhar depois
    QString m_name;
    QString m_father;
    QString m_mother;
    QString m_naturalness;
    QString m_IDNumber;
    QString m_IDissuingInstituation;
    QString m_IDissueDate;

public:
    //QDate birth --> Olhar depois para pssar como argumento
    StandartDate(QString name, QString father, QString mother,
                 QString naturalness, QString IDNumber,
                 QString IDissuingInstituation, QString IDissueDate);

    //Métodos gettes
    QString getName();
    QString getFather();
    QString getMother();
    QString getNaturalNess();
    QString getIDNumber();
    QString getIDIssuingInstituation();
    QString getIDIssueDate();

    //Métodos setters
    void setName(QString name);
    void setFather(QString father);
    void setMother(QString mother);
    void setNaturalNess(QString naturalNess);
    void setIDNumber(QString IDNumber);
    void setIDIssuingInstituation(QString IDIssuingInstituation);
    void setIDIssueDate(QString IDIssueDate);
};

#endif // STANDARTDATE_H
