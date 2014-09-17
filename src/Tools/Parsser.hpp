/**
 * @file Parsser.hpp
 * @author Steven GERARD
 */
#ifndef PARSSER_H
#define PARSSER_H

#include <iostream>
#include <string>
#include <json/json.h>
#include <fstream>

using namespace std;

/**
 * @class Parsser
 * @brief Manege the reading of the json config file
 */
class Parsser
{
public:
	/**
	 * @brief Default constructor
	 */
	Parsser();
	~Parsser();

	/**
	 * @brief Reade the json file
	 * 
	 * @param id Id of the data to read in the json file
	 * @return Return the data read in Json::Valon
	 */
	static Json::Value readConfig(string const& id);
	
	/**
	 * @brief Reade the json file
	 * @details Call the readConfig method and convert Json::Value in int
	 * 
	 * @param id Id of the data to read in the json file
	 * @return Return the data read in int
	 */
	static int readConfigInt(string const& id);

	/**
	 * @brief Reade the json file
	 * @details Call the readConfig method and convert Json::Value in double
	 * 
	 * @param id Id of the data to read in the json file
	 * @return Return the data read in double
	 */
	static double readConfigDouble(string const& id);

	/**
	 * @brief Reade the json file
	 * @details Call the readConfig method and convert Json::Value in string
	 * 
	 * @param id Id of the data to read in the json file
	 * @return Return the data read in string
	 */
	static string readConfigStr(string const& id);

	/**
	 * @brief Reade the json file
	 * @details Call the readConfig method and convert Json::Value in bool
	 * 
	 * @param id Id of the data to read in the json file
	 * @return Return the data read in bool
	 */
	static bool readConfigBool(string const& id);
};

#endif