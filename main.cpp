#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Set a default, take the first argument if supplied as the URL.
    QString url = "http://google.com/";
    if (argc > 1)
        url = QString(argv[1]);

    // Instantiate our window and start the event loop.
    MainWindow m(url);
    m.show();
    return app.exec();
}
