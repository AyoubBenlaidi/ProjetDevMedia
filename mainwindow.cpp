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

}

void MainWindow::updatescore(void){
    ui->score->setText(QString::number(score_));
}
void MainWindow::updatecible(void){
    ui->cib_->setText(QString::number(nombrecible_));
}


void MainWindow::up(){

    sec++;
    QTime t = QTime().addSecs(sec);
    ui->time_->setText(t.toString());


}

void MainWindow::myMatchTemplate(){
    partie_=Partie();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(up()));
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatecible())); // A CHANGER EN FIN CIBLE
    connect(timer, SIGNAL(timeout()), this, SLOT(updatescore())); // A CHANGER EN FIN CIBLE
    int y1=0;
    int y2=0;
    int moy=0;
    double V=0;
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
        if (cam_->read(frame)) // get a new frame from camera
        {

            // vertical flip of the image
            flip(frame,frame,1);

            // Do the Matching between the frame and the templateImage
            matchTemplate( frame, templateImage_, resultImage, TM_CCORR_NORMED );

            // Localize the best match with minMaxLoc
            double minVal; double maxVal; Point minLoc; Point maxLoc;
            minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
            // Save the location fo the matched rect
            resultRect=Rect(maxLoc.x,maxLoc.y,templateWidth_,templateHeight_);

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
            V = (y2-y1)*1000/(t2-t1) ;

//cout <<"Vitesse "<< V << " px/s " <<endl ;

            //POUR TESTER
            score_=V;

            if (V>80 && maxLoc.y<240 ){
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
    frameWidth_=cam_->get(CV_CAP_PROP_FRAME_WIDTH);
    frameHeight_=cam_->get(CV_CAP_PROP_FRAME_HEIGHT);
    Rect templateRect((frameWidth_-templateWidth_)/2,2*(frameHeight_-templateHeight_)/3,templateWidth_,templateHeight_);


    string input="";
    while(input == "" || (input.find_first_of(" ")!=-1)){
        input=QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo (Sans espaces) ?").toStdString();

    }


    // Acquisition of the template image

             // frame Mat
    while (waitKey(10)<0)
    {
        if (cam_->read(frame)) // get a new frame from camera
        {
            // vertical flip of the image
            flip(frame,frame,1);
            // Copy the template rect
            templateImage_=Mat(frame,templateRect).clone();
            // Draw red rectangle on the frame
            rectangle(frame,templateRect,Scalar( 0, 0, 255),2,8,0);
            // Display the frame
            cvtColor(frame,frame,CV_BGR2RGB);            // Invert Blue and Red color channels
            QImage img= QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_RGB888); // Convert to Qt image
            ui->label->setPixmap(QPixmap::fromImage(img));           // Display on label
            ui->label->resize(ui->label->pixmap()->size()); // Resize the label to fit the image


        }
    }


}



