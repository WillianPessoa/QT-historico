#ifndef INDIVIDUALSHEET_H
#define INDIVIDUALSHEET_H

#include <QDate>
#include <QString>

typedef enum _Sex {
    Masculine,
    Feminine
}Sex;

typedef enum _Turn {
    Diurnal,
    Nocturnal
}Turn;

class IndividualSheet
{
public:
    IndividualSheet();

    QString name() const;
    void setName(const QString &Name);

    QString IDNumber() const;
    void setIDNumber(const QString &IDNumber);

    QString IDDateExpedition() const;
    void setIDDateExpedition(const QString &IDDateExpedition);

    QString IDOrganDispatcher() const;
    void setIDOrganDispatcher(const QString &IDOrganDispatcher);

    QString motherName() const;
    void setMotherName(const QString &MotherName);

    QString fatherName() const;
    void setFatherName(const QString &FatherName);

    QDate dateOfBirth() const;
    void setDateOfBirth(const QDate &DateOfBirth);

    QString naturalness() const;
    void setNaturalness(const QString &Naturalness);

    Sex sex() const;
    void setSex(const Sex &Sex);

    QString year() const;
    void setYear(const QString &year);

    QString grade() const;
    void setGrade(const QString &grade);

    QString group() const;
    void setGroup(const QString &group);

    Turn turn() const;
    void setTurn(const Turn &turn);

    double artGrade() const;
    void setArtGrade(double artGrade);

    double biologyGrade() const;
    void setBiologyGrade(double biologyGrade);

    double chemistryGrade() const;
    void setChemistryGrade(double chemistryGrade);

    double englishGrade() const;
    void setEnglishGrade(double englishGrade);

    double geographyGrade() const;
    void setGeographyGrade(double geographyGrade);

    double mathGrade() const;
    void setMathGrade(double mathGrade);

    double philosophyGrade() const;
    void setPhilosophyGrade(double philosophyGrade);

    double physicalEducationGrade() const;
    void setPhysicalEducationGrade(double physicalEducationGrade);

    double portugueseGrade() const;
    void setPortugueseGrade(double portugueseGrade);

    double projectGrade() const;
    void setProjectGrade(double projectGrade);

    double religiousGrade() const;
    void setReligiousGrade(double religiousGrade);

    double sociologyGrade() const;
    void setSociologyGrade(double sociologyGrade);

    double textProductionGrade() const;
    void setTextProductionGrade(double textProductionGrade);

    double historyGrade() const;
    void setHistoryGrade(double historyGrade);

private:
    // Personal info
    QString m_name;
    QString m_IDNumber;
    QString m_IDDateExpedition;
    QString m_IDOrganDispatcher;
    QString m_motherName;
    QString m_fatherName;
    QDate m_dateOfBirth;
    QString m_naturalness;
    Sex m_sex;

    // Sheet info
    QString m_year;
    QString m_grade;
    QString m_group;
    Turn m_turn;

    // Subject grades info// Subject grades info
    double m_artGrade;
    double m_biologyGrade;
    double m_chemistryGrade;
    double m_englishGrade;
    double m_geographyGrade;
    double m_historyGrade;
    double m_mathGrade;
    double m_philosophyGrade;
    double m_physicalEducationGrade;
    double m_portugueseGrade;
    double m_projectGrade;
    double m_religiousGrade;
    double m_sociologyGrade;
    double m_textProductionGrade;
};

#endif // INDIVIDUALSHEET_H
