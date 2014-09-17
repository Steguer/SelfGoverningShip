/**
 * @file HelmHandler.hpp
 * @author  Steven GERARD
 */

#ifndef HELM_HANDLER_HPP
#define HELM_HANDLER_HPP

#include "../Handler.hpp"
#include "../../Tools/Parsser.hpp"

/**
 * @class HelmHandler
 * @brief Meta-class to use polymorphism.
 * @see HelmHandlerSideWind
 * @see HelmHandlerBackWind
 * @see HelmHandlerFrontWind
 */
class HelmHandler: public Handler
{
protected:
	/**
	 * @brief Limit of the helm angle
	 */
	float m_maxHelmAngle;
	/**
	 * @brief Speed of the helm
	 * @details When this value increase the helm turn less when boat is not in the good way. See the curve in the SideWind test.
	 *
	 */
	float m_speedHelm;

public:
	/**
	 * @brief Default constructor
	 * @details Init speed of the helm move and the limit of the helm commands.
	 */
	HelmHandler();
	~HelmHandler();
	
};

#endif