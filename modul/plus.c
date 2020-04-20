#include <Python.h>

static PyObject *py_distans(PyObject *self, PyObject *args){
  double x1, y1, x2, y2, rast;

  if(!PyArg_ParseTuple(args,"dddd", &x1, &y1,&x2, &y2))
    return NULL;

  rast = sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));

  return Py_BuildValue("d", rast);
}

static PyObject *py_str(PyObject *self, PyObject *args){
  double a, b, c, yr;

  if(!PyArg_ParseTuple(args,"fff", &a, &b,&c))
    return NULL;

  if (a < 0){
    a = "-%.2f"%(abs(a))}
  else:
    {a = "%.2f"%(a)}
  if (b < 0)
    {b = "- %.2f"%(abs(b))}
  else:
    {b = "+ %.2f"%(b)}
  if (c < 0)
    {c = "- %.2f"%(abs(c))}
  else:
    {c = "+ %.2f"%(c)}

  yr="{}x {}y {} = 0".format(a,b,c);

  return Py_BuildValue("c", yr);
}

/* Описывает методы модуля */
static PyMethodDef ownmod_methods[] = {
{
    "distans",          // название функции внутри python
     py_distans,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "plus function" // документация для функции внутри python
},{"str",py_str,METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
"plus function"},
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
