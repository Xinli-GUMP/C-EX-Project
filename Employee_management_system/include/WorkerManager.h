#pragma once
#include "AbsWorker.h"
#include "Employee.h"
#include "Boss.h"
#include "Manager.h"
#include "file_operator.h"

class WorkerManager
{
private:
    int m_workerNnum;
    int *m_id_array = nullptr; // 成员指针在定义或构造时最好初始化一下, 否则在delete时程序会崩溃。
    AbsWorker **m_worker_array = nullptr;
    WorkerType *m_worker_type = nullptr;
    file_operator fo;

public:
    WorkerManager();
    void add_worker();
    void show_menu();
    void display_worker();
    void delete_worker();
    void modify_worker_info();
    void search_worker();
    void sort_worker_data();
    void clear_worker_data();
    void exit();

    ~WorkerManager();
};