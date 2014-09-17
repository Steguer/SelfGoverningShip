/**
 * @file Logger.h
 * @author Steven GERARD, Batiste BERTIER
 * 
 * @brief Manage the log file or log in the standard output
 */
#include "Logger.hpp"

Logger::Logger()
{

}

Logger::~Logger()
{

}

void Logger::log(std::string logMess)
{
	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	std::ofstream out("log", std::ofstream::app);

		// out<<logMess<<std::endl;

	if(isAutomatic())
	{
		out<<logMess<<std::endl;
	}
	else
	{
		std::cout<<"j'écris pas"<<std::endl;
	}
}

bool Logger::isAutomatic()
{
	FILE* file;
    int value=0;
    char buffer[3] = "in";

    file = fopen("/sys/class/gpio/export","w");
    fprintf(file,"%d",2);
    fflush(file);
    fclose(file);

    file = fopen("/sys/class/gpio/gpio2/direction","w");
    fprintf(file,"%s", buffer);
    fflush(file);
    fclose(file);

    file = fopen("/sys/class/gpio/gpio2/value","r+");
    fscanf(file,"%d", &value);
    fflush(file);
    fclose(file);

    return true;
}

void Logger::logEC(std::vector<float> const& listInfo)
{
	std::ofstream out("/home/ubuntu/communication/bateau2.txt");

	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	std::string str = "";
	str += std::to_string(timeinfo->tm_hour);
	str += " ";
	str += std::to_string(timeinfo->tm_min);
	str += " ";
	str += std::to_string(timeinfo->tm_sec);
	for(auto it : listInfo)
	{
		str += " ";
		str += std::to_string(it);
	}

	out << str;
}