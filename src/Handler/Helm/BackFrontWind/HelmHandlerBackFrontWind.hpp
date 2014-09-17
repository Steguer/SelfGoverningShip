/**
 * @file HelmHandlerBackFrontWind.hpp
 * @author  Steven GERARD, Boris JEUDY
 *
 * @brief Contain the declaration of the helm handler to front wind class.
 */

#ifndef HELM_HANDLER_FRONT_BACK_WIND_HPP
#define HELM_HANDLER_FRONT_BACK_WIND_HPP

#include "../HelmHandler.hpp"
#include "../../Factory/Helm/HelmHandlerFactory.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include "../../../Tools/Coordinate.hpp"
#include "../../../Tools/Parsser.hpp"

#define valMax 5
#define valMin -5
#define ROTATION 50

/**
 * @class HelmHandlerBackFrontWind
 * @brief The goal of this class is to manege the behavior of the helm to a wind which arrive from the front of the boat.
 * @see  Handler
 * @see  FrontWind
 * @see  HelmHandlerFactory
 */
class HelmHandlerBackFrontWind: public HelmHandler
{
	//It's to allow the factory to access of the constructor and destructor.
	friend class HelmHandlerFactory;

	private:
		/**
		 * @brief Angle use when the boat have to turn
		 */
		float m_rotation;

		/**
		 * @brief Default constructor of the class
		 * @details [long description]
		 */
		HelmHandlerBackFrontWind();
		HelmHandlerBackFrontWind(WindDirection wind);
		/**
		 * @brief Destructor of the class
		 * @details [long description]
		 */
		~HelmHandlerBackFrontWind();

		/**
		 * @brief Calculate the new axe that the boat have to follow and return the new angle for the helm.
		 * @details Add a rotation to the wind axe.
		 *
		 * @param rotation Value of rotation for the axe
		 * @return New value of helm.
		 */
		int calculateNewHelm(Coordinate const& cor, int const& rotation);

		/**
		 * @brief calculate the angle between axe ref and boatflag axe.
		 * @details Work out the angle between axe ref and boatflag axe. Angle use to know when the boat need to change his direction.
		 *
		 * @param boatFlagAxe : Axe form north between the boat and the next mark. Angle in degrees (0°, 360°)
		 * @param AxeRef : Axe from north between the last and the next mark.Angle in degrees (0°, 360°)
		 *)
		 * @return angle alpha in degrees (-180°, 180°)
		 */
        float calculateAlpha (float const& boatFlagAxe, float const& AxeRef);

        /**
        * @brief Work out the distance between the next mark and the boat
        * @details Calculate the way between the boat and the next mark
        *
        * @param boueApLat next mark latitude value letting to calculate the distance between the boat and the next mark.
		* @param boueApLon next mark longitude value letting to calculate the distance between the boat and the next mark.
		* @param boatLat boat latitude value letting to calculate the distance between the boat and the next mark.
        * @param boatLon boat longitude value letting to calculate the distance between the boat and the next mark.
        *
        * @return distanceBoatMark in meter (m)
        */
        float distanceBoatMark (float const& boueApLat, float const& boueApLon, float const& boatLat, float const& boatLon);

        /**
		 * @brief calculate the angle between axe ref and boatAxe.
		 * @details Work out the angle between axe ref and boatAxe. Angle use to know where the the boat is going
		 *
		 * @param axeBoat : axe from north of the boat. Angle in degrees (0°, 360°)
		 * @param AxeRef : Axe from north between the last and the next mark. Angle in degrees (0°, 360°)
		 *
		 * @return angle beta in degrees (-180°, 180°).
		 */
        float calculatebeta (float const& AxeRef, float const& boatAxe);

        /**
		 * @brief Know which edge steer the boat.
		 * @details Fonction uses to know the edge where the boat is steering
		 *
		 * @param beta : the angle between axe ref and boatAxe in degrees (-180°,180°).
		 *
		 * @return Value of the corridor's edge.
		 */
        int corridorValue (float const& beta);



        /**
        * @brief Work out to know if the boat is in the corridor.
        * @details Calculate the distance between the axe ref and the boat to know if the boat is always inside the corridor.
        *
        * @param Alpha : the angle between axe ref and boatflag axe in degrees (-180°, 180°).
        * @param distanceBoatMark : the distance between the next mark and the boat in meter (m)
        * @param edgevalue : Value of the corridor's edge.
        *
        * @return true if the boat is outside the corridor else false
        */
        bool corridor (float const& alpha, float const& distanceBoatMark, int const& edgevalue);

	public:
		/**
		 * @brief Lauch the calculates of helm angle.
		 * @details Manage the calculation of the helm angle
		 *
		 * @param cor Contain all the useful informations about the boat
		 * @return The new angle for the helm.
		 */
		virtual int runHandler(Coordinate const& cor);

};

#endif
