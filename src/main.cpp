#include <QApplication>
#include <QMainWindow>
#include "Passenger.h"
#include "Building.h"
#include "Elevator.h"
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
    Building b(5);
    qDebug() << "Pięter:" << b.getTotalFloors();

    Passenger p1(1, 3);
    qDebug() << "Pasazer id:" << p1.getId() << "cel:" << p1.getDest();

    b.getFloor(0).addWaiting(p1, Direction::UP);
    qDebug() << "Pietro 0 UP" << b.getFloor(0).hasWaiting(Direction::UP);
    qDebug() << "Pietro 0 DOWN" << b.getFloor(0).hasWaiting(Direction::DOWN);

    Elevator e(1, 5);
    qDebug() << "Winda e na piętrze: " << e.getCurrentFloor();
    qDebug() << "Stan windy e:" << (int)e.getState();
    qDebug() << "Pasazerow w windzie:" << e.getLoad() << " Czy pełna: " << e.isFull();
     
    e.boardPassenger(p1);
    qDebug() << "Pasazerow w windzie:" << e.getLoad() << " Czy pełna: " << e.isFull();


    e.addStop(2);
    e.addStop(3);
    e.addStop(4);

    e.move(); //1
    e.move(); //2
    e.closeDoors();

    e.move(); //3


    auto alighted = e.alightPassengers();
    qDebug() << "Wysiadło: " << alighted.size();
    qDebug() << "Zostao: " << e.getLoad();

    e.closeDoors();
    e.move(); //4
    qDebug() << "Pietro po ruchu:" << e.getCurrentFloor();
    e.closeDoors();
    qDebug() << "Stan windy e:" << (int)e.getState();


    return app.exec();
}
