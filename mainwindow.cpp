#include "mainwindow.h"

#include "network.h"

#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

#include <QDebug>

MainWindow::MainWindow(const QString& url, QWidget *p) : QMainWindow(p)
{
    // Set up the network class, very basic...
    m_network = new Network(this);

    // Now a simple form to make queries, and display the responses.
    auto widget = new QWidget(this);
    auto vLayout = new QVBoxLayout();
    auto fLayout = new QFormLayout();
    auto hLayout = new QHBoxLayout();

    m_text = new QTextEdit();
    m_url = new QLineEdit();
    m_url->setText(url);
    auto combo = new QComboBox();
    combo->addItem("byte");
    combo->addItem("short");
    combo->addItem("int");
    combo->addItem("float");
    combo->addItem("double");
    combo->addItem("text");
    combo->setCurrentIndex(3);
    auto button = new QPushButton(tr("Do it!"));

    fLayout->addRow(tr("API URL:"), m_url);
    fLayout->addRow(tr("Payload Type:"), combo);
    hLayout->addLayout(fLayout);
    hLayout->addWidget(button);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(m_text);
    widget->setLayout(vLayout);
    setCentralWidget(widget);

    // A few signal-slot connections using new syntax and lambdas.
    connect(button, &QPushButton::clicked, [this]() {
        m_network->makeRequest(m_url->text());
    });

    connect(combo, qOverload<int>(&QComboBox::currentIndexChanged), [this](int index) {
        m_network->setType(index);
    });

    connect(m_network, &Network::reply, [this](QString data) {
        m_text->setText(data);
    });
}

MainWindow::~MainWindow()
{
    m_network->deleteLater();
}
