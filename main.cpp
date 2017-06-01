#include "mainwindow.h"
#include <QApplication>
#include "scenedejeu.h"
#include <GL/glut.h>


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(1500 ,800);
    w.move(50 , 100);
    w.show();

    return a.exec();
}
