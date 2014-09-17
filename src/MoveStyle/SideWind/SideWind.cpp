/**
 * @file SideWind.cpp
 * @author Steven GERARD
 * @date 10/02/2014
 * 
 * @brief Contain methode implementations of the SideWind class
 */
#include "SideWind.hpp"

SideWind::SideWind()
{

}

SideWind::~SideWind()
{

}

int SideWind::sailMotor(Coordinate const& cor)
{

	int s = m_shsw->runHandler(cor);

	std::cout<<"return of sail side wind: "<< s<<std::endl;

	return s;
}

int SideWind::helmMotor(Coordinate const& cor)
{
	int s = m_hhsw->runHandler(cor);

	std::cout<<"return of helm side wind: "<<s<<std::endl;


	return s;
}

void SideWind::setSailHandler(Handler *sh)
{
	cout<<"***Welcome in the setSailHandler to SideWind***"<<endl;
	cout<<"The new handler adress in the pointer is: "<<sh<<endl;
	m_shsw = sh;
	cout<<"Now the sail handler have as adress: "<<m_shsw<<endl;
	cout<<"***	Quit the setSailHandler to SideWind	***"<<endl;

}

void SideWind::setHelmHandler(Handler *hh)
{
	cout<<"***Welcome in the setHelmHandler to SideWind***"<<endl;
	cout<<"The new handler adress is: "<<hh<<endl;
	m_hhsw = hh;
	cout<<"Now the helm handler have as adress: "<<m_shsw<<endl;
	cout<<"***	Quit the setHelmHandler to SideWind	***"<<endl;
}