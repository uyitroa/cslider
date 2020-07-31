#define PY_SSIZE_T_CLEAN  /* Make "s#" use Py_ssize_t rather than int. */
#include <Python.h>
#include <iostream>
#include <vector>
#include "Vector2.h"
#include "BezierApproximator.h"


void decref(PyObject *self, PyObject *args) {

}


PyObject *create_bezier(PyObject *self, PyObject *args) {
	PyObject *output = PyList_New(0);
	Py_XINCREF(output);
	PyObject *input;
	Py_XINCREF(input);

	printf("Parsing\n");

	if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &input))
		return NULL;

	printf("Converting\n");

	int row_count = PyList_Size(input);
	std::vector<Vector2<double> > control_points(row_count);

	for(int i = row_count-1; i >= 0; i--) {
		PyObject *pos = PyList_GET_ITEM(input, i);
		Py_XINCREF(pos);
		Vector2<double> v(PyLong_AsDouble(PyList_GET_ITEM(pos, 0)), PyLong_AsDouble(PyList_GET_ITEM(pos, 1)));
		control_points[i] = v;
		Py_XDECREF(pos);
	}

	Py_XDECREF(input);


	printf("Creating Bezier instance\n");
    BezierApproximator b(control_points, row_count);

    printf("Creating output");
    b.create_bezier(output);
    printf("DOne");
	return output;
}

static PyMethodDef curves_methods[] = {
		/* The cast of the function is necessary since PyCFunction values
		 * only take two PyObject* parameters, and keywdarg_parrot() takes
		 * three.
		 */
		{"create_bezier", (PyCFunction)(void(*)(void))create_bezier, METH_VARARGS | METH_KEYWORDS,
				        "Return list of position"},
		{NULL, NULL, 0, NULL}   /* sentinel */
};

static struct PyModuleDef curvesmethods = {
		PyModuleDef_HEAD_INIT,
		"curves",
		NULL,
		-1,
		curves_methods
};

PyMODINIT_FUNC
PyInit_curves(void)
{
	return PyModule_Create(&curvesmethods);
}

//int main() {
//
//    std::vector<Vector2<double> > control_points = {Vector2<double>(306, 222), Vector2<double>(303, 149), Vector2<double>(303, 149), Vector2<double>(361, 207), Vector2<double>(372, 277), Vector2<double>(372, 277), Vector2<double>(401, 271), Vector2<double>(401, 271), Vector2<double>(413, 339), Vector2<double>(460, 375), Vector2<double>(460, 375), Vector2<double>(514, 306), Vector2<double>(482, 209), Vector2<double>(428, 191), Vector2<double>(428, 191), Vector2<double>(454, 129), Vector2<double>(454, 129), Vector2<double>(403, 88), Vector2<double>(355, 87), Vector2<double>(355, 87), Vector2<double>(368, 38), Vector2<double>(368, 38), Vector2<double>(278, 66), Vector2<double>(156, 53), Vector2<double>(82, 11)};
//    PyObject *output = PyList_New(0);
//
//    BezierApproximator b(control_points, control_points.size());
//    b.create_bezier(output);
//    printf("DOME");
//    return 0;
//}