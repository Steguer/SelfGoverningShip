/**
 * @file Coordinate.cpp
 * @author Boris JEUDY
 * @date 26/02/2014
 *
 * @brief Contain the implementation of the Coordinate class
 */

#include "Coordinate.hpp"


Coordinate::Coordinate ()
{
	//constructeur pour initialiser l'objet bateau

	m_boatAxe = 0;
	m_longitude = 0;
	m_latitude = 0; 
	m_windAxe = 0;	
	m_boatFlagAxe = 0;
	m_axeRef = 0;	
	m_theta = 0;
	m_latLast = 0;
	m_lonLast = 0;
	m_boatAxeGPS = 0;
	m_mainSail = 0;
	m_jib = 0;
	m_helm = 0;
	m_speed = 0;
	m_boueApLat = Parsser::readConfigDouble("BoueApLon");
	m_boueApLon = Parsser::readConfigDouble("BoueApLat");
	m_boueAvLat = Parsser::readConfigDouble("BoueAvLon");
	m_boueAvLon = Parsser::readConfigDouble("BoueAvLat");
}

Coordinate::Coordinate (float boatAxe, float latitude, float longitude, float boueAvLat, float boueAvLon, float boueApLat, float boueApLon)
{
	//constructeur pour l'objet bateau avec des paramètres

	m_boatAxe = boatAxe;
	m_longitude = longitude;
	m_latitude = latitude;
	m_latLast = latitude;
	m_lonLast = longitude;

	m_mainSail = 0;
	m_jib = 0;
	m_helm = 0;
	m_speed = 0;

	m_boatAxeGPS = calculateBoatAxeGPS(m_latitude, m_longitude, m_latLast, m_lonLast);
	m_axeRef = calculateAxeRef (boueAvLat, boueAvLon, boueApLat, boueApLon);
	m_boatFlagAxe = calculateBoatFlagAxe ( boueApLat, boueApLon, m_latitude, m_longitude);
	m_theta = calculateTheta (m_boatFlagAxe, m_boatAxe );

	m_boueApLat = Parsser::readConfigDouble("BoueApLon");
	m_boueApLon = Parsser::readConfigDouble("BoueApLat");
	m_boueAvLat = Parsser::readConfigDouble("BoueAvLon");
	m_boueAvLon = Parsser::readConfigDouble("BoueAvLat");
}

float Coordinate::calculateBoatAxeGPS (float latitude, float longitude, float lastLat, float lastLon)
{
    float a;

	// on verifie qu'on ne divise pas par 0 quand on utilise la formule pour calculer la pente entre deux points
	if (latitude==lastLat)
	{
		//si c'est égale alors on vérifie la position des longitudes
		if(latitude<lastLon)
        {
            return 90;
        }
        else if (longitude==lastLon)
        {
            return 0;
        }

		else
        {
            return 270;
        }
	}

	//sinon on lance le calcul
	else
	{

		//calcul du coefficient directeur de la pente par rapport à l'axe verticale (NORD)
		a = ((longitude-lastLon) / (latitude - lastLat));

		//la direction étant déterminee il ne reste plus qu'a trouver le sens
		//pour cela on compare les deux latitudes si la latitude de la bouee d'apres est plus petite que celle de la bouee d'avant alors il faut ajouter ou soustraire 180°

		if (latitude<lastLat)
		{
			//si a est négatif ou nul alors il faut rajouter pour obtenir une valeur d'angle entre 90° et 180°
			if (a <=0 )
			{
				return ((M_PI+ atan(a))*180)/M_PI;

			}

			//sinon si a est positif alors il faut soustraire pour obtenir une valeur d'angle entre -90° et -180°
			else if (a>0)
			{
				return 360+(((atan(a)-M_PI)*180)/M_PI);
			}
		}

		//sinon les angles sont les bons, on peut retourner directement la valeur

		else
        {
			float res;
        	(atan(a)*180)/M_PI<0 ? (res = (360+(atan(a)*180)/M_PI)) : (res = ((atan(a)*180)/M_PI));
        	return res;
        }

	}
}

//methode
float Coordinate::calculateAxeRef (float boueAvLat, float boueAvLon, float boueApLat, float boueApLon) const
{	//sinon on lance le calcul

	float a;

	cout<<"************* value of boueAvLat" << boueAvLat<<endl;
	cout<<"************* value of boueAvLon" << boueAvLon<<endl;
	cout<<"************* value of boueApLat" << boueApLat<<endl;
	cout<<"************* value of boueApLon" << boueApLon<<endl;	

	// on verifie qu'on ne divise pas par 0 quand on utilise la formule pour calculer la pente entre deux points
	if (boueApLat==boueAvLat)
	{
		//si c'est égale alors on vérifie la position des longitudes
		if(boueApLon<boueAvLon)
        {
            return 90;
        }
        else if (boueApLon==boueAvLon)
        {
            return 0;
        }

		else
        {
            return 270;
        }
	}

	//sinon on lance le calcul
	else
	{

		//calcul du coefficient directeur de la pente par rapport à l'axe verticale (NORD)
		a = ((boueApLon-boueAvLon) / (boueApLat - boueAvLat));

		//la direction étant déterminee il ne reste plus qu'a trouver le sens
		//pour cela on compare les deux latitudes si la latitude de la bouee d'apres est plus petite que celle de la bouee d'avant alors il faut ajouter ou soustraire 180°

		if (boueApLat<boueAvLat)
		{
			//si a est négatif ou nul alors il faut rajouter pour obtenir une valeur d'angle entre 90° et 180°
			if (a <=0 )
			{
				return ((M_PI+ atan(a))*180)/M_PI;

			}

			//sinon si a est positif alors il faut soustraire pour obtenir une valeur d'angle entre -90° et -180°
			else if (a>0)
			{
				return 360+(((atan(a)-M_PI)*180)/M_PI);
			}
		}

		//sinon les angles sont les bons, on peut retourner directement la valeur

		else
        {
        	float res;
        	(atan(a)*180)/M_PI<0 ? (res = (360+(atan(a)*180)/M_PI)) : (res = ((atan(a)*180)/M_PI));
        	return res;
        }

	}
}

float Coordinate::calculateBoatFlagAxe ( float boueApLat, float boueApLon, float boatLat, float boatLon) const
{
	float a;

	// on verifie qu'on ne divise pas par 0 quand on utilise la formule pour calculer la pente entre deux points
	if (boueApLat==boatLat)
	{
		//si c'est égale alors on vérifie la position des longitudes
		if(boueApLon<boatLon)

        {
            return 90;
        }
        else if (boueApLon==boatLon)
        {
            return 0;
        }
		else
        {
            return 270;
        }
	}

	//sinon on lance le calcul
	else
	{

		//calcul du coefficient directeur de la pente par rapport à l'axe verticale (NORD)
		a = ((boueApLon-boatLon) / (boueApLat - boatLat));


		//la direction étant déterminee il ne reste plus qu'a trouver le sens
		//pour cela on compare les deux latitudes si la latitude de la bouee d'apres est plus petite que celle de la bouee d'avant alors il faut ajouter ou soustraire 180°

		if (boueApLat<boatLat)
		{
			//si a est négatif ou nul alors il faut rajouter pour obtenir une valeur d'angle entre 90° et 180°
			if (a <=0 )
			{
				return ((M_PI+atan(a))*180)/M_PI;
			}

			//sinon si a est positif alors il faut soustraire pour obtenir une valeur d'angle entre -90° et -180°
			else if (a>0)
			{
				return 360+(((atan(a)-M_PI)*180)/M_PI);
            }
		}

		//sinon les angles sont les bons, on peut retourner directement la valeur

		else
        {
        	float res;
        	(atan(a)*180)/M_PI<0 ? (res = (360+(atan(a)*180)/M_PI)) : (res = ((atan(a)*180)/M_PI));
        	return res;
        }
	}
}

float Coordinate::calculateTheta ( float boatFlagAxe, float axeBoat) const
{
	float x , y;

	boatFlagAxe = (boatFlagAxe*M_PI)/180;
	axeBoat = (axeBoat*M_PI)/180;

	// on utilise la formule qui est sin (a-b) = sin(a)*cos(b) - cos(a)*sin(b) avec x = a-b
	x = acos ( (cos(boatFlagAxe)*cos(axeBoat)) + (sin(boatFlagAxe)*sin(axeBoat)) );
    //avec a = boatFlagAxe et b = axeBoat

    y = asin ( sin(boatFlagAxe)*cos(axeBoat) - cos(boatFlagAxe)*sin(axeBoat) );

    x = (x*180)/M_PI;

    if (y <= 0)
        return -x;
    else
        return x;
}

// float Coordinate::calculateTheta ( float boatFlagAxe, float axeBoat) const
// {
// 	cout<<"boat flag axe in calcule theta "<<boatFlagAxe<<endl;
// 	cout<<"axe boat in calcule theta "<<axeBoat<<endl;
// 	float sub = boatFlagAxe - axeBoat;
// 	float res = 0;
// 	if(sub > 360)
// 	{
// 		res = sub - 360;
// 	}
// 	else if(sub < 0)
// 	{
// 		res = 360 + sub;
// 	}
// 	else
// 	{
// 		res = sub;
// 	}

// 	if(res > 180)
// 	{
// 		res = (360 - res)*(-1);
// 	}

// 	return res;
// }

float Coordinate::calculateWindAxeRef(float axeRef, float axeWind) const
{
	float x;

	axeWind += 170;

	if(axeWind > 360)
	{
		axeWind -= 360;
	}

	cout<<"$$$$$$$$$$$$$$$$$$$ wind "<<axeWind<<endl;

	axeRef = (axeRef*M_PI)/180;
	axeWind = (axeWind*M_PI)/180;

	// on utilise la formule qui est sin (a-b) = sin(a)*cos(b) - cos(a)*sin(b) avec x = a-b
	x = acos ( (cos(axeRef)*cos(axeWind)) + (sin(axeRef)*sin(axeWind)) );
    //avec a = boatFlagAxe et b = axeBoat

    x = (x*180)/M_PI;

    return x;
}



//Accesseur
float Coordinate::getTheta() const
{
	return m_theta;
}

float Coordinate::getAxeBoat() const
{
	return m_boatAxe;
}

float Coordinate::getBoatFlagAxe() const
{
	return m_boatFlagAxe;
}

float Coordinate::getLatitude() const
{
	return m_latitude;
}

float Coordinate::getLongitude() const
{
	return m_longitude;
}

float Coordinate::getWindAxe() const
{
	return m_windAxe;
}

float Coordinate::getAxeRef() const
{
	return m_axeRef;
}

float Coordinate::getBoueApLat() const
{
	return m_boueApLat;
}

float Coordinate::getBoueApLon() const
{
	return m_boueApLon;
}

float Coordinate::getBoueAvLat() const
{
	return m_boueAvLat;
}

float Coordinate::getBoueAvLon() const
{
	return m_boueAvLon;
}

float Coordinate::getRaw() const
{
	return m_raw;
}
float Coordinate::getPitch() const
{
	return m_pitch;
}
void Coordinate::setRaw(float raw)
{
	m_raw = raw;
}
void Coordinate::setPitch(float pitch)
{
	m_pitch = pitch;
}

map<string, double> Coordinate::getAllData() const
{
	map<string, double> data;

	data["longitude"] = m_longitude;
	data["latitude"] = m_latitude;
	data["windAxe"] = m_windAxe;
	data["boueApLat"] = m_boueApLat;
	data["boueApLon"] = m_boueApLon;
	data["boueAvLat"] = m_boueAvLat;
	data["boueAvLon"] = m_boueAvLon;
	data["speed"] = m_speed;
	data["pitch"] = m_pitch;
	data["raw"] = m_raw;
	
	return data;
}

vector<float> Coordinate::getValueToEC()
{
	vector<float> tab;
	tab.push_back(m_latitude);
	tab.push_back(m_longitude);
	tab.push_back(0);
	tab.push_back(0);
	tab.push_back(m_helm);
	tab.push_back(m_mainSail);
	tab.push_back(m_jib);
	tab.push_back(m_windAxe);
	tab.push_back(0);
	tab.push_back(m_pitch);
	tab.push_back(m_speed);
	tab.push_back(m_boatAxe);

	return tab;
}

//Modificateurs
void Coordinate::setLatitude (float newLatitude)
{
	m_latLast = m_latitude;
	m_latitude = newLatitude;
}

void Coordinate::setLongitude (float newLongitude)
{
	m_lonLast = m_longitude;
	m_longitude = newLongitude;
}

void Coordinate::setAxeBoat (float newAxeBoat)
{
	m_boatAxe = newAxeBoat;
}

void Coordinate::setWindAxe(float newAxeWind)
{
	m_windAxe = newAxeWind;
}

void Coordinate::setHelm(float helm)
{
	m_helm = helm;
}

void Coordinate::setMainSail(float mainSail)
{
	m_mainSail = mainSail;
}

void Coordinate::setJib(float jib)
{
	m_jib = jib;
}

void Coordinate::setSpeed(float speed)
{
	m_speed = speed;
}
