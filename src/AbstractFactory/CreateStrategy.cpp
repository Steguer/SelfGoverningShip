/**
 * @file CreateStrategy.cpp
 * @author Steven GERARD
 * @date 26/03/2014
 */
#include "CreateStrategy.hpp"

CreateStrategy::CreateStrategy()
{
	m_ms = nullptr;
}

CreateStrategy::~CreateStrategy()
{
	if(m_ms != nullptr)
	{
		delete m_ms;
		m_ms = nullptr;
	}
	SideWindStrategyFactory::kill();
	FrontWindStrategyFactory::kill();
	BackWindStrategyFactory::kill();
}

MoveStyle* CreateStrategy::setStrategy(WindDirection const& dir)
{
	LOG("***	We enter in the world of creation of strategy 	***");

	SideWindStrategyFactory::kill();
	FrontWindStrategyFactory::kill();
	BackWindStrategyFactory::kill();

	switch (dir)
	{
		case SIDE_WIND:
			try
			{
				m_ms = configStrategy(SideWindStrategyFactory::getInstance());
				LOG("Configuration of a Side Wind Strategy : ok in "<<m_ms);
				break;
			}
			catch(exception const& e)
			{
				LOG("EXCEPTION IN SIDE WIND CONFIGURATION: "<<e.what());
			}
		case FRONT_WIND:
			try
			{
				m_ms = configStrategy(FrontWindStrategyFactory::getInstance());
				LOG("Configuration of a Front Wind Strategy : ok");
				break;
			}
			catch(exception const& e)
			{
				LOG("EXCEPTION IN FRONT WIND CONFIGURATION: "<<e.what());
			}
		case BACK_WIND:
			try
			{
				m_ms = configStrategy(BackWindStrategyFactory::getInstance());
				LOG("Configuration of a Back Wind Strategy : ok");
				break;
			}
			catch(exception const& e)
			{
				LOG("EXCEPTION IN FRONT WIND CONFIGURATION: "<<e.what());
			}
	}
	LOG(endl<<"***	We quit the world of creation of strategy 	***");
	return m_ms;
}

MoveStyle* CreateStrategy::configStrategy(StrategyFactory* const& sf)
{
	MoveStyle* ms;

	ms = sf->makeStrategy();
	LOG("Creation of the move style : ok in "<<ms);
	ms->setSailHandler(sf->makeSailHandler());
	LOG("Creation of the sail handler : ok");
	ms->setHelmHandler(sf->makeHelmHandler());
	LOG("Creation of the helm handler : ok");

	return ms;
}