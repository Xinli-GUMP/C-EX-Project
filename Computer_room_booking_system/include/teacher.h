//   教师具体功能
//   查看所有预约   ---   查看全部预约信息以及预约状态
//   审核预约    ---   对学生的预约进行审核
//   注销登录    ---   退出登录
#ifndef TEACHER
#define TEACHER

#include "identity.h"
#include "order.h"
#include <fstream>
#include <map>

class Manager;
class Admin;
class Teacher : public Identity
{
    friend Admin;
    friend Manager;
private:
    int teacher_id;
public:
    Teacher(int teacher_id, std::string account, std::string pwd);
    void show_user_menu() override;
    static void check_all_bookings(std::map< int, Order > &m_order);
    static void review_bookings(std::map< int, Order > &m_order,
                                std::fstream &fs_order);
    static void change_booking_status(Order &order);
};

#endif /* TEACHER */
