/**
 * @file PyScriptHandler.hpp
 * @author Steven GERARD
 * @date 01/05/2014
 */
#ifndef PY_SCRIPT_HANDLER_HPP
#define PY_SCRIPT_HANDLER_HPP

#include "../Handler.hpp"
#include "../../Tools/Parsser.hpp"
#include "../../PyScriptManager/PyScriptManager.hpp"

using namespace std;

/**
 * @class PyScriptHandler
 * @brief It's an handler wich use a python script to calculate the helm or sail's motors command.
 * 
 * @see  PyScriptManager
 * @see  Handler
 */
class PyScriptHandler: public Handler
{
public:
	/**
	 * @brief Default constructor
	 */
	PyScriptHandler();
	/**
	 * @brief Cretate an handler with a specific script
	 * 
	 * @param scriptId The name of the script to use
	 */
	PyScriptHandler(string scriptId);
	~PyScriptHandler();

	string m_scriptName;

public:
	/**
	 * @brief Launch the handler
	 * 
	 * @param cor Lots of useful stuff
	 * @return Return the command for the motors
	 * 
	 * @see  Coordinate
	 */
	virtual int runHandler(Coordinate const& cor);
	
};

#endif