#ifndef MATTERANDNOTES_H
#define MATTERANDNOTES_H

#include <QString>

class SubjectAndGrade
{
public:
    SubjectAndGrade(QString subject,
                    double grade);

    QString subject() const;
    void setSubject(const QString &subject);

    double grade() const;
    void setGrade(const double &grade);

private:
    QString m_subject;
    double m_grade;
};

#endif // MATTERANDNOTES_H
