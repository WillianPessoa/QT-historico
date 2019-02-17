#ifndef GRADES_H
#define GRADES_H

class Grades
{
public:
    Grades();

    double portugueseGrade() const;
    void setPortugueseGrade(const double &portugueseGrade);

    double artGrade() const;
    void setArtGrade(const double &artGrade);

    double physicalEducationGrade() const;
    void setPhysicalEducationGrade(const double &physicalEducationGrade);

    double mathGrade() const;
    void setMathGrade(const double &mathGrade);

    double chemistryGrade() const;
    void setChemistryGrade(const double &chemistryGrade);

    double physicsGrade() const;
    void setPhysicsGrade(const double &physicsGrade);

    double biologyGrade() const;
    void setBiologyGrade(const double &biologyGrade);

    double historyGrade() const;
    void setHistoryGrade(const double &historyGrade);

    double geographyGrade() const;
    void setGeographyGrade(const double &geographyGrade);

    double sociologyGrade() const;
    void setSociologyGrade(const double &sociologyGrade);

    double philosophyGrade() const;
    void setPhilosophyGrade(const double &philosophyGrade);

    double englishGrade() const;
    void setEnglishGrade(const double &englishGrade);

    double religiousGrade() const;
    void setReligiousGrade(const double &religiousGrade);

    double projectGrade() const;
    void setProjectGrade(const double &projectGrade);

    double mathProblemSolvingGrade() const;
    void setMathProblemSolvingGrade(const double &mathProblemSolvingGrade);

    double textProductionGrade() const;
    void setTextProductionGrade(const double &textProductionGrade);

    bool wasInitialized() const;

private:
    double m_portugueseGrade;
    double m_artGrade;
    double m_physicalEducationGrade;
    double m_mathGrade;
    double m_chemistryGrade;
    double m_physicsGrade;
    double m_biologyGrade;
    double m_historyGrade;
    double m_geographyGrade;
    double m_sociologyGrade;
    double m_philosophyGrade;
    double m_englishGrade;
    double m_religiousGrade;
    double m_projectGrade;
    double m_mathProblemSolvingGrade;
    double m_textProductionGrade;
};

#endif // GRADES_H
