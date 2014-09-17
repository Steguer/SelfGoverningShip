/**
 * @file SailHandlerFrontWind.hpp
 * @author Steven GERARD
 */
#ifndef SAIL_HANDLER_FRONT_WIND_HPP
#define SAIL_HANDLER_FRONT_WIND_HPP

#include "../../Handler.hpp"
#include "../../Factory/Sail/SailHandlerFactory.hpp"

using namespace std;

/**
 * @class SailHandlerFrontWind
 * @brief Manege the sail motors with wind wich come from front
 * 
 * @see  Handler
 * @deprecated Now we use only the SideWindSailHandler for all the strategies.
 */
class SailHandlerFrontWind: public Handler
{
	friend class SailHandlerFactory;

	private:
		/**
		 * @brief Default constructor
		 */
		SailHandlerFrontWind();
		~SailHandlerFrontWind();

		/**
		 * @brief Contain the setting to use in accordance with the wind.
		 */
		map<int, int> m_windMap;

	public:
	/**
	 * @brief Lauch the handler
	 * 
	 * @param cor Lot of useful stuff
	 * @return Return the command for the sail motor
	 * 
	 * @see  Coordinate
	 */
	virtual int runHandler(Coordinate const& cor);	
};

#endif