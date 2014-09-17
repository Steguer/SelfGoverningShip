/**
 * @file SailHandlerSideWind.cpp
 * @author Steven GERARD
 */
#include "SailHandlerSideWind.hpp"

SailHandlerSideWind::SailHandlerSideWind()
{
	for(int i=50, j=35; i<=160; i+=10, j+=5)
	{
		m_windMap[i] = j;
	}


}

SailHandlerSideWind::~SailHandlerSideWind()
{

}

int SailHandlerSideWind::runHandler(Coordinate const& cor)
{
	int wind;
	int inf = m_windMap.begin()->first;
	float axeRef = cor.calculateAxeRef(cor.getBoueAvLat(), cor.getBoueAvLon(), cor.getBoueApLat(), cor.getBoueApLon());
	int windAngle = cor.calculateWindAxeRef(cor.getAxeBoat(), cor.getWindAxe());
	float res = 35;

	if(windAngle <=50 && windAngle>=0)
	{
		res = Parsser::readConfigInt("FrontWindSail");
	}

	else if(windAngle >= 160 && windAngle <= 180)
	{
		res = Parsser::readConfigInt("BackWindSail");
	}

	else
	{
		for(pair<const int,int> &i : m_windMap)
		{
			if(windAngle<i.first && windAngle>inf)
			{
				if(cor.getWindAxe() == i.first)
				{
					wind = i.first;
					break;
				}
				if(windAngle < i.first-((i.first - inf)/2))
				{
					wind = inf;
				}
				else
				{
					wind = i.first;
				}
				break;
			}
			inf = i.first;
		}
		res = m_windMap[wind];
	}

	return res;
}
