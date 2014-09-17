/**
 * @file Logger.h
 * @author Steven GERARD, Batiste BERTIER
 * 
 * @brief Manage the log file or log in the standard output
 */

 #ifndef LOGGER_H
 #define LOGGER_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>

 #define LOG(msg) cout<<msg<<endl;

/**
 * @class Logger
 * @brief Manege the log writing.
 */
 class Logger
 {
 public:
 	/**
 	 * @brief Default constructor
 	 */
 	Logger();
 	~Logger();

 	/**
 	 * @brief Write data in the log file
 	 * 
 	 * @param logMess Data to write
 	 */
 	static void log(std::string logMess);
 	/**
 	 * @brief Write data in a file for an other team of project
 	 * 
 	 * @param listInfo Data to write
 	 */
 	static void logEC(std::vector<float> const& listInfo);
 	/**
 	 * @brief To know if the boat sailing alone or not. Don't work 
 	 * @return true if boat is in automatic.
 	 */
 	static bool isAutomatic();
 };

 #endif