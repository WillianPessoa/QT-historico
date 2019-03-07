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
    QXlsx::Document modelHistoric;

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

    //Variaveis de formatação de bordas das células
    QXlsx::Format borderThinCell;
    borderThinCell.setBorderStyle(QXlsx::Format::BorderThin);

    QXlsx::Format borderMediumRightBoldHCenter(formatBoldAlignHCenter);
    borderMediumRightBoldHCenter.setBorderStyle(QXlsx::Format::BorderThin);
    borderMediumRightBoldHCenter.setRightBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderMediumLeftBoldHCenter(formatBoldAlignHCenter);
    borderMediumLeftBoldHCenter.setBorderStyle(QXlsx::Format::BorderThin);
    borderMediumLeftBoldHCenter.setLeftBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderLeftMedium(borderThinCell);
    borderLeftMedium.setLeftBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderThinBoldAlignHCenter(formatBoldAlignHCenter);
    borderThinBoldAlignHCenter.setBorderStyle(QXlsx::Format::BorderThin);

    QXlsx::Format borderLeftTopMediumBoldHVCenter(formatBoldAlignHVCenter);
    borderLeftTopMediumBoldHVCenter.setBorderStyle(QXlsx::Format::BorderThin);
    borderLeftTopMediumBoldHVCenter.setTopBorderStyle(QXlsx::Format::BorderMedium);
    borderLeftTopMediumBoldHVCenter.setLeftBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderTopMediumBoldHVCenter(borderLeftTopMediumBoldHVCenter);
    borderTopMediumBoldHVCenter.setLeftBorderStyle(QXlsx::Format::BorderThin);

    QXlsx::Format borderThinAlignHCenter(formatAlignHCenter);
    borderThinAlignHCenter.setBorderStyle(QXlsx::Format::BorderThin);

    QXlsx::Format borderLeftMediumBold(formatBold);
    borderLeftMediumBold.setLeftBorderStyle(QXlsx::Format::BorderThin);
    borderLeftMediumBold.setLeftBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderMediumTopThinAlignTopLeft(formatAlignTopLeft);
    borderMediumTopThinAlignTopLeft.setBorderStyle(QXlsx::Format::BorderMedium);
    borderMediumTopThinAlignTopLeft.setTopBorderStyle(QXlsx::Format::BorderThin);

    QXlsx::Format borderMediumBoldAlignTopLeft(formatBoldAlignTopLeft);
    borderMediumBoldAlignTopLeft.setBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderMediumAlignHVCenter(formatAlignHVCenter);
    borderMediumAlignHVCenter.setVerticalAlignment(QXlsx::Format::AlignTop);
    borderMediumAlignHVCenter.setBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderNoneAlignHCenter(formatAlignHCenter);
    borderNoneAlignHCenter.setBorderStyle(QXlsx::Format::BorderNone);

    QXlsx::Format borderMediumRightLeft;
    borderMediumRightLeft.setBorderStyle(QXlsx::Format::BorderNone);
    borderMediumRightLeft.setLeftBorderStyle(QXlsx::Format::BorderMedium);
    borderMediumRightLeft.setRightBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderRightTopMediumBoldHVCenter(formatBoldAlignHVCenter);
    borderRightTopMediumBoldHVCenter.setBorderStyle(QXlsx::Format::BorderThin);
    borderRightTopMediumBoldHVCenter.setTopBorderStyle(QXlsx::Format::BorderMedium);
    borderRightTopMediumBoldHVCenter.setRightBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderLeftMediumAlignTopLeft(formatAlignTopLeft);
    borderLeftMediumAlignTopLeft.setBorderStyle(QXlsx::Format::BorderThin);
    borderLeftMediumAlignTopLeft.setLeftBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderMediumBottomNoneAlignTopCenter(formatAlignHCenter);
    borderMediumBottomNoneAlignTopCenter.setVerticalAlignment(QXlsx::Format::AlignTop);
    borderMediumBottomNoneAlignTopCenter.setBorderStyle(QXlsx::Format::BorderMedium);
    borderMediumBottomNoneAlignTopCenter.setBottomBorderStyle(QXlsx::Format::BorderNone);

    QXlsx::Format borderMediumTopNoneAlignTopCenter(formatAlignHCenter);
    borderMediumTopNoneAlignTopCenter.setVerticalAlignment(QXlsx::Format::AlignTop);
    borderMediumTopNoneAlignTopCenter.setBorderStyle(QXlsx::Format::BorderMedium);
    borderMediumTopNoneAlignTopCenter.setTopBorderStyle(QXlsx::Format::BorderNone);

    QXlsx::Format borderMediumTopNone;
    borderMediumTopNone.setBorderStyle(QXlsx::Format::BorderMedium);
    borderMediumTopNone.setTopBorderStyle(QXlsx::Format::BorderNone);

    QXlsx::Format borderLeftMediumHVCenter(formatAlignHVCenter);
    borderLeftMediumHVCenter.setLeftBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderRightMediumHVCenter(formatAlignHVCenter);
    borderRightMediumHVCenter.setRightBorderStyle(QXlsx::Format::BorderMedium);

    QXlsx::Format borderMediumRightLeftAlignTopLeft(borderMediumRightLeft);
    borderMediumRightLeftAlignTopLeft.setVerticalAlignment(QXlsx::Format::AlignTop);

    //*****************CRIANDO LISTAS***********************
    //Lista com conjunto de posições (range) do histórico para mesclar
    QStringList rangeCellsMerge = {"C2:H2", "C3:H3",        //Tipo de governo, tipo de secretaria
                                   "A6:F6", "A7:F7",        //nome da escola, tipo de estabelecimento
                                   "A9:F9", "A10:F10",      //endereço da escola, endereço
                                   "A11:M11", "B12:C12",    //Histórico escolar, Tipo de curso
                                   "A13:B13", "C13:M13",    //nome, nome do aluno
                                   "A14:B14", "C14:D14",    //data de nascimento, data/de/nascimento
                                   "E14:F14", "G14:H14",    //"NACIONALIDADE", nacionalidade
                                   "I14:J14", "K14:M14",    //"NATURALIDADE", naturalidade
                                   "B15:G15", "I15:M15",    //nome do pai, nome da mãe
                                   "A16:B16", "C16:E16",    //"IDENTIDADE nº", numero da ID
                                   "F16:G16", "H16:I16",    //"ORGÃO EXPEDIDOR", orgão expedidor
                                   "J16:K16", "L16:M16",    //"DATA DA EMISSÃO", data da emissão
                                   "A17:D20", "E17:F18",    //"DISCIPLINAS", ano do 1º ano
                                   "G17:H18", "I17:J18",    //ano do 2º ano, ano do 3º ano
                                   "K17:M18", "E19:F19",    //"CARGA HORÁRIA", "1º ANO"
                                   "G19:H19", "I19:J19",    //"2º ANO", "3º ANO"
                                   "K19:M19", "K20:M20",    //"TOTAL", espaço em branco
                                   "A48:M50", "A51:M54",    //"OBSERVAÇÕES", escola anterior
                                   "A55:M59", "I43:J43",    //"DATA DE EXPEDIÇÃO", "APROVADO"(3º ano)
                                   "E43:F43", "G43:H43",    //"APROVADO"(1º ano), "APROVADO" (2º ano)
                                   "A60:F60", "A61:F61",    //linha, "SECRETÁRIO ESCOLAR"
                                   "H60:M60", "H61:M61",    //linha, "DIRETOR"
                                   "A62:M63", "B44:G44",    //espaço em branco, "ESTABELECIMENTO DE ENSINO"
                                   "H44:J44", "K44:M44"};   //"MUNICIPIO/ESTADO", "ANO"

    //Lista com posições de células com dados fixos do histórico
    QStringList dataCells = {"C2","C3","A6","A7","A9","A10", "A11","A12","B12","A13",
                             "A14","E14","I14","A15","H15","A16","F16","J16","A17"};

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

    //Lista com algumas letras de células para adicionar bordas finas
    QStringList cellsBorderThinLetters = {"E", "F", "G", "H", "I", "J"};

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
    QStringList subDataCells = {"A","B","H", "K"};

    //Textos da parte de baixo acima de "OBSERVAÇÕES" no histórico
    QStringList subDataText = {"Série/Ano", "ESTABELECIMENTO DE ENSINO", "MUNICÍPIO / ESTADO", "ANO"};

    //Lista de posições de células da parte final do histórico
    QStringList finalCells = {"A48", "A51", "A55", "A60", "A61", "H60", "H61"};

    //Lista com textos das células da parte final do histórico
    QStringList finalText = {"OBSERVAÇÕES:",
                             "Segue em Anexo Histórico Escolar Anterior emitido de acordo com Deliberação CEE nº 363/17, art. 5º.",
                             "DATA DA EXPEDIÇÃO: RJ, " + QDate::currentDate().toString("dd/MM/yyyy"),
                             "_________________________________",
                             "SECRETÁRIO ESCOLAR",
                             "_________________________________",
                             "DIRETOR"};

    QList<QXlsx::Format> rangeCellsMergeFormats = {formatBoldAlignHCenter, formatBoldAlignHCenter,
                                                   formatBoldAlignHCenterUnderline, formatAlignHCenter,
                                                   formatBoldAlignHCenterUnderline, formatAlignHCenter,
                                                   formatBoldAlignHCenter, formatBoldUnderline,
                                                   QXlsx::Format(), formatBold,
                                                   QXlsx::Format(), formatBold,
                                                   QXlsx::Format(), formatBold,
                                                   QXlsx::Format(), formatBold,
                                                   formatBold, formatBold,
                                                   QXlsx::Format(), formatBold,
                                                   QXlsx::Format(), formatBold,
                                                   QXlsx::Format(), formatBold,
                                                   borderLeftTopMediumBoldHVCenter, borderTopMediumBoldHVCenter,
                                                   borderTopMediumBoldHVCenter, borderTopMediumBoldHVCenter,
                                                   borderRightTopMediumBoldHVCenter, borderThinAlignHCenter,
                                                   borderThinAlignHCenter, borderThinAlignHCenter,
                                                   borderMediumRightBoldHCenter, borderMediumRightBoldHCenter,
                                                   borderMediumRightLeftAlignTopLeft, borderMediumBoldAlignTopLeft,
                                                   borderMediumBottomNoneAlignTopCenter, borderThinAlignHCenter,
                                                   borderThinAlignHCenter, borderThinAlignHCenter,
                                                   borderLeftMediumHVCenter, borderLeftMediumHVCenter,
                                                   borderRightMediumHVCenter, borderRightMediumHVCenter,
                                                   borderMediumTopNone, borderThinBoldAlignHCenter,
                                                   borderThinBoldAlignHCenter, borderMediumRightBoldHCenter};

    //lista com formatações de textos nas células das 3 linhas em cima de "OBSERVAÇÕES"
    QList<QXlsx::Format> cellTopObservationsFormat = {borderThinCell, borderThinAlignHCenter,
                                                      borderMediumRightBoldHCenter};

    //Lista com variaveis de formatação de textos da parte final do histórico
    QList<QXlsx::Format> finalformat = {borderMediumTopThinAlignTopLeft, borderMediumBoldAlignTopLeft,
                                        borderMediumAlignHVCenter, borderNoneAlignHCenter,
                                        borderNoneAlignHCenter, borderNoneAlignHCenter,
                                        borderNoneAlignHCenter};

    //***********Adicionando imagens***************
    QImage img1(":/images/samples/image1.png");
    modelHistoric.insertImage(0, 0, img1);

    QImage img2(":/images/samples/image2.png");
    modelHistoric.insertImage(0, 8, img2);

    //*****Mesclando e adicionando textos "fixos" do modelo de histórico
    for(int i = 0; i <= 63; i++){

        //********Mesclando Células/Preparando Histórico para escrever dados
        //Mesclando células para adicionar dados do histórico
        if(i < rangeCellsMerge.size()){
            modelHistoric.mergeCells(rangeCellsMerge.at(i), rangeCellsMergeFormats.at(i));
        }

        //Mesclando Células para adicionar nomes fixos de matérias e cargas horárias
        if(i >= 21 && i <= 43){
            QString row = QString::number(i);
            QString rangeCellsSubject = "A" + row + ":D" + row;
            QString rangeCellsWorkload = "K" + row + ":M" + row;

            if(i == 41){
                modelHistoric.mergeCells(rangeCellsSubject, borderLeftMediumBold);
            }else{
                modelHistoric.mergeCells(rangeCellsSubject, borderLeftMedium);
            }

            modelHistoric.mergeCells(rangeCellsWorkload, borderMediumRightBoldHCenter);      //carga horária

            //Adicionando Máterias, Cargas Horárias e Formatações para as notas no histórico
            if(i <= 36){
                QString row = QString::number(i);
                modelHistoric.write("A" + row, subjectsList.at(i - 21));  //Matéria

                //Cargas horárias
                modelHistoric.write("F" + row, workloadGradeFirstYear.at(i - 21), borderThinBoldAlignHCenter);     //1ºano
                modelHistoric.write("H" + row, workloadGradeSecondYear.at(i - 21), borderThinBoldAlignHCenter);    //2ºano
                modelHistoric.write("J" + row, workloadGradeThirdYear.at(i - 21), borderThinBoldAlignHCenter);     //3ºano
                modelHistoric.write("K" + row, workloadTotal.at(i - 21));              //total

                //Formatação nas células com notas
                modelHistoric.write("E" + row, "", borderThinBoldAlignHCenter);   //1º ano
                modelHistoric.write("G" + row, "", borderThinBoldAlignHCenter);   //2º ano
                modelHistoric.write("I" + row, "", borderThinBoldAlignHCenter);   //3º ano
            }
        }

        //Adicionando bordas finas em algumas células
        if(i >= 37 && i <= 42){
            QString row = QString::number(i);
            for(int j = 0; j < cellsBorderThinLetters.size(); j++){
                modelHistoric.write(cellsBorderThinLetters.at(j) + row, "", borderThinCell);
            }
        }

        //Mesclando células em cima das "OBSERVAÇÕES"
        if(i < 4){
            QString row = QString::number(44 + i);
            QStringList rangeCellsPositions = {"B" + row + ":G" + row, "H" + row + ":J" + row,
                                               "K" + row + ":M" + row};

            for(int j = 0; j < rangeCellsPositions.size(); j++){
                modelHistoric.mergeCells(rangeCellsPositions.at(j), cellTopObservationsFormat.at(j));
            }
        }

        //adicionando textos da lista dataText
        if(i < dataCells.size()){
            modelHistoric.write(dataCells.at(i), dataText.at(i));
        }

        //adicionando textos do lado de "DISCIPLINAS" no histórico
        if(i < cellsYearLetters.size()) {
            modelHistoric.write(cellsYearLetters.at(i) + "17", "ANO: ");
            modelHistoric.write(cellsYearLetters.at(i) + "19", QString::number(i + 1) + "º ANO");
            modelHistoric.write(cellsYearLetters.at(i) + "20", "Nota/Conc", borderThinAlignHCenter);
        }

        //adicionando "C/H" no histórico
        if(i < workload.size()){
            modelHistoric.write(workload.at(i) + "20", "C/H", borderThinAlignHCenter);
        }

        //Adicionando textos em baixo das matérias
        if(i < undergroundSubjectsTextsList.size()){
            modelHistoric.write("A" + QString::number(41 + i), undergroundSubjectsTextsList.at(i));
        }

        //Adicionando as cargas horárias totais de cada ano
        if(i < workloadTotalYearsLetters.size()){
            modelHistoric.write(workloadTotalYearsLetters.at(i) + "41", "1200", borderThinAlignHCenter);
        }

        //Adicionando os textos "APROVADO" em suas posições no histórico
        if(i < approvedCells.size()){
            modelHistoric.write(approvedCells.at(i) + "43", "APROVADO");
        }

        //Adicionando textos nas células em baixo da situação final
        if(i < subDataCells.size()){
            if(i == 0){
                modelHistoric.write(subDataCells.at(i) + "44", subDataText.at(i), borderMediumLeftBoldHCenter);
            }
            modelHistoric.write(subDataCells.at(i) + "44", subDataText.at(i));
        }

        //Adicionando textos nas 3 células em cima de "OBSERVAÇÕES"
        if(i < (subDataCells.size() - 1)){
            for(int j = 0; j < 3; j++){
                QString cell = subDataCells.at(i) + QString::number(45 + j);

                if(i == 0){         //colocando Série/Ano --> xª
                    modelHistoric.write(cell, QString::number(j + 1) + "ª", borderMediumLeftBoldHCenter);
                }else if (i == 1){  //Estabelecimento de Ensino
                    modelHistoric.write(cell, "CIEP 165 BRIGADEIRO SÉRGIO CARVALHO");
                }else if(i == 2){   //Estado
                    modelHistoric.write(cell, "RIO DE JANEIRO/RJ");
                }
            }
        }

        //Adicionando textos nas células do final (Começa em "OBSERVAÇÕES")
        if(i < finalCells.size()){
            modelHistoric.write(finalCells.at(i), finalText.at(i));
        }
    }

    //Escrevendo "Carga Horária" e "Total" e a carga horária total do E.M. no histórico
    modelHistoric.write("K17", "CARGA\nHORÁRIA");
    modelHistoric.write("K19", "TOTAL");
    modelHistoric.write("K41", 3600);

    //Salvando histórico na pasta especificada pelo usuário com o nome do estudante no arquivo
    modelHistoric.saveAs(adressSaveModelHistoricStudent);

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

        //Adicionar dados básicos do aluno
        qDebug() << "Gravando dados pessoais ...\n" << endl;

        const QString name = student.name();
        historic.write("C13", name);                                  //name
        qDebug() << "Nome: " << name << endl;

        //TODO: implementar estrutura para verificar se a data de nascimento esta correta
        //      se não estiver, concertar invertendo a ordem que aparecem os membros
        const QString dateOfBirth = student.dateOfBirth().toString("dd/MM/yyyy");
        historic.write("C14", dateOfBirth);    //data de nascimento
        qDebug() << "Data de Nascimento: " << dateOfBirth << endl;

        const QString naturalness = student.naturalness();
        historic.write("K14", naturalness);
        qDebug() << "Naturalidade: " << naturalness << endl;

        const QString nationalness = (naturalness == "RIO DE JANEIRO - RJ") ? "BRASILEIRA" : "";
        historic.write("G14", nationalness);
        qDebug() << "Nacionalidade: " << nationalness << endl;

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

        //***Adicionando instituição anterior
        QString instituitionBackText;

        //verificando se instituição anterior existe
        if(student.institutionBack().isEmpty()){
            instituitionBackText.append("Segue em Anexo Histórico Escolar Anterior emitido de acordo com Deliberação CEE nº 363/17, art. 5º.");
        }else{
            instituitionBackText.append("Segue em Anexo Histórico Escolar Anterior emitido pelo(a) " + student.institutionBack() + " de acordo com Deliberação CEE nº 363/17, art. 5º.");
        }

        historic.write("A51", instituitionBackText);
        qDebug() << "Escola Anterior: " << instituitionBackText << endl;

        const QDate expeditionDate = QDate::currentDate();
        historic.write("A55", "DATA DA EXPEDIÇÃO: RJ, " + expeditionDate.toString("dd/MM/yyyy"));
        qDebug() << "Data da Expedição: " << expeditionDate.toString("dd/MM/yyyy") << endl;

        //Variaveis e Listas com letras de células de matérias, notas e cargas horárias
        const QString subjectLetter = "A";
        const QStringList gradesLetters = {"E", "G", "I"};
        const QStringList workloadsLetters = {"F", "H", "J"};

        bool dataComplete = true;   //variavel para auxiliar na verificação se os dados estão imcompletos

        //Estrutura de repetição para analisar as grades dos 3 anos escolares do(a) aluno(a)
        for(int numberGradeYear = 1; numberGradeYear <= 3; numberGradeYear++){

            Grades gradeYearCurrent = student.getGrades(QString::number(numberGradeYear));

            //Escrevendo ano
            QStringList cellsYear = {"E17", "K45"};
            if(gradeYearCurrent.series() == "2"){
                cellsYear.insert(0, "G17");
                cellsYear.insert(1, "K46");
            }else if(gradeYearCurrent.series() == "3"){
                cellsYear.insert(0, "I17");
                cellsYear.insert(1, "K47");
            }

            historic.write(cellsYear.at(0), "ANO: " + gradeYearCurrent.year());
            historic.write(cellsYear.at(1), gradeYearCurrent.year());

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
