#include "Python.h"

#include <boost/python.hpp>

#include "Graphics/Font.h"

using namespace boost::python;

using namespace FlatWorld;

std::string world() { return "Hello, World"; }

BOOST_PYTHON_MODULE(hello)
{
	def("world", &world);
}

Python::Python(void)
{
	try
	{
		PyImport_AppendInittab("hello", &inithello);

		Py_Initialize();

		object main_module( ( handle<>( borrowed( PyImport_AddModule("__main__") ) ) ) );
		object main_namespace = main_module.attr("__dict__");

		handle<> ignored( PyRun_String(
			"import hello\n"
			"print hello.world()",
			Py_file_input,
			main_namespace.ptr(),
			main_namespace.ptr()
			) );
	}
	catch (error_already_set)
	{
		PyErr_Print();
	}
}

Python::~Python(void)
{
}
