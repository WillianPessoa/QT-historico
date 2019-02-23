#ifndef DATAPERSIST_H
#define DATAPERSIST_H

#include <QObject>

#include "student.h"

class DataPersist : public QObject
{
    Q_OBJECT
public:

signals:

public slots:
    static bool saveData(QList<Student> list);
private:
    explicit DataPersist(QObject *parent = nullptr);

};

#endif // DATAPERSIST_H
