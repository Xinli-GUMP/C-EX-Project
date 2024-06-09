#include "manager.h"
#include "admin.h"
#include "identity.h"
#include "order.h"
#include "student.h"
#include "teacher.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>

void Manager::show_main_menu()
{
    std::cout
        << "====================== Welcome to Computer Room Booking System =====================\n";
    std::cout << "\t\t --------------------------------\n";
    std::cout << "\t\t|                               |\n";
    std::cout << "\t\t|          1.Monitor            |\n";
    std::cout << "\t\t|                               |\n";
    std::cout << "\t\t|          2.Teacher            |\n";
    std::cout << "\t\t|                               |\n";
    std::cout << "\t\t|          3.Admin              |\n";
    std::cout << "\t\t|                               |\n";
    std::cout << "\t\t|          0.Exit               |\n";
    std::cout << "\t\t|                               |\n";
    std::cout << "\t\t -------------------------------\n";
    std::cout << std::endl << "Please enter your identity:\n";
}

auto Manager::input_num() -> int
{
    int num = 0;
    std::cout << "-> ";
    while (!static_cast< bool >(std::cin >> num))
    {
        std::cin.clear();
        std::cin.ignore(sizeof(std::string), '\n');
        std::cout << "Error input, try again: ";
    }
    // std::cout << '\n';
    return num;
}

auto Manager::check_identity(int identity_type, int &m_id, std::string &account,
                             std::string &pwd) const -> bool
{
    bool identity_exist = false;

    if (identity_type == 1)
    {
        for (const auto &ite : file_operator.v_student)
        {
            if (ite.stu_id == m_id and ite.account == account and
                ite.pwd == pwd)
            {
                identity_exist = true;
                return identity_exist;
            }
        };
    }
    if (identity_type == 2)
    {
        for (const auto &ite : file_operator.v_teacher)
        {
            if (ite.teacher_id == m_id and ite.account == account and
                ite.pwd == pwd)
            {
                identity_exist = true;
                return identity_exist;
            }
        };
    }
    if (identity_type == 3)
    {
        for (const auto &ite : file_operator.v_admin)
        {
            if (ite.admin_id == m_id and ite.account == account and
                ite.pwd == pwd)
            {
                identity_exist = true;
                return identity_exist;
            }
        };
    }
    std::cout << "\nIdentity check failed, please try agagin!❌\n";
    return identity_exist;
}

void Manager::Student_Login()
{
    int stu_id;
    std::string account;
    std::string pwd;

    int count = 0;
    int max_errors = 3;
    while (count < max_errors)
    {
        count++;
        std::cout << "Please input Student ID: ";
        stu_id = input_num();
        std::cout << "Please input Account: ";
        std::cin >> account;
        std::cout << "Please input Password: ";
        std::cin >> pwd;
        if (check_identity(1, stu_id, account, pwd))
        {
            identity = std::make_unique< Student >(stu_id, account, pwd);
            std::cout << "\nIdentity check out✅\n\n\t\tWelcome Student "
                      << identity->account << std::endl;

            student_manager_menu(identity);
            return;
        }

        std::cout << "Maybe your select a incorrect identity?\n";
    }
}

void Manager::Teacher_Login()
{
    int teacher_id;
    std::string account;
    std::string pwd;

    int count = 0;
    int max_errors = 3;
    while (count < max_errors)
    {
        count++;
        std::cout << "Please input Teacher ID: ";
        teacher_id = input_num();
        std::cout << "Please input Account: ";
        std::cin >> account;
        std::cout << "Please input Password: ";
        std::cin >> pwd;
        if (check_identity(2, teacher_id, account, pwd))
        {
            identity = std::make_unique< Teacher >(teacher_id, account, pwd);
            std::cout << "\nIdentity check out✅\n\n\t\tWelcome Teacher "
                      << identity->account << std::endl;

            teacher_manager_menu(identity);
            return;
        }
    }
    std::cout << "Maybe your select a incorrect identity?\n";
}

void Manager::Admin_Login()
{
    int admin_id;
    std::string account;
    std::string pwd;

    int count = 0;
    int max_errors = 3;
    while (count < max_errors)
    {
        count++;
        std::cout << "Please input Admin ID: ";
        admin_id = input_num();
        std::cout << "Please input Account: ";
        std::cin >> account;
        std::cout << "Please input Password: ";
        std::cin >> pwd;
        if (check_identity(3, admin_id, account, pwd))
        {
            identity = std::make_unique< Admin >(admin_id, account, pwd);
            std::cout << "\nIdentity check out✅\n"
                      << "\t\t\tWelcome Admin " << identity->account
                      << std::endl;

            admin_manager_menu(identity);
            return;
        }
    }
    std::cout << "Maybe your select a incorrect identity?\n";
}

void Manager::admin_manager_menu(std::unique_ptr< Identity > &identity_ptr)
{
    // force conversion identity_ptr to admin_ptr to use admin function only.
    // first get raw_ptr and then release ownership to realize
    // ownership from a  smart ptr to another
    std::unique_ptr< Admin > admin_ptr(
        dynamic_cast< Admin * >(identity_ptr.release()));

    enum class Admin_functions : int
    {
        logOut,
        add_account,
        delete_account,
        lookOver_accounts,
        lookOver_rooms,
        clean_bookings
    };

    while (true)
    {
        admin_ptr->show_user_menu();
        int choice = input_num();
        // force conversion enum class to avoid use migic numbers
        switch (static_cast< Admin_functions >(choice))
        {
        case Admin_functions::add_account:
            admin_ptr->add_account(
                file_operator.fs_stu, file_operator.v_student,
                file_operator.fs_techer, file_operator.v_teacher);
            break;
        case Admin_functions::delete_account:
            admin_ptr->delete_account(
                file_operator.fs_stu, file_operator.v_student,
                file_operator.fs_techer, file_operator.v_teacher);
            break;
        case Admin_functions::lookOver_accounts:
            admin_ptr->lookOver_accounts(file_operator.v_student,
                                         file_operator.v_teacher);
            break;
        case Admin_functions::lookOver_rooms:
            admin_ptr->lookOver_rooms(file_operator.m_room);
            break;
        case Admin_functions::clean_bookings:
            admin_ptr->clean_bookings(file_operator.m_Order,
                                      file_operator.fs_room);
            break;
        case Admin_functions::logOut:
            std::cout << "\nAdmin " << admin_ptr->account
                      << " Logout -> return main menu\n\n";
            return;
        default: std::cout << "Error function number!\n"; break;
        }
    }
}

void Manager::student_manager_menu(std::unique_ptr< Identity > &identity_ptr)
{
    std::unique_ptr< Student > stu_ptr(
        dynamic_cast< Student * >(identity_ptr.release()));

    enum class Student_function
    {
        logOut,
        book_room,
        check_booking_status,
        check_all_booking,
        cancel_booking,
    };

    while (true)
    {
        stu_ptr->show_user_menu();
        int choice = input_num();
        switch (static_cast< Student_function >(choice))
        {
        case Student_function::book_room:
            stu_ptr->book_room(static_cast< int >(file_operator.m_room.size()),
                               file_operator.fs_order, file_operator.m_Order);

            break;
        case Student_function::check_booking_status:
            stu_ptr->check_booking_status(file_operator.m_Order);
            break;
        case Student_function::check_all_booking:
            stu_ptr->check_all_bookings(file_operator.m_Order);
            break;
        case Student_function::cancel_booking:
            stu_ptr->cancel_booking(file_operator.m_Order,
                                    file_operator.fs_order);
            break;
        case Student_function::logOut:
            std::cout << "\tStudent " << stu_ptr->account
                      << " Logout -> return main menu\n\n";
            return;
        default: std::cout << "Error function number!\n"; break;
        }
    }
}

void Manager::teacher_manager_menu(std::unique_ptr< Identity > &identity_ptr)
{
    std::unique_ptr< Teacher > teacher_ptr(
        dynamic_cast< Teacher * >(identity_ptr.release()));

    enum class teacher_function
    {
        logOut,
        check_all_booking,
        review_bookings,
    };

    while (true)
    {
        teacher_ptr->show_user_menu();
        int choice = input_num();
        switch (static_cast< teacher_function >(choice))
        {
        case teacher_function::check_all_booking:
            teacher_ptr->check_all_bookings(file_operator.m_Order);
            break;
        case teacher_function::review_bookings:
            teacher_ptr->review_bookings(file_operator.m_Order,
                                         file_operator.fs_order);
            break;
        case teacher_function::logOut:
            std::cout << "\tTeacher " << teacher_ptr->account
                      << " Logout -> return main menu\n\n";
            return;
        default: std::cout << "Error function number!\n"; break;
        }
    }
}