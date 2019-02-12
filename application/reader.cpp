#include "reader.h"

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
    qDebug() << "Mãe:" << mothername;
    studentSheet.setMotherName(mothername);  //Pega o nome da mãe

    const QString fathername = xlsx.read("L16").toString().remove("PAI:").simplified();
    qDebug() << "Pai:" << fathername;
    studentSheet.setFatherName(fathername);  //Pega o nome do pai

    const QString dateofbirth = xlsx.read("W13").toString().remove("DATA DE NASCIMENTO : ").simplified();
    qDebug() << "Data de nascimento:" << dateofbirth;
    studentSheet.setDateOfBirth(dateofbirth); //Data de nascimento e hora

    const QString naturalness = xlsx.read("D16").toString().remove("NATURAL:").simplified();
    qDebug() << "Natural:" << naturalness;
    studentSheet.setNaturalness(naturalness);

    // Identificar a primeira celula (linha) que contem as notas
    // Verificar cada campo importante da linha, pra identificar qual materia estamos lendo
    // Depois de identificar, guardar no seu devido local
    const int subjectColumn = 7;
    const int gradeColumn = 34;
    QString subject = "Subject";
    for (int row = 25; !subject.isEmpty(); ++row) {
        subject = xlsx.read(row, subjectColumn).toString();
        const QString grade = xlsx.read(row, gradeColumn).toString();
        qDebug() << "Materia: " << subject << " | Nota: " << grade;


        if (subject == "ARTES") {
            studentSheet.setArtGrade(grade.toDouble());
        } else if (subject == "BIOLOGIA") {
            studentSheet.setBiologyGrade(grade.toDouble());
        } else if (subject == "EDUCAÇÃO FÍSICA"){
            studentSheet.setPhysicalEducationGrade(grade.toDouble());
        } else if (subject == "FILOSOFIA"){
            studentSheet.setPhilosophyGrade(grade.toDouble());
        } else if (subject == "GEOGRAFIA"){
            studentSheet.setGeographyGrade(grade.toDouble());
        } else if (subject.contains("LINGUA ESTRANGEIRA")) {
            studentSheet.setEnglishGrade(grade.toDouble());
        } else if (subject == "HISTÓRIA") {
            studentSheet.setHistoryGrade(grade.toDouble());
        } else if (subject == "MATEMÁTICA"){
            studentSheet.setMathGrade(grade.toDouble());
        } else if (subject == "") {

        } else if(subject == "QUÍMICA"){
            studentSheet.setChemistryGrade(grade.toDouble());
        }
    }


    return studentSheet;
}
