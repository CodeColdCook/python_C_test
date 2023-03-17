# 用 C 或 C++ 扩展 Python

## 相关链接

[python接口调用与说明——官方文档](https://docs.python.org/2/extending/extending.html#)

[FindPython3的cmake官方文档](https://cmake.org/cmake/help/latest/module/FindPython3.html)

[python2 教程——Python与C/C++混合编程](https://zhuanlan.zhihu.com/p/20150641?refer=python-dev)

[python3 教程——C++调用Python3接口](https://zhuanlan.zhihu.com/p/149887203)

## python2的基础调用教程

### 直接调用python测试

- 调用python的print

- 测试内容[test_1](./test_1)

### 调用python.py测试

- 构建python的function，通过C进行调用。注意执行时的python环境变量

- 测试内容[test_2](./test_2)

### 使用Cython调用python

- 通过cython对pyx文件进行编译，生成.h和.c文件，以供程序调用
- 安装cython `sudo apt-get install cython`
- 测试内容[test_3](./test_3)

## python3的基础调用教程

### 构建cmake工程

- 通过cmake对python调用程序进行调用，关键为`find_package`
- 指定python3编译环境
  - 若系统中存在多个版本python3，需要在cmake编译时注意当前find_package找到的版本，可能会出现`Development.Module``Development.Embed`无法找到的错误
  - 原因参考[FindPython3的cmake官方文档](https://cmake.org/cmake/help/latest/module/FindPython3.html)，需要cmake 3.18版本
- 编译方式`cd build`,`cmake ..`,`make`

### 基本测试内容

- [test_4](./test_4)

- 设置`.py`文件路径测试[test_5](./test_5)
- 无参数输入function调用测试[test_6](./test_6)

### Class调用

- [test_class](./test_class)
- 分别测试带参和不带参的类调用

### jtop测试

- 通过以上教程进行jtop功能调用

- [test_6](./stats_cpython_test)



## TODO

- [ ] python类的调用
- [ ] 其他常用功能测试