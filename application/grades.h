#ifndef GRADES_H
#define GRADES_H

class Grades
{
public:
    Grades();

    double portugueseGrade() const;
    void setPortugueseGrade(double portugueseGrade);

    double artGrade() const;
    void setArtGrade(double artGrade);

    double physicalEducationGrade() const;
    void setPhysicalEducationGrade(double physicalEducationGrade);

    double mathGrade() const;
    void setMathGrade(const double mathGrade);

    double chemistryGrade() const;
    void setChemistryGrade(double chemistryGrade);

    double physicsGrade() const;
    void setPhysicsGrade(double physicsGrade);

    double biologyGrade() const;
    void setBiologyGrade(double biologyGrade);

    double storeGrade() const;
    void setStoreGrade(double storeGrade);

    double geographyGrade() const;
    void setGeographyGrade(double geographyGrade);

    double sociologyGrade() const;
    void setSociologyGrade(double sociologyGrade);

    double philosophyGrade() const;
    void setPhilosophyGrade(double philosophyGrade);

    double englishGrade() const;
    void setEnglishGrade(double englishGrade);

    double religiousGrade() const;
    void setReligiousGrade(double religiousGrade);

    double projectGrade() const;
    void setProjectGrade(double projectGrade);

    double mathProblemSolvingGrade() const;
    void setMathProblemSolvingGrade(double mathProblemSolvingGrade);

    double textProductionGrade() const;
    void setTextProductionGrade(double textProductionGrade);

private:
    double m_portugueseGrade;
    double m_artGrade;
    double m_physicalEducationGrade;
    double *m_mathGrade;
    double m_chemistryGrade;
    double m_physicsGrade;
    double m_biologyGrade;
    double m_storeGrade;
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
