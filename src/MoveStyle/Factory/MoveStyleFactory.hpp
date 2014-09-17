/**
 * @file MoveStyleFactory.hpp
 * @author Steven GERARD
 */
#ifndef MOVE_STYLE_FACTORY_HPP
#define MOVE_STYLE_FACTORY_HPP

#include <iostream>
#include <stdexcept>
#include "../MoveStyle.hpp"
#include "../../Tools/Data.hpp"
#include "../SideWind/SideWind.hpp"
#include "../BackWind/BackWind.hpp"
#include "../FrontWind/FrontWind.hpp"

using namespace std;

/**
 * @class MoveStyleFactory
 * @brief Manege the moce style making
 * 
 * @see  Singleton
 * @see  BackWind
 * @see  SideWind
 * @sse  FrontWind
 */
class MoveStyleFactory: public Singleton<MoveStyleFactory>
{
	friend class Singleton<MoveStyleFactory>;

	private:
		/**
		 * @brief Use to avoid that different moveStyle are create at the same time
		 */
		static MoveStyle* m_moveStyle;
		/**
		 * @brief Default constructor
		 */
		MoveStyleFactory();
		~MoveStyleFactory();

	public:
		/**
		 * @brief Make the move style
		 * @details The move-styles are the strategies wich are use
		 *  
		 * @param dir Type of move style (front, side, back)
		 * @return Return a new move-style
		 */
		MoveStyle* makeMoveStyle(WindDirection dir);
		/**
		 * @brief Delete a move-style
		 * 
		 * @param ms Move-style to delete
		 */
		void deleteMoveStyle(MoveStyle* ms);
	
};

#endif