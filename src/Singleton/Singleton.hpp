/**
 * @file Singleton.hpp
 * @author Steven GERARD
 */
#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <stdexcept>
#include "../Tools/Logger.hpp"

using namespace std;

/**
 * @class Singleton
 * @brief Class template which avoid multiple creation of an object which inherit of this class
 */
template <typename T>
class Singleton
{
	protected:
		Singleton()
		{

		}
		~Singleton()
		{

		}

	public:
		/**
		 * @brief Create an return an object
		 * @return The object create
		 */
		static T *getInstance()
		{
			if (m_singleton == nullptr)
			{
				return m_singleton = new T;
			}
			else
			{
				throw runtime_error("Singleton already exist.");
			}
		}

		/**
		 * @brief Delete the singleton object
		 */
		static void kill()
		{
			if(m_singleton != nullptr)
			{
				delete m_singleton;
				m_singleton = nullptr;
			}
		}

	private:
		/**
		 * @brief Contain the current singleton object and avoid a multiple creation on this object
		 */
		static T *m_singleton;
};

template <typename T>
T *Singleton<T>::m_singleton = nullptr;

#endif