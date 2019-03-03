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

    //Lista com posições da parte inicial do histórico para mesclar
    QStringList positionsRangeCellsMerge = {"C2:H2",     //texto do governo
                                           "C3:H3",     //texto da secretaria
                                           "A6:F6",     //nome da escola
                                           "A7:F7",     //endereço da escola
                                           "A9:F9",     //escrito endereço
                                           "A10:F10",   //tipo de estabelecimento
                                           "A11:M11",   //titulo do histórico
                                           "B12:C12",   //Tipo de Curso
                                           "A13:B13",   //Nome do aluno
                                           "A14:B14",   //Data de Nascimento --> Pesquisar como aumentar tamanho de celula
                                           "E14:F14",   //nacionalidade
                                           "J14:K14",   //naturalidade
                                           "A16:B16",   //identidade
                                           "F16:G16",   //orgão expedidor
                                           "J16:K16",   //data da emissão
                                           "A17:D20",   //disciplinas
                                           "E17:F18",   //Ano do 1º ano
                                           "G17:H18",   //Ano do 2º ano
                                           "I17:J18",   //Ano do 3º ano
                                           "K17:M18",   //Carga Horária
                                           "E19:F19",   //1º Ano
                                           "G19:H19",   //2º Ano
                                           "I19:J19",   //3º Ano
                                           "K19:M19",   //Total
                                           "K20:M20"};  //Total

    //Mesclando conjunto de células especificadas em cada posição da lista acima, com for
    for(int i = 0; i < positionsRangeCellsMerge.size(); i++){
        historic.mergeCells(positionsRangeCellsMerge.at(i));
    }

    //Mesclando Células para adicionar nomes fixos de matérias e cargas horárias
    for(int row = 21; row <= 43; row++){
        QString rowStr = QString::number(row);
        QString rangeCellsSubject = "A" + rowStr + ":" + "D" + rowStr;
        QString rangeCellsTime = "K" + rowStr + ":" + "M" + rowStr;
        historic.mergeCells(rangeCellsSubject);     //subject
        historic.mergeCells(rangeCellsTime);        //carga horária
    }

    //Mesclando células para adionar aprovado em cada um dos três anos
    QStringList positionsRangeCells = {"E43:F43", "G43:H43", "I43:J43"};
    for(int i = 0; i < positionsRangeCells.size(); i++){
        historic.mergeCells(positionsRangeCells.at(i));
    }

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

    QStringList rangeCellsUndeground = {"A48:M50",     //observações
                                        "A51:M54",     //escola anterior e outras informações
                                        "A55:M56",     //data de expedição
                                        "A57:M58",     //em branco
                                        "B59:E59",     //Linha de Assinatura da Secretária
                                        "H59:K59",     //Linha de Assinatura do diretor
                                        "B60:E60",     //Assinatura da Secretária
                                        "H60:K60",     //Assinatura do diretor
                                        "A61:M63",     //em branco
                                        "A59:A60",     //em branco
                                        "F59:G60",     //em branco
                                        "L59:M60",     //em branco
                                        "C13:M13",     //exportar nome do aluno
                                        "C14:D14",     //exportar data de nascimento
                                        "G14:I14",     //exportar nacionalidade
                                        "L14:M14",     //exportar naturalidade
                                        "B15:G15",     //exportar nome do pai
                                        "I15:M15",     //exportar nome da mãe
                                        "C16:E16",     //exportar identidade
                                        "H16:I16",     //exportar orgão expedidor
                                        "L16:M16"};     //exportar data da emissão

    for(int i = 0; i < rangeCellsUndeground.size(); i++){
        historic.mergeCells(rangeCellsUndeground.at(i));
    }

    //Escrevendos dados fixos do histórico
    QStringList dataCells = {"C2","C3","A6","A7","A9","A10",
                             "A11","A12","B12","A13","A14","E14",
                             "J14","A15","H15","A16","F16","J16","A17"};
    QStringList dataText = {"GOVERNO DO ESTADO DO RIO DE JANEIRO",
                            "SECRETARIA DE ESTADO DE EDUCAÇÃO",
                            "CIEP-BRIZOLÃO 165 - BRIGADEIRO SERGIO CARVALHO",
                            "Estabelecimento de Ensino",
                            "Estrada do Lameirão Pequeno, s/nº-Campo Grande/RJ",
                            "Endereço",
                            "HISTÓRICO ESCOLAR",
                            "CURSO: ",
                            "ENSINO MÉDIO",
                            "NOME DO ALUNO:"
                            "DATA DE NASCIMENTO:"
                            "NACIONALIDADE:",
                            "NATURALIDADE:",
                            "FILIAÇÃO:",
                            "E",
                            "IDENTIDADE Nº:",
                            "ORGÃO EXPEDITOR:",
                            "DATA DE EMISSÂO:",
                            "DISCIPLINAS"};
    QList<QXlsx::Format> dataFormat = {formatBoldAlignHCenter,
                                       formatBoldAlignHCenter,
                                       formatBoldAlignHCenterUnderline,
                                       formatAlignHCenter,
                                       formatBoldAlignHCenterUnderline,
                                       formatAlignHCenter,
                                       formatBoldAlignHCenter,
                                       formatBold,
                                       formatBoldUnderline,
                                       QXlsx::Format(),
                                       QXlsx::Format(),
                                       QXlsx::Format(),
                                       QXlsx::Format(),
                                       QXlsx::Format(),
                                       formatAlignHCenter,
                                       QXlsx::Format(),
                                       QXlsx::Format(),
                                       QXlsx::Format(),
                                       formatBoldAlignHVCenter};

    for (int c=0; c<dataCells.size(); c++){
        historic.write(dataCells.at(c),dataText.at(c),dataFormat.at(c));
    }
    //Escrito o numero do ano no calendário --> xxxx
    QStringList cellsYear = {"E17","G17","I17"};
    QStringList year = {"2016","2017","2018"};

    for(int j=0; j<year.size();j++) {
        historic.write(cellsYear.at(j),year.at(j),formatBoldAlignHVCenter);
    }

    //Escrito o numero do ano no ano escolar do aluno --> xº ano
    QStringList schoolYearCells = {"E19","G19","I19"};
    QStringList schoolYearText = {"1º ANO","2º ANO","3º ANO"};

    for(int k=0; k<schoolYearCells.size(); k++){
        historic.write(schoolYearCells.at(k),schoolYearText.at(k),formatAlignHCenter);
    }

    //Escrito "Nota/Conc"
    QStringList gradeCells = {"E20","G20","I20"};

    for(int l=0; l<gradeCells.size(); l++){
        historic.write(gradeCells.at(l),"Nota/Conc",formatAlignHCenter);
    }

    //Escrito "C/H" --> Carga Horária
    QStringList workload = {"F20","H20","J20"};

    for(int m=0; m<workload.size(); m++){
        historic.write(workload.at(m),"C/H",formatAlignHCenter);
    }
    //Células escrito "Carga\nHorária" e "Total"
    historic.write("K17", "CARGA\nHORÁRIA", formatBoldAlignHVCenter); //esses eu acho que nao precisa de lista
    historic.write("K19", "TOTAL", formatBoldAlignHCenter);

    //Matérias
    QStringList schoolStuffCells = {"A21","A22","A23","A24","A25",
                                    "A26","A27","A28","A29","A30",
                                    "A31","A32","A33","A34","A35","A36"};

    QStringList schoolStuffText = {"LÍNGUA PORTUGUESA E LITERATURA",
                                   "ARTE",
                                   "ED. FÍSICA",
                                   "MATEMÁTICA",
                                   "QUÍMICA",
                                   "FÍSICA",
                                   "BIOLOGIA",
                                   "HISTÓRIA",
                                   "GEOGRAFIA",
                                   "SOCIOLOGIA",
                                   "FILOSOFIA",
                                   "LINGUA ESTRANGEIRA / INGLÊS",
                                   "ENSINO RELIGIOSO/PROJETO",
                                   "LÍNGUA ESTRANGEIRA/PROJETO",
                                   "RES. PROBL. MATEMÁTICOS",
                                   "PROD. TEXTUAL"};
    for(int n=0; n<schoolStuffText.size();n++){
        historic.write(schoolStuffCells.at(n),schoolStuffText.at(n));
    } //deixei esses debaixo fora da lista pq 2 deles tem formatação diferente

    historic.write("A41","TOTAL", formatBold);
    historic.write("A42","% FREQUÊNCIA ANUAL");
    historic.write("A43","SITUAÇÃO FINAL");
    historic.write("E42",">75%", formatAlignHCenter); //frequencia anual para ser aprovado (condição)

    //****Células escrito o tempo em carga horária****
    //1º ano (deixar os numeros por padrao ou alterar)
    QStringList workloadGradeFirstCells = {"F21","F22","F23","F24",
                                           "F25","F26","F27","F28",
                                           "F29","F30","F31","F32",
                                           "F33","F34","F35","F36"};

    QStringList workloadGradeFirstText = {"240","0","80","240",
                                          "80","80","80","80",
                                          "80","40","40","80",
                                          "40","40","0","0"};

    for (int o=0; o<workloadGradeFirstCells.size(); o++){
        historic.write(workloadGradeFirstCells.at(o),workloadGradeFirstText.at(o),formatBoldAlignHCenter);
    }

    //2º ano (deixar os numeros por padrao ou alterar)
    QStringList workloadGradeSecondCells = {"H21","H22","H23","H24",
                                            "H25","H26","H27","H28",
                                            "H29","H30","H31","H32",
                                            "H33","H34","H35","H36"};

    QStringList workloadGradeSecondText = {"160","80","80","160",
                                           "80","80","80","80",
                                           "80","40","40","80",
                                           "40","40","80","0"};

    for (int p=0; p<workloadGradeSecondCells.size(); p++){
        historic.write(workloadGradeSecondCells.at(p),workloadGradeSecondText.at(p),formatBoldAlignHCenter);
    }

    //3º ano (deixar os numeros por padrao ou alterar)
    QStringList workloadGradeThirdCells = {"J21","J22","J23","J24",
                                           "J25","J26","J27","J28",
                                           "J29","J30","J31","J32",
                                           "J33","J34","J35","J36"};

    QStringList workloadGradeThirdText = {"160","0","80","160",
                                           "80","80","80","80",
                                           "80","80","80","80",
                                           "40","40","0","80"};

    for (int q=0; q<workloadGradeThirdCells.size(); q++){
        historic.write(workloadGradeThirdCells.at(q),workloadGradeThirdText.at(q),formatBoldAlignHCenter);
    }

    //CARGA HORARIA TOTAL
    QStringList workloadGradeTotalCells = {"K21","K22","K23","K24",
                                           "K25","K26","K27","K28",
                                           "K29","K30","K31","K32",
                                           "K33","K34","K35","K36"};

    QStringList workloadGradeTotalText = {"560","80","240","560",
                                          "240","240","240","240",
                                          "240","160","160","240",
                                          "120","120","80","80"};

    for (int r=0; r<workloadGradeTotalCells.size(); r++){
        historic.write(workloadGradeTotalCells.at(r),workloadGradeTotalText.at(r),formatBoldAlignHCenter);
    }

    //Cargas Horárias totais
    QStringList workloadGradeTotalYearsCells = {"F41","H41","J41","K41"};
    QStringList workloadGradeTotalYearsText = {"1200","1200","1200","3600"};

    for(int s=0; s<workloadGradeTotalYearsCells.size(); s++){
        historic.write(workloadGradeTotalYearsCells.at(s),workloadGradeTotalYearsText.at(s),formatAlignHCenter);
    }

    //Células escrito "APROVADO"
    QStringList approvedCells = {"E43","G43","I43"};

    for(int t=0; t<approvedCells.size(); t++){
        historic.write(approvedCells.at(t),"APROVADO",formatAlignHCenter);
    }

    //****Células para adicionar as notas****
    //1º ano --> substituir os numeros pelo treco que pega as notas
    QStringList insertGradeFirstYeartCells = {"E21","E22","E23","E24",
                                              "E25","E26","E27","E28",
                                              "E29","E30","E31","E32",
                                              "E33","E34","E35","E36",};

    QStringList insertGradeFirstYearData = {"", //portugues
                                            "", //arte
                                            "", //ed fisica
                                            "", //matematica
                                            "", //quimica
                                            "", //fisica
                                            "", //biologia
                                            "", //historia
                                            "", //geografia
                                            "", //sociologia
                                            "", //filosofia
                                            "", //ingles
                                            "", //ensino religioso
                                            "", //lingua estrangeira projeto
                                            "", //rpm
                                            "",}; //produção textual  //substituir pelos metodos que  pega as notas

    for (int u=0; u<insertGradeFirstYeartCells.size(); u++) {
        historic.write(insertGradeFirstYeartCells.at(u),insertGradeFirstYearData.at(u),formatBoldAlignHCenter);
    }


    //2º ano --> substituir os numeros pelo treco que pega as notas
    QStringList insertGradeSecondYearCells = {"G21","G22","G23","G24",
                                              "G25","G26","G27","G28",
                                              "G29","G30","G31","G32",
                                              "G33","G34","G35","G36",};

    QStringList insertGradeSecondYearData = {"", //portugues
                                             "", //arte
                                             "", //ed fisica
                                             "", //matematica
                                             "", //quimica
                                             "", //fisica
                                             "", //biologia
                                             "", //historia
                                             "", //geografia
                                             "", //sociologia
                                             "", //filosofia
                                             "", //ingles
                                             "", //ensino religioso
                                             "", //lingua estrangeira projeto
                                             "", //rpm
                                             "",}; //produção textual  //substituir pelos metodos que  pega as notas

    for (int v=0; v<insertGradeSecondYearCells.size(); v++) {
        historic.write(insertGradeSecondYearCells.at(v),insertGradeSecondYearData.at(v),formatBoldAlignHCenter);
    }

    //3º ano --> substituir os numeros pelo treco que pega as notas
    QStringList insertGradeThirdYearCells = {"I21","I22","I23","I24",
                                             "I25","I26","I27","I28",
                                             "I29","I30","I31","I32",
                                             "I33","I34","I35","I36",};

    QStringList insertGradeThirdYearData = {"", //portugues
                                            "", //arte
                                            "", //ed fisica
                                            "", //matematica
                                            "", //quimica
                                            "", //fisica
                                            "", //biologia
                                            "", //historia
                                            "", //geografia
                                            "", //sociologia
                                            "", //filosofia
                                            "", //ingles
                                            "", //ensino religioso
                                            "", //lingua estrangeira projeto
                                            "", //rpm
                                            "",}; //produção textual  //substituir pelos metodos que  pega as notas

    for (int v=0; v<insertGradeThirdYearCells.size(); v++) {
        historic.write(insertGradeThirdYearCells.at(v),insertGradeThirdYearData.at(v),formatBoldAlignHCenter);
    }

    //*****PARTE DE BAIXO DO HISTORICO(estabelecimento de ensino)*****
    QStringList subdataCells= {"A44","B44","H44","K44"};
    QStringList subdataText = {"Série/Ano",
                               "ESTABELECIMENTO DE ENSINO",
                               "MUNICÍPIO / ESTADO",
                               "ANO"};
    for(int w=0; w<subdataCells.size(); w++){
        historic.write(subdataCells.at(w),subdataText.at(w),formatBoldAlignHCenter);
    }

    //Série/Ano --> xª
    QStringList yearClassCells = {"A45","A46","A47"};
    QStringList yearCLassNumber = {"1º","2º","3º"};
    for (int x=0; x<yearClassCells.size();x++){
        historic.write(yearClassCells.at(x),yearCLassNumber.at(x),formatBoldAlignHCenter);
    }

    //Estabelecimento de Ensino
    QStringList nameSchoolCells = {"B45","B46","B47"};
    for (int y=0;y<nameSchoolCells.size();y++) {
        historic.write(nameSchoolCells.at(y),"CIEP 165 BRIGADEIRO SÉRGIO CARVALHO");

    }

    //Municipio/Estado
    QStringList cityCells = {"H45","H46","H47"};
    for (int z=0; z<cityCells.size(); z++) {
        historic.write(cityCells.at(z),"RIO DE JANEIRO/RJ",formatAlignHCenter);

    }
    //Ano --> xxxx
    QStringList yearFinalCells = {"K45","K46","K47"};
    QStringList yearFinalText = {"2016","2017","2018"};

    for (int a=0; a<yearFinalCells.size(); a++) {
        historic.write(yearFinalCells.at(a),yearFinalText,formatAlignHCenter);

    }
    //FINAL
    QStringList finalCells = {"A48","A51","A55","B59","B60","H59","H60"};
    QStringList finalText = {"OBSERVAÇÕES:",
                             "Segue em Anexo Histórico Escolar Anterior emitido pelo(a) NOME-DA-ESCOLA, \nde acordo com  Deliberação  CEE nº 363/17 , art. 5º.",
                             "DATA DA EXPEDIÇÃO: RJ, DATA/DE/CRIAÇÃO",
                              "_________________________________",
                              "SECRETÁRIO ESCOLAR",
                              "________________________________",
                              "DIRETOR"};
    QList<QXlsx::Format> finalformat = {formatAlignTopLeft,
                                        formatBoldAlignTopLeft,
                                        formatAlignHVCenter,
                                        formatAlignHCenter,
                                        formatAlignHCenter,
                                        formatAlignHCenter,
                                        formatAlignHCenter};

    for(int b=0; b<finalCells.size(); b++){
        historic.write(finalCells.at(b),finalText.at(b),finalformat.at(b));
    }

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
