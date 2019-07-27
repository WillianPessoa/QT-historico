#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAbstractItemView>
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

    QTreeWidgetItem *getBackStudent() const;
    void setBackStudent(QTreeWidgetItem *value);

public slots:
    void showStudent(const Student &student);
    void generateTree(const Student &student);
    void gradesDisplay(const Student &student);

    void selectFolder();
    void selectFile();

    void editStudent();
    void saveStudent(Student &student);

    QString nameStudentEdit() const;
    void setNameStudentEdit(const QString &nameStudentEdit);

    QTreeWidget *getTree();
    QPushButton *getEditStudentButton();
    QPushButton *getSaveStudentButton();
    bool nameLineIsReadOnly();

signals:
    void exportTranscripts();
    void folderSelected(QString folderName);
    void fileSelected(QString fileName);

private:
    Ui::MainWindow *ui;

    QString m_openFolder;
    QString m_nameStudentEdit;
};

#endif // MAINWINDOW_H
