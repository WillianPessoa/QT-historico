#include "importer.h"

#include <QDir>

Importer::Importer()
{

}

QList<IndividualSheet> Importer::importStudentsFrom(const QString &studentSheetDirName)
{
    return Reader::readStudentsFrom(QDir(studentSheetDirName));
}
