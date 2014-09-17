/**
 * @file SideWindStrategyFactory.hpp
 * @author Steven GERARD
 * @date 11/03/2014
 * 
 * @brief Contain declaration of the SideWindStrategyFactory class
 */
#ifndef SIDE_WIND_STRATEGY_FACTORY_HPP
#define SIDE_WIND_STRATEGY_FACTORY_HPP

#include "../../Singleton/Singleton.hpp"
#include "../StrategyFactory.hpp"

/**
 * @class SideWindStrategyFactory
 * @brief Manage the back wind stratefy making.
 * @details This class is a singleton to avoid the the creation of multiple factory of the same type.
 * @see  Singleton
 * @see  StrategyFactory
 */
class SideWindStrategyFactory: public Singleton<SideWindStrategyFactory>, public StrategyFactory
{
	friend class Singleton<SideWindStrategyFactory>;

	private:
		/**
		 * @brief Default Constructor.
		 */
		SideWindStrategyFactory();
		/**
		 * @brief Destructor.
		 */
		virtual ~SideWindStrategyFactory();

	public:
		/**
		 * @brief Manege the strategy making.
		 * @details Use the move style factory to create a strategy.
		 * @return Return pointer to the strategy created.
		 * @see  MoveStyleFactory
		 * @see  SideWind
		 */
		virtual MoveStyle* makeStrategy();
		/**
		 * @brief Manege the sail handler making.
		 * @details Use the sail handler factory to create a sail handler.
		 * @return Return a pointer to the sail handler created.
		 * @see  SailHandlerFactory
		 * @see  SailHandlerSideWind
		 */
		virtual Handler* makeSailHandler();
		/**
		 * @brief Manege the helm handler making.
		 * @details Use the helm handler factory to create a helm handler.
		 * @return Return a pointer to the helm handler created.
		 * @see  HelmHandlerFactory
		 * @see  HelmHandlerSideWind
		 */
		virtual Handler* makeHelmHandler();
};

#endif