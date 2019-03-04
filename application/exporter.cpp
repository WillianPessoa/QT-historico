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
    QXlsx::Format formatBoldAlignHCenter;
    formatBoldAlignHCenter.setFontBold(true);
    formatBoldAlignHCenter.setHorizontalAlignment(QXlsx::Format::AlignHCenter);

    QXlsx::Format formatBoldAlignHCenterUnderline(formatBoldAlignHCenter);
    formatBoldAlignHCenterUnderline.setFontUnderline(QXlsx::Format::FontUnderlineSingle);

    QXlsx::Format formatAlignHCenter;
    formatAlignHCenter.setHorizontalAlignment(QXlsx::Format::AlignHCenter);

    QXlsx::Format formatBold;
    formatBold.setFontBold(true);

    QXlsx::Format formatBoldUnderline(formatBold);
    formatBoldUnderline.setFontUnderline(QXlsx::Format::FontUnderlineSingle);

    QXlsx::Format formatAlignHVCenter(formatAlignHCenter);
    formatAlignHVCenter.setVerticalAlignment(QXlsx::Format::AlignVCenter);

    QXlsx::Format formatBoldAlignHVCenter(formatBoldAlignHCenter);
    formatBoldAlignHVCenter.setVerticalAlignment(QXlsx::Format::AlignVCenter);

    QXlsx::Format formatAlignTopLeft;
    formatAlignTopLeft.setVerticalAlignment(QXlsx::Format::AlignTop);
    formatAlignTopLeft.setHorizontalAlignment(QXlsx::Format::AlignLeft);

    QXlsx::Format formatBoldAlignTopLeft(formatAlignTopLeft);
    formatBoldAlignTopLeft.setFontBold(true);

    //*****************CRIANDO LISTAS***********************
    //Lista com conjunto de posições (range) do histórico para mesclar
    QStringList rangeCellsMerge = {"C2:H2", "C3:H3", "A6:F6", "A7:F7", "A9:F9",
                                            "A10:F10", "A11:M11", "B12:C12", "A13:B13",
                                            "A14:B14", "E14:F14", "J14:K14", "A16:B16",
                                            "F16:G16", "J16:K16", "A17:D20", "E17:F18",
                                            "G17:H18", "I17:J18", "K17:M18", "E19:F19",
                                            "G19:H19", "I19:J19", "K19:M19", "K20:M20",
                                            "A48:M50", "A51:M54", "A55:M56", "A57:M58",
                                            "B59:E59", "H59:K59", "B60:E60", "H60:K60",
                                            "A61:M63", "A59:A60", "F59:G60", "L59:M60",
                                            "C13:M13", "C14:D14", "G14:I14", "L14:M14",
                                            "B15:G15", "I15:M15", "C16:E16", "H16:I16",
                                            "L16:M16", "E43:F43", "G43:H43", "I43:J43"};

    QStringList rangeCellsMergeFormats = {"C13:M13", "C14:D14", "G14:I14",
                                          "L14:M14", "B15:G15", "I15:M15",
                                          "C16:E16", "H16:I16", "L16:M16"};

    //Lista com posições de células com dados fixos do histórico
    QStringList dataCells = {"C2","C3","A6","A7","A9","A10", "A11","A12","B12","A13",
                             "A14","E14","J14","A15","H15","A16","F16","J16","A17"};

    //Lista com textos fixos do histórico para adicionar em células
    QStringList dataText = {"GOVERNO DO ESTADO DO RIO DE JANEIRO",
                            "SECRETARIA DE ESTADO DE EDUCAÇÃO",
                            "CIEP-BRIZOLÃO 165 - BRIGADEIRO SERGIO CARVALHO",
                            "Estabelecimento de Ensino",
                            "Estrada do Lameirão Pequeno, s/nº-Campo Grande/RJ",
                            "Endereço",
                            "HISTÓRICO ESCOLAR",
                            "CURSO: ",
                            "ENSINO MÉDIO",
                            "NOME DO ALUNO:",
                            "DATA DE NASCIMENTO:",
                            "NACIONALIDADE:",
                            "NATURALIDADE:",
                            "FILIAÇÃO:",
                            "E",
                            "IDENTIDADE Nº:",
                            "ORGÃO EXPEDITOR:",
                            "DATA DE EMISSÂO:",
                            "DISCIPLINAS"};

    //Letras do histórico que com o número da posição vão ter os textos: ano (xxxx), xº ANO e "Nota/Conc"
    QStringList cellsYearLetters = {"E","G","I"};

    //Letras do histórico que com o número da posição vão ter os textos: "C/H" --> Carga Horária
    QStringList workload = {"F","H","J"};

    //Lista com nomes das matérias do histórico
    QStringList subjectsList = {"LÍNGUA PORTUGUESA E LITERATURA", "ARTE", "ED. FÍSICA",
                                "MATEMÁTICA", "QUÍMICA", "FÍSICA", "BIOLOGIA",
                                "HISTÓRIA", "GEOGRAFIA", "SOCIOLOGIA", "FILOSOFIA",
                                "LINGUA ESTRANGEIRA / INGLÊS", "ENSINO RELIGIOSO/PROJETO",
                                "LÍNGUA ESTRANGEIRA/PROJETO", "RES. PROBL. MATEMÁTICOS",
                                "PROD. TEXTUAL"};

    //Lista com textos logo abaixo das matérias no histórico
    QStringList undergroundSubjectsTextsList = {"TOTAL", "% FREQUÊNCIA ANUAL", "SITUAÇÃO FINAL"};

    //****Lista de cargas horárias****
    //1º ano
    QStringList workloadGradeFirstYear = {"240","0","80","240","80","80","80","80",
                                          "80","40","40","80","40","40","0","0"};

    //2º ano
    QStringList workloadGradeSecondYear = {"160","80","80","160","80","80","80","80",
                                           "80","40","40","80","40","40","80","0"};

    //3º ano
    QStringList workloadGradeThirdYear = {"160","0","80","160","80","80","80","80",
                                          "80","80","80","80","40","40","0","80"};

    //total
    QStringList workloadTotal = {"560","80","240","560", "240","240","240","240",
                                 "240","160","160","240","120","120","80","80"};

    //Letras do histórico que com o número da posição vão ter as cargas horárias totais de cada ano
    QStringList workloadTotalYearsLetters = {"F","H","J"};

    //Letras do histórico que com o número da posição vão ter o texto "APROVADO"
    QStringList approvedCells = {"E","G","I"};

    //Letras do histórico que com o número da posição vão ter os textos da parte de baixo do historico
    QStringList subDataCells = {"A","B","H","K"};

    //Textos da parte de baixo acima de "OBSERVAÇÕES" no histórico
    QStringList subDataText = {"Série/Ano", "ESTABELECIMENTO DE ENSINO", "MUNICÍPIO / ESTADO", "ANO"};

    //Lista de posições de células da parte final do histórico
    QStringList finalCells = {"A48","A51","A55","B59","B60","H59","H60"};

    //Lista com textos das células da parte final do histórico
    QStringList finalText = {"OBSERVAÇÕES:",
                             "Segue em Anexo Histórico Escolar Anterior emitido pelo(a) NOME-DA-ESCOLA, \nde acordo com  Deliberação  CEE nº 363/17 , art. 5º.",
                             "DATA DA EXPEDIÇÃO: RJ, DATA/DE/CRIAÇÃO",
                              "_________________________________",
                              "SECRETÁRIO ESCOLAR",
                              "________________________________",
                              "DIRETOR"};

    //Lista com variaveis de formatação de textos da parte inicial do histórico
    QList<QXlsx::Format> dataFormat = {formatBoldAlignHCenter, formatBoldAlignHCenter,
                                       formatBoldAlignHCenterUnderline, formatAlignHCenter,
                                       formatBoldAlignHCenterUnderline, formatAlignHCenter,
                                       formatBoldAlignHCenter, formatBold, formatBoldUnderline,
                                       QXlsx::Format(), QXlsx::Format(), QXlsx::Format(),
                                       QXlsx::Format(), QXlsx::Format(), formatAlignHCenter,
                                       QXlsx::Format(), QXlsx::Format(), QXlsx::Format(),
                                       formatBoldAlignHVCenter};

    //Lista com variaveis de formatação de textos da em baixo das matérias no histórico
    QList<QXlsx::Format> formatUndergroundSubjectsList = {formatBold, QXlsx::Format(), QXlsx::Format()};

    //Lista com variaveis de formatação de textos da parte final do histórico
    QList<QXlsx::Format> finalformat = {formatAlignTopLeft, formatBoldAlignTopLeft, formatAlignHVCenter,
                                        formatAlignHCenter, formatAlignHCenter, formatAlignHCenter,
                                        formatAlignHCenter};


    //***********Adicionando imagens***************
    QImage img1(":/images/samples/image1.png");
    historic.insertImage(0, 0, img1);

    QImage img2(":/images/samples/image2.png");
    historic.insertImage(0, 8, img2);

    //*****Mesclando e adicionando textos "fixos" do modelo de histórico
    for(int i = 0; i <= 63; i++){

        //********Mesclando Células/Preparando Histórico para escrever dados
        //Mesclando células para adicionar dados do histórico
        if(i < rangeCellsMerge.size()){
            QString rangeCell = rangeCellsMerge.at(i);

            //Condicional para adicionar formatação em células iniciais que o usuário pode alterar o valor
            if(rangeCellsMergeFormats.contains(rangeCell)){
                historic.mergeCells(rangeCell, formatBold);
            }
            historic.mergeCells(rangeCell);
        }

        //Mesclando Células para adicionar nomes fixos de matérias e cargas horárias
        if(i >= 21 && i <= 43){
            QString row = QString::number(i);
            QString rangeCellsSubject = "A" + row + ":D" + row;
            QString rangeCellsWorkload = "K" + row + ":M" + row;

            historic.mergeCells(rangeCellsSubject);     //subject
            historic.mergeCells(rangeCellsWorkload);        //carga horária

            //Adicionando Máterias, Cargas Horárias e Formatações para as notas no histórico
            if(i <= 36){
                QString row = QString::number(i);
                historic.write("A" + row, subjectsList.at(i - 21));  //Matéria

                //Cargas horárias
                historic.write("F" + row, workloadGradeFirstYear.at(i - 21), formatBoldAlignHCenter);     //1ºano
                historic.write("H" + row, workloadGradeSecondYear.at(i - 21), formatBoldAlignHCenter);    //2ºano
                historic.write("J" + row, workloadGradeThirdYear.at(i - 21), formatBoldAlignHCenter);     //3ºano
                historic.write("K" + row, workloadTotal.at(i - 21), formatBoldAlignHCenter);              //total

                //Formatação nas células com notas
                historic.write("E" + row, "", formatBoldAlignHCenter);   //1º ano
                historic.write("G" + row, "", formatBoldAlignHCenter);   //2º ano
                historic.write("I" + row, "", formatBoldAlignHCenter);   //3º ano
            }
        }

        //Mesclando células em cima das "OBSERVAÇÕES"
        if(i < 4){
            QString row = QString::number(44 + i);
            QStringList rangeCellsPositions = {"A" + row, "B" + row + ":G" + row,
                                               "H" + row + ":J" + row, "K" + row + ":M" + row};

            for(int j = 0; j < rangeCellsPositions.size(); j++){
                historic.mergeCells(rangeCellsPositions.at(j));
            }
        }

        //adicionando textos da lista dataText
        if(i < dataCells.size()){
            historic.write(dataCells.at(i), dataText.at(i), dataFormat.at(i));
        }

        //adicionando textos do lado de "DISCIPLINAS" no histórico
        if(i < cellsYearLetters.size()) {
            historic.write(cellsYearLetters.at(i) + "17", "ANO: " + QString::number(2016 + i),
                           formatBoldAlignHVCenter);
            historic.write(cellsYearLetters.at(i) + "19", QString::number(i + 1) + "º ANO",
                           formatAlignHCenter);
            historic.write(cellsYearLetters.at(i) + "20", "Nota/Conc", formatAlignHCenter);
        }

        //adcionando "C/H" no histórico
        if(i < workload.size()){
            historic.write(workload.at(i) + "20", "C/H", formatAlignHCenter);
        }

        //Adicionando textos em baixo das matérias
        if(i < undergroundSubjectsTextsList.size()){
            historic.write("A" + QString::number(41 + i),
                           undergroundSubjectsTextsList.at(i), formatUndergroundSubjectsList.at(i));
        }

        //Adicionando as cargas horárias totais de cada ano
        if(i < workloadTotalYearsLetters.size()){
            historic.write(workloadTotalYearsLetters.at(i) + "41", "1200", formatAlignHCenter);
        }

        //Adicionando os textos "APROVADO" em suas posições no histórico
        if(i < approvedCells.size()){
            historic.write(approvedCells.at(i) + "43", "APROVADO", formatAlignHCenter);
        }

        //Adicionando textos nas células em baixo da situação final
        if(i < subDataCells.size()){
            historic.write(subDataCells.at(i) + "44", subDataText.at(i), formatBoldAlignHCenter);
        }

        //Adicionando textos nas 3 células em cima de "OBSERVAÇÕES"
        if(i < subDataCells.size()){
            for(int j = 0; j < 3; j++){

                QString cell = subDataCells.at(i) + QString::number(45 + j);

                if(i == 0){     //colocando Série/Ano --> xª
                    historic.write(cell, QString::number(j + 1) + "º", formatBoldAlignHCenter);
                }else if (i == 1){  //Estabelecimento de Ensino
                    historic.write(cell, "CIEP 165 BRIGADEIRO SÉRGIO CARVALHO");
                }else if(i == 2){
                    historic.write(cell, "RIO DE JANEIRO/RJ", formatAlignHCenter);
                }else if(i == 3){
                    historic.write(cell, 2016 + j, formatBoldAlignHCenter);
                }
            }
        }

        //Adicionando textos nas células do final (Começa em "OBSERVAÇÕES")
        if(i < finalCells.size()){
            historic.write(finalCells.at(i), finalText.at(i), finalformat.at(i));
        }
    }

    //Escrevendo "Carga Horária" e "Total" e a carga horária total do E.M. no histórico
    historic.write("K17", "CARGA\nHORÁRIA", formatBoldAlignHVCenter);
    historic.write("K19", "TOTAL", formatBoldAlignHCenter);
    historic.write("K41", 3600, formatAlignHCenter);

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

        //Variaveis e Listas com letras de células de matérias, notas e cargas horárias
        const QString subjectLetter = "A";
        const QStringList gradesLetters = {"E", "G", "I"};
        const QStringList workloadsLetters = {"F", "H", "J"};

        bool dataComplete = true;   //variavel para auxiliar na verificação se os dados estão imcompletos

        //Estrutura de repetição para analisar as grades dos 3 anos escolares do(a) aluno(a)
        for(int numberGradeYear = 1; numberGradeYear <= 3; numberGradeYear++){

            Grades gradeYearCurrent = student.getGrades(QString::number(numberGradeYear));

            qDebug() << "Adicionando notas do " << numberGradeYear << "º ano ...\n" << endl;
            for(int line = 21; line <= 36; line++){

                double gradeTemp = 0;
                QString numberLineStr = QString::number(line);

                //Estrutura de decisões para achar a nota da matéria
                //Armazena nota na variavel temporária
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
                int workLoad = historic.read(workloadsLetters.at(numberGradeYear - 1) + numberLineStr).toInt();
                QString cellGradeInHistoric = gradesLetters.at(numberGradeYear - 1) + numberLineStr;
                if(gradeTemp < 0 && workLoad == 0){
                    qDebug() << "Nota de " << subjectInCell
                             << " ou/e sua carga horaria é invalida." << endl;
                    dataComplete = false;
                }else if(gradeTemp < 0 && workLoad != 0){
                    historic.write(cellGradeInHistoric, "*");
                }else{
                    historic.write(cellGradeInHistoric, gradeTemp);
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
