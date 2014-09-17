/**
 * @file BackWindStrategyFactory.cpp
 * @author Steven GERARD
 * @date 11/03/2014
 */
#include "BackWindStrategyFactory.hpp"

BackWindStrategyFactory::BackWindStrategyFactory(): StrategyFactory()
{

}

BackWindStrategyFactory::~BackWindStrategyFactory()
{
	SailHandlerFactory::kill();
	HelmHandlerFactory::kill();
	MoveStyleFactory::kill();
	msf = nullptr;
	shf = nullptr;
	hhf = nullptr;
}

MoveStyle* BackWindStrategyFactory::makeStrategy()
{
	return msf->makeMoveStyle(BACK_WIND);
}
Handler* BackWindStrategyFactory::makeSailHandler()
{
	return shf->makeHandler(BACK_WIND);
}
Handler* BackWindStrategyFactory::makeHelmHandler()
{
	return hhf->makeHandler(BACK_WIND);
}