/**
* @file BackWind.cpp
* @author Steven GERARD
* @version 1.0
* @date 11/12/2013
* 
* @brief Contain methode implementations of the BackWind class
*/

#include "BackWind.hpp"

BackWind::BackWind()
{

}

BackWind::~BackWind()
{

}

int BackWind::sailMotor(Coordinate const& cor)
{
	int s = m_shbw->runHandler(cor);
	return s;
}

int BackWind::helmMotor(Coordinate const& cor)
{
	int s = m_hhbw->runHandler(cor);
	return s;
}

void BackWind::setSailHandler(Handler *sh)
{
	m_shbw = sh;
}

void BackWind::setHelmHandler(Handler *hh)
{
	m_hhbw = hh;
}