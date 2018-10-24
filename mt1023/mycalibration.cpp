#include "mycalibration.h"

bool myRgbCalibration(const std::vector<cv::Mat> &img_vec){
    return true;
}

bool myBinocularCalibration(){
    QProcess *proc = new QProcess;
    proc->start("./bin/CETOOL_CALI_STEREO_CAL -w=10 -h=11 ./stereo_calib.xml");	//it's working!
    return true;
}

bool myWriteXML(int total_imgs, std::string s){
    std::ofstream out_file;
    out_file.open(s);
    if(!out_file){
        return false;
    }

    out_file<<"<?xml version=\"1.0\"?>\n"<<std::endl;
    out_file<<"<opencv_storage>"<<std::endl;
    out_file<<"<imagelist>"<<std::endl;
    for(int i=0; i<total_imgs; ++i){
        out_file<<"\"./imgL/left"<<i<<".jpg\""<<std::endl;
        out_file<<"\"./imgR/right"<<i<<".jpg\""<<std::endl;
    }
    out_file<<"</imagelist>"<<std::endl;
    out_file<<"</opencv_storage>"<<std::endl;
    out_file.close();
    return true;
}

