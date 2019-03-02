#include "transcriptmaker.h"
#include <QApplication>

#include "xlsxdocument.h"
#include <QDebug>
#include <QFile>
#include <QDir>

#include <exporter.h>
#include "student.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TranscriptMaker tm;
    tm.startApp();
    return a.exec();
}
