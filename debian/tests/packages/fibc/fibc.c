#include <Python.h>

int fib(int n) {
	if (n < 0) {
		return -1; // Raise
	}
	if (n < 2) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

static PyObject * fibc_fib(PyObject *self, PyObject *args) {
	int n;

	if (!PyArg_ParseTuple(args, "i", &n))
		return NULL;
	int r = fib(n);
	return PyLong_FromLong(r);
}

static PyMethodDef FibcMethods[] = {
	{"fib",  fibc_fib, METH_VARARGS, "Calculate a fibonacci sequence value."},
	{NULL, NULL, 0, NULL},
};

static PyModuleDef fibcmodule = {
	PyModuleDef_HEAD_INIT,
	"fibc",
	NULL,  // documentation
	-1,  // state in global vars
	FibcMethods
};

PyMODINIT_FUNC PyInit_fibc(void) {
	return PyModule_Create(&fibcmodule);
};
