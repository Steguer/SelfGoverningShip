/**
 * @file StrategyFactory.hpp
 * @author Steven GERARD
 * @date 18/03/2014
 * 
 * @details Contain declaration of the StrategyFactory interface
 */
#ifndef STRATEGY_FACTORY_HPP
#define STRATEGY_FACTORY_HPP

#include "../MoveStyle/Factory/MoveStyleFactory.hpp"
#include "../Handler/Factory/Helm/HelmHandlerFactory.hpp"
#include "../Handler/Factory/Sail/SailHandlerFactory.hpp"

/**
 * @class StrategyFactory
 * @brief Interface for the strategy factory.
 * @see  BackWindStrategyFactory
 * @see  FrontWindStrategyFactory
 * @see  SideWindStrategyFactory
 */
class StrategyFactory
{
	protected:
		/**
		 * @brief Contain an object of sail handler factory. It is use to create the sail handlers.
		 * @see  SailHandlerFactory
		 */
		SailHandlerFactory *shf;
		/**
		 * @brief Contain an object of helm handler factory. It is use to create the helm handlers.
		 * @see  HelmHandlerFactory
		 */
		HelmHandlerFactory *hhf;
		/**
		 * @brief Contain an object of move style factory. It is use to create the move style.
		 * @see  MoveStyleFactory
		 */
		MoveStyleFactory *msf;

	public:
		/**
		 * @brief Default Constructor
		 * @details Create the instance of the each factories.
		 */
		StrategyFactory();
		/**
		 * @brief Destructor
		 */
		virtual ~StrategyFactory()=0;
		/**
		 * @brief Manege the strategy making.
		 * @see  BackWindStrategyFactory
		 * @see  FrontWindStrategyFactory
		 * @see  SideWindStrategyFactory
		 */
		virtual MoveStyle* makeStrategy()=0;
		/**
		 * @brief Manege the sail handler making.
		 * @see  BackWindStrategyFactory
		 * @see  FrontWindStrategyFactory
		 * @see  SideWindStrategyFactory
		 */
		virtual Handler* makeSailHandler()=0;
		/**
		 * @brief Manege the helm handler making.
		 * @see  BackWindStrategyFactory
		 * @see  FrontWindStrategyFactory
		 * @see  SideWindStrategyFactory
		 */
		virtual Handler* makeHelmHandler()=0;
};

#endif