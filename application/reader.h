#ifndef READER_H
#define READER_H

#include <QList>
#include <QHash>

class QDir;

typedef enum _StudentData{
    Name,
    IDNumber,
    IDDateExpedition,
    IDOrganDispatcher
}StudentData;

class Reader
{
public:
    static QList<QHash<StudentData, QString>> readStudentsFrom(const QDir &studentSheetDir);

private:
    Reader();

    static QStringList getStudentSheetFilenamesFrom(const QDir &studentSheetDir);
    static QHash<StudentData, QString> getStudentsDataFrom(const QString &filename);


};

#endif // READER_H
