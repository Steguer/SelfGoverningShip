/**
 * @file Handler.hpp
 * @author Steven GERARD
 */
#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "../Tools/Coordinate.hpp"

using namespace std;

/**
 * @class Handler
 * @brief Interface for the handler
 */
class Handler
{
public:
	Handler();
	virtual ~Handler()=0;
	virtual int runHandler(Coordinate const& cor)=0;
};

#endif