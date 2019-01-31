#include "importer.h"

#include <QDir>

Importer::Importer()
{

}

QList<QHash<StudentData, QString>> Importer::importStudentsFrom(const QString &studentSheetDirName)
{
    return Reader::readStudentsFrom(QDir(studentSheetDirName));
}
