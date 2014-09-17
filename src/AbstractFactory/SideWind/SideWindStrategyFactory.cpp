/**
 * @file SideWindStrategyFactory.cpp
 * @author Steven GERARD
 * @date 11/03/2014
 */
#include "SideWindStrategyFactory.hpp"

SideWindStrategyFactory::SideWindStrategyFactory(): StrategyFactory()
{

}
SideWindStrategyFactory::~SideWindStrategyFactory()
{
	SailHandlerFactory::kill();
	HelmHandlerFactory::kill();
	MoveStyleFactory::kill();
	msf = nullptr;
	shf = nullptr;
	hhf = nullptr;
}

MoveStyle* SideWindStrategyFactory::makeStrategy()
{
	return msf->makeMoveStyle(SIDE_WIND);
}
Handler* SideWindStrategyFactory::makeSailHandler()
{
	return shf->makeHandler(SIDE_WIND);
}
Handler* SideWindStrategyFactory::makeHelmHandler()
{
	return hhf->makeHandler(SIDE_WIND);
}