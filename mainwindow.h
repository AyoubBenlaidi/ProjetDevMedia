#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtOpenGL>
#include "opencv2/opencv.hpp"
#include <QWidget>
#include "partie.h"
#include "scenedejeu.h"

using namespace cv;




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Mat templateImage_;
    Mat frame_;
    VideoCapture *cam_ =new VideoCapture(0);
    Partie partie_ ;
    int nombrecible_=10;
    int score_=0;
    int seconds_=0;
    double vitesseMain_=0;
    //position de la main [ x entre 0 et 512 ] [ y entre 0 et 280 ]
    int coordx_;
    int coordy_;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    void setNombreCible(int n){nombrecible_=n;}
    void setScore(int s){score_=s;}

private slots:
    void setTemplate(void);
    void myMatchTemplate(void);
    void updateTime(void);
    void updateScoreCible(void);

};

#endif // MAINWINDOW_H
