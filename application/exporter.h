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
    void exportHistoric(const QList<Student> &students);
    void exportHistoric(const QList<Student> &students, const QDir &exportHistoryDir);

private:
    Exporter();

    QXlsx::Document makeHistoric(const Student &student, QString addressModelHistoric);
};

#endif // EXPORTER_H
