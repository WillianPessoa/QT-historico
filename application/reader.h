#ifndef READER_H
#define READER_H

#include <QList>
#include <QHash>

class QDir;

typedef enum _StudentData{
    Name,
    IDNumber,
    IDDateExpedition,
    IDOrganDispatcher,
    MotherName,
    FatherName,
    DateOfBirth,
    Naturalness,

    PortugueseGradeF1,
    PortugueseGradeF2,
    PortugueseGradeF3,

    ArtGradeF1,
    ArtGradeF2,
    ArtGradeF3,

    PhysicalEducationGradeF1,
    PhysicalEducationGradeF2,
    PhysicalEducationGradeF3,

    MathGradeF1,
    MathGradeF2,
    MathGradeF3,

    ChemistryGradeF1, //quimica
    ChemistryGradeF2,
    ChemistryGradeF3,

    PhysicsGradeF1,
    PhysicsGradeF2,
    PhysicsGradeF3,

    BiologyGradeF1,
    BiologyGradeF2,
    BiologyGradeF3,

    HistoryGradeF1,
    HistoryGradeF2,
    HistoryGradeF3,

    GeographyGradeF1,
    GeographyGradeF2,
    GeographyGradeF3,

    SociologyGradeF1,
    SociologyGradeF2,
    SociologyGradeF3,

    PhilosophyGradeF1,
    PhilosophyGradeF2,
    PhilosophyGradeF3,

    EnglishGradeF1, //lingua estrangeira/inglês
    EnglishGradeF2,
    EnglishGradeF3,

    ReligiousInstructionGradeF1, //ensino relogioso
    ReligiousInstructionGradeF2,
    ReligiousInstructionGradeF3,

    ProjectGradeF1,  //lingua estrangeira projeto
    ProjectGradeF2,
    ProjectGradeF3,

    MathProblemsGradeF1,
    MathProblemsGradeF2,
    MathProblemsGradeF3,

    TextProductionF1,
    TextProductionF2,
    TextProductionF3,

    FrequencyF1,
    FrequencyF2,
    FrequencyF3,


}StudentData;


class Reader
{
public:
    static QList<QHash<StudentData, QString>> readStudentsFrom(const QDir &studentSheetDir);

private:
    Reader();

    static QStringList getStudentSheetFilenamesFrom(const QDir &studentSheetDir);
    static QHash<StudentData, QString> getStudentsDataFrom(const QString &filename);


};



#endif // READER_H
