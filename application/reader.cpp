#include "reader.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>

#include <QtXlsx>

Reader::Reader()
{

}

QList<QHash<StudentData, QString>> Reader::readStudentsFrom(const QDir &studentSheetDir)
{
    QList<QHash<StudentData, QString>> data;

    QStringList studentSheetFiles(getStudentSheetFilenamesFrom(studentSheetDir));

    if (!studentSheetFiles.isEmpty()) {
        for (const QString &sheetFilename : studentSheetFiles) {
            data.append(getStudentsDataFrom(studentSheetDir.absolutePath() + "/" + sheetFilename));
        }
    }
    return data;
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

QHash<StudentData, QString> Reader::getStudentsDataFrom(const QString &filename)
{
    QHash<StudentData, QString> data;

    QXlsx::Document xlsx(filename);

    const QString name = xlsx.read("D13").toString().remove("NOME DO ALUNO : ").simplified();
    qDebug() << "Nome do aluno:" << name;
    data.insert(Name, name);

    // TODO: Realizar a leitura dos outros campos

    return data;
}
