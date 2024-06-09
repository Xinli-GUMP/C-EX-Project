// 添加账号--添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
// 查看账号-- 可以选择查看学生或教师的全部信息
// 查看机房--查看所有机房的信息
// 清空预约--清空所有预约记录
// 注销登录--退出登录
// 默认管理员账号: ID:0 Account:Alice Password:36149
#ifndef ADMIN
#define ADMIN

#include "identity.h"
#include "student.h"
#include "teacher.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>

class Manager;
class Admin : public Identity
{
    friend Manager;
private:
    int admin_id;
public:
    Admin(int admin_id, std::string &account, const std::string &pwd);
    void show_user_menu() override;
    static void add_account(std::fstream &fs_stu, std::vector< Student > &v_stu,
                            std::fstream &fs_teacher,
                            std::vector< Teacher > &v_teacher);

    static void delete_account(std::fstream &fs_stu,
                               std::vector< Student > &v_stu,
                               std::fstream &fs_teacher,
                               std::vector< Teacher > &v_teacher);

    static void lookOver_accounts(std::vector< Student > &v_stu,
                                  std::vector< Teacher > &v_teacher);
    static void lookOver_rooms(std::map< int, int > &m_room);
    static void clean_bookings(std::map< int, Order > &m_order,
                               std::fstream &fs_order);
    ~Admin() = default;
};
#endif /* ADMIN */
