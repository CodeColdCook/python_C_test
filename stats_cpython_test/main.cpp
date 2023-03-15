#include <Python.h>

#include <iostream>

using namespace std;

int print_jetson_hardware() {
  int res;
  PyObject *pModule, *pFunc;
  PyObject *pArgs, *pValue;

  // 设置python路径
  string change_dir = "sys.path.append('../../examples')";
  PyRun_SimpleString("import sys");
  PyRun_SimpleString(change_dir.c_str());
  /* import */
  pModule = PyImport_ImportModule("jtop_hardware_func");
  if (pModule == nullptr) {
    cout << "[Error] Import module error" << endl;
    return -1;
  }

  pFunc = PyObject_GetAttrString(pModule, "jtop_hardware_func");
  if (pFunc == nullptr) {
    cout << "[Error] Import function error" << endl;
    return -1;
  }

  pValue = PyObject_CallObject(pFunc, NULL);

  res = PyLong_AsLong(pValue);

  cout << "python 功能函数返还值： " << res << endl;

  Py_DecRef(pModule);
  Py_DecRef(pFunc);
  Py_DecRef(pArgs);
  Py_DecRef(pValue);

  return res;
}

int main(int argc, char *argv[]) {
  Py_Initialize();
  printf("%d \n", print_jetson_hardware());
  Py_Finalize();
}