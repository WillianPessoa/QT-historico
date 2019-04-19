#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

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
    QTreeWidget *getTree();

signals:
    void exportTranscripts();
    void folderSelected(QString folderName);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
