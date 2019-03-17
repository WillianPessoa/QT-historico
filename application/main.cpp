#include "transcriptmaker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TranscriptMaker tm;
    tm.startApp();
    return a.exec();
}
