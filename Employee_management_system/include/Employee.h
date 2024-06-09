#pragma once
#include "AbsWorker.h"

class Employee : public AbsWorker
{
public:
    Employee(int id, const char *name, const char *rank);
    ~Employee();
    void show_Info() override;
    char* get_task() override;
    int get_id() override;
    char* get_rank() override;
    char* get_name() override;
};
