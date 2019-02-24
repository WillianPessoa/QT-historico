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

        qDebug() << "Montando histórico do aluno(a) " << student.name() << endl;

        //Armazena o endereço no sistema do modelo de histórico do modelo do aluno
        const QString addressModelHistoricStudent = exportHistoryDir.absolutePath() + "/" + student.name() + ".xlsx";

        //Copia modelo de histórico para a pasta indicada pelo usuário com nome do aluno
        QFile::copy(":/transcript/modelHistoric.xlsx", addressModelHistoricStudent);

        //Abrir cópia do histórico no diretório especificado pelo usuário
        QXlsx::Document historic(addressModelHistoricStudent);

        //Adicionar dados pessoais
        qDebug() << "Gravando dados pessoais ..." << endl;

        const QString name = student.name();
        historic.write("J17", name);                                  //name
        qDebug() << "Nome: " << name << endl;

        const QString dateOfBirth = student.dateOfBirth().toString("dd/MM/yyyy");
        historic.write("L19", dateOfBirth);    //data de nascimento
        qDebug() << "Data de Nascimento: " << dateOfBirth << endl;

        const QString fatherName = student.fatherName();
        historic.write("G21", fatherName);                            //pai
        qDebug() << "Nome do pai: " << fatherName << endl;

        const QString motherName = student.motherName();
        historic.write("AD21", motherName);                           //mae
        qDebug() << "Nome da Mãe: " << motherName << endl;

        const QString IDNumber = student.IDNumber();
        historic.write("I23", IDNumber);                              //rg
        qDebug() << "Número da Identidade: " << IDNumber << endl;

        const QString IDIssuingInstitution = student.IDIssuingInstitution();
        historic.write("AA23", student.IDIssuingInstitution());                 //orgão expeditor
        qDebug() << "Orgão de Expedição: " << IDIssuingInstitution << endl;

        const QString IDIssueDate = student.IDIssueDate();
        historic.write("AP23", IDIssueDate);                          //data de emissao
        qDebug() << "Data de Emissão: " << IDIssueDate << endl;

        //Adicionar notas
        const QString subjectLetter = "C";
        const QStringList gradesLetters = {"S", "AA", "AI"};
        const QStringList hourLetters = {"W", "AE", "AM"};

        bool dataComplete = true;

        for(int grade = 1; grade <= 3; grade++){

            Grades gradesCurrent = student.getGrades(QString::number(grade));

            if(!gradesCurrent.wasInitialized()){
                dataComplete = false;
                continue;
            }

            qDebug() << "Adicionando notas do " << grade << "º ano ...\n" << endl;
            for(int line = 29; line < 45; line++){

                double gradeTemp = 0;
                QString lineString = QString::number(line);

                //Estrutura de decisões para achar a nota da matéria
                QString subjectCell = historic.read(subjectLetter + lineString).toString();

                qDebug() << "Cúlula da Materia: " << subjectLetter + lineString << endl;
                qDebug() << "Matéria lida do histórico: " << subjectCell << endl;

                if(subjectCell == "LÍNGUA PORTUGUESA E LITERATURA"){
                    gradeTemp = gradesCurrent.portugueseGrade();
                }else if(subjectCell == "ARTE"){
                    gradeTemp = gradesCurrent.artGrade();
                }else if(subjectCell == "ED. FÍSICA"){
                    gradeTemp = gradesCurrent.physicalEducationGrade();
                }else if(subjectCell == "MATEMÁTICA"){
                    gradeTemp = gradesCurrent.mathGrade();
                }else if(subjectCell == "QUÍMICA"){
                    gradeTemp = gradesCurrent.chemistryGrade();
                }else if(subjectCell == "FÍSICA"){
                    gradeTemp = gradesCurrent.physicsGrade();
                }else if(subjectCell == "BIOLOGIA"){
                    gradeTemp = gradesCurrent.biologyGrade();
                }else if(subjectCell == "HISTÓRIA"){
                    gradeTemp = gradesCurrent.historyGrade();
                }else if(subjectCell == "GEOGRAFIA"){
                    gradeTemp = gradesCurrent.geographyGrade();
                }else if(subjectCell == "SOCIOLOGIA"){
                    gradeTemp = gradesCurrent.sociologyGrade();
                }else if(subjectCell == "FILOSOFIA"){
                    gradeTemp = gradesCurrent.philosophyGrade();
                }else if(subjectCell == "LINGUA ESTRANGEIRA / INGLÊS"){
                    gradeTemp = gradesCurrent.englishGrade();
                }else if(subjectCell == "ENSINO RELIGIOSO/PROJETO"){
                    gradeTemp = gradesCurrent.religiousGrade();
                }else if(subjectCell == "LÍNGUA ESTRANGEIRA/PROJETO"){
                    gradeTemp = gradesCurrent.projectGrade();
                }else if(subjectCell == "RES. PROBL. MATEMÁTICOS"){
                    gradeTemp = gradesCurrent.mathProblemSolvingGrade();
                }else if(subjectCell == "PROD. TEXTUAL"){
                    gradeTemp = gradesCurrent.textProductionGrade();
                }

                //Escrever nota
                int workLoad = historic.read(hourLetters.at(grade - 1) + lineString).toInt();
                if(gradeTemp < 0 && workLoad == 0){
                    qDebug() << "Nota de " << subjectCell
                             << " ou/e sua carga horaria é invalida." << endl;
                }else if(gradeTemp < 0 && workLoad != 0){
                    historic.write(gradesLetters.at(grade - 1) + lineString, "*");
                }else{
                    historic.write(gradesLetters.at(grade - 1) + lineString, gradeTemp);
                    qDebug() << "Materia: " << subjectCell << " | " << "Nota: " << gradeTemp << endl;
                }
            }
        }

        if(!dataComplete){
            qDebug() << "O histórico do aluno(a) " << student.name() << " foi feito com os dados imcompletos." << endl;
        }

        //salvar histórico
        qDebug() << "HISTÓRICO PRONTO!\n" << endl;
        qDebug() << "Salvo no endereço: " << addressModelHistoricStudent << endl;
        historic.saveAs(addressModelHistoricStudent);
    }
}

void Exporter::exportHistoric(const QList<Student> &students)
{
    exportHistoric(students, QDir("../historical"));
}
