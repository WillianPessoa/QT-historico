#include "exporter.h"

#include "xlsxdocument.h"

Exporter::Exporter()
{

}

void Exporter::exportHistory(const QList<Student> &students)
{

}

void Exporter::exportHistory(const QList<Student> &students, const QDir &exportHistoryDir)
{
    for(const Student &student : students){

        //Criar documento do modelo de histórico
        QXlsx::Document historic("modelHistoric.xlsx");

        //Gravar dados pessoais
        historic.write("J17", student.name());       //name
        historic.write("L19", student.dateOfBirth().toString("dd/MM/yyyy"));    //data de nascimento

        //Gravar notas do 1º, 2º e 3º anos

        //salvar histórico
        //historic.saveAs();
    }
}
