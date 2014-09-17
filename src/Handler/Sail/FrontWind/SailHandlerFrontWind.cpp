/**
 * @file SailHandlerFrontWind.cpp
 * @author Steven GERARD
 */
#include "SailHandlerFrontWind.hpp"

SailHandlerFrontWind::SailHandlerFrontWind()
{
	for(int i=0; i<=50; i+=10)
	{
		m_windMap[i] = 35;
	}
}

SailHandlerFrontWind::~SailHandlerFrontWind()
{

}

int SailHandlerFrontWind::runHandler(Coordinate const& cor)
{
	int wind;
	int inf = m_windMap.begin()->first;
	float axeRef = cor.calculateAxeRef(cor.getBoueAvLat(), cor.getBoueAvLon(), cor.getBoueApLat(), cor.getBoueApLon());
	int windAngle = cor.calculateWindAxeRef(axeRef, cor.getWindAxe());

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

	return m_windMap[wind];
}