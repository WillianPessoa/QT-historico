#include "exporter.h"
#include "studentmanager.h"

#include <QDebug>
#include <QDir>

Exporter::Exporter()
{

}

 QString Exporter::makeModelHistoricStudentAdress(const QString &nameOfStudent, const QDir &historicStudentDir)
{
    //Endereço com nome do estudante para salvar
    const QString adressSaveStudent = historicStudentDir.absolutePath() + "/" + nameOfStudent + ".xlsx";

    //Abrindo documento do tipo xlsx para escrever o modelo de histórico
    QXlsx::Document historic;

    //TODO: Começar a escrever o código para gerar o modelo de histórico dessa parte para baixo
    historic.write("J5", "GOVERNO DO ESTADO DO RIO DE JANEIRO");
    historic.write("J6","SECRETARIA DE ESTADO DE EDUCAÇÃO");
    historic.write("C8","CIEP-BRIZOLÃO 165 -  BRIGADEIRO SERGIO CARVALHO\n\t\t\tEstabelecimento de Ensino");
    historic.write("C12","Estrada do Lameirão Pequeno, s/nº-Campo Grande/RJ Endereço");
    historic.write("C14","HISTÓRICO ESCOLAR");
    historic.write("C15","CURSO: ENSINO MÉDIO");
    historic.write("C17","NOME DO ALUNO: ");
    historic.write("C19","DATA DE NASCIMENTO: ");
    historic.write("S19","NACIONALIDADE: ");
    historic.write("AI19","NATURALIDADE: ");
    historic.write("C21","FILIAÇÃO: ");
    historic.write("AC21","E");
    historic.write("C23","IDENTIDADE Nº: ");
    historic.write("S23","ORGÃO EXPEDITOR: ");
    historic.write("AI23","DATA DE EMISSÂO: ");
    historic.write("C25","DISCIPLINAS");

    //Matérias
    historic.write("C29","LÍNGUA PORTUGUESA E LITERATURA");
    historic.write("C30","ARTE");
    historic.write("C31","ED. FÍSICA");
    historic.write("C32","MATEMÁTICA");
    historic.write("C33","QUÍMICA");
    historic.write("C34","FÍSICA");
    historic.write("C35","BIOLOGIA");
    historic.write("C36","HISTÓRIA");
    historic.write("C37","GEOGRAFIA");
    historic.write("C38","SOCIOLOGIA");
    historic.write("C39","FILOSOFIA");
    historic.write("C40","LINGUA ESTRANGEIRA / INGLÊS");
    historic.write("C41","ENSINO RELIGIOSO/PROJETO");
    historic.write("C42","LÍNGUA ESTRANGEIRA/PROJETO");
    historic.write("C43","RES. PROBL. MATEMÁTICOS");
    historic.write("C44","PROD. TEXTUAL");
    historic.write("C49","TOTAL");
    historic.write("C50","% FREQUÊNCIA ANUAL");
    historic.write("S50",">75%"); //frequencia anual
    historic.write("C51","SITUAÇÃO FINAL");

    //*******Primeiro ano*******
    historic.write("S25","ANO: ");
    historic.write("W25","2016"); //alterar o 2016 pelo ano da individualsheet
    historic.write("S27","1º ANO");
    historic.write("S28","Nota/Conc");

    //carga horaria(deixar os numeros por padrao ou alterar)
    historic.write("W28","C/H");
    historic.write("W29","240"); //c.h portugues
    historic.write("W30",""); //c.h arte
    historic.write("W31","80"); //c.h ed fisica
    historic.write("W32","240"); //c.h matematica
    historic.write("W33","80"); //c.h quimica
    historic.write("W34","80"); //c.h fisica
    historic.write("W35","80"); //c.h biologia
    historic.write("W36","80"); //c.h historia
    historic.write("W37","80"); //c.h geografia
    historic.write("W38","40"); //c.h sociologia
    historic.write("W39","40"); //c.h filosofia
    historic.write("W40","80"); //c.h ingles
    historic.write("W41","40"); //c.h ensino religioso
    historic.write("W42","40"); //c.h lingua estrangeira projeto
    historic.write("W43",""); //c.h rpm
    historic.write("W44",""); //c.h produção textual
    historic.write("W49","1200"); //c.h total

    //inserção das notas (substituir os numeros pelo treco que pega as notas)
    historic.write("S29","0"); //portugues
    historic.write("S30","1"); //arte
    historic.write("S31","2"); //ed fisica
    historic.write("S32","3"); //matematica
    historic.write("S33","4"); //quimica
    historic.write("S34","5"); //fisica
    historic.write("S35","6"); //biologia
    historic.write("S36","7"); //historia
    historic.write("S37","8"); //geografia
    historic.write("S38","9"); //sociologia
    historic.write("S39","10"); //filosofia
    historic.write("S40","11"); //ingles
    historic.write("S41","12"); //ensino religioso
    historic.write("S42","13"); //lingua estrangeira projeto
    historic.write("S43","14"); //rpm
    historic.write("S44","15"); //produção textual
    historic.write("S51","APROVADO");


    //*******SEGUNDO ANO*******
    historic.write("AA25","ANO: ");
    historic.write("AE25","2017"); //alterar o 2016 pelo ano da individualsheet
    historic.write("AA27","2º ANO/ I");
    historic.write("AA28","Nota/Conc");


    //carga horaria(deixar os numeros por padrao ou alterar)
    historic.write("AE28","C/H");
    historic.write("AE29","160"); //c.h portugues
    historic.write("AE30","80"); //c.h arte
    historic.write("AE31","80"); //c.h ed fisica
    historic.write("AE32","160"); //c.h matematica
    historic.write("AE33","80"); //c.h quimica
    historic.write("AE34","80"); //c.h fisica
    historic.write("AE35","80"); //c.h biologia
    historic.write("AE36","80"); //c.h historia
    historic.write("AE37","80"); //c.h geografia
    historic.write("AE38","40"); //c.h sociologia
    historic.write("AE39","40"); //c.h filosofia
    historic.write("AE40","80"); //c.h ingles
    historic.write("AE41","40"); //c.h ensino religioso
    historic.write("AE42","40"); //c.h lingua estrangeira projeto
    historic.write("AE43","80"); //c.h rpm
    historic.write("AE44",""); //c.h produção textual
    historic.write("AE49","1200"); //c.h total

    //inserção das notas (substituir os numeros pelo treco que pega as notas)
    historic.write("AA29","0"); //portugues
    historic.write("AA30","1"); //arte
    historic.write("AA31","2"); //ed fisica
    historic.write("AA32","3"); //matematica
    historic.write("AA33","4"); //quimica
    historic.write("AA34","5"); //fisica
    historic.write("AA35","6"); //biologia
    historic.write("AA36","7"); //historia
    historic.write("AA37","8"); //geografia
    historic.write("AA38","9"); //sociologia
    historic.write("AA39","10"); //filosofia
    historic.write("AA40","11"); //ingles
    historic.write("AA41","12"); //ensino religioso
    historic.write("AA42","13"); //lingua estrangeira projeto
    historic.write("AA43","14"); //rpm
    historic.write("AA44","15"); //produção textual
    historic.write("AA51","APROVADO ");

    //*******TeRcEiRo AnO*******
    historic.write("AI25","ANO: ");
    historic.write("AM25","2018"); //alterar o 2016 pelo ano da individualsheet
    historic.write("AI27","3º ANO");
    historic.write("AI28","Nota/Conc");

    //carga horaria(deixar os numeros por padrao ou alterar)
    historic.write("AM28","C/H");
    historic.write("AM29","160"); //c.h portugues
    historic.write("AM30",""); //c.h arte
    historic.write("AM31","80"); //c.h ed fisica
    historic.write("AM32","160"); //c.h matematica
    historic.write("AM33","80"); //c.h quimica
    historic.write("AM34","80"); //c.h fisica
    historic.write("AM35","80"); //c.h biologia
    historic.write("AM36","80"); //c.h historia
    historic.write("AM37","80"); //c.h geografia
    historic.write("AM38","80"); //c.h sociologia
    historic.write("AM39","80"); //c.h filosofia
    historic.write("AM40","80"); //c.h ingles
    historic.write("AM41","40"); //c.h ensino religioso
    historic.write("AM42","40"); //c.h lingua estrangeira projeto
    historic.write("AM43",""); //c.h rpm
    historic.write("AM44","80"); //c.h produção textual
    historic.write("AM49","1200"); //c.h total

    //inserção das notas (substituir os numeros pelo treco que pega as notas)
    historic.write("AI29","0"); //portugues
    historic.write("AI30","1"); //arte
    historic.write("AI31","2"); //ed fisica
    historic.write("AI32","3"); //matematica
    historic.write("AI33","4"); //quimica
    historic.write("AI34","5"); //fisica
    historic.write("AI35","6"); //biologia
    historic.write("AI36","7"); //historia
    historic.write("AI37","8"); //geografia
    historic.write("AI38","9"); //sociologia
    historic.write("AI39","10"); //filosofia
    historic.write("AI40","11"); //ingles
    historic.write("AI41","12"); //ensino religioso
    historic.write("AI42","13"); //lingua estrangeira projeto
    historic.write("AI43","14"); //rpm
    historic.write("AI44","15"); //produção textual
    historic.write("AI51","APROVADO");

    //CARGA HORARIA TOTAL
    historic.write("AQ25","CARGA HORÁRIA");
    historic.write("AQ27","TOTAL");
    historic.write("AQ29","560"); //c.h portugues
    historic.write("AQ30","80"); //c.h arte
    historic.write("AQ31","240"); //c.h ed fisica
    historic.write("AQ32","560"); //c.h matematica
    historic.write("AQ33","240"); //c.h quimica
    historic.write("AQ34","240"); //c.h fisica
    historic.write("AQ35","240"); //c.h biologia
    historic.write("AQ36","240"); //c.h historia
    historic.write("AQ37","240"); //c.h geografia
    historic.write("AQ38","160"); //c.h sociologia
    historic.write("AQ39","160"); //c.h filosofia
    historic.write("AQ40","240"); //c.h ingles
    historic.write("AQ41","120"); //c.h ensino religioso
    historic.write("AQ42","120"); //c.h lingua estrangeira projeto
    historic.write("AQ43","80"); //c.h rpm
    historic.write("AQ44","80"); //c.h produção textual
    historic.write("AQ49","3600"); //c.h c.h total

    //PARTE DE BAIXO DO HISTORICO(estabelecimento de ensino)
    historic.write("C52","Série/Ano");
    historic.write("F52","ESTABELECIMENTO DE ENSINO");
    historic.write("AE52","MUNICÍPIO / ESTADO");
    historic.write("AQ52","ANO");
    //Primeiro ano
    historic.write("C53","1ª");
    historic.write("F53","CIEP 165  BRIGADEIRO SÉRGIO CARVALHO  ");
    historic.write("AE53","RIO DE JANEIRO/RJ");
    historic.write("AQ53","2016"); //substituir pelo ano desejado
    //Segundo ano
    historic.write("C54","2ª");
    historic.write("F54","CIEP 165  BRIGADEIRO SÉRGIO CARVALHO  ");
    historic.write("AE54","RIO DE JANEIRO/RJ");
    historic.write("AQ54","2017"); //substituir pelo ano desejado
    //Terceiro ano
    historic.write("C55","3ª");
    historic.write("F55","CIEP 165  BRIGADEIRO SÉRGIO CARVALHO  ");
    historic.write("AE55","RIO DE JANEIRO/RJ");
    historic.write("AQ55","2018"); //substituir pelo ano desejado

    //FINAL
    historic.write("C56","OBSERVAÇÕES: ");
    historic.write("C59","Segue em Anexo  Histórico Escolar Anterior emitido pelo CE Professor Fernando Antonio Raja Gabaglia, de acordo com  Deliberação  CEE nº 363/17 , art. 5º.");
    historic.write("M64","                           DATA DA EXPEDIÇÃO: ");
    historic.write("Y64","RJ,   14/01/2019"); //substitur pela data de criação
    historic.write("D67","_________________________________"); //campo de assinatura do secretario
    historic.write("D68","SECRETÁRIO ESCOLAR");
    historic.write("AE67","________________________________"); //campo de assinatura do diretor
    historic.write("AA68","DIRETOR");
    //Escrevendo os dados do 1° ano






    //Salvando histórico na pasta especificada pelo usuário com o nome do estudante no arquivo
    historic.saveAs(adressSaveStudent);

    //Retorna endereço em que o modelo de histórico do aluno esta contido para a escrita de dados
    return adressSaveStudent;
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
