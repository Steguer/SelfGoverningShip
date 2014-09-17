/**
 * @file CreateStrategy.hpp
 * @author Steven GERARD
 * @date 26/03/2014
 * 
 * @brief Contain the top of the strategy creation process.
 */

#ifndef CREATE_STRATEGY_HPP
#define CREATE_STRATEGY_HPP


#include "../Tools/Data.hpp"
#include "SideWind/SideWindStrategyFactory.hpp"
#include "FrontWind/FrontWindStrategyFactory.hpp"
#include "BackWind/BackWindStrategyFactory.hpp"
#include "../Tools/Logger.hpp"

using namespace std;

/**
 * @class CreateStrategy
 * @brief Manege the using of the abstract factory which create the strategy.
 * @details Contain two method. The first setStragy allow to chose the good factory to use for create the
 * 			configure strategy. The second is use to configure the strategy with the factory which was chose before.
 * @see  SideWindStrategyFactory
 * @see  FrontWindStrategyFactory
 * @see  BackWindStrategyFactory
 */
class CreateStrategy
{
	private:
		/**
		 * @brief It's use in internal working like temprory variable.
		 */
		MoveStyle *m_ms;

	public:
		/**
		 * @brief Default constructor
		 * @details Set m_ms to nullptr
		 */
		CreateStrategy();
		/**
		 * @brief Destructor
		 * @details Delete m_ms and all the factory which are use to create the strategy
		 */
		~CreateStrategy();

		/**
		 * @brief Select the good factory to use and sent it to configStrategy
		 * @param dir The choose made by the user
		 * @return A configure object strategy
		 */
		MoveStyle* setStrategy(WindDirection const& dir);
		/**
		 * @brief Configure the moveStyle object with the factory in parameter.
		 * @details Create the strategy next the sail handler and the helm handler.
		 * 
		 * @param sf Factory use to create the moveStyle object
		 * @return A configure strategy object.
		 */
		MoveStyle* configStrategy(StrategyFactory* const& sf);
};

#endif