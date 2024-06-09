#pragma once
#include "AbsWorker.h"

class Manager : public AbsWorker
{
public:
    Manager(int id, const char *name, const char *rank);
    ~Manager();
    void show_Info() override;
    int get_id() override;
    char* get_rank() override;
    char* get_name() override;
    char* get_task() override;
};
