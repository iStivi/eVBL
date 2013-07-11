#ifndef EVBL_H
#define EVBL_H

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QFileDialog>
#include <QTimer>

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
    void multi_shot();
    void on_device_list_currentIndexChanged(int index);
    void on_zoom_setting_currentIndexChanged();
    void recentre_vertical_capture(int min_bar, int max_bar);
    void recentre_horizontal_capture(int min_bar, int max_bar);
    void on_save_image_button_clicked();
    void update_video();
    void on_evbl_tabs_currentChanged(int index);

private:
    Ui::eVBL *ui;

    void display_capture(cv::Mat display);
    void set_camera(int index);

    QTimer *preview_timer;
    cv::VideoCapture videoCapture;
    cv::Mat buffered_snapshot;
    cv::Mat preview_frame;
    cv::Mat output_preview;

protected:
    //void timerEvent(QTimerEvent*);

};


#endif // EVBL_H
