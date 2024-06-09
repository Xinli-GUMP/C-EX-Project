/* 学生具体功能
申请预约-- 预约机房
查看自身的预约-- 查看自己的预约状态
查看所有预约--- 查看全部预约信息以及预约状态
取消预约---取消自身的预约，预约成功或审核中的预约均可取消
注销登录-- 退出登录
 */
#ifndef STUDENT
#define STUDENT
#include "identity.h"
#include "order.h"
#include <fstream>
#include <map>
#include <vector>

class Manager;
class Admin;
class Student : public Identity
{
    friend Manager;
    friend Admin;
private:
    int stu_id;
public:
    void show_user_menu() override;
    Student(int stu_id, std::string accout, std::string pwd);
    static void orderable(int room_nums, std::vector< Order > &v_order);
    static auto is_repeat(int room_Id, int weekday, int timeSlot,
                          std::vector< Order > &v_order) -> bool;
    auto book_room(int room_nums, std::fstream &fs_order,
                   std::map< int, Order > &m_order) -> void;
    static void show_order_info(const Order &order);
    void check_booking_status(const std::map< int, Order > &m_order) const;
    static void check_all_bookings(std::map< int, Order > &m_order);
    void cancel_booking(std::map< int, Order > &m_order,
                        std::fstream &fs_order) const;
};

#endif /* STUDENT */
