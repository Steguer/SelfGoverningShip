/**
 * @file FrontWindStrategyFactory.hpp
 * @author Steven GERARD
 * @date 11/03/2014
 * 
 * @brief Contain declaration of the FrontWindStrategyFactory class
 */
#ifndef FRONT_WIND_STRATEGY_FACTORY_HPP
#define FRONT_WIND_STRATEGY_FACTORY_HPP

#include "../../Singleton/Singleton.hpp"
#include "../StrategyFactory.hpp"

/**
 * @class FrontWindStrategyFactory
 * @brief Manage the back wind stratefy making.
 * @details This class is a singleton to avoid the the creation of multiple factory of the same type.
 * @see  Singleton
 * @see  StrategyFactory
 */
class FrontWindStrategyFactory: public Singleton<FrontWindStrategyFactory>, public StrategyFactory
{
	friend class Singleton<FrontWindStrategyFactory>;

	private:
		/**
		 * @brief Default Constructor.
		 */
		FrontWindStrategyFactory();
		/**
		 * @brief Destructor.
		 */
		virtual ~FrontWindStrategyFactory();
	
	public:
		/**
		 * @brief Manege the strategy making.
		 * @details Use the move style factory to create a strategy.
		 * @return Return pointer to the strategy created.
		 * @see  MoveStyleFactory
		 * @see  FrontWind
		 */
		virtual MoveStyle* makeStrategy();
		/**
		 * @brief Manege the sail handler making.
		 * @details Use the sail handler factory to create a sail handler.
		 * @return Return a pointer to the sail handler created.
		 * @see  SailHandlerFactory
		 * @see  SailHandlerFrontWind
		 */
		virtual Handler* makeSailHandler();
		/**
		 * @brief Manege the helm handler making.
		 * @details Use the helm handler factory to create a helm handler.
		 * @return Return a pointer to the helm handler created.
		 * @see  HelmHandlerFactory
		 * @see  HelmHandlerFrontWind
		 */
		virtual Handler* makeHelmHandler();
};

#endif