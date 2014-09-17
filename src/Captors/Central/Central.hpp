/**
 * @file Central.hpp
 * @author  Batiste Bertier
 */
#ifndef CENTRAL_H
#define CENTRAL_H
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <vector>
#include <deque>

#include "../../Tools/Data.hpp"
#include "../../Tools/Parsser.hpp"
#include "../../Observer/Observable.hpp"

using namespace std;

class Central: public Observable
{
    public:
        Central();
int initCentral();
int readData();
void notifyData();

typedef struct bytes {

unsigned char bytes1;
unsigned char bytes2;
unsigned char bytes3;
unsigned char bytes4;

} bytes;

 typedef union data {

float nbFl;
bytes nbByte;

}data;

/*typedef struct rph {

int raw;
int pitch;
int heading;

}*/


/////////////////////////////////

struct CH{
unsigned char char0;
unsigned char char1;
unsigned char char2;
unsigned char char3;
unsigned char char4;
unsigned char char5;
unsigned char char6;
unsigned char char7;
unsigned char char8;
unsigned char char9;
unsigned char char10;
unsigned char char11;
}CH;

union flochar {
 float nbf1;
 float nbf1h;
 float nbf1p;
 struct CH nbch;
 } flochar;

 int getHeading();
 int getRaw();
 int getPitch();

    void  cbInit(CircularBuffer &cb, int size) ;
    void cbFree(CircularBuffer *cb) ;
    int cbIsFull(CircularBuffer *cb) ;
    int  cbIsEmpty(CircularBuffer *cb) ;
    void  cbWrite(CircularBuffer *cb, int *elem);
    void cbRead(CircularBuffer *cb, int *elem);
    int dataMean(deque <int> &buf, int sizeBuf);
    int finalData(int sizeMean);

    protected:

    int heading;
    int raw;
    int pitch;
    int dx;
    int a;
    int mean;

    short int fd,fd2;
    int bytes_read;

    deque<int> bu;
    int sizeMean;

    private:
};

#endif // CENTRAL_H
