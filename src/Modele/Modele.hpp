/**
 * @file Modele.hpp
 * @author Steven GERARD
 * @date 10/02/2014
 * 
 * @brief Contain Modele declaration of the Modele class
 */

#ifndef MODELE_H
#define MODELE_H

#include "../Observer/Observer.hpp"
#include "../Observer/Observable.hpp"
#include "../Tools/Data.hpp"
#include "../MoveStyle/MoveStyle.hpp"
#include "../AbstractFactory/CreateStrategy.hpp"
#include <chrono>

 using namespace std;

/**
 * @class Modele
 * @brief Manege all the behavior of the ship in regard of navigation
 * @see  MoveStyle
 */
class Modele : public Observer, public Observable
{
	private:
		/**
		 * @brief Move style use by the system
		 * 
		 * @see  MoveStyle
		 */
		MoveStyle *m_ms;
		/**
		 * @brief Factory wich create strategy
		 * @see  CreateStrategy
		 */
		CreateStrategy *m_createStrat;
		/**
		 * @brief Contain lot of useful method and data about the system
		 * @see  Coordinate
		 */
		Coordinate cor;
		/**
		 * @brief Current direction od the wind
		 * @see  WindDirection
		 */
		WindDirection m_wind;
		/**
		 * @brief New wind receive by the captor
		 * @see  WindDirection
		 */
		WindDirection m_newWind;

		/**
		 * @brief Where we call the strategy for the sail motor command.
		 * 
		 * @param cor Data of the system and other useful things.
		 * @return the commande for the sail motors.
		 * 
		 * @see  Coordinate
		 * @see  SideWind
		 * @see  BackWind
		 * @see  FrontWind
		 */
		int sailMotor(Coordinate & cor);
		/**
		 * @brief Where we call the strategy for the helm motor command.
		 * 
		 * @param cor Data of the system and other useful things.
		 * @return the commande for the helm motors.
		 * 
		 * @see  Coordinate
		 * @see  SideWind
		 * @see  BackWind
		 * @see  FrontWind
		 */
		int helmMotor(Coordinate & cor);

	public:
		/**
		 * @brief Default constructor
		 */
		Modele();
		/**
		 * @brief Construct a model with strategy chose by the user.
		 * 
		 * @param dir Type of strategy chosed by the users.
		 * @see  WindDirection
		 */
		Modele(WindDirection const& dir);
		~Modele();

		/**
		 * @brief Use when the Observable notify this method.
		 * @details This method is use with the Observer pattern.
		 * 
		 * @param cmd Command receive from the Observable
		 */
		virtual void update(DataPack cmd);
		/**
		 * @brief Change the strategy use by this method.
		 * 
		 * @param dir Type of strategy use by the system.
		 * @see  WindDirection
		 */
		void setStrategy(WindDirection const& dir);
		/**
		 * @brief Send the new command to the actuators.
		 * 
		 * @param cmdSailMotor Command send to sail motors
		 * @param cmdHelmMotor Command send to helm motor
		 */
		void notifyMot(int cmdSailMotor, int cmdHelmMotor);
		/**
		 * @brief Lauch the modele
		 */
		void run();
		/**
		 * @brief Go to flag and return to the first flag strategy for the boat.
		 */
		void goBack();
		/**
		 * @brief Chose if the wind come frome side, front or back.
		 * @return The direction of the wind
		 */
		WindDirection choseWind();
};

#endif