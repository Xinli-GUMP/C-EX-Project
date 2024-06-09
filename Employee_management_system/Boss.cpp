#include "Boss.h"

Boss::Boss(int id, const char *name, const char *rank)
{
    m_Id = id;
    strncpy(m_rank, rank, sizeof(m_rank) - 1);
    this->m_rank[sizeof(m_rank) - 1] = '\0'; // 确保字符串以null终止
    strncpy(m_Name, name, sizeof(m_Name) - 1);
    this->m_Name[sizeof(m_Name) - 1] = '\0'; // 确保字符串以null终止
}

void Boss::show_Info()
{
    cout << "职工编号：" << m_Id
         << " \t职工姓名：" << m_Name
         << " \t岗位职级：" << m_rank
         << " \t岗位任务：" << get_task() << '\n'
         << endl;
};

int Boss::get_id()
{
    return this->m_Id;
}
char *Boss::get_rank()
{
    return this->m_rank;
}
char *Boss::get_name()
{
    return this->m_Name;
}
char *Boss::get_task()
{
    return (char *)"狠狠滴降本增效";
}

Boss::~Boss(){};