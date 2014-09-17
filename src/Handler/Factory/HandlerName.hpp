/**
 * @file HandlerName.hpp
 * @author Steven GERARD
 * @brief Just some macro use in the factories
 */
#ifndef HANDLER_NAME_HPP
#define HANDLER_NAME_HPP

#define SAIL_HANDLER_SIDE_WIND SailHandlerSideWind()
#define SAIL_HANDLER_FRONT_WIND SailHandlerFrontWind()
#define SAIL_HANDLER_BACK_WIND SailHandlerBackWind()

#define HELM_HANDLER_SIDE_WIND HelmHandlerSideWind()
#define HELM_HANDLER_FRONT_WIND HelmHandlerBackFrontWind(FRONT_WIND)
#define HELM_HANDLER_BACK_WIND HelmHandlerBackFrontWind(BACK_WIND)

#define HELM_HANDLER_BACK_WIND_PY_SCRIPT PyScriptHandler("HelmHandlerBackWindPyScript")
#define HELM_HANDLER_FRONT_WIND_PY_SCRIPT PyScriptHandler("HelmHandlerFrontWindPyScript")
#define HELM_HANDLER_SIDE_WIND_PY_SCRIPT PyScriptHandler("HelmHandlerSideWindPyScript")

#define SAIL_HANDLER_BACK_WIND_PY_SCRIPT PyScriptHandler("SailHandlerBackWindPyScript")
#define SAIL_HANDLER_FRONT_WIND_PY_SCRIPT PyScriptHandler("SailHandlerFrontWindPyScript")
#define SAIL_HANDLER_SIDE_WIND_PY_SCRIPT PyScriptHandler("SailHandlerSideWindPyScript")


#endif