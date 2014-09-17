/**
 * @file PyScriptManager.hpp
 * @author Steven GERARD
 * @date 02/05/2014
 * 
 * @brief Contain PyScriptManager declaration of the PyScriptManager class
 */

#ifndef SCRIPT_MANAGER_HPP
#define SCRIPT_MANAGER_HPP

#include <map>
#include <Python.h>
#include "../Tools/Parsser.hpp"

using namespace std;

/**
 * @class PyScriptManager
 * @brief Create an interface to use some python scripts.
 */
class PyScriptManager
{
private:
	/**
	 * @brief Contain the path to the script directory
	 */
	static string m_scriptPath;
public:
	/**
	 * @brief Default Constructor of the class.
	 * @details Set the scipt path to ../../rsc by default.
	 */
	PyScriptManager();
	/**
	 * @brief Set the param value as script path.
	 * 
	 * @param scriptPath New value of script path.
	 */
	PyScriptManager(string const& scriptPath);
	/**
	 * @brief Destructor of the class
	 */
	~PyScriptManager();
	/**
	 * @brief Allow the utilization of external python script.
	 * 
	 * @param scriptName Name of the script that you want use
	 * @param data data pass to the script
	 * 
	 * @return the result of the script
	 */
	static double usePyScript(string const& scriptName, map<string, double> const& data);

	/**
	 * @brief Return the value of the python script path.
	 */
	string getScriptPath();
	/**
	 * @brief Change the value of the python script path.
	 * 
	 * @param scriptPath New value to the python script path.
	 */
	void setScriptPath(string const& scriptPath);
};

#endif