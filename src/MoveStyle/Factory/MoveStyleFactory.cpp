/**
 * @file MoveStyleFactory.cpp
 * @author Steven GERARD
 */
#include "MoveStyleFactory.hpp"

MoveStyle* MoveStyleFactory::m_moveStyle = nullptr;

MoveStyleFactory::MoveStyleFactory()
{

}
MoveStyleFactory::~MoveStyleFactory()
{
	if(m_moveStyle != nullptr)
	{
		delete m_moveStyle;	
		m_moveStyle = nullptr;	
	}
}

MoveStyle* MoveStyleFactory::makeMoveStyle(WindDirection dir)
{
	cout<<endl<<"*** Enter in the MoveStyle Factory ***"<<endl;
	if(m_moveStyle != nullptr)
	{
		cout<<"An other move already exist"<<endl;
		throw runtime_error("AN OTHER MOVE STYLE ALREADY EXIST !");
	}

	switch(dir)
	{
		case SIDE_WIND:
			m_moveStyle = new SideWind();
			cout<<"SideWind creation"<<endl;
			break;
		case BACK_WIND:
			cout<<"BackWind creation : ";
			m_moveStyle = new BackWind();
			cout<<"BackWind creation"<<endl;
			break;
		case FRONT_WIND:
			cout<<"FrontWind creation : ";
			m_moveStyle = new FrontWind();
			cout<<"FrontWind creation"<<endl;
			break;
	}
	cout<<"*** Quit the MoveStyle Factory ***"<<endl;
	return m_moveStyle;
}
void MoveStyleFactory::deleteMoveStyle(MoveStyle* ms)
{
	cout<<endl<<"*** Enter in the delete room of the factory ***"<<endl;
	if(m_moveStyle == ms)
	{
		cout<<"Destruction of the move style : ";
		delete ms;
		cout<<"Destruction of the move style : ok"<<endl;
		cout<<"Inner movestyle to nullptr : ";
		m_moveStyle = nullptr;
		cout<<"Inner movestyle to nullptr : ok"<<endl;
	}

	else
	{
		cout<<"Inner move style and move style parameter are different"<<endl;
		throw runtime_error("DELETE MOVE STYLE ERROR !");
	}
}