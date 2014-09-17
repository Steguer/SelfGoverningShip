/**
 * @file BackWindStrategyFactory.hpp
 * @author Steven GERARD
 * @date 11/03/2014
 * 
 * @brief Contain declaration of the BackWindStrategyFactory class
 */

#ifndef BACK_WIND_STRATEGY_FACTORY_HPP
#define BACK_WIND_STRATEGY_FACTORY_HPP

#include "../../Singleton/Singleton.hpp"
#include "../StrategyFactory.hpp"

/**
 * @class BackWindStrategyFactory
 * @brief Manage the back wind strategy making.
 * @details This class is a singleton to avoid the the creation of multiple factory of the same type.
 * @see  Singleton
 * @see  StrategyFactory
 */
class BackWindStrategyFactory: public Singleton<BackWindStrategyFactory>, public StrategyFactory
{
	friend class Singleton<BackWindStrategyFactory>;

	private:
		/**
		 * @brief Default Constructor.
		 */
		BackWindStrategyFactory();
		/**
		 * @brief Destructor.
		 */
		virtual ~BackWindStrategyFactory();
	
	public:
		/**
		 * @brief Manege the strategy making.
		 * @details Use the move style factory to create a strategy.
		 * @return Return pointer to the strategy created.
		 * @see  MoveStyleFactory
		 * @see  BackWind
		 */
		virtual MoveStyle* makeStrategy();
		/**
		 * @brief Manege the sail handler making.
		 * @details Use the sail handler factory to create a sail handler.
		 * @return Return a pointer to the sail handler created.
		 * @see  SailHandlerFactory
		 * @see  SailHandlerBackWind
		 */
		virtual Handler* makeSailHandler();
		/**
		 * @brief Manege the helm handler making.
		 * @details Use the helm handler factory to create a helm handler.
		 * @return Return a pointer to the helm handler created.
		 * @see  HelmHandlerFactory
		 * @see  HelmHandlerBackWind
		 */
		virtual Handler* makeHelmHandler();
};

#endif