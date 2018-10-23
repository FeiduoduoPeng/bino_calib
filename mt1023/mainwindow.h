#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "global.h"
#include "mythread.h"
#include "cedriver_cam.h"
#include <QTimer>
#include "mycetool_calib_stereo_capture_img.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    static QImage Mat2QImage(const cv::Mat &img);
    void saveImage(const lrImg &img);

private slots:
    void on_pushButton_one_clicked();
    void accept();
    void on_pushButton_save_img_clicked();

    void on_pushButton_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_start_calib_clicked();

private:
    myThread *p_th;// = new myThread();
    Ui::MainWindow *ui;

    QTimer *timer = new QTimer(this);
    lrImg plr;
    bool save_flag = false;
    int frames=0;	//numbers of paired pictures;
};

#endif // MAINWINDOW_H
