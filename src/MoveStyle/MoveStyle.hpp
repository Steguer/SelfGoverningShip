/**
 * @file SideWind.h
 * @author Steven GERARD
 * @version 1.0
 * @date 05/12/2013
 * 
 *@brief Contain MoveStyle declaration of the MoveStyle class
*/	

#ifndef MOVESTYLE_H
#define MOVESTYLE_H

#include "../Tools/Coordinate.hpp"
#include "../Handler/Handler.hpp"

using namespace std;

/**
 * @class MoveStyle
 * @brief Interface which will allow to change the behavior of the ship according to wind
*/
class MoveStyle
{
	public:
		MoveStyle();
		virtual ~MoveStyle()=0;
		virtual void setSailHandler(Handler *sh)=0;
 		virtual void setHelmHandler(Handler *hh)=0;
 		virtual int sailMotor(Coordinate const& cor)=0;
		virtual int helmMotor(Coordinate const& cor)=0;
};

#endif