/**
 * @file Coordinate.hpp
 * @author Boris JEUDY
 * @date 26/02/2014
 *
 * @brief Contain the decalaration of Coordinate class
 */

#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <sstream>
#include <cmath>
#include <map>
#include "Parsser.hpp"


#define M_PI 3.14159265358979323846




using namespace std;

/**
 * @class Coordinate
 * @brief Manage the record of the data.
 * @details Allow to record data and calculate the reference axe and the axe betwenne the
 * 			the boat and the water flag.
 * @test The tests are realize with a specific class @see Coordinate_Test.cpp
 */
class Coordinate
{
	private:
	//attributs

		//valeur a entrer
		/**
		 * @brief Current boat axe
		 */
		float m_boatAxe; 	//axe du bateau
		/**
		 * @brief Current boat longitude
		 */
		float m_longitude; 	//longitude du bateau
		/**
		 * @brief Current boat latitude
		 */
		float m_latitude;  	// latitude du bateau
		/**
		 * @brief Current wind axe
		 */
		float m_windAxe;	//Axe of the wind
		/**
		 * @brief Arrival point latitude
		 */
		float m_boueApLat;
		/**
		 * @brief Arrival point longitude
		 */
		float m_boueApLon;
		/**
		 * @brief Starting point latitude
		 */
		float m_boueAvLat;
		/**
		 * @brief Starting point longitude
		 */
		float m_boueAvLon;
		/**
		 * @brief Last boat latitude
		 */
		float m_latLast;
		/**
		 * @brief Last boat longitude
		 */
		float m_lonLast;
		/**
		 * @brief Current boat raw
		 */
		float m_raw;
		/**
		 * @brief Current boat pitch
		 */
		float m_pitch;
		/**
		 * @brief Current command for the helm
		 */
		float m_helm;
		/**
		 * @brief Current command for the main sail
		 */
		float m_mainSail;
		/**
		 * @brief Current command for the jib
		 */
		float m_jib;
		/**
		 * @brief Current velocity of the boat
		 */
		float m_speed;

		//valeur a calculer
		/**
		 * @brief Boat axe calculate with gps datas
		 */
		float m_boatAxeGPS;
		/**
		 * @brief Axe between the arrival point and the boat
		 */
		float m_boatFlagAxe;  	// axe entre le bateau et la bouee suivante
		/**
		 * @brief Axe between the arrival point and the starting point
		 */
		float m_axeRef;		// axe entre la dernière bouee et la suivante
		/**
		 * @brief Axe between the the boat axe and the boat-flag axe
		 */
		float m_theta;		// angle entre axe bateau bouee (boatFatAxe) et laxe du bateau (axeBoat)



	public:
		/**
		 * @brief Default constructor of the class
		 * @details Init all attributs to 0
		 * @param nothing
		 * @return nothing
		 */
		Coordinate();

		/**
		 * @brief Advance constructor
		 * @details This methode implemente the local attributs with the new attributs
		 * 			and calculate the both axis (reference axe and boat-flag axe) with the both methods
		 * 			calculateAxeRef and calculateBoatFlagAxe.
		 *
		 * @param boatAxe Init boat axe collect with the boat compas
		 * @param longitude Init longitude value collect with GPS
		 * @param latitude Init latitude value collect with GPS
		 * @param boueApLat Init next mark latitude value collect in memorise
		 * @param boueApLon Init next mark longitude value collect in memorise
		 * @param boueAvLat Init last mark latitude value collect in memorise
		 * @param boueAvLon Init last mark longitude value collect in memorise
		 * @return nothing
		 */
		Coordinate (float boatAxe, float latitude, float longitude, float boueAvLat, float boueAvLon, float boueApLat, float boueApLon);

    //methode

		/**
		 * @brief Allow to work out the reference axe.
		 * @details To work out the angle the reference axe from north. It is the axe formed by two mark, the last and the next mark
		 *
		 * @param boueAvLat last mark latitude value letting to calculate the referent axe
		 * @param boueAvLon last mark longitude value letting to calculate the referent axe
		 * @param boueApLat next mark latitude value letting to calculate the referent axe
		 * @param boueApLon next mark longitude value letting to calculate the referent axe
		 * @return angle of the referent axe in degrees (0°, 360°).
		 */
		float calculateAxeRef (float boueAvLat, float boueAvLon, float boueApLat, float boueApLon) const;

		/**
		 * @brief Allow to work out the boat axe.
		 * @details To work out the angle the boat axe from north.
		 *
		 * @param latitude : boat latitude value
		 * @param longitude : boat longitude value
		 * @param lastLat : last boat latitude value
		 * @param lastLon : last boat longitude value
		 * @return angle of the boat axe in degrees (0°, 360°).
		 */
		float calculateBoatAxeGPS (float latitude, float longitude, float lastLat, float lastLon);

		/**
		 * @brief Allow to work out the boat flag axe
		 * @details calculate the angle from north formed by the boat and the next mark.
		 *
		 * @param boueApLat next mark latitude value letting to calculate the boat flag axe
		 * @param boueApLon next mark longitude value letting to calculate the boat flag axe
		 * @param boatLat boat latitude value letting to calculate the boat flag axe
		 * @param boatLon boat longitude value letting to calculate the boat flag axe
		 * @return angle of the boat flag axe in degrees (0°, 360°).
		 */
		float calculateBoatFlagAxe ( float boueApLat, float boueApLon, float boatLat, float boatLon) const;

		/**
		 * @brief Allow to work out the angle who named theta
		 * @details Calculate the angle between the boat flag axe and boat axe.
		 *
		 * @param boatFlagAxe : Axe form north between the boat and the next mark.
		 * @param axeBoat : axe from north of the boat
		 *
		 * @return angle theta in degrees (-180°, 180°).
		 */
		float calculateTheta ( float boatFlagAxe, float axeBoat) const;

		/**
		 * @brief Calculate the angle between axeRef and the windAxe.
		 * @details Return a value between 0 and 360
		 * 
		 * @param axeRef Axe between the two flags
		 * @param axeWind Axe of the wind
		 * 
		 * @return Return the axe between axeRef and axeWind
		 */
		float calculateWindAxeRef(float axeRef, float axeWind) const;

		/**
		 * @brief Return all datas of the class in a vector.
		 * @details The vector return is after use to write datas in a file wich are read by an other team of project.
		 * @return A vector wich contain all the data of this class
		 */
		vector<float> getValueToEC();

		/**
		 * @brief Return all datas of the class in a map.
		 * @details The map is after use to send all datas of this class to python scripts
		 * @return A map wich contain all datas of this class
		 */
		map<string, double> getAllData() const;
    //Accesseur
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getTheta() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getAxeBoat() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getBoatFlagAxe() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getLatitude() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getLongitude() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getWindAxe() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getAxeRef () const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getBoueApLat() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getBoueApLon() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getBoueAvLat() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getBoueAvLon() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getRaw() const;
		/**
		 * @brief Basic getter
		 * @return Return the data that is write in the method's name
		 */
		float getPitch() const;


    //Modificateurs
		 /**
		  * @brief Basic setter
		  * 
		  * @param newLatitude Change the internal data
		  */
		void setLatitude (float newLatitude);
		/**
		 * @brief Basic setter
		 * 
		 * @param newLongitude Change the internal data
		 */
		void setLongitude (float newLongitude);
		/**
		 * @brief Basic setter
		 * 
		 * @param newAxeBoat Change the internal data
		 */
		void setAxeBoat (float newAxeBoat);
		/**
		 * @brief Basic setter
		 * 
		 * @param newAxeWind Change the internal data
		 */
		void setWindAxe(float newAxeWind);
		/**
		 * @brief Basic setter
		 * 
		 * @param raw Change the internal data
		 */
		void setRaw(float raw);
		/**
		 * @brief Basic setter
		 * 
		 * @param pitch Change the internal data
		 */
		void setPitch(float pitch);
		/**
		 * @brief Basic setter
		 * 
		 * @param helm Change the internal data
		 */
		void setHelm(float helm);
		/**
		 * @brief Basic setter
		 * 
		 * @param mainSail Change the internal data
		 */
		void setMainSail(float mainSail);
		/**
		 * @brief Basic setter
		 * 
		 * @param jib Change the internal data
		 */
		void setJib(float jib);
		/**
		 * @brief Basic setter
		 * 
		 * @param speed Change the internal data
		 */
		void setSpeed(float speed);

};
#endif
