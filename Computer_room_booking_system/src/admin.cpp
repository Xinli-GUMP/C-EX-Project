#include "admin.h"
#include "file_operator.h"
#include "manager.h"
#include "teacher.h"
#include <algorithm>
#include <format>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;

Admin::Admin(int admin_id, std::string &account, const std::string &pwd)
{
    this->admin_id = admin_id;
    this->account = account;
    this->pwd = pwd;
}

void Admin::show_user_menu()
{
    cout << "\t\t-------------------------------\n";
    cout << "\t\t|                             |\n";
    cout << "\t\t|       1.Add account         |\n";
    cout << "\t\t|                             |\n";
    cout << "\t\t|       2.Delete account      |\n";
    cout << "\t\t|                             |\n";
    cout << "\t\t|       3.Look over accounts  |\n";
    cout << "\t\t|                             |\n";
    cout << "\t\t|       4.Look over rooms     |\n";
    cout << "\t\t|                             |\n";
    cout << "\t\t|       5.Clean bookings      |\n";
    cout << "\t\t|                             |\n";
    cout << "\t\t|       0.Logout              |\n";
    cout << "\t\t|                             |\n";
    cout << "\t\t-------------------------------\n";
    cout << "Please select function nums： ";
}

void Admin::add_account(std::fstream &fs_stu, std::vector< Student > &v_stu,
                        std::fstream &fs_teacher,
                        std::vector< Teacher > &v_teacher)
{
    int m_id = 0;
    std::string account;
    std::string pwd;
    cout << "Whice account type you want to add?\n"
         << "1. Student  2.Teacher\n";
    int choice = Manager::input_num();
    if (choice == 1)
    {
        bool is_repeat = true;
        while (is_repeat)  // check repeat
        {
            cout << "Please input student id: ";
            m_id = Manager::input_num();
            for (const auto &ite : v_stu)
            {
                if (ite.stu_id == m_id)
                {
                    cout << std::format("ID {} is already exist❌\n", m_id);
                    break;  // has repeat, break for loop
                            // and input id again
                }
                is_repeat = false;
            };

            if (v_stu.empty())
            {
                is_repeat = false;
            }
        }
        cout << "Please input account: ";
        cin >> account;
        cout << "Please input password: ";
        cin >> pwd;
        v_stu.emplace_back(m_id, account, pwd);
        fs_stu << m_id << ' ' << account << ' '
               << File_Operator::stringToHex(pwd) << '\n';
        fs_stu.flush();  // forece push the fstream cache into file
        cout << "Add successful✅\n\n";
    }

    if (choice == 2)
    {
        bool is_repeat = true;
        while (is_repeat)  // check repeat
        {
            cout << "Please input teacher id: ";
            m_id = Manager::input_num();

            // traverse teacher vector by find_if, obviously, it's more simple
            // than using for loop
            auto repeat_id_ite =
                std::find_if(v_teacher.begin(), v_teacher.end(),
                             [m_id](Teacher &teacher) -> bool
                             {
                                 return teacher.teacher_id == m_id;
                             });
            if (repeat_id_ite != v_teacher.end())
            {
                cout << std::format("ID {} is already exist❌\n", m_id);
                continue;  // has repeat
            }
            is_repeat = false;
        }
        cout << "Please input account :";
        cin >> account;
        cout << "Please input password: ";
        cin >> pwd;
        v_teacher.emplace_back(m_id, account, pwd);
        fs_teacher << m_id << ' ' << account << ' '
                   << File_Operator::stringToHex(pwd) << '\n';
        fs_teacher.flush();  // 强制将缓冲区中的数据写入磁盘
        cout << "Add successful✅\n\n";
    }
}

void Admin::delete_account(std::fstream &fs_stu, std::vector< Student > &v_stu,
                           std::fstream &fs_teacher,
                           std::vector< Teacher > &v_teacher)
{
    cout
        << "Please input type num which you want to delete(1. Student 2.Teacher): ";
    int type_num = Manager::input_num();
    if (type_num == 1)
    {
        cout << "Please input the student ID which will be deleted: ";
        int deleted_id = Manager::input_num();
        auto ite = find_if(v_stu.begin(), v_stu.end(),
                           [deleted_id](const Student &stu)
                           {
                               return stu.stu_id == deleted_id;
                           });
        if (ite == v_stu.end())
        {
            cout
                << "Not found the student id, maybe you input a wrong number\n";
            return;
        }
        v_stu.erase(ite);
        if (fs_stu.is_open())  // overwrite data to realize delete operation
        {
            fs_stu.close();
            fs_stu.open(STUDENT_FILE,
                        std::ios::out | std::ios::in | std::ios::trunc);
            for (const auto &ite : v_stu)
            {
                fs_stu << ite.stu_id << ' ' << ite.account << ' '
                       << File_Operator::stringToHex(ite.pwd) << '\n';
            };
            fs_stu.flush();
            cout << "Delete successful\n";
        }
    }

    if (type_num == 2)
    {
        cout
            << "Please input type num which you want to delete(1. Student 2.Teacher): ";
        int deleted_id = Manager::input_num();
        auto ite = find_if(v_teacher.begin(), v_teacher.end(),
                           [deleted_id](const Teacher &teacher)
                           {
                               return teacher.teacher_id == deleted_id;
                           });
        if (ite == v_teacher.end())
        {
            cout
                << "Not found the teacher id, maybe you input a wrong number\n";
            return;
        }
        v_teacher.erase(ite);
        if (fs_teacher.is_open())  // overwrite data to realize delete operation
        {
            fs_teacher.close();
            fs_teacher.open(TEACHER_FILE,
                            std::ios::out | std::ios::in | std::ios::trunc);
            for (const auto &ite : v_teacher)
            {
                fs_teacher << ite.teacher_id << ' ' << ite.account << ' '
                           << File_Operator::stringToHex(ite.pwd) << '\n';
            };
            fs_teacher.flush();
        }
    }
}

void Admin::lookOver_accounts(std::vector< Student > &v_stu,
                              std::vector< Teacher > &v_teacher)
{
    cout << "Whice account type you want to look over?\n"
         << "1. Student  2.Teacher\n";
    int choice = Manager::input_num();
    if (choice == 1)
    {
        if (v_stu.empty())
        {
            cout << "No account yet\n";
            return;
        }
        for (auto const &ite : v_stu)
        {
            cout << std::format("ID: {}\tAccount: {}\tPassword: {}\n\n",
                                ite.stu_id, ite.account, ite.pwd);
        };
    }

    else if (choice == 2)
    {
        if (v_stu.empty())
        {
            cout << "No account yet\n";
            return;
        }
        for (auto const &ite : v_teacher)
        {
            cout << std::format("ID: {}\tAccount: {}\tPassword: {}\n\n",
                                ite.teacher_id, ite.account, ite.pwd);
        };
    } else
    {
        cout << "Please input reasonable number\n";
    }
}

void Admin::lookOver_rooms(std::map< int, int > &m_room)
{
    cout << "\n\t\tComputer Rooms\t\t\n";
    for (auto const &ite : m_room)
    {
        cout << std::format("Room ID: {0}\tComputer numbers {1}\n", ite.first,
                            ite.second);
    }
}

void Admin::clean_bookings(std::map< int, Order > &m_order,
                           std::fstream &fs_order)
{
    if (m_order.empty())
    {
        cout << "There are no orders right now\n";
        return;
    }

    m_order.clear();
    if (fs_order.is_open())
    {
        fs_order.close();
        fs_order.open(ORDER_FILE, std::ios::out | std::ios::trunc);
        cout << "All bookings are deleted\n";
    } else
    {
        fs_order.open(ORDER_FILE, std::ios::out | std::ios::trunc);
    }
}