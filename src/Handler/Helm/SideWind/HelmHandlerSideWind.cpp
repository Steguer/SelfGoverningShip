#include "HelmHandlerSideWind.hpp"

HelmHandlerSideWind::HelmHandlerSideWind(): HelmHandler()
{
	m_boueApLat = Parsser::readConfigDouble("BoueApLat");
	m_boueApLon = Parsser::readConfigDouble("BoueApLon");
	m_boueAvLat = Parsser::readConfigDouble("BoueAvLat");
	m_boueAvLon = Parsser::readConfigDouble("BoueAvLon");
	m_phase = FIRST;
}

HelmHandlerSideWind::~HelmHandlerSideWind()
{

}

int HelmHandlerSideWind::runHandler(Coordinate const& cor)
{
	// Logger::log("\n***Value in run handler side wind***");
	// float boatFlagAxe = cor.calculateBoatFlagAxe(m_boueApLat, m_boueApLon, cor.getLatitude(), cor.getLongitude());
	// int posNeg = cor.calculateTheta(boatFlagAxe, cor.getAxeBoat())>0 ? posNeg = 1 : posNeg = -1;

	// int res = m_maxHelmAngle*posNeg*(1-exp(posNeg*(-cor.calculateTheta(boatFlagAxe, cor.getAxeBoat())/m_speedHelm)));

	// cout<<"Value of helm handler side wind "<<res<<endl;
	// std::string str = "Value of boat flag axe ";
	// str += to_string(boatFlagAxe);
	// Logger::log(str);
	// str = "Value of theta ";
	// str += to_string(cor.calculateTheta(boatFlagAxe, cor.getAxeBoat()));
	// Logger::log(str);
	// str = "Value of boat axe ";
	// str += cor.getAxeBoat();
	// Logger::log(str);
	// Logger::log("***End value of handler side wind***\n");
	
	// res += 125;

	int res = runHandlerComeBack(cor);

	return res;
}

int HelmHandlerSideWind::runHandlerComeBack(Coordinate const& cor)
{
	double lat = 0;
	double lon = 0;

	cout<<"Value of lat "<<lat<<endl;
	cout<<"Value of lon"<<lon<<endl;


	Logger::log("\n***Value in run handler side wind***");
	float boatFlagAxe = cor.calculateBoatFlagAxe(m_boueApLat, m_boueApLon, cor.getLatitude(), cor.getLongitude());
	// float boatFlagAxe = cor.calculateBoatFlagAxe(m_boueApLat, m_boueApLon, 48.407040, -4.496062);
	float axeRef = cor.calculateAxeRef(m_boueAvLat, m_boueAvLon, m_boueApLat, m_boueApLon);

	float ang = subAngle(boatFlagAxe, axeRef);

	string str1 = "\nValue of axe ref ";
	str1 += to_string(axeRef);
	str1 += "\n";
	Logger::log(str1);
	cout<<str1<<endl;

	// switch(m_phase)
	// {
	// 	case FIRST:
	// 	{
	// 			Logger::log("\n***First phase of bypass***");
	// 			cout<<"first case "<<subAngle(boatFlagAxe, axeRef)<<endl;
	// 			cout<<"value of boat flag axe "<<boatFlagAxe<<endl;
	// 			cout<<"value of axe ref "<<axeRef<<endl;
	// 			boatFlagAxe += Parsser::readConfigInt("GapWithFlag");
	// 			string str = "Value of boat flag: ";
	// 			str += to_string(boatFlagAxe);
	// 			Logger::log(str);
	// 			str = "Value of angle boat flag/axe ref: ";
	// 			str += to_string(subAngle(boatFlagAxe, axeRef));
	// 			Logger::log(str);
	// 			Logger::log("***End first phase of bypass***\n");
	// 		if(ang > 90 && ang <= 180)
	// 		{
	// 			m_phase = SECOND;
	// 		}
	// 		break;
	// 	}
	// 	case SECOND:
	// 	{
	// 		if(ang > 90 && ang <= 180 )
	// 		{
	// 			Logger::log("\n***Second phase of bypass***");
	// 			cout<<"value of boat flag axe "<<boatFlagAxe<<endl;
	// 			cout<<"value of axe ref "<<axeRef<<endl;
	// 			cout<<"second case "<<subAngle(boatFlagAxe, axeRef)<<endl;
	// 			boatFlagAxe = subAngle(axeRef, 90);
	// 			string str = "Value of boat flag: ";
	// 			str += to_string(boatFlagAxe);
	// 			Logger::log(str);
	// 			str = "Value of angle boat flag/axe ref: ";
	// 			str += to_string(subAngle(boatFlagAxe, axeRef));
	// 			Logger::log(str);
	// 			Logger::log("***End second phase of bypass***\n");
	// 		}

	// 		else if(ang> 180 && ang <= 270 )
	// 		{
	// 			m_phase = THIRD;
	// 		}
	// 		break;
	// 	}
	// 	case THIRD:
	// 	{
	// 		if(ang> 180 && ang <= 270 )
	// 		{
	// 			Logger::log("\n***Third phase of bypass***");
	// 			cout<<"value of boat flag axe "<<boatFlagAxe<<endl;
	// 			cout<<"value of axe ref "<<axeRef<<endl;
	// 			cout<<"third case "<<ang<<endl;
	// 			boatFlagAxe = subAngle(axeRef, 90);
	// 			string str = "Value of boat flag: ";
	// 			str += to_string(boatFlagAxe);
	// 			Logger::log(str);
	// 			str = "Value of angle boat flag/axe ref: ";
	// 			str += to_string(subAngle(boatFlagAxe, axeRef));
	// 			Logger::log(str);
	// 			Logger::log("***End third phase of bypass***\n");
	// 		}
	// 		else if(ang > 270 && ang <= 360)
	// 		{
	// 			m_phase = FOURTH;
	// 		}
	// 		break;
	// 	}
	// 	case FOURTH:
	// 	{
	// 		Logger::log("\n***Third phase of bypass***");
	// 		cout<<"forth case"<<endl;
	// 		float tmp1 = m_boueApLat;
	// 		float tmp2 = m_boueApLon;
	// 		m_boueApLat = m_boueAvLat;
	// 		m_boueApLon = m_boueAvLon;
	// 		m_boueApLat = tmp1;
	// 		m_boueApLon = tmp2;
	// 		Logger::log("***End third phase of bypass***\n");
	// 		break;
	// 	}
	// }


	// int posNeg = cor.calculateTheta(boatFlagAxe, cor.getAxeBoat())>0 ? posNeg = 1 : posNeg = -1;

	// int res = m_maxHelmAngle*posNeg*(1-exp(posNeg*(-cor.calculateTheta(boatFlagAxe, cor.getAxeBoat())/m_speedHelm)));

	int posNeg = cor.calculateTheta(boatFlagAxe, cor.getAxeBoat())>0 ? posNeg = 1 : posNeg = -1;

	int res = m_maxHelmAngle*posNeg*(1-exp(posNeg*(-cor.calculateTheta(boatFlagAxe, cor.getAxeBoat())/m_speedHelm)));


	cout<<"Value of helm handler side wind "<<res<<endl;
	std::string str = "Value of boat flag axe ";
	str += to_string(boatFlagAxe);
	Logger::log(str);
	str = "Value of theta ";
	str += to_string(cor.calculateTheta(boatFlagAxe, cor.getAxeBoat()));
	Logger::log(str);
	str = "Value of boat axe ";
	str += cor.getAxeBoat();
	Logger::log(str);
	Logger::log("***End value of handler side wind***\n");
	
	res += 125;
	cout<<"Res of helm handller go and back "<<res<<endl;
	cout<<"******************Theta value "<<cor.calculateTheta(boatFlagAxe, cor.getAxeBoat())<<endl;

	return res;
}

float HelmHandlerSideWind::subAngle(float a, float b)
{
	float x;

	if(a > b)
	{
		x = a-b;
	}
	else
	{
		x = b-a;
	}
	
	if(x>360)
	{
		cout<<"coucou"<<endl;
		x -= 360;
	}
	else if(x<0)
	{
		cout<<"coucou2"<<endl;
		x += 360;
	}

	return x;
}