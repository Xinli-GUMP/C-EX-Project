#include "teacher.h"
#include "file_operator.h"
#include "manager.h"
#include "order.h"
#include "student.h"
#include <iostream>
#include <string>

using std::cout;
Teacher::Teacher(int teacher_id, std::string account, std::string pwd)
{
    this->teacher_id = teacher_id;
    this->account = std::move(account);
    this->pwd = std::move(pwd);
}

void Teacher::show_user_menu()
{
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|       1. Check all bookings   |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|       2. Review bookings      |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|       0. Logout               |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
    cout << "Please input funciton numbers：";
    cout << '\n';
}

void Teacher::check_all_bookings(std::map< int, Order > &m_order)
{
    Student::check_all_bookings(m_order);
}

void Teacher::change_booking_status(Order &order)
{
    cout << "Choose a status number ↓\n";
    cout << "1. Pass  2. Reject  3. Skip\n";

    int choice = Manager::input_num();
    if (choice == 1)
    {
        order.booking_status = static_cast< int >(Booking_status::successful);
        cout << "Order Pass✅\n";
    } else if (choice == 2)
    {
        order.booking_status = static_cast< int >(Booking_status::Rejected);
        cout << "Order Reject❌\n";
    } else
    {
        cout << "Skip🔔\n";
    }
}

void Teacher::review_bookings(std::map< int, Order > &m_order,
                              std::fstream &fs_order)
{
    cout << "Please choose a review mode ↓\n";
    cout << "1. Order by Order\t2. By order ID\t3. Exit\nMode: ";
    int choice = Manager::input_num();
    if (choice == 1)
    {
        for (auto &ite : m_order)
        {
            if (ite.second.booking_status ==
                static_cast< int >(Booking_status::checking))
            {
                cout << "Order: " << ite.first << '\n';
                Student::show_order_info(ite.second);
                change_booking_status(ite.second);
            }
        };
    } else if (choice == 2)
    {
        cout << "Which order ID would you review?\n";
        int orderID = Manager::input_num();
        for (auto &ite : m_order)
        {
            if (orderID == ite.first)
            {
                Student::show_order_info(ite.second);
                change_booking_status(ite.second);
                break;
            }
        }
    } else
    {
        return;
    }
    // overwrite file data
    File_Operator::clean_file(fs_order, ORDER_FILE);
    for (auto &ite : m_order)
    {
        fs_order << ite.first << ' ' << ite.second.room_Id << ' '
                 << ite.second.stu_Id << ' ' << ite.second.account << ' '
                 << ite.second.weekday << ' ' << ite.second.timeSlot << ' '
                 << ite.second.booking_status << '\n';
        fs_order.flush();
    };
}
