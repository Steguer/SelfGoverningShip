/**
 * @file SailHandlerFactory.cpp
 * @author Steven GERARD
 * @date 20/04/2014
 */
#include "SailHandlerFactory.hpp"

Handler* SailHandlerFactory::m_sailHandler = nullptr; 

SailHandlerFactory::SailHandlerFactory()
{
}

SailHandlerFactory::~SailHandlerFactory()
{
	if(m_sailHandler != nullptr)
	{
		delete m_sailHandler;
		m_sailHandler = nullptr;
	}
}

Handler* SailHandlerFactory::makeHandler(WindDirection type)
{
	if(m_sailHandler != nullptr)
	{			
		throw runtime_error("A SAIL HANDLER ALREADY EXIST !");
	}

	switch (type)
	{
		case SIDE_WIND:
			if (Parsser::readConfigBool("EnableSailHandlerSideWindPyScript"))
			{
				m_sailHandler = new SAIL_HANDLER_SIDE_WIND_PY_SCRIPT;

			}
			else
			{
				m_sailHandler = new SAIL_HANDLER_SIDE_WIND;
			}
			break;
		case BACK_WIND:
			if(Parsser::readConfigBool("EnableSailHandlerBackWindPyScript"))
			{
				m_sailHandler = new SAIL_HANDLER_BACK_WIND_PY_SCRIPT;
			}
			else
			{
				m_sailHandler = new SAIL_HANDLER_SIDE_WIND;
			}				break;
		case FRONT_WIND:
			if(Parsser::readConfigBool("EnableSailHandlerFrontWindPyScript"))
			{
				m_sailHandler = new SAIL_HANDLER_FRONT_WIND_PY_SCRIPT;
			}
			else
			{
				m_sailHandler = new SAIL_HANDLER_SIDE_WIND;
			}
			break;
	}

	return m_sailHandler;
}

void SailHandlerFactory::deleteHandler(Handler* h)
{
	if(m_sailHandler == h)
	{
		delete h;
		m_sailHandler = nullptr;
	}

	else
	{
		throw runtime_error("DELETE HANDLER ERROR !");
	}
}
	