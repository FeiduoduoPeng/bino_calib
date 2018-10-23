#ifndef MYCALIBRATION_H
#define MYCALIBRATION_H

#include "global.h"

bool myRgbdCalibration(const std::vector<cv::Mat> &img);
bool myBinocularCalibration();
bool myWriteXML(int total_imgs=0, std::string s = "stereo_calib.xml");

#endif // MYCALIBRATION_H
