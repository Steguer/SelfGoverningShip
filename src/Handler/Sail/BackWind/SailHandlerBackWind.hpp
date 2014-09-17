/**
 * @file SailHandlerBackWind.hpp
 * @author Steven GERARD
 */
#ifndef SAIL_HANDLER_BACK_WIND_HPP
#define SAIL_HANDLER_BACK_WIND_HPP

#include "../../Handler.hpp"
#include "../../Factory/Sail/SailHandlerFactory.hpp"
#include "../../../Tools/Coordinate.hpp"

using namespace std;

/**
 * @class SailHandlerBackWind
 * @brief Manege the sail motors with wind wich come from back
 * 
 * @see  Handler
 * @deprecated Now we use only the SideWindSailHandler for all the strategies.
 */
class SailHandlerBackWind: public Handler
{
	friend class SailHandlerFactory;

	private:
		/**
		 * @brief Default constructor
		 */
		SailHandlerBackWind();
		~SailHandlerBackWind();

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