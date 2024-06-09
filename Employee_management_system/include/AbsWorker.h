#pragma once
#include <iostream>
#include <cstring>
//#include "file_operator.h"
using namespace std;

/**
 * @brief 基类
 *
 */
class AbsWorker
{
    // friend file_operator;
public:
    int m_Id;
    char m_Name[32];
    char m_rank[32];

public:
    virtual void show_Info() = 0;
    virtual char *get_task() = 0;
    virtual int get_id() = 0;
    virtual char *get_rank() = 0;
    virtual char *get_name() = 0;
    virtual ~AbsWorker() = default; // 对于析构函数，如果它在头文件（.h）中被直接定义（即实现了函数体），那么每个包含这个头文件的.cpp文件都会生成这个析构函数的一个定义。当链接器将这些编译单元合并成一个可执行文件时，就会发现这个析构函数有多个定义，从而报错。如果析构函数中没有必要的代码，且AbsWorker是一个抽象类，可以直接在头文件中将析构函数声明为默认。 这样做的目的是告诉编译器生成默认的析构函数实现，但是如果你已经有特定的析构逻辑，这种方法不适用。
};

// AbsWorker::~AbsWorker()
// {
// }