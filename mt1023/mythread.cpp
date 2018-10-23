//#include "global.h"
#include "mythread.h"
#include "cedriver_cam.h"
#include "cedriver_usb.h"
#include "cedriver_imu.h"
#include "cedriver_config.h"


myThread::myThread()
{
}
void myThread::run(){
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
            //ce_cam_showimg_init();
        }
    }

    while(1){
        sleep(10);
    }
    //char myfilename[10];
    //while(true)
    //{
    //    if(p_lr.left.data && p_lr.right.data){

    //        emit send_data(p_lr);

    //        //sprintf(myfilename, "left%d.jpg",i);
    //        //cv::imwrite(myfilename, p_lr.left);
    //        //sprintf(myfilename, "right%d.jpg",i);
    //        //cv::imwrite(myfilename, p_lr.right);
    //    }
    //}

    ce_imu_capture_close();
    ce_imu_showdata_close();
    ce_cam_capture_close();
    ce_cam_showimg_close();
}

/*
void myThread::run(){
    //cv::Mat img = cv::imread("imgL.jpg");
    QTime timedebug;
    cv::VideoCapture cap = cv::VideoCapture(0);
    cv::Mat img;
    //cv::Mat img_gray;
    //cv::TermCriteria critera = cv::TermCriteria(
    //            cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS,
    //            40, 0.1);
    //int ret;
    //std::vector<cv::Point2f> corners;

    if(cap.isOpened()){
        while(1){
            timedebug.start();
            cap>>img;
            //cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
            //if(ret = cv::findChessboardCorners(img_gray,cv::Size(10,11),corners)){
            //    cv::cornerSubPix(img_gray, corners, cv::Size(10,11), cv::Size(-1,-1), critera);
            //    cv::drawChessboardCorners(img, cv::Size(10,11), corners, ret);
            //}
            emit send_data(img);
            //qDebug()<<"time: "<<timedebug.elapsed()/1000.0<<"s";
        }
    }
}
*/
