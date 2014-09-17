/**
 * @file HelmHandlerBackFrontWind.cpp
 * @author  Steven GERARD, Boris JEUDY
 *
 * @brief Contain the implementation of the helm handler to front wind class.
 */

#include "HelmHandlerBackFrontWind.hpp"

HelmHandlerBackFrontWind::HelmHandlerBackFrontWind(): HelmHandler()
{
    m_rotation = ROTATION;
}

HelmHandlerBackFrontWind::HelmHandlerBackFrontWind(WindDirection wind): HelmHandler()
{
    switch(wind)
    {
        case FRONT_WIND:
            m_rotation = Parsser::readConfigInt("FrontWindRotation");
            break;
        case BACK_WIND:
            m_rotation = Parsser::readConfigInt("BackWindRotation");
            break;
        default:
            break;
    }
}

HelmHandlerBackFrontWind::~HelmHandlerBackFrontWind()
{

}

int HelmHandlerBackFrontWind::runHandler(Coordinate const& cor)
{

	float boatFlagAxe = cor.calculateBoatFlagAxe(cor.getBoueApLat(), cor.getBoueApLon(), cor.getLatitude(), cor.getLongitude());
    float alpha = calculateAlpha(boatFlagAxe, cor.getAxeRef());
    float distanceBM = distanceBoatMark(cor.getBoueApLat(), cor.getBoueApLon(), cor.getLatitude(), cor.getLongitude());
    float beta = calculatebeta(cor.getAxeRef(), cor.getAxeBoat());
    float turn = corridor(alpha, distanceBM, corridorValue(beta));
	if(turn == false)
	{
        int res = calculateNewHelm(cor, m_rotation);
        cout<<"Return of helm handler back wind "<<res<<endl;
        res += 125;
		return res;
	}

	else if(turn == true)
	{
        m_rotation *= -1;
        int res = calculateNewHelm(cor, m_rotation);
        cout<<"Return of helm handler back wind "<<res<<endl;
        res += 125;
		return res;
	}

	else
	{
		return 0;
	}
}

int HelmHandlerBackFrontWind::calculateNewHelm(Coordinate const& cor, int const& rotation)
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

    return m_maxHelmAngle*posNeg*(1-exp(posNeg*(-theta/m_speedHelm)));
}


float HelmHandlerBackFrontWind::calculateAlpha (float const& boatFlagAxe, float const& AxeRef)
{
   float x=0;
   float y = 0;
   float BFA = (boatFlagAxe*M_PI)/180;
   float AR = (AxeRef*M_PI)/180;

	// on utilise la formule qui est sin (a-b) = sin(a)*cos(b) - cos(a)*sin(b) avec x = a-b
	x = acos ( cos(BFA)*cos(AR) + sin(BFA)*sin(AR) );
    //avec a = BFA et b = AR

    y = asin ( sin(BFA)*cos(AR) - cos(BFA)*sin(AR) );

    x = (x*180)/M_PI;

    if (y <= 0)
        return x;
    else
        return -x;
}

float HelmHandlerBackFrontWind::distanceBoatMark (float const& boueApLat, float const& boueApLon, float const& boatLat, float const& boatLon)
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

float HelmHandlerBackFrontWind::calculatebeta (float const& AxeRef, float const& boatAxe)
{
    float x , y;
    float AR, BA;
    AR = (AxeRef*M_PI)/180;
    BA = (boatAxe*M_PI)/180;

	// on utilise la formule qui est sin (a-b) = sin(a)*cos(b) - cos(a)*sin(b) avec x = a-b
	x = acos ( cos(AR)*cos(BA) + sin(AR)*sin(BA) );
    //avec a = AR et b = boatAxe

    y = asin ( sin(AR)*cos(BA) - cos(AR)*sin(BA) );

    x = (x*180)/M_PI;

    if (y <= 0)
        return x;
    else
        return -x;
}

int HelmHandlerBackFrontWind::corridorValue (float const& beta)
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

bool HelmHandlerBackFrontWind::corridor (float const& alpha, float const& distanceBoatMark, int const& edgevalue)//=false;
{
    float distanceAuCentre;
    float Al = (alpha*M_PI)/180;


    distanceAuCentre = sin(Al) * distanceBoatMark;

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
