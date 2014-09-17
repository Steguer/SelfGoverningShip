/**
 * @file SailHandlerSideWind.hpp
 * @author Steven GERARD
 */
#ifndef SAIL_HANDLER_SIDE_WIND_HPP
#define SAIL_HANDLER_SIDE_WIND_HPP

#include "../../Handler.hpp"
#include "../../Factory/Sail/SailHandlerFactory.hpp"

#include <iostream>
#include <map>

using namespace std;

/**
 * @class SailHandlerSideWind
 * @brief Manege the sail motors with wind wich come from back, front or side
 * 
 * @see  Handler
 */
class SailHandlerSideWind: public Handler
{
	friend class SailHandlerFactory;

	private:
		/**
		 * @brief Default constructor
		 */
		SailHandlerSideWind();
		~SailHandlerSideWind();

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