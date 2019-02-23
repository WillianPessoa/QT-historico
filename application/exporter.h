#ifndef EXPORTER_H
#define EXPORTER_H

#include "student.h"

#include <QDebug>
#include <QDir>
#include <QList>

class Exporter
{
public:
    void exportHistory(const QList<Student> &students);
    void exportHistory(const QList<Student> &students, const QDir &exportHistoryDir);

private:
    Exporter();

    bool checkDate(const Student &student);
};

#endif // EXPORTER_H
