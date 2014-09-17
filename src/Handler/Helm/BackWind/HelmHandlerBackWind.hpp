/**
 * @file HelmHandlerBackWind.hpp
 * @author Steven GERARD
 */
#ifndef HELM_HANDLER_BACK_WIND_HPP
#define HELM_HANDLER_BACK_WIND_HPP

#include "../HelmHandler.hpp"
#include "../../Factory/Helm/HelmHandlerFactory.hpp"

/**
 * @deprecated Now we use HelmHandlerBackFrontWind which group Front and Back wind.
 * @class HelmHandlerBackWind
 * @brief Calculate the helm command
 */
class HelmHandlerBackWind: public HelmHandler
{
	friend class HelmHandlerFactory;

	private:
		HelmHandlerBackWind();
		~HelmHandlerBackWind();
	
	public:
		/**
		 * @brief Lauch the handler
		 * 
		 * @param cor Lot of useful stuff
		 * @return The command send to the motors.
		 * 
		 * @see  Coordinate
		 */
		virtual int runHandler(Coordinate const& cor);
};

#endif