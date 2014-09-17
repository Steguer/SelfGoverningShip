/**
 * @file SideWind.h
 * @author Steven GERARD
 * @version 1.0
 * @date 05/12/2013
 * 
 * @brief It is juste the main to do the tests
 */	

#include <iostream>
#include <string>
#include <cmath>
#include "Tools/Parsser.hpp"
#include "Modele/Modele.hpp"
#include "Actuators/Actionneur.hpp"
#include "Captors/Gps/Gps.hpp"
#include "PyScriptManager/PyScriptManager.hpp"
#include "Handler/PyScriptHandler/PyScriptHandler.hpp"
#include "Captors/Central/Central.hpp"
#include "Captors/Vane/Vane.hpp"

using namespace std;

int main(int argc, char** argv)
{
	Modele *mod = new Modele();
	Actionneur *act = new Actionneur();
	Gps *gps = new Gps();
	Central *central = new Central();
	Vane *vane = new Vane();
	WindDirection wind;
	WindDirection newWind; //just use for tests

	gps->addObserver(mod);
	central->initCentral();
	central->addObserver(mod);
	mod->addObserver(act);
	vane->addObserver(mod);
	wind = SIDE_WIND;
	mod->setStrategy(wind);

	vane->getMeanData();

	while(1)
	{
		gps->readData();
		central->notifyData();
		mod->run();
	}

	//It's useless I now
	delete mod;
	delete act;
	delete gps;
	delete central;
	delete vane;
	
	return 0;
}