/**
 * @file FrontWind.cpp
 * @author Steven GERARD
 * @version 1.0
 * @date 11/12/2013
 * 
 * @brief Contain method implmentations of the FrontWind class
 */

#include "FrontWind.hpp"

FrontWind::FrontWind()
{
	
}

FrontWind::~FrontWind()
{

}

int FrontWind::sailMotor(Coordinate const& cor)
{
	int s = m_shfw->runHandler(cor);
	return s;
}

int FrontWind::helmMotor(Coordinate const& cor)
{
	int s = m_hhfw->runHandler(cor);
	return s;
}

void FrontWind::setSailHandler(Handler *sh)
{
	m_shfw = sh;
}

void FrontWind::setHelmHandler(Handler *hh)
{
	m_hhfw= hh;
}