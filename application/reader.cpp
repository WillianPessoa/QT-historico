#include "reader.h"

#include "xlsxdocument.h"

#include <cassert>

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>

#include "xlsxdocument.h"

Reader::Reader()
{

}

QList<IndividualSheet> Reader::readStudentsFrom(const QDir &studentSheetDir)
{
    QList<IndividualSheet> studentSheets;

    QStringList studentSheetFiles(getStudentSheetFilenamesFrom(studentSheetDir));

    if (!studentSheetFiles.isEmpty()) {
        for (const QString &sheetFilename : studentSheetFiles) {
            studentSheets.append(getStudentsDataFrom(studentSheetDir.absolutePath() + "/" + sheetFilename));
        }
    }
    return studentSheets;
}

QStringList Reader::getStudentSheetFilenamesFrom(const QDir &studentSheetDir)
{
    QStringList studentSheetFiles;
    if (studentSheetDir.isReadable()) {
        studentSheetFiles << studentSheetDir.entryList(QStringList() << "*.xlsx", QDir::Files);

        // TODO: Verificar se os arquivos *.xslx são fichas válidas.
        //       Caso não sejam, excluí-los da lista.

        if (studentSheetFiles.isEmpty()) {
            qDebug() << "O diretório \"" << studentSheetDir.absolutePath() << "\" não contém fichas de estudantes";
        } else {
            qDebug() << "Arquivos encontrados: ";
            for (const QString &sheetFilename : studentSheetFiles) {
                qDebug () << "\t" << sheetFilename;
            }
        }
    } else {
        qDebug () << "O diretório " << studentSheetDir.absolutePath() << " não está disponível para leitura";
    }
    return studentSheetFiles;
}

IndividualSheet Reader::getStudentsDataFrom(const QString &filename)
{
    IndividualSheet studentSheet;

    QXlsx::Document xlsx(filename);

    const QString name = xlsx.read("D13").toString().remove("NOME DO ALUNO : ").simplified();
    qDebug() << "Nome do aluno:" << name;
    studentSheet.setName(name);

    // TODO: Realizar a leitura dos outros campos

    const QString mothername = xlsx.read("Z16").toString().remove("MÃE:").simplified();
    qDebug() << "Mãe: " << mothername;
    studentSheet.setMotherName(mothername);  //Pega o nome da mãe

    const QString fathername = xlsx.read("L16").toString().remove("PAI:").simplified();
    qDebug() << "Pai: " << fathername;
    studentSheet.setFatherName(fathername);  //Pega o nome do pai

    const QString fullDate = xlsx.read("W13").toString().remove("DATA DE NASCIMENTO : ").simplified().split(" ").first();
    qDebug() << "Data de nascimento:" << fullDate;
    const QStringList splitedDate = fullDate.split("/");
    assert(splitedDate.size() == 3);
    const QDate dateofbirth(splitedDate.at(2).toDouble(), splitedDate.at(1).toDouble(), splitedDate.at(0).toDouble());
    studentSheet.setDateOfBirth(dateofbirth); //Data de nascimento e hora

    const QString naturalness = xlsx.read("D16").toString().remove("NATURAL:").simplified();
    qDebug() << "Natural:" << naturalness;
    studentSheet.setNaturalness(naturalness);

    const QString sexStr = xlsx.read("AG12").toString().remove("SEXO:").simplified();
    qDebug() << "Sexo: " << sexStr;
    studentSheet.setSex(sexStr == "M" ? Feminine : Masculine);

    const QString year = xlsx.read("AD20").toString().remove("ANO:").simplified();
    qDebug() << "Ano: " << year;
    studentSheet.setYear(year);

    const QString gradeYear = xlsx.read("R21").toString().remove("SÉRIE:").simplified();
    qDebug() << "Série: " << gradeYear;
    studentSheet.setGrade(gradeYear);

    const QString group = xlsx.read("J21").toString().remove("TURMA:").simplified();
    qDebug() << "Turma: " << group;
    studentSheet.setGroup(group);

    const QString turnStr = xlsx.read("X21").toString().remove("TURNO:").simplified();
    qDebug() << "Turno: " << turnStr;
    studentSheet.setTurn(turnStr == "M" ? Diurnal : Nocturnal);

    // Identificar a primeira celula (linha) que contem as notas
    // Verificar cada campo importante da linha, pra identificar qual materia estamos lendo
    // Depois de identificar, guardar no seu devido local
    const int subjectColumn = 7;
    const int gradeColumn = 34;
    QString subject = "None";
    double grade = -1;
    for (int row = 25;; ++row) {
        subject = xlsx.read(row, subjectColumn).toString();

        if (subject.isEmpty()){
            break;
        }

        grade = xlsx.read(row, gradeColumn).toString().toDouble();
        qDebug() << "Materia: " << subject << " | Nota: " << grade;

        if (subject == "ARTES") {
            studentSheet.setArtGrade(grade);
        } else if (subject == "BIOLOGIA") {
            studentSheet.setBiologyGrade(grade);
        } else if (subject == "EDUCAÇÃO FÍSICA") {
            studentSheet.setPhysicalEducationGrade(grade);
        } else if (subject == "FILOSOFIA") {
            studentSheet.setPhilosophyGrade(grade);
        } else if (subject == "GEOGRAFIA") {
            studentSheet.setGeographyGrade(grade);
        } else if (subject.contains("LINGUA ESTRANGEIRA")) {
            studentSheet.setEnglishGrade(grade);
        } else if (subject == "HISTÓRIA") {
            studentSheet.setHistoryGrade(grade);
        } else if (subject == "MATEMÁTICA") {
            studentSheet.setMathGrade(grade);
        } else if (subject == "LÍNGUA PORTUGUESA/LITERATURA") {
            studentSheet.setPortugueseGrade(grade);
        } else if (subject == "PRODUÇÃO TEXTUAL") {
            studentSheet.setTextProductionGrade(grade);
        } else if (subject == "PROJETO") {
            studentSheet.setProjectGrade(grade);
        } else if(subject == "QUÍMICA") {
            studentSheet.setChemistryGrade(grade);
        } else if (subject == "ENSINO RELIGIOSO/PROJETO") {
            studentSheet.setReligiousGrade(grade);
        } else if (subject == "SOCIOLOGIA") {
            studentSheet.setChemistryGrade(grade);
        }

        // Retornando para um valor default
        subject = "None";
        grade = -1;
    }

    return studentSheet;
}
