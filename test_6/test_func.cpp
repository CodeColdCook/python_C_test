#include <Python.h>
#include <iostream>

using namespace std;

int great_function_from_python(int a) {
    int res;
    PyObject *pModule,*pFunc;
    PyObject *pArgs, *pValue;
    printf("%d \n", 1);

    // 设置python路径
    string change_dir = "sys.path.append('../scripts')";
    PyRun_SimpleString("import sys");
    PyRun_SimpleString(change_dir.c_str());
    change_dir = "sys.path.append('../scripts/test')";
    PyRun_SimpleString(change_dir.c_str());
    /* import */
    pModule = PyImport_ImportModule("func");
    printf("%d \n", 2);
    if (pModule == nullptr){
        cout <<"[Error] Import module error" << endl;
        return -1;
    }

    /* great_module.great_function */
    pFunc = PyObject_GetAttrString(pModule, "great_function"); 
    printf("%d \n", 3);
    if (pFunc == nullptr){
        cout << "[Error] Import function error" << endl;
        return -1;
    }
    
    /* build args */
    // 要不带参数调用 Python 函数，请传入 NULL 或空元组
    pArgs = PyTuple_New(0);
    // printf("%d \n", 4);
    // PyTuple_SetItem(pArgs,0, PyLong_FromLong(a));
    // printf("%d \n", 5);
      
    /* call */
    // pValue = PyObject_CallObject(pFunc, NULL);
    pValue = PyObject_CallObject(pFunc, pArgs);
    printf("%d \n", 6);
    
    res = PyLong_AsLong(pValue);
    printf("%d \n", 7);
    
    Py_DecRef(pModule);
    Py_DecRef(pFunc);
    Py_DecRef(pArgs);
    Py_DecRef(pValue);

    return res;
}

int main(int argc, char *argv[]) {
    Py_Initialize();
    printf("%d \n", great_function_from_python(2));
    Py_Finalize();
}