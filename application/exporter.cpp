#include "exporter.h"

#include "xlsxdocument.h"

Exporter::Exporter()
{

}

void Exporter::exportHistory(const QList<Student> &students)
{
    for(const Student &student : students){

            //Criar documento do modelo de histórico
            QXlsx::Document historic("modelHistoric.xlsx");

            //Gravar notas do 1º, 2º e 3º anos

            //salvar histórico
            historic.saveAs("./historical/" + student.name());
        }
}

void Exporter::exportHistory(const QList<Student> &students, const QDir &exportHistoryDir)
{

}
