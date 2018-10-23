#ifndef MYTHREAD_H
#define MYTHREAD_H
#include "global.h"
#include "cedriver_cam.h"

class myThread : public QThread{
    Q_OBJECT
public:
    myThread();
    virtual void run();

//public:

signals:
    void send_data(const lrImg &img);
};

Q_DECLARE_METATYPE(cv::Mat)

#endif // MYTHREAD_H
