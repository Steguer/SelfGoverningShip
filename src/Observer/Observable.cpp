/**
 * @file Observable.cpp
 * @author Steven GERARD
 * @version 1.0
 * @date  20/01/2014
 * 
 * @brief Contain method implementations of the Observable class.
 */

#include "Observable.hpp"

Observable::Observable()
{

}

Observable::~Observable()
{
	for(list<Observer*>::iterator it = m_listObserver.begin(); it != m_listObserver.end(); ++it)
	{
		m_listObserver.erase(it);
	}
	m_listObserver.clear();
}

void Observable::addObserver(Observer* newObs)
{
	m_listObserver.push_back(newObs);
}

void Observable::delObserver(Observer* oldObs)
{
	list<Observer*>::iterator it = find(m_listObserver.begin(), m_listObserver.end(), oldObs);

	m_listObserver.erase(it);
}
