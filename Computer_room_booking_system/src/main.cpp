// @Date: Last edit 2024-06-08  23:48
// @Encoding:  UTF-8
// @Author: Heathcliff

/** 大纲首先进入登录界面，可选登录身份有：
  学生代表
  老师
  管理员
  退出
  每个身份都需要进行验证后，进入子菜单
  学生需要输入 ：学号、姓名、登录密码
  老师需要输入：职工号、姓名、登录密码
  管理员需要输入：管理员姓名、登录密码
  学生具体功能
  申请预约    ---   预约机房
  查看自身的预约    ---  查看自己的预约状态
  查看所有预约   ---   查看全部预约信息以及预约状态
  取消预约    ---   取消自身的预约，预约成功或审核中的预约均可取消
  注销登录    ---   退出登录
  教师具体功能
  查看所有预约   ---   查看全部预约信息以及预约状态
  审核预约    ---   对学生的预约进行审核
  注销登录    ---   退出登录
  管理员具体功能
  添加账号    ---   添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
  查看账号    ---   可以选择查看学生或教师的全部信息
  查看机房    ---   查看所有机房的信息
  清空预约    ---   清空所有预约记录
  注销登录    ---   退出登录
*/
#include "file_operator.h"
#include "manager.h"
#include <cstdlib>
#include <iostream>

auto main() -> int
{
    Manager manager;
    while (true)
    {
        Manager::show_main_menu();
        int choice = Manager::input_num();
        switch (choice)
        {
        case 1: manager.Student_Login(); break;
        case 2: manager.Teacher_Login(); break;
        case 3: manager.Admin_Login(); break;
        case 0: std::cout << "Thanks for using!💕" << std::endl; return 0;
        default:
            std::cout << "Please input a reasonable number as above!\n";
            const int clean_window = 10;
            for (int i = 0; i < clean_window; i++)
            {
                std::cout << std::endl;
            }
            break;
        }
    }

    return 0;
}