#include "datapersist.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

bool DataPersist::saveData(QList<Student> list)
{
    QJsonObject studentsObj;
    for (int i = 0; i < list.size(); ++i) {
        QJsonObject aluno;
        list.at(i).writeInJsonObject(aluno);
        studentsObj.insert(QString::number(i), aluno);
    }

    QFile file("database.json");

    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Não foi possível abrir o banco de dados para escrita";
        return false;
    }

    QJsonDocument doc(studentsObj);
    file.write(doc.toJson());
    return true;
}

DataPersist::DataPersist(QObject *parent) : QObject(parent)
{

}
