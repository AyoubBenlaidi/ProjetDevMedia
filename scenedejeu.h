#ifndef SCENEDEJEU_H
#define SCENEDEJEU_H
#include <QGLWidget>

class SceneDejeu : public QGLWidget
{
    Q_OBJECT
public:
    explicit SceneDejeu(QWidget * parent =0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w , int h );


};

#endif // SCENEDEJEU_H
