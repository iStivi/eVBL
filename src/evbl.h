#ifndef EVBL_H
#define EVBL_H

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include <QtMultimedia/QCameraImageCapture>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

namespace Ui {
class eVBL;
}

class eVBL : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit eVBL(QWidget *parent = 0);
    ~eVBL();

private slots:
    void take_shot();

private:
    Ui::eVBL *ui;

    QCamera *camera;
    QCameraImageCapture *imageCapture;

    cv::VideoCapture videoCapture;

protected:
    void timerEvent(QTimerEvent*);

};


#endif // EVBL_H
