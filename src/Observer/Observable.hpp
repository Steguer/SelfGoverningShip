/**
 * @file Observable.h
 * @author Steven GERARD
 * @version  1.0
 * @date 20/01/2014
 * 
 * @brief Contain declaration of the Observable class
 */

#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <list>
#include <algorithm>
#include "Observer.hpp"

using namespace std;

/**
 * @see Observer
 */
class Observer;

/**
 * @class Observable
 * 
 * @brief One part of the Observer patern.
 * @details With the Observer class it allow us to check the information contain in the observable object.
 */
class Observable
{
public:
	/**
	 * @brief Dfault constructor
=	 */
	Observable();
	virtual ~Observable();

	/**
	 * @brief Add observer to the list of observers
	 * 
	 * @param newObs The new observer to add
	 */
	void addObserver(Observer* newObs);
	/**
	 * @brief Remove an observer of the list
	 * 
	 * @param oldObs Observer to remove
	 */
	void delObserver(Observer* oldObs);

protected:
	/**
	 * @brief Contain all the Observer which look this observable
	 */
	list<Observer*> m_listObserver;

	/**
	 * @brief Notify all the Observer that something is new
	 * 
	 * @param Datas send to the observer
	 */
	template <typename T>
	void notify(T const& data)
	{
		for(list<Observer*>::iterator it=m_listObserver.begin(); it != m_listObserver.end(); ++it)
		{
			(*it)->update(data);
		}
	}

};

#endif