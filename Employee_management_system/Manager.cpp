#include "Manager.h"

Manager::Manager(int id, const char *name, const char *rank)
{
    m_Id = id;
    strncpy(m_rank, rank, sizeof(m_rank) - 1);
    this->m_rank[sizeof(m_rank) - 1] = '\0'; // 确保字符串以null终止
    strncpy(m_Name, name, sizeof(m_Name) - 1);
    this->m_Name[sizeof(m_Name) - 1] = '\0'; // 确保字符串以null终止
}

void Manager::show_Info()
{
    cout << "职工编号：" << m_Id
         << " \t职工姓名：" << m_Name
         << " \t岗位职级：" << m_rank
         << " \t岗位任务：" << get_task() << '\n'
         << endl;
}

int Manager::get_id()
{
    return this->m_Id;
}
char *Manager::get_rank()
{
    return this->m_rank;
}
char *Manager::get_name()
{
    return this->m_Name;
}
char *Manager::get_task()
{
    return (char *)"狠狠滴压榨员工";
}

Manager::~Manager()
{
}
