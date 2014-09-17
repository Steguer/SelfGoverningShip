/**
 * @file Modele.hpp
 * @author Steven GERARD
 * @date 10/02/2014
 */
 
#include "Modele.hpp"

Modele::Modele()
{
	m_createStrat = new CreateStrategy();
	m_ms = nullptr;
	// cor.setWindAxe(Parsser::readConfigInt("WindAxe"));
	// cor.setWindAxe();
	m_wind = NOTHING;
	m_newWind = NOTHING;
}

Modele::Modele(WindDirection const& dir) : Modele()
{
	m_ms = m_createStrat->setStrategy(dir);
}

Modele::~Modele()
{

}

void Modele::setStrategy(WindDirection const& dir)
{
	m_ms = m_createStrat->setStrategy(dir);
}

int Modele::sailMotor(Coordinate & cor)
{
	Logger::log("\n***Cmd sail motors***");
	int res = m_ms->sailMotor(cor);
	std::string sRes("Value of sail motor ");
	cor.setMainSail(res);
	cor.setJib(res);
	Logger::log(sRes += std::to_string(res));
	Logger::log("***End cmd sail motors***\n");

	return res;
}

int Modele::helmMotor(Coordinate &  cor)
{
	Logger::log("\n***Cmd helm motor***");
	int res = m_ms->helmMotor(cor);
	cor.setHelm(res);
	std::string sRes("Value of helm motor ");
	Logger::log(sRes += std::to_string(res));
	Logger::log("***Cmd helm motor***\n");

	return res;
}

void Modele::run()
{
	cout<<"Run modele !"<<endl;

	m_newWind = choseWind();

	if (m_newWind != m_wind)
	{
		switch(m_newWind)
		{
			case SIDE_WIND:
				setStrategy(SIDE_WIND);
				Logger::log("\n***Change wind for Side Wind***\n");
				break;
			case BACK_WIND:
				setStrategy(BACK_WIND);
				Logger::log("\n***Change wind for Back Wind***\n");
				break;
			case FRONT_WIND:
				setStrategy(FRONT_WIND);
				Logger::log("\n***Change wind for Front Wind***\n");
				break;
		}
		m_wind = m_newWind;
	}

	// if(cor.getPitch() > Parsser::readConfigInt("PitchLimit") || cor.getPitch() < -Parsser::readConfigInt("PitchLimit"))
	// {
	// 	Logger::log("\n***/!\\Danger with raw/!\\***");
	// 	notifyMot(90, 125);
	// 	std::string str = "value notify to motor : sail 90, helm 125";
	// 	cout<<"I sleep"<<endl;
	// 	sleep(5);
	// 	Logger::log(str);
	// 	Logger::log("\n***/!\\End danger with raw/!\\***\n");
	// }
	// else
	// {
		notifyMot(this->sailMotor(cor), this->helmMotor(cor));
	// }

	Logger::logEC(cor.getValueToEC());
}

void Modele::goBack()
{

}

void Modele::update(DataPack cmd)
{
	switch(cmd.id)
	{
		case GPS_ID:
		{
			Logger::log("\n***Cmd gsp receive***");
			cor.setLatitude(cmd.data[0]);
			cor.setLongitude(cmd.data[1]);
			std::string str = "Value of gps lat ";
			str += to_string(cmd.data[0]);
			Logger::log(str);
			str = "Value of gps lon ";
			str += to_string(cmd.data[1]);
			Logger::log(str);
			Logger::log("***End gps reception***\n");
			break;
		}
		case COMPAS_ID:
		{
			Logger::log("\n***Cmd compas received***");
			cor.setAxeBoat(cmd.data[0]);
			std::string str = "Value of compas ";
			str += to_string(cmd.data[0]);
			Logger::log(str);
			Logger::log("***End cmd compas received***\n");
			cout<<"Value of compas "<<cmd.data[0]<<endl;
			break;
		}
		case RAW_ID:
		{
			Logger::log("\n***Cmd raw received***");
			cor.setRaw(cmd.data[0]);
			std::string str = "Value of raw ";
			str += to_string(cmd.data[0]);
			Logger::log(str);
			Logger::log("***End cmd raw received***\n");
			break;
		}
		case PITCH_ID:
		{
			cout<<"we are int pitch id"<<endl;
			Logger::log("\n***Cmd pitch received***");
			cor.setPitch(cmd.data[0]);
			std::string str = "Value of pitch ";
			str += to_string(cmd.data[0]);
			Logger::log(str);
			Logger::log("***End cmd pitch received***\n");
			break;
		}
		case SPEED_ID:
		{
			Logger::log("\n***Cmd speed received***");
			cor.setSpeed(cmd.data[0]);
			std::string str = "Value of speed ";
			str += to_string(cmd.data[0]);
			Logger::log(str);
			Logger::log("***End cmd speed received***\n");
			break;
		}

		case VANE_ID:
		{
			Logger::log("\n***Cmd vane received***");
			// cor.setWindAxe(cmd.data[0]);
			cor.setWindAxe(Parsser::readConfigInt("WindAxe"));
			std::string str = "Value of vane ";
			str += to_string(cmd.data[0]);
			Logger::log(str);
			cout<<"vane received "<<cmd.data[0]<<endl;
			Logger::log("***End cmd vane received***");
			break;
		}
		default:
			break;
	}
}

void Modele::notifyMot(int cmdSailMotor, int cmdHelmMotor)
{
	DataPack mot;
	mot.id = MOTORS_ID;
	mot.data[0] = cmdSailMotor;
	mot.data[1] = cmdHelmMotor;
	notify<DataPack>(mot);
}

WindDirection Modele::choseWind()
{
	float axeRef = cor.calculateAxeRef(cor.getBoueAvLat(), cor.getBoueAvLon(), cor.getBoueApLat(), cor.getBoueApLon());
	float wind = cor.calculateWindAxeRef(axeRef, cor.getWindAxe());

	cout<<"********************** axe ref"<<axeRef<<endl;
	cout<<"********************** axe wind"<<cor.getWindAxe()<<endl;
	cout<<"********************** axe wind after"<<wind<<endl;	

	if(wind >= 0 && wind < 50)
	{
		Logger::log("\n***Wind come from front***\n");
		return FRONT_WIND;
	}
	else if(wind >= 160 && wind < 180)
	{
		Logger::log("\n***Wind come from back***\n");
		return BACK_WIND;
	}
	else
	{
		Logger::log("\n***Wind come from side***\n");
		return SIDE_WIND;
	}
}