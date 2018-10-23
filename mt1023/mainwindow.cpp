#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mycalibration.h"
#include "cedriver_cam.h"
#include "cedriver_config.h"

extern std::mutex pfmutex;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //timer = new QTimer(this);


    //p_th = new myThread();
    //qRegisterMetaType<cv::Mat>("cv::Mat");
    //qRegisterMetaType<lrImg>("lrImg");
    //QObject::connect(p_th,SIGNAL(send_data(const lrImg &)), this, SLOT(accept(const lrImg &)),Qt::ConnectionType::BlockingQueuedConnection);
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(accept()));

    /*initialize the frames*/
    QDir dir_l("./imgL");
    QStringList filter;
    filter<<"*.jpg";
    dir_l.setNameFilters(filter);
    QFileInfoList fileinfo = dir_l.entryInfoList(filter);

    frames = fileinfo.count() ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::Mat2QImage(const cv::Mat &cvImg){
    QImage qImg;
    if(cvImg.channels()==3){                         //3 channels color image
        static cv::Mat cv_temp;
        cv::cvtColor(cvImg,cv_temp,CV_BGR2RGB);
        qImg =QImage((const unsigned char*)(cv_temp.data),
                    cv_temp.cols, cv_temp.rows,
                    cv_temp.cols*cv_temp.channels(),
                    QImage::Format_RGB888);
    }
    else if(cvImg.channels()==1){                    //grayscale image
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_Indexed8);
    }
    else{
        qImg =QImage((const unsigned char*)(cvImg.data),
                    cvImg.cols,cvImg.rows,
                    cvImg.cols*cvImg.channels(),
                    QImage::Format_RGB888);
    }
    return qImg;
}

void MainWindow::saveImage(const lrImg &img){
    std::ostringstream ostr_l, ostr_r;
    ostr_l<<"./imgL/"<<"left"<<frames<<".jpg";
    ostr_r<<"./imgR/"<<"right"<<frames<<".jpg";
    cv::imwrite(ostr_l.str(), img.left);
    cv::imwrite(ostr_r.str(), img.right);
    frames++;
}

void MainWindow::on_pushButton_one_clicked()
{
    //p_th->start();
    ce_config_load_settings("./config/cecfg_std.txt");

    int r = ce_cam_capture_init();
    if(r < 0)
    {
        printf("celog: cam capture error \r\n");
    }else{
        printf("celog: cam capture success \r\n");

        r = ce_cam_preprocess_init();
        if(r < 0)
        {
            printf("celog: cam preprocess error \r\n");
        }else{
            //ce_cam_showimg_init(plr);
            ce_cam_capture_calib_init(plr);
        }
    }
    timer->start(100);

}

void MainWindow::accept(){
    pfmutex.lock();
    ui->label_left->setPixmap(QPixmap::fromImage(Mat2QImage(plr.left)) );
    ui->label_right->setPixmap(QPixmap::fromImage(Mat2QImage(plr.right)) );
    if(save_flag){
        saveImage(plr);
        save_flag = false;
    }
    pfmutex.unlock();
    //sleep(1);		//for test
}

void MainWindow::on_pushButton_save_img_clicked()
{
    save_flag = true;
    //myBinocularCalibration();
}

void MainWindow::on_pushButton_clicked(){}

void MainWindow::on_pushButton_clear_clicked()
{
    QDir dir_l("./imgL");
    QDir dir_r("./imgR");
    foreach (QString dirFile, dir_l.entryList()) {
        std::cout<<dirFile.toStdString()<<std::endl;
        dir_l.remove(dirFile);
    }
    foreach (QString dirFile, dir_r.entryList()) {
        std::cout<<dirFile.toStdString()<<std::endl;
        dir_r.remove(dirFile);
    }
    frames = 0 ;
}


void MainWindow::on_pushButton_start_calib_clicked()
{
    myWriteXML(frames);
    std::cout<<frames<<std::endl;
    sleep(1);
    myBinocularCalibration();
}
