
/**
 * @file StrategyFactory.cpp
 * @author Steven GERARD
 * @date 18/03/2014
 */

 #include "StrategyFactory.hpp"

StrategyFactory::StrategyFactory()
{
	shf = SailHandlerFactory::getInstance();
	hhf = HelmHandlerFactory::getInstance();
	msf = MoveStyleFactory::getInstance();
}

StrategyFactory::~StrategyFactory()
{
	
}
