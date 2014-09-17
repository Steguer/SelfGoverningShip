#include "PyScriptManager.hpp"

string PyScriptManager::m_scriptPath = "";

PyScriptManager::PyScriptManager()
{

}

PyScriptManager::PyScriptManager(string const& scriptPath)
{
	m_scriptPath = "sys.path.append(\"";
	m_scriptPath += scriptPath;
	m_scriptPath += "\")";
}

PyScriptManager::~PyScriptManager()
{

}

double PyScriptManager::usePyScript(string const& scriptName, map<string, double> const& data)
{
	PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue, *pTuple;
    int i;
    double result;

    m_scriptPath = "sys.path.append(\"";
    m_scriptPath += Parsser::readConfigStr("ScriptPath");
    m_scriptPath += "\")";

    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString(m_scriptPath.c_str());
    pName = PyUnicode_FromString(scriptName.c_str());
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL)
    {
        pFunc = PyObject_GetAttrString(pModule, "main");
        /* pFunc is a new reference */
        if (pFunc && PyCallable_Check(pFunc))
        {
        	pArgs = PyDict_New();
        	pTuple = PyTuple_New(1);
        	for(auto &it : data)
        	{
	            PyDict_SetItemString(pArgs, it.first.c_str(), PyFloat_FromDouble(it.second));
        	}
            PyTuple_SetItem(pTuple, 0, pArgs);
            pValue = PyObject_CallObject(pFunc, pTuple);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                printf("Result of call: %ld\n", PyLong_AsLong(pValue));
                result = PyLong_AsLong(pValue);
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else 
        {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", "hello");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", scriptName.c_str());
        return 1;
    }
    Py_Finalize();
 
    return result;
}

string PyScriptManager::getScriptPath()
{
	return m_scriptPath;
}

void PyScriptManager::setScriptPath(string const& scriptPath)
{
	m_scriptPath = "sys.path.append(\"";
	m_scriptPath += scriptPath;
	m_scriptPath += "\")";
}