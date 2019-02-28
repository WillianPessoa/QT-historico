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
    file.close();
    return true;
}
QList<Student> DataPersist::loadData()
{
    QFile loadFile("database.json");
    QList<Student> studentList;

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Não foi possível abrir o banco de dados para leitura";
        return QList<Student>();
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonObject studentsObj = loadDoc.object();
    QJsonObject aluno;
    int i = 0;

    while(true){
        aluno = studentsObj.value(QString::number(i)).toObject();
        if(aluno == QJsonObject()){
            return studentList;
        }
        studentList.append(aluno);
        i++;
    }
}
DataPersist::DataPersist(QObject *parent) : QObject(parent)
{

}
