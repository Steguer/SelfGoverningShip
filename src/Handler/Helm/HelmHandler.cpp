/**
 * @file HelmHandler.cpp
 * @author  Steven GERARD
 */
#include "HelmHandler.hpp"

HelmHandler::HelmHandler()
{
	m_speedHelm = Parsser::readConfigInt("SpeedHelm");
	m_maxHelmAngle = Parsser::readConfigInt("MaxHelmAngle");
}

HelmHandler::~HelmHandler()
{
	
}