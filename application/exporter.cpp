#include "exporter.h"

#include "studentmanager.h"

#include "xlsxdocument.h"

#include <QDebug>
#include <QDir>

Exporter::Exporter()
{

}

void Exporter::exportHistory(const QList<Student> &students)
{
    exportHistory(students, QDir::currentPath() + "/historical");
}

void Exporter::exportHistory(const QList<Student> &students, const QDir &exportHistoryDir)
{
    for(const Student &student : students){

        //Abrir modelo de histórico para escrever dados
        QXlsx::Document historic("modelHistoric.xlsx");

        //Verificar se dados dos alunos estão completos, antes de fazer o histórico
        //  - dados imcompletos: Fazer histórico e mostrar mensagem de histórico imcompleto

        //Gravar dados pessoais
        historic.write("J17", student.name());       //name
        historic.write("L19", student.dateOfBirth().toString("dd/MM/yyyy"));    //data de nascimento
        historic.write("G21", student.fatherName());         //pai
        historic.write("AD21", student.motherName());        //mae
        historic.write("I23", student.IDNumber());           //rg
        historic.write("AA23", student.IDIssuingInstitution());   //orgão expeditor
        historic.write("AP23", student.IDIssueDate());    //data de emissao

        //Gravar notas do 1º, 2º e 3º anos

        //salvar histórico
        historic.saveAs(exportHistoryDir.absolutePath());
    }
}

bool Exporter::checkDate(const Student &student)
{
    if(!(student.firstYearGrades().wasInitialized() ||
         student.secondYearGrades().wasInitialized() ||
         student.thirdYearGrades().wasInitialized())){
         return false;
    }
    return true;
}
