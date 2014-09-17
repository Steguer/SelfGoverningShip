/**
 * @file FrontWind.h
 * @author Steven GERARD
 * @version 1.0
 * @date 11/12/2013
 * 
 * @brief Contain the declaration of the FrontWind class
 */

#ifndef FRONTWIND_H
#define FRONTWIND_H

#include "../MoveStyle.hpp"

using namespace std;

/**
 * @class FrontWind
 * @brief Manage the behavior of the ship in case the wind arrive by the front
 * @see MoveStyle
 */

class  FrontWind : public MoveStyle
{
	friend class MoveStyleFactory;

	private:
		/**
		 * @brief Default constructor
		 */
		 FrontWind();

		 /**
		  * @brief Destructor of the class
		  */
		~ FrontWind();

		/**
	 	 * @brief Handler use by the strategy to calculate helm command
	 	 */
		Handler *m_hhfw;
		/**
	 	 * @brief Handler use by the strategy to calculate sail command
	 	 */
		Handler *m_shfw;

	public:
		/**
		 * @brief Where we call the handler for the sail motor command.
		 * 
		 * @param cor Data of the system and other useful things.
		 * @return the commande for the sail motors.
		 * 
		 * @see  Coordinate
		 * @see  SailHandlerSideWind
		 * @see  SailHandlerBackWind
		 * @see  SailHandlerFrontWind
		 */
		virtual int sailMotor(Coordinate const& cor);
		/**
		 * @brief Where we call the handler for the helm motor command.
		 * 
		 * @param cor Data of the system and other useful things.
		 * @return the commande for the helm motors.
		 * 
		 * @see  Coordinate
		 * @see  HelmHandlerSideWind
		 * @see  HelmHandlerBackWind
		 * @see  HelmHandlerFrontWind
		 */
		virtual int helmMotor(Coordinate const& cor);

		/**
 		 * @brief Change the handler use for calculate sail's motors command
 		 * 
 		 * @param sh New handler to use
 		 */
		virtual void setSailHandler(Handler *sh);
		/**
 		 * @brief Change the handler use for calculate helm's motors command
 		 * 
 		 * @param hh New handler to use
 		 */
 		virtual void setHelmHandler(Handler *hh);
};

#endif