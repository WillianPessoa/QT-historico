#ifndef TRANSCRIPTMAKER_H
#define TRANSCRIPTMAKER_H

#include <QObject>

#include "mainwindow.h"
#include "studentmanager.h"

class TranscriptMaker : public QObject
{
    Q_OBJECT
public:
    explicit TranscriptMaker(QObject *parent = nullptr);

    /**
     * @brief startApp Inicializa a aplicação, realizando preparativos gráficos e não gráficos
     */
    void startApp();

signals:

public slots:

private:

    /**
     * @brief initUi Configira a interface gráfica antes de exibí-la
     */
    void initUi();

    /**
     * @brief makeConnections Estabelece todas as conexões necessárias com os 'módulos'
     */
    void makeConnections();


    /**
     * @brief tests Método de testes improvisado
     */
    void tests();

private:
    MainWindow m_mainWindow;
    StudentManager m_studentManager;
};

#endif // TRANSCRIPTMAKER_H
