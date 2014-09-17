/**
 * @file Observer.h
 * @author  Steven GERARD
 * @version  1.0
 * @date 20/01/2014
 * 
 * @brief Contain the declaration of the Observer class
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>
#include "../Tools/Data.hpp"

using namespace std;

/**
 * @see Observable
//  */
// class Observable;

/**
 * @class Observer
 * 
 * @brief One part of the Observer pattern.
 * @details With the Observer class it allow us to check the information contain in the observable object.
 */
class Observer
{
public:
	/**
	 * @brief Default constructor
	 */
	Observer();
	virtual ~Observer();

	/**
	 * @brief Method call by the Observable to update their observer.
	 * 
	 * @param cmd Commande receive by the Observable
	 */
	virtual void update(DataPack cmd) =0;

};

#endif