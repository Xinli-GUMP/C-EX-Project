#pragma once
#include "AbsWorker.h"

class Boss : public AbsWorker
{

public:
    Boss(int id, const char *name, const char *rank); // 用const char* 接收形参, 代表传入的形参不会被改变
    ~Boss();
    void show_Info() override;
    int get_id() override;
    char *get_rank() override;
    char *get_name() override;
    char *get_task() override;
};
