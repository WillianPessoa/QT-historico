#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>

#include <qtreewidget.h>

#include "student.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showStudent(const Student &student);
    void generateTree(const Student &student);
    void gradesDisplay(const Student &student);
    void selectFolder();
    void selectFile();
    QTreeWidget *getTree();

signals:
    void exportTranscripts();
    void folderSelected(QString folderName);
    void fileSelected(QString fileName);

private:
    Ui::MainWindow *ui;

    QString m_openFolder;
};

#endif // MAINWINDOW_H
