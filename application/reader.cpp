#include "reader.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>

#include <QtXlsx>

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


    return studentSheet;
}
