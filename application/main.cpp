#include "mainwindow.h"
#include <QApplication>

#include "importer.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    /** Ignorando parte visual
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec(); */

    // TODO: Implementar testes
    // Realiza a leitura dos arquivos de teste
    QList<IndividualSheet> list = Importer::importStudentsFrom(":/samples");
    return 0;
}
