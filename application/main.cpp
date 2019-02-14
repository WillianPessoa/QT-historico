#include "transcriptmaker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TranscriptMaker tm;
    tm.startApp();
    return a.exec();

    /*
    // TODO: Implementar testes
    // Realiza a leitura dos arquivos de teste
    QList<IndividualSheet> list = Importer::importStudentsFrom(":/samples");
    return 0;*/
}
