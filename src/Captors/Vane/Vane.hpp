/**
 * @file Vane.hpp
 * @author  Batiste Bertier
 */
#ifndef VANE_H
#define VANE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <math.h>
#include <vector>
#include "../../Observer/Observable.hpp"
#include "../../Tools/Data.hpp"
/****************************************************************
* Constants
****************************************************************/

#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define MAX_BUF 64

using namespace std;


class Vane: public Observable
{
public:

    Vane();

    int gpio_get_value(unsigned int gpio, int *value);
    int gpio_set_dir(unsigned int gpio, unsigned int out_flag);
    int gpio_unexport(unsigned int gpio);
    int gpio_export(unsigned int gpio);
    int dataVane();
    int convert(int value,int correction);

    void initGpio();
    void closeGpio();
    void  cbInit(CircularBuffer &cb, int size) ;
    void cbFree(CircularBuffer *cb) ;
    int cbIsFull(CircularBuffer *cb) ;
    int  cbIsEmpty(CircularBuffer *cb) ;
    void  cbWrite(CircularBuffer *cb, int *elem);
    void cbRead(CircularBuffer *cb, int *elem);
    int dataMean(vector<int> &buf);
    int getMeanData();


protected:
private:
};

#endif // VANE_H
