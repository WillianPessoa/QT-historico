#ifndef EXPORTER_H
#define EXPORTER_H

#include "student.h"

#include <QDir>
#include <QList>

class Exporter
{
public:
    void exportHistory(const QList<Student> &students);
    void exportHistory(const QList<Student> &students, const QDir &exportHistoryDir);

private:
    Exporter();
};

#endif // EXPORTER_H
