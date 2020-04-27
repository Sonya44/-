#include <Python.h>

static PyObject *py_distans(PyObject *self, PyObject *args){
  double x1, y1, x2, y2, rast;

  if(!PyArg_ParseTuple(args,"dddd", &x1, &y1,&x2, &y2))
    return NULL;

  rast = sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));

  return Py_BuildValue("d", rast);
}

static PyObject *py_dToZero(PyObject *self, PyObject *args){
  double a,b,c, rast;

  if(!PyArg_ParseTuple(args,"ddd", &a, &b, &c))
    return NULL;

  rast = fabs(c)/sqrt(pow(a,2)+pow(b,2));

  return Py_BuildValue("d", rast);
}

static PyObject *py_dToPoint(PyObject *self, PyObject *args){
  double a,b,c, x,y, rast;

  if(!PyArg_ParseTuple(args,"ddddd", &a, &b, &c, &x, &y))
    return NULL;

  rast = fabs(a*x + b*y + c)/sqrt(pow(a,2)+pow(b,2));

  return Py_BuildValue("d", rast);
}

static PyObject *py_isParallel(PyObject *self, PyObject *args){
  double a,b,c,a1,b1,c1; int res;

  if(!PyArg_ParseTuple(args,"dddddd", &a, &b, &c, &a1, &b1, &c1 ))
    return NULL;

  res = fabs(a*b1 - b*a1) <= 0.001;

  return Py_BuildValue("i", res);
}


/* Описывает методы модуля */
static PyMethodDef ownmod_methods[] = {
{
    "distans",          // название функции внутри python
     py_distans,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "distance between two points" // документация для функции внутри python
},{"dToZero",py_dToZero,METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
"distance from (0;0) to line"},
{"dToPoint",py_dToPoint,METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
"distance from point to line"},
{"isParallel",py_isParallel,METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
"Parallel or no Parallel"},
{ NULL, NULL, 0, NULL }
// так называемый sentiel. Сколько бы элементов структуры
// у вас не было, этот нулевой элемент должен быть всегда, и при этом быть последним
};


/* Описываем наш модуль */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT,   // обязательный макрос
    "my_line",               // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods           // сюда передаем методы модуля
};

// в названии функции обязательно должен быть префикс PyInit
PyMODINIT_FUNC PyInit_my_line(void) {
      PyObject* m;
      // создаем модуль
      m = PyModule_Create(&simple_module);
      // если все корректно, то эта проверка не проходит
      if (m == NULL)
          return NULL;
      return m;
}
