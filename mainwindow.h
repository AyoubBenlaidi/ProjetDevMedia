#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtOpenGL>
#include "opencv2/opencv.hpp"
#include <QWidget>
#include "partie.h"

using namespace cv;




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Mat templateImage_; // template Mat
    int frameWidth_;
    int frameHeight_;
    int templateWidth_=128;
    int templateHeight_=128;
    VideoCapture *cam_ =new VideoCapture(0);
    Ui::MainWindow *ui;
    Partie partie_ ;


private slots:
    void setTemplate(void);
    void myMatchTemplate(void);
    void updateTable(void);
};

#endif // MAINWINDOW_H
