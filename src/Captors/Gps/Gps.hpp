/**
 * @file Gps.hpp
 * @author  Batiste Bertier
 */
#ifndef GPS_H
#define GPS_H
#define TAILLE 70

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../../Tools/Data.hpp"
#include "../../Observer/Observable.hpp"

using namespace std;

class Gps: public Observable
{
    public:
        Gps();

    void initGpsUart();
    int readData();
    float readLat();
    float readLongi();
    float readVelocity();
    void sizeFile();
    void supprFile();

    protected:

    char rawData[TAILLE];
    int size;

    float longiDecimale;
    char *longiStr;

    void convertDecimal();

    float latDecimale;
     char *latStr;

   float velocity_knots;
   char *velocityStr;
   long velocity ;

    private:



};

#endif // GPS_H
