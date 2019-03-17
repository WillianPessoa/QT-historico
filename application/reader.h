#ifndef READER_H
#define READER_H

#include "individualsheet.h"

#include <QList>

class QDir;

class Reader
{
public:
    static QList<IndividualSheet> readStudentsFrom(const QDir &studentSheetDir);

private:
    Reader();

    static QStringList getStudentSheetFilenamesFrom(const QDir &studentSheetDir);
    static IndividualSheet getStudentsDataFrom(const QString &filename);


};



#endif // READER_H
