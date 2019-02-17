#ifndef IMPORTER_H
#define IMPORTER_H

#include "reader.h"

class Importer
{
public:
    static QList<IndividualSheet> importStudentsFrom(const QString &studentSheetDirName);

private:
    Importer();
};

#endif // IMPORTER_H
