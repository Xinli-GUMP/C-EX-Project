#pragma once
#include <filesystem>
#include <fstream>
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"

enum class WorkerType
{
    None,         // 代表空值
    BossType,     // 代表 Boss 类
    ManagerType,  // 代表Manager类
    EmployeeType, // 代表 Employee 类
};

struct type_work_tuple // 用于接收二进制类数据
{
    WorkerType *type_data = nullptr;
    AbsWorker **worker_data = nullptr;
};

class file_operator
{
public:
    fstream f;
    fstream fb;
    type_work_tuple TW_tuple;

public:
    file_operator(/* args */);
    ~file_operator();
    void write_worker(AbsWorker &worker);
    // void bin_write_worker(WorkerType type, AbsWorker *worker);
    void bin_write_worker(int workerNum, WorkerType *type, AbsWorker **worker);
    void bin_read_worker();
    int file_worker_num(fstream &f);
};
