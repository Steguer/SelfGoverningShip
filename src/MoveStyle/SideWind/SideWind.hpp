/**
 * @file SideWind.hpp
 * @author Steven GERARD
 * @version 1.0
 * @date 05/12/2013
 * 
 * @brief Contain SideWind declaration of the SideWind class
 */	

#ifndef SIDEWIND_H
#define SIDEWIND_H

#include <cmath>
#include <iostream>
#include "../MoveStyle.hpp"

using namespace std;

/**
 * @class SideWind
 * @brief Manage the behavior of the ship in case the wind arrive by the side
 * @see MoveStyle
 */
class SideWind : public MoveStyle
{
	friend class MoveStyleFactory;

	private:
		/**
		 * @brief Default constructor of the class
		 * @details like the rest is to later
		 * 
		 * @param  nothing
		 * @return nothing
		 */
		SideWind();
		/**
		 * @brief Destructor of the class
		 * @details [long description]
		 */
		~SideWind();
		
		Handler *m_shsw;
		Handler *m_hhsw;
		
	public:
		/**
		 * @brief Manege the use of the motor
		 * @details All things is not deceded and we will whange that soon
		 * 
		 * @return The number of rope that have to leave or take for the sail
		 */
		virtual int sailMotor(Coordinate const& cor);

		/**
		 * @test To test this methode we used an Octave script than provide the graph bellow where the angle between boat-axe and boat-flag axe, this angle is name /teta.
		 * 		@image html helmAngleGraph.jpg
		 * 
		 * @brief Manege the use of the motor
		 * @details The behavior of the motor is manege with \f$h(\theta)=E*i*(1-\exp(i*(\theta/\tau)))\f$ function.\n
		 * 			This function is controlled by 3 parameters: \n
		 * 			E : Manage the max value of the formula. Indeed when \f$\theta\f$ tends towards infinity the result tends to E.\n
		 * 			\f$tau\f$ : Manege the slope of the function. I.e more it is and more the function will tend quickly to E.
		 * 			i : i allow to manege the \f$\theta\f$ negative values. I.e i=1 if \f$\theta<0\f$ and i=-1 if \f$\theta<0\f$.
		 * 					 * 
		 * @return The number of degrees to return in the good way
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