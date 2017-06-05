#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>

using namespace cv;
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->calibrer_ , SIGNAL(clicked()), this , SLOT(setTemplate()) );
    connect(ui->matcher_ , SIGNAL(clicked()), this , SLOT(myMatchTemplate()) ); // A CHANGER EN INITIALISER
    partie_=Partie();
    ui->Scene_->ciblegraph=partie_.niveaux_[0];


}

void MainWindow::updateScoreCible(void){
    ui->score->setText(QString::number(score_));
    ui->cib_->setText(QString::number(nombrecible_));
}


void MainWindow::updateTime(){

    seconds_++;
    QTime t = QTime().addSecs(seconds_);
    ui->time_->setText(t.toString());
    ui->Scene_->projectile.setZ(seconds_);
    ui->Scene_->updateGL(); // A enlever d'ici


}

void MainWindow::myMatchTemplate(){

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateScoreCible())); // A CHANGER EN FIN CIBLE
    int y1=0;
    int y2=0;
    double t1=0 ;
    double t2=0;
    if (templateImage_.empty() ){
        cout<<"Veuillez Entrer une image pour calibrer d'abords !!"<<endl;
    }
    else{

    Mat frame;         // frame Mat
    cam_->read(frame);
    // Create the matchTemplate image result
    Mat resultImage;    // to store the matchTemplate result
    int result_cols =  frame.cols - templateImage_.cols + 1;
    int result_rows = frame.rows - templateImage_.rows + 1;
    resultImage.create( result_cols, result_rows, CV_32FC1 );
    Rect resultRect;    // to store the location of the matched rect
    // Online template matching
    cout<<"Online template matching, hit a key to stop"<<endl;
    while (waitKey(5)<0)
    {
        if (cam_->read(frame)) // get a new frame from cupamera
        {

            // vertical flip of the image
            flip(frame,frame,1);

            // Do the Matching between the frame and the templateImage
            matchTemplate( frame, templateImage_, resultImage, TM_CCORR_NORMED );

            // Localize the best match with minMaxLoc
            double minVal; double maxVal; Point minLoc; Point maxLoc;
            minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
            // Save the location fo the matched rect
            resultRect=Rect(maxLoc.x,maxLoc.y,128,128);

            // Show the result
            Mat normResultImage;
            // Normalize values
            normalize(resultImage,normResultImage,1,0,NORM_MINMAX);
            // Return to RGB to plot the max in red
            cvtColor(normResultImage,normResultImage,CV_GRAY2RGB);
            // Draw a red square
            rectangle(normResultImage,Rect(maxLoc.x,maxLoc.y,3,3),Scalar( 0, 0, 1),2,8,0);

            // Show image

            // Draw green rectangle on the frame
            rectangle(frame,resultRect,Scalar( 0, 255, 0),2,8,0);
            // Display the frame
            cvtColor(frame,frame,CV_BGR2RGB);            // Invert Blue and Red color channels
            QImage img= QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_RGB888); // Convert to Qt image
            ui->label->setPixmap(QPixmap::fromImage(img));           // Display on label
            ui->label->resize(ui->label->pixmap()->size()); // Resize the label to fit the image
            t1=t2;
            t2=QDateTime::currentMSecsSinceEpoch();
            y1=y2;
            y2 =maxLoc.y;
            coordx_=maxLoc.x;
            coordy_=maxLoc.y;
            vitesseMain_ = (y2-y1)*1000/(t2-t1) ;

//cout <<"Vitesse "<< V << " px/s " <<endl ;

            if (vitesseMain_>80 && maxLoc.y<240 ){
                cout<< "Initialiser le jeu "<<endl;
            }
}
}}
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setTemplate(){
    cam_->set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cam_->set(CV_CAP_PROP_FRAME_HEIGHT , 480);
    int frameWidth_=cam_->get(CV_CAP_PROP_FRAME_WIDTH);
    int frameHeight_=cam_->get(CV_CAP_PROP_FRAME_HEIGHT);
    Rect templateRect((frameWidth_-128)/2,2*(frameHeight_-128)/3,128,128);
    string input="";
    while(input == "" || (input.find_first_of(" ")!=-1)){
        input=QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo (Sans espaces) ?").toStdString();

    }


    // Acquisition of the template image

             // frame Mat
    while (waitKey(10)<0)
    {
        if (cam_->read(frame_)) // get a new frame from camera
        {

            // vertical flip of the image
            flip(frame_,frame_,1);
            // Copy the template rect
            templateImage_=Mat(frame_,templateRect).clone();
            // Draw red rectangle on the frame
            rectangle(frame_,templateRect,Scalar( 0, 0, 255),2,8,0);
            // Display the frame
            cvtColor(frame_,frame_,CV_BGR2RGB);            // Invert Blue and Red color channels
            QImage img= QImage((const unsigned char*)(frame_.data),frame_.cols,frame_.rows,QImage::Format_RGB888); // Convert to Qt image
            ui->label->setPixmap(QPixmap::fromImage(img));           // Display on label
            ui->label->resize(ui->label->pixmap()->size()); // Resize the label to fit the image


        }
    }


}



