#ifndef EXPORTER_H
#define EXPORTER_H

#include "student.h"

#include <QDebug>
#include <QDir>
#include <QList>

#include "xlsxdocument.h"

class Exporter
{
public:
    static void exportHistoric(const QList<Student> &students);
    static void exportHistoric(const QList<Student> &students, const QDir &exportHistoryDir);
    static QString makeModelHistoricStudentAdress(const QString &nameOfStudent, const QDir &historicStudentDir);

private:
    Exporter();

};

#endif // EXPORTER_H
