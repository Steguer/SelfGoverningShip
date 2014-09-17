#include "PyScriptHandler.hpp"

PyScriptHandler::PyScriptHandler()
{
	m_scriptName = Parsser::readConfigStr("test");
}

PyScriptHandler::PyScriptHandler(string scriptId)
{
	m_scriptName = Parsser::readConfigStr(scriptId);
}

PyScriptHandler::~PyScriptHandler()
{

}

int PyScriptHandler::runHandler(Coordinate const& cor)
{
				std::cout<<"mkqjmdkjfmkqsjdfmkqjdf"<<std::endl;

	return PyScriptManager::usePyScript(m_scriptName, cor.getAllData());
}