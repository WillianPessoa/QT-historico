#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <QObject>

#include "individualsheet.h"
#include "student.h"

#include <QList>

class StudentManager : public QObject
{
    Q_OBJECT
public:
    explicit StudentManager(QObject *parent = nullptr);


    /**
     * @brief insertStudentData Insere novos dados através de uma ficha individual.
     *        Verifica se é a primeira inserção de dados do estudante, caso o estudante
     *        já tenha sido adicionado, somente as informações extras são inseridas.
     * @param studentSheet
     * @return true se conseguiu realizar as inserções.
     */
    bool insertStudentData(const IndividualSheet &studentSheet);

    void insertStudents(const QList<Student> students);

    void replaceStudent(int index, const Student &student);

    /**
     * @brief containsStudent Verifica se contém um determinado estudante através do IDNumber
     * @param studentIDNumber
     * @return
     */
    bool containsStudent(const IndividualSheet &studentSheet) const;

    /**
     * @brief students Fornece todos os estudantes cadastrados (cópia)
     * @return Uma lista com os estudantes
     */
    QList<Student> students() const;

signals:

public slots:

private:
    bool isEqual(const Student &student, const IndividualSheet &studentSheet) const;

private:
    QList<Student> m_students;
};

#endif // STUDENTMANAGER_H
