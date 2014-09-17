#ifndef HELM_HANDLER_SIDE_WIND_HPP
#define HELM_HANDLER_SIDE_WIND_HPP

#include "../HelmHandler.hpp"
#include "../../Factory/Helm/HelmHandlerFactory.hpp"

typedef enum
{
	FIRST, SECOND, THIRD, FOURTH
}PhaseEnum;

/**
 * @class HelmHandlerSideWind
 * @brief Manege the helm handler for a side wind
 */
class HelmHandlerSideWind: public HelmHandler
{
	friend class HelmHandlerFactory;

	private:
		/**
		 * @brief Default constructor.
		 * @details Is private because we use the Singleton pattern.
		 * @see  Singleton
		 */
		HelmHandlerSideWind();
		~HelmHandlerSideWind();

		/**
		 * @brief Startting point latitude
		 */
		float m_boueAvLat;
		/**
		 * @brief Starting point longitude
		 */
		float m_boueAvLon;
		/**
		 * @brief Arrival point latitude
		 */
		float m_boueApLat;
		/**
		 * @brief Arrival point longitude
		 */
		float m_boueApLon;
		/**
		 * @brief In wich part of flag by pass the boat has arrived
		 */
		PhaseEnum m_phase;
	
	public:
		/**
		 * @brief Launch the handler
		 * 		  
		 * @param cor Data of the system
		 * @return Value for actuator
		 */
		virtual int runHandler(Coordinate const& cor);
		/**
		 * @brief Lauch the strategy which do the boat go and back.
		 * 
		 * @param cor Lot of useful stuff
		 * @return The command for the helm motor
		 * 
		 * @see  Coordinate
		 */
		int runHandlerComeBack(Coordinate const& cor);
		/**
		 * @brief Subtraction of the angles a and b.
		 * 
		 * @param a First angles
		 * @param b Second angle.
		 * 
		 * @return A value from  to 360. 
		 */
		float subAngle(float a, float b);
};

#endif