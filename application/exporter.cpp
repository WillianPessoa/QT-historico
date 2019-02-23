#include "exporter.h"
#include "studentmanager.h"

#include <QDebug>
#include <QDir>

Exporter::Exporter()
{

}

void Exporter::exportHistoric(const QList<Student> &students, const QDir &exportHistoryDir)
{
    for(const Student &student : students){

        //Armazena o endereço no sistema do modelo de histórico do modelo do aluno
        QString addressModelHistoricDir = exportHistoryDir.absolutePath() + "/" + student.name();

        //Copia modelo de histórico para a pasta indicada pelo usuário com nome do aluno
        QFile::copy(":/transcript/modelHistoric.xlsx", addressModelHistoricDir);

        //Abrir cópia do história no diretório especificado pelo usuário
        QXlsx::Document historic(addressModelHistoricDir);

        //Adicionar dados pessoais
        historic.write("J17", student.name());                                  //name
        historic.write("L19", student.dateOfBirth().toString("dd/MM/yyyy"));    //data de nascimento
        historic.write("G21", student.fatherName());                            //pai
        historic.write("AD21", student.motherName());                           //mae
        historic.write("I23", student.IDNumber());                              //rg
        historic.write("AA23", student.IDIssuingInstitution());                 //orgão expeditor
        historic.write("AP23", student.IDIssueDate());                          //data de emissao

        //Adicionar notas
        for(int grade = 1; grade <= 3; grade++){
            int column = 19;
            for(int line = 29; line < 45; line++){
                Grades gradeCurrent = student.getGrades(QString::number(grade));

                double gradeTemp = gradeCurrent.portugueseGrade();
                int workload = historic.read(line, column + 1).toInt();
                if(gradeTemp < 0 && workload == 0){
                    qDebug() << "Nota de " << historic.read(line, 3).toString() <<
                                " ou sua carga horaria invalida" << endl;
                }else{

                }
            }
        }

        //salvar histórico

    }
}

void Exporter::exportHistoric(const QList<Student> &students)
{
    exportHistoric(students, QDir::currentPath() + "/historical");
}

//bool Exporter::checkData(const Student &student)
//{
//    if(!(student.firstYearGrades().wasInitialized() ||
//         student.secondYearGrades().wasInitialized() ||
//         student.thirdYearGrades().wasInitialized())){
//         return false;
//    }
//    return true;
//}
