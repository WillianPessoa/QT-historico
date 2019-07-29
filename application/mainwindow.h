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

public slots:
    void showStudent(const Student &student);
    void generateTree(const Student &student);
    void gradesDisplay(const Student &student);

    void selectFolder();
    void selectFile();

    void editStudent();
    void saveStudent(Student &student);

    QString nameStudentForEdit() const;
    void setNameStudentForEdit(const QString &nameStudentForEdit);

    QTreeWidget *studentsTree();
    QPushButton *editStudentPushButton();
    QPushButton *saveStudentPushButton();
    QString nameLineEditText() const;

    void setNameStudent(Student &student, const QString &name);

    void lockUi(bool value);

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
