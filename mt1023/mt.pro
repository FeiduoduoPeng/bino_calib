#-------------------------------------------------
#
# Project created by QtCreator 2018-10-17T15:55:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mt
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    mythread.cpp \
    mycalibration.cpp \
    src/cedriver_cam.cpp \
    src/cedriver_imu.cpp \
    src/cedriver_usb.cpp \
    src/celib_img_process.cpp \
    src/cedriver_config.cpp \
    src/cetool_cali_stereo_capture_img.cpp

INCLUDEPATH += $$PWD/include

HEADERS  += mainwindow.h \
    mythread.h \
    global.h \
    mycalibration.h \
    include/cedriver_cam.h \
    include/cedriver_config.h \
    include/cedriver_imu.h \
    include/celib_img_process.h \
    include/cedriver_usb.h \
    include/mycetool_calib_stereo_capture_img.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include \

/usr/local/include/opencv \

/usr/local/include/opencv2

#LIBS += $$PWD/lib/libCEDRIVER_CAM.a
#LIBS += $$PWD/lib/libCEDRIVER_CONFIG.a
#LIBS += $$PWD/lib/libCEDRIVER_IMU.a

LIBS += /usr/local/lib/libopencv_calib3d.so\
    /usr/local/lib/libopencv_core.so \
    /usr/local/lib/libopencv_dnn.so \
    /usr/local/lib/libopencv_features2d.so \
    /usr/local/lib/libopencv_flann.so \
    /usr/local/lib/libopencv_highgui.so \
    /usr/local/lib/libopencv_imgcodecs.so \
    /usr/local/lib/libopencv_imgproc.so \
    /usr/local/lib/libopencv_ml.so \
    /usr/local/lib/libopencv_objdetect.so \
    /usr/local/lib/libopencv_photo.so \
    /usr/local/lib/libopencv_shape.so \
    /usr/local/lib/libopencv_stitching.so \
    /usr/local/lib/libopencv_superres.so \
    /usr/local/lib/libopencv_video.so \
    /usr/local/lib/libopencv_videoio.so \
    /usr/local/lib/libopencv_videostab.so \
    /usr/local/lib/libopencv_viz.so \
    /usr/local/lib/libopencv_aruco.so \
    /usr/local/lib/libopencv_bgsegm.so

LIBS += -lusb-1.0

