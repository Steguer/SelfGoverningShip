/**
 * @file FrontWindStrategyFactory.cpp
 * @author Steven GERARD
 * @date 11/03/2014
 */
#include "FrontWindStrategyFactory.hpp"

FrontWindStrategyFactory::FrontWindStrategyFactory(): StrategyFactory()
{
}

FrontWindStrategyFactory::~FrontWindStrategyFactory()
{
	SailHandlerFactory::kill();
	HelmHandlerFactory::kill();
	MoveStyleFactory::kill();
	msf = nullptr;
	shf = nullptr;
	hhf = nullptr;
}

MoveStyle* FrontWindStrategyFactory::makeStrategy()
{
	return msf->makeMoveStyle(FRONT_WIND);
}
Handler* FrontWindStrategyFactory::makeSailHandler()
{
	return shf->makeHandler(FRONT_WIND);
}
Handler* FrontWindStrategyFactory::makeHelmHandler()
{
	return hhf->makeHandler(FRONT_WIND);
}