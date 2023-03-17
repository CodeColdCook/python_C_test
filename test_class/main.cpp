#include <Python.h>

#include <iostream>

using namespace std;

int main() {
  Py_Initialize();
  if (!Py_IsInitialized()) {
    cout << "[Error] Init error" << endl;
    return -1;
  }

  string change_dir = "sys.path.append('../scripts')";
  PyRun_SimpleString("import sys");
  PyRun_SimpleString(change_dir.c_str());

  PyObject *pModule = PyImport_ImportModule("test_class");

  if (pModule == nullptr) {
    cout << "[Error] Import module error" << endl;
    return -1;
  }
  cout << "[INFO] Get Module" << endl;

  PyObject *pClass_no_arg = PyObject_GetAttrString(pModule, "TestDemo");
  if (pClass_no_arg == nullptr) {
    cout << "[Error] Import class error" << endl;
    return -1;
  }
  cout << "[INFO] Get Class no arg" << endl;

  PyObject *pInstance = PyObject_CallObject(pClass_no_arg, NULL);  // 创建实例
  // PyObject *pInstance = PyObject_Call(pClass_no_arg,args1, nullptr);
  // //创建实例
  assert(pInstance != nullptr);

  PyObject *args2 = Py_BuildValue("(i)", 3);
  PyObject *pRet = PyObject_CallMethod(pInstance, "evaluate", "O", args2);

  if (pRet != nullptr) {
    cout << "成功获取结果" << endl;
    int res = 999;

    // 注意格式，此处采用string会存在解析错误
    char *res2;
    string ss = "mmm";
    // PyArg_Parse(pRet, "i", &res);
    PyArg_ParseTuple(pRet, "is", &res, &res2);
    cout << "成功返回参数: " << res << endl;
    cout << "成功返回参数: " << res2 << endl;
  }

  PyObject *pClass_with_args = PyObject_GetAttrString(pModule, "TestDemo2");
  if (pClass_no_arg == nullptr) {
    cout << "[Error] Import class error" << endl;
    return -1;
  }
  cout << "[INFO] Get Class with arg" << endl;

  PyObject *args1 = Py_BuildValue("(is)", 5, "bob");
  pInstance = PyObject_CallObject(pClass_with_args, args1);
  assert(pInstance != nullptr);
  pRet = PyObject_CallMethod(pInstance, "evaluate", "O", args2);
  if (pRet != nullptr) {
    cout << "成功获取结果" << endl;
    int res = 999;

    // 注意格式，此处采用string会存在解析错误
    char *res2;
    string ss = "mmm";
    // PyArg_Parse(pRet, "i", &res);
    PyArg_ParseTuple(pRet, "is", &res, &res2);
    cout << "成功返回参数: " << res << endl;
    cout << "成功返回参数: " << res2 << endl;
  }

  Py_DecRef(pModule);
  Py_DecRef(pClass_no_arg);
  Py_DecRef(pInstance);
  // Py_DecRef(args1);
  Py_DecRef(args2);
  Py_DecRef(pRet);
  Py_Finalize();
  return 1;
}