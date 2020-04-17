#include <Python.h>

static PyObject *py_plus(PyObject *self, PyObject *args) {
  double x, y, result;

  if (!PyArg_ParseTuple(args,"dd", &x, &y)) {
    return NULL;
  }
  result = x + y;
  return Py_BuildValue("d", result);
}

static PyMethodDef ownmod_methods[] = {
    {
        "plus", // name of fucntion in python interpreter
        py_plus, // function C declaration
        METH_VARARGS, // special macros about function arguments
        "plus function" // doc for function in python interpreter
    },
    { NULL, NULL, 0, NULL }
};

static PyModuleDef simple_module = {
    /* Info about module */
    PyModuleDef_HEAD_INIT,
    "my_plus", // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods, // methods are here
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_my_plus(void)
{
    PyObject* m;
    // creating module object
    m = PyModule_Create(&simple_module);
    if (m == NULL)
        return NULL;

    return m;
}
