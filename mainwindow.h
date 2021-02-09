#pragma once

#include <QMainWindow>

#include <QString>

class Network;

class QLineEdit;
class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString& url, QWidget *p = nullptr);
    ~MainWindow() override;

private:
    Network *m_network = nullptr;
    QLineEdit *m_url = nullptr;
    QTextEdit *m_text = nullptr;
};
