/**
 * @file Parsser.hpp
 * @author Steven GERARD
 */
#include "Parsser.hpp"

Parsser::Parsser()
{

}

Parsser::~Parsser()
{

}

Json::Value Parsser::readConfig(string const& id)
{
	Json::Value root;
	Json::Reader reader;

	//Opening of the config file.
	ifstream monFlux("../../rsc/config.json");

	if(monFlux)
	{
		bool parsingSuccessful = reader.parse(monFlux, root);
		if ( !parsingSuccessful )
		{
		    // report to the user the failure and their locations in the document.
		    std::cout  << "Failed to parse configuration "<<id<<"\n"<<endl;
		}

		// cout<<root[id].asInt()<<endl;
	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier de config en lecture." << endl;
	}

	return root[id];
}

int Parsser::readConfigInt(string const& id)
{
	return (Parsser::readConfig(id)).asInt();
}

double Parsser::readConfigDouble(string const& id)
{
	return (Parsser::readConfig(id)).asDouble();
}

string Parsser::readConfigStr(string const& id)
{
	return (Parsser::readConfig(id)).asString();
}

 bool Parsser::readConfigBool(string const& id)
{
	return (Parsser::readConfig(id)).asBool();
}
