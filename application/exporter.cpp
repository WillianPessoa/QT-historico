#include "exporter.h"
#include "studentmanager.h"

Exporter::Exporter()
{

}

 QString Exporter::makeModelHistoricStudentAdress(const QString &nameOfStudent, const QDir &historicStudentDir)
{
    //Endereço com nome do estudante para salvar
    const QString adressSaveModelHistoricStudent = historicStudentDir.absolutePath() + "/" + nameOfStudent + ".xlsx";

    //Abrindo documento do tipo xlsx para escrever o modelo de histórico
    QXlsx::Document historic;

    //****definindo variaveis de formatação das células
    //Coloca em negrito e no centro
    QXlsx::Format formatBoldAlignHCenter;
    formatBoldAlignHCenter.setFontBold(true);
    formatBoldAlignHCenter.setHorizontalAlignment(QXlsx::Format::AlignHCenter);

    //Coloca em negrito, no centro e sublinhado
    QXlsx::Format formatBoldAlignHCenterUnderline(formatBoldAlignHCenter);
    formatBoldAlignHCenterUnderline.setFontUnderline(QXlsx::Format::FontUnderlineSingle);

    //coloca no centro
    QXlsx::Format formatAlignHCenter;
    formatAlignHCenter.setHorizontalAlignment(QXlsx::Format::AlignHCenter);

    //coloca em negrito
    QXlsx::Format formatBold;
    formatBold.setFontBold(true);

    //coloca em negrito e sublinhado
    QXlsx::Format formatBoldUnderline(formatBold);
    formatBoldUnderline.setFontUnderline(QXlsx::Format::FontUnderlineSingle);

    //coloca no centro horizontal e vertical
    QXlsx::Format formatAlignHVCenter(formatAlignHCenter);
    formatAlignHVCenter.setVerticalAlignment(QXlsx::Format::AlignVCenter);

    //coloca em negrito, no centro, tanto na vertical, quanto na horizonatal
    QXlsx::Format formatBoldAlignHVCenter(formatBoldAlignHCenter);
    formatBoldAlignHVCenter.setVerticalAlignment(QXlsx::Format::AlignVCenter);

    //coloca no canto superior esquerdo
    QXlsx::Format formatAlignTopLeft;
    formatAlignTopLeft.setVerticalAlignment(QXlsx::Format::AlignTop);
    formatAlignTopLeft.setHorizontalAlignment(QXlsx::Format::AlignLeft);

    //coloca em negrito e no canto superior esquerdo
    QXlsx::Format formatBoldAlignTopLeft(formatAlignTopLeft);
    formatBoldAlignTopLeft.setFontBold(true);

    //Mesclando celulas do cabeçalho
    historic.mergeCells("C2:H2");       //texto do governo
    historic.mergeCells("C3:H3");       //texto da secretaria
    historic.mergeCells("A6:F6");       //nome da escola
    historic.mergeCells("A7:F7");       //endereço da escola
    historic.mergeCells("A9:F9");       //escrito endereço
    historic.mergeCells("A10:F10");     //tipo de estabelecimento
    historic.mergeCells("A11:M11");     //titulo do histórico
    historic.mergeCells("B12:C12");     //Tipo de curso

    //*******Mesclando células que tem textos fixos no modelo de histórico*******
    historic.mergeCells("A13:B13");     //Nome do aluno
    historic.mergeCells("A14:B14");     //Data de Nascimento --> Pesquisar como aumentar tamanho de celula
    historic.mergeCells("E14:F14");     //nacionalidade
    historic.mergeCells("J14:K14");     //naturalidade
    historic.mergeCells("A16:B16");     //identidade
    historic.mergeCells("F16:G16");     //orgão expedidor
    historic.mergeCells("J16:K16");     //data da emissão
    historic.mergeCells("A17:D20");     //disciplinas
    historic.mergeCells("E17:F18");     //Ano do 1º ano
    historic.mergeCells("G17:H18");     //Ano do 2º ano
    historic.mergeCells("I17:J18");     //Ano do 3º ano
    historic.mergeCells("K17:M18");     //Carga Horária
    historic.mergeCells("E19:F19");     //1º Ano
    historic.mergeCells("G19:H19");     //2º Ano
    historic.mergeCells("I19:J19");     //3º Ano
    historic.mergeCells("K19:M19");     //Total
    historic.mergeCells("K20:M20");     //Total

    //Mesclando Células para adicionar nomes fixos de matérias e cargas horárias
    for(int row = 21; row <= 43; row++){
        QString rowStr = QString::number(row);
        QString rangeCellsSubject = "A" + rowStr + ":" + "D" + rowStr;
        QString rangeCellsTime = "K" + rowStr + ":" + "M" + rowStr;
        historic.mergeCells(rangeCellsSubject);     //subject
        historic.mergeCells(rangeCellsTime);        //carga horária
    }

    //Mesclando células para adionar aprovado em cada um dos três anos
    historic.mergeCells("E43:F43");     //Aprovado 1º Ano
    historic.mergeCells("G43:H43");     //Aprovado 2º Ano
    historic.mergeCells("I43:J43");     //Aprovado 3º Ano

    //Mesclando células com nomes da escola, do estado e os anos de ensino
    for(int row = 44; row <= 47; row++){
        QString rowStr = QString::number(row);
        QString rangeCellsSchoolName = "B" + rowStr + ":" + "G" + rowStr;
        QString rangeCellsStateName =  "H" + rowStr + ":" + "J" + rowStr;
        QString rangeCellsYears =  "K" + rowStr + ":" + "M" + rowStr;

        historic.mergeCells(rangeCellsSchoolName);
        historic.mergeCells(rangeCellsStateName);
        historic.mergeCells(rangeCellsYears);
    }

    historic.mergeCells("A48:M50");     //observações
    historic.mergeCells("A51:M54");     //escola anterior e outras informações
    historic.mergeCells("A55:M56");     //data de expedição
    historic.mergeCells("A57:M58");
    historic.mergeCells("B59:E59");     //Linha de Assinatura da Secretária
    historic.mergeCells("H59:K59");     //Linha de Assinatura do diretor
    historic.mergeCells("B60:E60");     //Assinatura da Secretária
    historic.mergeCells("H60:K60");     //Assinatura do diretor
    historic.mergeCells("A61:M63");

    //Espaços em branco
    historic.mergeCells("A59:A60");
    historic.mergeCells("F59:G60");
    historic.mergeCells("L59:M60");

    //Mesclando células para exportar dados
    historic.mergeCells("C13:M13");     //nome do aluno
    historic.mergeCells("C14:D14");     //data de nascimento
    historic.mergeCells("G14:I14");     //nacionalidade
    historic.mergeCells("L14:M14");     //naturalidade
    historic.mergeCells("B15:G15");     //nome do pai
    historic.mergeCells("I15:M15");     //nome da mãe
    historic.mergeCells("C16:E16");     //identidade
    historic.mergeCells("H16:I16");     //orgão expedidor
    historic.mergeCells("L16:M16");     //data da emissão

    //Escrevendos dados fixos do histórico
    historic.write("C2", "GOVERNO DO ESTADO DO RIO DE JANEIRO", formatBoldAlignHCenter);
    historic.write("C3", "SECRETARIA DE ESTADO DE EDUCAÇÃO", formatBoldAlignHCenter);
    historic.write("A6","CIEP-BRIZOLÃO 165 - BRIGADEIRO SERGIO CARVALHO", formatBoldAlignHCenterUnderline);
    historic.write("A7", "Estabelecimento de Ensino", formatAlignHCenter);
    historic.write("A9","Estrada do Lameirão Pequeno, s/nº-Campo Grande/RJ", formatBoldAlignHCenterUnderline);
    historic.write("A10","Endereço", formatAlignHCenter);
    historic.write("A11","HISTÓRICO ESCOLAR", formatBoldAlignHCenter);
    historic.write("A12", "CURSO: ", formatBold);
    historic.write("B12","ENSINO MÉDIO", formatBoldUnderline);
    historic.write("A13","NOME DO ALUNO:");
    historic.write("A14", "DATA DE NASCIMENTO:");
    historic.write("E14","NACIONALIDADE:");
    historic.write("J14","NATURALIDADE:");
    historic.write("A15","FILIAÇÃO:");
    historic.write("H15","E", formatAlignHCenter);
    historic.write("A16","IDENTIDADE Nº:");
    historic.write("F16","ORGÃO EXPEDITOR:");
    historic.write("J16","DATA DE EMISSÂO:");
    historic.write("A17","DISCIPLINAS", formatBoldAlignHVCenter);

    //Escrito o numero do ano no calendário --> xxxx
    historic.write("E17", "ANO: 2016", formatBoldAlignHVCenter);
    historic.write("G17", "ANO: 2017", formatBoldAlignHVCenter);
    historic.write("I17", "ANO: 2018", formatBoldAlignHVCenter);

    //Escrito o numero do ano no ano escolar do aluno --> xº ano
    historic.write("E19", "1º ANO", formatAlignHCenter);
    historic.write("G19", "2º ANO", formatAlignHCenter);
    historic.write("I19", "3º ANO", formatAlignHCenter);

    //Escrito "Nota/Conc"
    historic.write("E20", "Nota/Conc", formatAlignHCenter);
    historic.write("G20", "Nota/Conc", formatAlignHCenter);
    historic.write("I20", "Nota/Conc", formatAlignHCenter);

    //Escrito "C/H" --> Carga Horária
    historic.write("F20", "C/H", formatAlignHCenter);
    historic.write("H20", "C/H", formatAlignHCenter);
    historic.write("J20", "C/H", formatAlignHCenter);

    //Células escrito "Carga\nHorária" e "Total"
    historic.write("K17", "CARGA\nHORÁRIA", formatBoldAlignHVCenter);
    historic.write("K19", "TOTAL", formatBoldAlignHCenter);

    //Matérias
    historic.write("A21","LÍNGUA PORTUGUESA E LITERATURA");
    historic.write("A22","ARTE");
    historic.write("A23","ED. FÍSICA");
    historic.write("A24","MATEMÁTICA");
    historic.write("A25","QUÍMICA");
    historic.write("A26","FÍSICA");
    historic.write("A27","BIOLOGIA");
    historic.write("A28","HISTÓRIA");
    historic.write("A29","GEOGRAFIA");
    historic.write("A30","SOCIOLOGIA");
    historic.write("A31","FILOSOFIA");
    historic.write("A32","LINGUA ESTRANGEIRA / INGLÊS");
    historic.write("A33","ENSINO RELIGIOSO/PROJETO");
    historic.write("A34","LÍNGUA ESTRANGEIRA/PROJETO");
    historic.write("A35","RES. PROBL. MATEMÁTICOS");
    historic.write("A36","PROD. TEXTUAL");

    historic.write("A41","TOTAL", formatBold);
    historic.write("A42","% FREQUÊNCIA ANUAL");
    historic.write("A43","SITUAÇÃO FINAL");

    historic.write("E42",">75%", formatAlignHCenter); //frequencia anual para ser aprovado (condição)

    //****Células escrito o tempo em carga horária****
    //1º ano (deixar os numeros por padrao ou alterar)
    historic.write("F21","240", formatBoldAlignHCenter);    //c.h portugues
    historic.write("F22","0", formatBoldAlignHCenter);      //c.h arte
    historic.write("F23","80", formatBoldAlignHCenter);     //c.h ed fisica
    historic.write("F24","240", formatBoldAlignHCenter);    //c.h matematica
    historic.write("F25","80", formatBoldAlignHCenter);     //c.h quimica
    historic.write("F26","80", formatBoldAlignHCenter);     //c.h fisica
    historic.write("F27","80", formatBoldAlignHCenter);     //c.h biologia
    historic.write("F28","80", formatBoldAlignHCenter);     //c.h historia
    historic.write("F29","80", formatBoldAlignHCenter);     //c.h geografia
    historic.write("F30","40", formatBoldAlignHCenter);     //c.h sociologia
    historic.write("F31","40", formatBoldAlignHCenter);     //c.h filosofia
    historic.write("F32","80", formatBoldAlignHCenter);     //c.h ingles
    historic.write("F33","40", formatBoldAlignHCenter);     //c.h ensino religioso
    historic.write("F34","40", formatBoldAlignHCenter);     //c.h lingua estrangeira projeto
    historic.write("F35","0", formatBoldAlignHCenter);      //c.h rpm
    historic.write("F36","0", formatBoldAlignHCenter);      //c.h produção textual

    //2º ano (deixar os numeros por padrao ou alterar)
    historic.write("H21","160", formatBoldAlignHCenter);    //c.h portugues
    historic.write("H22","80", formatBoldAlignHCenter);     //c.h arte
    historic.write("H23","80", formatBoldAlignHCenter);     //c.h ed fisica
    historic.write("H24","160", formatBoldAlignHCenter);    //c.h matematica
    historic.write("H25","80", formatBoldAlignHCenter);     //c.h quimica
    historic.write("H26","80", formatBoldAlignHCenter);     //c.h fisica
    historic.write("H27","80", formatBoldAlignHCenter);     //c.h biologia
    historic.write("H28","80", formatBoldAlignHCenter);     //c.h historia
    historic.write("H29","80", formatBoldAlignHCenter);     //c.h geografia
    historic.write("H30","40", formatBoldAlignHCenter);     //c.h sociologia
    historic.write("H31","40", formatBoldAlignHCenter);     //c.h filosofia
    historic.write("H32","80", formatBoldAlignHCenter);     //c.h ingles
    historic.write("H33","40", formatBoldAlignHCenter);     //c.h ensino religioso
    historic.write("H34","40", formatBoldAlignHCenter);     //c.h lingua estrangeira projeto
    historic.write("H35","80", formatBoldAlignHCenter);     //c.h rpm
    historic.write("H36","0", formatBoldAlignHCenter);      //c.h produção textual

    //3º ano (deixar os numeros por padrao ou alterar)
    historic.write("J21","160", formatBoldAlignHCenter);    //c.h portugues
    historic.write("J22","0", formatBoldAlignHCenter);      //c.h arte
    historic.write("J23","80", formatBoldAlignHCenter);     //c.h ed fisica
    historic.write("J24","160", formatBoldAlignHCenter);    //c.h matematica
    historic.write("J25","80", formatBoldAlignHCenter);     //c.h quimica
    historic.write("J26","80", formatBoldAlignHCenter);     //c.h fisica
    historic.write("J27","80", formatBoldAlignHCenter);     //c.h biologia
    historic.write("J28","80", formatBoldAlignHCenter);     //c.h historia
    historic.write("J29","80", formatBoldAlignHCenter);     //c.h geografia
    historic.write("J30","80", formatBoldAlignHCenter);     //c.h sociologia
    historic.write("J31","80", formatBoldAlignHCenter);     //c.h filosofia
    historic.write("J32","80", formatBoldAlignHCenter);     //c.h ingles
    historic.write("J33","40", formatBoldAlignHCenter);     //c.h ensino religioso
    historic.write("J34","40", formatBoldAlignHCenter);     //c.h lingua estrangeira projeto
    historic.write("J35","0", formatBoldAlignHCenter);      //c.h rpm
    historic.write("J36","80", formatBoldAlignHCenter);     //c.h produção textual

    //CARGA HORARIA TOTAL
    historic.write("K21","560", formatBoldAlignHCenter);    //c.h portugues
    historic.write("K22","80", formatBoldAlignHCenter);     //c.h arte
    historic.write("K23","240", formatBoldAlignHCenter);    //c.h ed fisica
    historic.write("K24","560", formatBoldAlignHCenter);    //c.h matematica
    historic.write("K25","240", formatBoldAlignHCenter);    //c.h quimica
    historic.write("K26","240", formatBoldAlignHCenter);    //c.h fisica
    historic.write("K27","240", formatBoldAlignHCenter);    //c.h biologia
    historic.write("K28","240", formatBoldAlignHCenter);    //c.h historia
    historic.write("K29","240", formatBoldAlignHCenter);    //c.h geografia
    historic.write("K30","160", formatBoldAlignHCenter);    //c.h sociologia
    historic.write("K31","160", formatBoldAlignHCenter);    //c.h filosofia
    historic.write("K32","240", formatBoldAlignHCenter);    //c.h ingles
    historic.write("K33","120", formatBoldAlignHCenter);    //c.h ensino religioso
    historic.write("K34","120", formatBoldAlignHCenter);    //c.h lingua estrangeira projeto
    historic.write("K35","80", formatBoldAlignHCenter);     //c.h rpm
    historic.write("K36","80", formatBoldAlignHCenter);     //c.h produção textual

    //Cargas Horárias totais
    historic.write("F41", "1200", formatAlignHCenter);   //c.h total 1º ano
    historic.write("H41", "1200", formatAlignHCenter);   //c.h total 2º ano
    historic.write("J41", "1200", formatAlignHCenter);   //c.h total 3º ano
    historic.write("K41", "3600", formatAlignHCenter);   //c.h total total

    //Células escrito "APROVADO"
    historic.write("E43", "APROVADO", formatAlignHCenter);  //1º ano
    historic.write("G43", "APROVADO", formatAlignHCenter);  //2º ano
    historic.write("I43", "APROVADO", formatAlignHCenter);  //3º ano

    //****Células para adicionar as notas****
    //1º ano --> substituir os numeros pelo treco que pega as notas
    historic.write("E21","", formatBoldAlignHCenter); //portugues
    historic.write("E22","", formatBoldAlignHCenter); //arte
    historic.write("E23","", formatBoldAlignHCenter); //ed fisica
    historic.write("E24","", formatBoldAlignHCenter); //matematica
    historic.write("E25","", formatBoldAlignHCenter); //quimica
    historic.write("E26","", formatBoldAlignHCenter); //fisica
    historic.write("E27","", formatBoldAlignHCenter); //biologia
    historic.write("E28","", formatBoldAlignHCenter); //historia
    historic.write("E29","", formatBoldAlignHCenter); //geografia
    historic.write("E30","", formatBoldAlignHCenter); //sociologia
    historic.write("E31","", formatBoldAlignHCenter); //filosofia
    historic.write("E32","", formatBoldAlignHCenter); //ingles
    historic.write("E33","", formatBoldAlignHCenter); //ensino religioso
    historic.write("E34","", formatBoldAlignHCenter); //lingua estrangeira projeto
    historic.write("E35","", formatBoldAlignHCenter); //rpm
    historic.write("E36","", formatBoldAlignHCenter); //produção textual

    //2º ano --> substituir os numeros pelo treco que pega as notas
    historic.write("G21","", formatBoldAlignHCenter); //portugues
    historic.write("G22","", formatBoldAlignHCenter); //arte
    historic.write("G23","", formatBoldAlignHCenter); //ed fisica
    historic.write("G24","", formatBoldAlignHCenter); //matematica
    historic.write("G25","", formatBoldAlignHCenter); //quimica
    historic.write("G26","", formatBoldAlignHCenter); //fisica
    historic.write("G27","", formatBoldAlignHCenter); //biologia
    historic.write("G28","", formatBoldAlignHCenter); //historia
    historic.write("G29","", formatBoldAlignHCenter); //geografia
    historic.write("G30","", formatBoldAlignHCenter); //sociologia
    historic.write("G31","", formatBoldAlignHCenter); //filosofia
    historic.write("G32","", formatBoldAlignHCenter); //ingles
    historic.write("G33","", formatBoldAlignHCenter); //ensino religioso
    historic.write("G34","", formatBoldAlignHCenter); //lingua estrangeira projeto
    historic.write("G35","", formatBoldAlignHCenter); //rpm
    historic.write("G36","", formatBoldAlignHCenter); //produção textual

    //3º ano --> substituir os numeros pelo treco que pega as notas
    historic.write("I21","", formatBoldAlignHCenter); //portugues
    historic.write("I22","", formatBoldAlignHCenter); //arte
    historic.write("I23","", formatBoldAlignHCenter); //ed fisica
    historic.write("I24","", formatBoldAlignHCenter); //matematica
    historic.write("I25","", formatBoldAlignHCenter); //quimica
    historic.write("I26","", formatBoldAlignHCenter); //fisica
    historic.write("I27","", formatBoldAlignHCenter); //biologia
    historic.write("I28","", formatBoldAlignHCenter); //historia
    historic.write("I29","", formatBoldAlignHCenter); //geografia
    historic.write("I30","", formatBoldAlignHCenter); //sociologia
    historic.write("I31","", formatBoldAlignHCenter); //filosofia
    historic.write("I32","", formatBoldAlignHCenter); //ingles
    historic.write("I33","", formatBoldAlignHCenter); //ensino religioso
    historic.write("I34","", formatBoldAlignHCenter); //lingua estrangeira projeto
    historic.write("I35","", formatBoldAlignHCenter); //rpm
    historic.write("I36","", formatBoldAlignHCenter); //produção textual

    //*****PARTE DE BAIXO DO HISTORICO(estabelecimento de ensino)*****
    historic.write("A44","Série/Ano", formatBoldAlignHCenter);
    historic.write("B44","ESTABELECIMENTO DE ENSINO", formatBoldAlignHCenter);
    historic.write("H44","MUNICÍPIO / ESTADO", formatBoldAlignHCenter);
    historic.write("K44","ANO", formatBoldAlignHCenter);

    //Série/Ano --> xª
    historic.write("A45","1ª", formatBoldAlignHCenter);
    historic.write("A46","2ª", formatBoldAlignHCenter);
    historic.write("A47","3ª", formatBoldAlignHCenter);

    //Estabelecimento de Ensino
    historic.write("B45","CIEP 165 BRIGADEIRO SÉRGIO CARVALHO");
    historic.write("B46","CIEP 165 BRIGADEIRO SÉRGIO CARVALHO");
    historic.write("B47","CIEP 165 BRIGADEIRO SÉRGIO CARVALHO");

    //Municipio/Estado
    historic.write("H45","RIO DE JANEIRO/RJ", formatAlignHCenter);
    historic.write("H46","RIO DE JANEIRO/RJ", formatAlignHCenter);
    historic.write("H47","RIO DE JANEIRO/RJ", formatAlignHCenter);

    //Ano --> xxxx
    historic.write("K45","2016", formatAlignHCenter); //substituir pelo ano desejado
    historic.write("K46","2017", formatAlignHCenter); //substituir pelo ano desejado
    historic.write("K47","2018", formatAlignHCenter); //substituir pelo ano desejado

    //FINAL
    historic.write("A48","OBSERVAÇÕES:", formatAlignTopLeft);
    historic.write("A51","Segue em Anexo Histórico Escolar Anterior emitido pelo(a) NOME-DA-ESCOLA, \nde acordo com  Deliberação  CEE nº 363/17 , art. 5º.", formatBoldAlignTopLeft);
    historic.write("A55","DATA DA EXPEDIÇÃO: RJ, DATA/DE/CRIAÇÃO", formatAlignHVCenter); //Substituir pela data de criação
    historic.write("B59","_________________________________", formatAlignHCenter); //campo de assinatura do secretario
    historic.write("B60","SECRETÁRIO ESCOLAR", formatAlignHCenter);
    historic.write("H59","________________________________", formatAlignHCenter); //campo de assinatura do diretor
    historic.write("H60","DIRETOR", formatAlignHCenter);

    //Salvando histórico na pasta especificada pelo usuário com o nome do estudante no arquivo
    historic.saveAs(adressSaveModelHistoricStudent);

    //Retorna endereço em que o modelo de histórico do aluno esta contido para a escrita de dados
    return adressSaveModelHistoricStudent;
}

void Exporter::exportHistoric(const QList<Student> &students, const QDir &exportHistoryDir)
{
    for(const Student &student : students){

        qDebug() << "Montando histórico do aluno(a) " << student.name() << endl;

        //Variavel com endereço do modelo de histórico do aluno no sistema
        const QString addressModelHistoricStudent = makeModelHistoricStudentAdress(student.name(), exportHistoryDir.absolutePath());

        //Abrir cópia do histórico no diretório especificado pelo usuário
        QXlsx::Document historic(addressModelHistoricStudent);

        //Adicionar dados pessoais
        qDebug() << "Gravando dados pessoais ...\n" << endl;

        const QString name = student.name();
        historic.write("C13", name);                                  //name
        qDebug() << "Nome: " << name << endl;

        const QString dateOfBirth = student.dateOfBirth().toString("dd/MM/yyyy");
        historic.write("C14", dateOfBirth);    //data de nascimento
        qDebug() << "Data de Nascimento: " << dateOfBirth << endl;

        const QString fatherName = student.fatherName();
        historic.write("B15", fatherName);                            //pai
        qDebug() << "Nome do pai: " << fatherName << endl;

        const QString motherName = student.motherName();
        historic.write("I15", motherName);                           //mae
        qDebug() << "Nome da Mãe: " << motherName << endl;

        const QString IDNumber = student.IDNumber();
        historic.write("C16", IDNumber);                              //rg
        qDebug() << "Número da Identidade: " << IDNumber << endl;

        const QString IDIssuingInstitution = student.IDIssuingInstitution();
        historic.write("H16", student.IDIssuingInstitution());                 //orgão expeditor
        qDebug() << "Orgão de Expedição: " << IDIssuingInstitution << endl;

        const QString IDIssueDate = student.IDIssueDate();
        historic.write("L16", IDIssueDate);                          //data de emissao
        qDebug() << "Data de Emissão: " << IDIssueDate << endl;

        //Adicionar notas
        const QString subjectLetter = "A";
        const QStringList gradesLetters = {"E", "G", "I"};
        const QStringList hourLetters = {"F", "H", "J"};

        bool dataComplete = true;

        for(int numberGradeYear = 1; numberGradeYear <= 3; numberGradeYear++){

            Grades gradeYearCurrent = student.getGrades(QString::number(numberGradeYear));

            qDebug() << "GRADE ATUAL: " << numberGradeYear << endl;

            qDebug() << "Adicionando notas do " << numberGradeYear << "º ano ...\n" << endl;
            for(int line = 21; line <= 36; line++){

                double gradeTemp = 0;
                QString numberLineStr = QString::number(line);

                //Estrutura de decisões para achar a nota da matéria
                QString subjectInCell = historic.read(subjectLetter + numberLineStr).toString();

                if(subjectInCell == "LÍNGUA PORTUGUESA E LITERATURA"){
                    gradeTemp = gradeYearCurrent.portugueseGrade();
                }else if(subjectInCell == "ARTE"){
                    gradeTemp = gradeYearCurrent.artGrade();
                }else if(subjectInCell == "ED. FÍSICA"){
                    gradeTemp = gradeYearCurrent.physicalEducationGrade();
                }else if(subjectInCell == "MATEMÁTICA"){
                    gradeTemp = gradeYearCurrent.mathGrade();
                }else if(subjectInCell == "QUÍMICA"){
                    gradeTemp = gradeYearCurrent.chemistryGrade();
                }else if(subjectInCell == "FÍSICA"){
                    gradeTemp = gradeYearCurrent.physicsGrade();
                }else if(subjectInCell == "BIOLOGIA"){
                    gradeTemp = gradeYearCurrent.biologyGrade();
                }else if(subjectInCell == "HISTÓRIA"){
                    gradeTemp = gradeYearCurrent.historyGrade();
                }else if(subjectInCell == "GEOGRAFIA"){
                    gradeTemp = gradeYearCurrent.geographyGrade();
                }else if(subjectInCell == "SOCIOLOGIA"){
                    gradeTemp = gradeYearCurrent.sociologyGrade();
                }else if(subjectInCell == "FILOSOFIA"){
                    gradeTemp = gradeYearCurrent.philosophyGrade();
                }else if(subjectInCell == "LINGUA ESTRANGEIRA / INGLÊS"){
                    gradeTemp = gradeYearCurrent.englishGrade();
                }else if(subjectInCell == "ENSINO RELIGIOSO/PROJETO"){
                    gradeTemp = gradeYearCurrent.religiousGrade();
                }else if(subjectInCell == "LÍNGUA ESTRANGEIRA/PROJETO"){
                    gradeTemp = gradeYearCurrent.projectGrade();
                }else if(subjectInCell == "RES. PROBL. MATEMÁTICOS"){
                    gradeTemp = gradeYearCurrent.mathProblemSolvingGrade();
                }else if(subjectInCell == "PROD. TEXTUAL"){
                    gradeTemp = gradeYearCurrent.textProductionGrade();
                }

                qDebug() << "Materia: " << subjectInCell << " | "
                         << "Nota: " << gradeTemp << endl;

                //Escrever nota
                int workLoad = historic.read(hourLetters.at(numberGradeYear - 1) + numberLineStr).toInt();
                QString positionGradeCurrentInHistoric = gradesLetters.at(numberGradeYear - 1) + numberLineStr;
                if(gradeTemp < 0 && workLoad == 0){
                    qDebug() << "Nota de " << subjectInCell
                             << " ou/e sua carga horaria é invalida." << endl;
                    dataComplete = false;
                }else if(gradeTemp < 0 && workLoad != 0){
                    historic.write(positionGradeCurrentInHistoric, "*");
                }else{
                    historic.write(positionGradeCurrentInHistoric, gradeTemp);
                    qDebug() << "Materia: " << subjectInCell << " | "
                             << "Nota: " << gradeTemp << endl;
                }
            }
        }

        if(!dataComplete){
            qDebug() << "O histórico do aluno(a) " << student.name() << " foi feito com os dados imcompletos." << endl;
        }

        //salvar histórico
        qDebug() << "HISTÓRICO PRONTO!\n" << endl;
        historic.saveAs(addressModelHistoricStudent);
        qDebug() << "Salvo no endereço: " << addressModelHistoricStudent << endl;
    }
}

void Exporter::exportHistoric(const QList<Student> &students)
{
    exportHistoric(students, QDir(QDir::homePath()));   //Exporta para a pasta home do usuário
    //exportHistoric(students, QDir("../historical"));  //ERRO: Não exporta para pasta de históricos do programa
}
