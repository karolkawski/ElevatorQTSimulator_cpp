#include <QApplication>
#include <QMainWindow>
#include "Passenger.h"
#include <QDebug>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle(QStringLiteral("Windziarz — symulacja"));
    window.resize(640, 480);
    window.show();

    //debbug
    // Passenger p(1, 5);
    // qDebug() << "Pasażer id:" << p.getId() << "cel:" << p.getDest();

    return app.exec();
}
