#ifndef SAIL_HANDLER_FACTORY_HPP
#define SAIL_HANDLER_FACTORY_HPP

#include "../HandlerFactory.hpp"
#include "../../Handler.hpp"
#include "../../Sail/SideWind/SailHandlerSideWind.hpp"
#include "../../Sail/FrontWind/SailHandlerFrontWind.hpp"
#include "../../Sail/BackWind/SailHandlerBackWind.hpp"
#include "../../../Singleton/Singleton.hpp"
#include "../HandlerName.hpp"
#include "../../../Tools/Parsser.hpp"
#include "../../PyScriptHandler/PyScriptHandler.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @class SailHandlerFactory
 * @brief Manege the sail handler making
 *
 * @see  HandlerFactory
 * @see  Singleton
 * @see  SailHandlerSideWind
 * @see  SailHandlerBackWind
 * @see  SailHandlerFrontWind 
 */
class SailHandlerFactory: public HandlerFactory, public Singleton<SailHandlerFactory>
{
	friend class Singleton<SailHandlerFactory>;

	public:
		/**
		 * @brief Make the sail handler
		 * 
		 * @param type Type of handler
		 * @return Return the new handler
		 */
		virtual Handler *makeHandler(WindDirection type);

		virtual void deleteHandler(Handler* h);
	
	private:
		/**
		 * @brief It's use in internal working like temprory variable.
		 */
		static Handler *m_sailHandler;
		/**
		 * @brief Default constructor
		 */
		SailHandlerFactory();
		~SailHandlerFactory();
};

#endif