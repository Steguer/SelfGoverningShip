/**
 * @file HelmHandlerFactory.hpp
 * @author Steven GERARD
 * @date 20/04/2014
 */
#ifndef HELM_HANDLER_FACTORY_HPP
#define HELM_HANDLER_FACTORY_HPP

#include "../../Handler.hpp"
#include "../HandlerFactory.hpp"
#include "../../Helm/SideWind/HelmHandlerSideWind.hpp"
#include "../../Helm/FrontWind/HelmHandlerFrontWind.hpp"
#include "../../Helm/BackWind/HelmHandlerBackWind.hpp"
#include "../../../Singleton/Singleton.hpp"
#include "../../Helm/BackFrontWind/HelmHandlerBackFrontWind.hpp"
#include "../HandlerName.hpp"
#include "../../../Tools/Parsser.hpp"
#include "../../PyScriptHandler/PyScriptHandler.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

/**
 * @class HelmHandlerFactory
 * @brief Factory for the helm handler
 * 
 * @see HandlerFactory
 * @see Singleton
 */
class HelmHandlerFactory: public HandlerFactory, public Singleton<HelmHandlerFactory>
{
	friend class Singleton<HelmHandlerFactory>;

	public:
		/**
		 * @brief Method to make the handler
		 * 
		 * @param type Type of handler to make
		 * @return A new handler
		 */
		virtual Handler *makeHandler(WindDirection type);
		/**
		 * @brief Delete an handler
		 * 
		 * @param h Handler to delete
		 */
		virtual void deleteHandler(Handler* h);


	private:
		/**
		 * @brief Default constructor
		 */
		HelmHandlerFactory();
		~HelmHandlerFactory();
		
		/**
		 * @brief It's use in internal working like temprory variable.
		 */
		static Handler *m_helmHandler;
	
};

#endif