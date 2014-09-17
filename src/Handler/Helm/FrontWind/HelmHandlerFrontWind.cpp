/**
 * @file HelmHandlerFrontWind.cpp
 * @author  Steven GERARD, Boris JEUDY
 * 
 * @brief Contain the implementation of the helm handler to front wind class.
 */

#include "HelmHandlerFrontWind.hpp"

HelmHandlerFrontWind::HelmHandlerFrontWind(): HelmHandler()
{
}

HelmHandlerFrontWind::~HelmHandlerFrontWind()
{

}

int HelmHandlerFrontWind::runHandler(Coordinate const& cor)
{
    float boatFlagAxe = cor.calculateBoatFlagAxe(cor.getBoueApLat(), cor.getBoueApLon(), cor.getLatitude(), cor.getLongitude());
	float alpha = calculateAlpha(boatFlagAxe, cor.getAxeRef());
	float distanceBM = distanceBoatMark(cor.getBoueApLat(), cor.getBoueApLon(), cor.getLatitude(), cor.getLongitude());
	float beta = calculatebeta(cor.getAxeRef(), cor.getAxeBoat());
	float turn = corridor(alpha, distanceBM, corridorValue(beta));
	if(turn == false)
	{
		return calculateNewHelm(cor, ROTATION);
	}

	else if(turn == true)
	{
		return calculateNewHelm(cor, -ROTATION);
	}

	else
	{
		return 0;
	}
}

int HelmHandlerFrontWind::calculateNewHelm(Coordinate const& cor, int const& rotation)
{
	float newAxe = cor.getWindAxe()+rotation;
    if(newAxe > 360)
    {
        newAxe = newAxe-360;
    }
    else if(newAxe < 0)
    {
        newAxe = 360 + newAxe;
    }

    float theta = cor.calculateTheta(newAxe, cor.getAxeBoat());

    int posNeg = theta>0 ? posNeg = 1 : posNeg = -1;

    return m_maxHelmAngle*posNeg*(1-exp(posNeg*(-cor.getTheta()/m_speedHelm)));
}

float HelmHandlerFrontWind::distanceBoatMark (float const& boueApLat, float const& boueApLon, float const& boatLat, float const& boatLon)
{
    double angle;
    float distance;
    float A, B, C, D;

    /* (all converted to radians: degree/57.29577951)*/
    A = boueApLat/57.29577951;
    cout <<"boueApLon "<< A <<endl;
    B = boueApLon/57.29577951;
    cout <<"boueApLat "<< B <<endl;
    C = boatLat/57.29577951;
    cout<< "boatLon "<< C <<endl;
    D = boatLon/57.29577951;
    cout <<"boatLat "<< D <<endl;



    if ((A == C) and (B == D))
   {
       cout <<"distance égale"<<endl;
       distance = 0;

   }

   else
   {
//=ACOS(SIN(RADIANS(B2))*SIN(RADIANS(B3))+COS(RADIANS(B2))*COS(RADIANS(B3))*COS(RADIANS(C2-C3)))*6371.
        if (((sin(A)*sin(C))+(cos(A)*cos(C)*cos(B-D))) > 1)
        {
            angle = acos(1); /* solved a prob I ran into.  I haven't fully analyzed it yet */
            cout << "supérieur a 1, valeur de langle " << angle << endl;
            distance = 6367445*angle;
            cout << "supérieur a 1, valeur de la distance " << distance << endl;
        }

        else
        {
            angle =2*asin(sqrt(((sin((A-C)/2))*(sin((A-C)/2))) + cos(A)*cos(C)*(sin((B-D)/2))*(sin((B-D)/2))));// acos((sin(A)*sin(C))+(cos(A)*cos(C)*cos(B-D)));
            cout << "inférieur a 1, valeur de langle " << angle << endl;
            distance=6370985*angle;
            cout << "inférieur a 1, valeur de la distance " << distance << endl;


        }
   }

   return distance;

}

float HelmHandlerFrontWind::calculateAlpha (float const& boatFlagAxe, float const& AxeRef)
{
   float x=0;
   float y = 0;

    // on utilise la formule qui est sin (a-b) = sin(a)*cos(b) - cos(a)*sin(b) avec x = a-b
    x = acos ( cos(boatFlagAxe)*cos(AxeRef) + sin(boatFlagAxe)*sin(AxeRef) );
    //avec a = boatFlagAxe et b = AxeRef

    y = asin ( sin(boatFlagAxe)*cos(AxeRef) - cos(boatFlagAxe)*sin(AxeRef) );

    if (y <= 0)
        return -x;
    else
        return x;
}

float HelmHandlerFrontWind::calculatebeta (float const& AxeRef, float const& boatAxe)
{
    float x , y;

	// on utilise la formule qui est sin (a-b) = sin(a)*cos(b) - cos(a)*sin(b) avec x = a-b
	x = acos ( cos(AxeRef)*cos(boatAxe) + sin(AxeRef)*sin(boatAxe) );
    //avec a = AxeRef et b = boatAxe

    y = asin ( sin(AxeRef)*cos(boatAxe) - cos(AxeRef)*sin(boatAxe) );

    if (y <= 0)
        return -x;
    else
        return x;
}

int HelmHandlerFrontWind::corridorValue (float const& beta)
{
    int edgeVal;

    if (beta > 0 )
    {
        edgeVal = valMax ;
    }
    else
    {
        edgeVal = valMin ;
    }
    return edgeVal;
}

bool HelmHandlerFrontWind::corridor (float const& alpha, float const& distanceBoatMark, int const& edgevalue)//=false;
{
    float distanceAuCentre;


    distanceAuCentre = sin(alpha) * distanceBoatMark;

    if (edgevalue < 0)
    {
        if (distanceAuCentre <= edgevalue)
        {
            return true;
        }
        else return false;
    }
    else
    {
        if (distanceAuCentre > edgevalue)
        {
            return true;
        }
        else return false;
    }
}