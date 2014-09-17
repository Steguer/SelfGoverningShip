/**
 * @file HelmHandlerFactory.cpp
 * @author Steven GERARD
 * @date 20/04/2014
 */
#include "HelmHandlerFactory.hpp"

Handler* HelmHandlerFactory::m_helmHandler = nullptr;

HelmHandlerFactory::HelmHandlerFactory()
{
	m_helmHandler = nullptr;
}

HelmHandlerFactory::~HelmHandlerFactory()
{
	if(m_helmHandler != nullptr)
	{
		delete m_helmHandler;
		m_helmHandler = nullptr;
	}
}

Handler* HelmHandlerFactory::makeHandler(WindDirection type)
{
	cout<<"*** We enter in the Helm handler factory  ***"<<endl;
	if(m_helmHandler != nullptr)
	{
		cout<<"An handler already exist"<<endl;
		delete m_helmHandler;
		m_helmHandler = nullptr;
	}

	switch (type)
	{
		case SIDE_WIND:
			if(Parsser::readConfigBool("EnableHelmHandlerSideWindPyScript"))
			{
				m_helmHandler = new HELM_HANDLER_SIDE_WIND_PY_SCRIPT;
			}
			else
			{
				m_helmHandler = new HELM_HANDLER_SIDE_WIND;
				cout<<"Creation of an helm handler for side wind in adress: "<<m_helmHandler<<endl;
			}
			break;
		case BACK_WIND:
			if(Parsser::readConfigBool("EnableHelmHandlerBackWindPyScript"))
			{
				m_helmHandler = new HELM_HANDLER_BACK_WIND_PY_SCRIPT;
			}
			else
			{
				m_helmHandler = new HELM_HANDLER_BACK_WIND;
				cout<<"Creation of an helm handler for back wind in adress: "<<m_helmHandler<<endl;				
			}
			break;
		case FRONT_WIND:
			if(Parsser::readConfigBool("EnableHelmHandlerFrontWindPyScript"))
			{
				m_helmHandler = new HELM_HANDLER_FRONT_WIND_PY_SCRIPT;
			}
			else
			{
				m_helmHandler = new HELM_HANDLER_FRONT_WIND;
				cout<<"Creation of an helm handler for front wind in adress: "<<m_helmHandler<<endl;
			}
			break;
		default:
			m_helmHandler = nullptr;
			break;
	}

	cout<<"*** We quit the Helm handler factory  ***"<<endl;
	return m_helmHandler;
}

void HelmHandlerFactory::deleteHandler(Handler* h)
{
	if(m_helmHandler == h)
	{
		delete h;
		m_helmHandler = nullptr;
	}

	else
	{
		throw runtime_error("DELETE HANDLER ERROR !");
	}
}