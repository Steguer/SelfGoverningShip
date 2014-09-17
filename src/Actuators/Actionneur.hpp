/**
 * @file Actionneur.hpp
 * @author  Batiste Bertier
 */
#ifndef ACTIONNEUR_H
#define ACTIONNEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <thread>
#include "../Observer/Observer.hpp"
#include "../Tools/Data.hpp"

using namespace std;

class Actionneur: public Observer
{
    public:
        Actionneur();
        ~Actionneur();
        int Get() { return m_q; }
        void Set(int val) { m_q = val; }
        int Getup_time() { return up_time; }
        void Setup_time(int val) { up_time = val; }

        void moveJibe(int angle);
        void moveMainSail(int angle);
        void moveRudder(int angleD);
        void stopSystem();

        virtual void update(DataPack cmd);

    protected:
    private:
        int m_q;
        int up_time2;
        int up_time;
};

#endif // ACTIONNEUR_H
