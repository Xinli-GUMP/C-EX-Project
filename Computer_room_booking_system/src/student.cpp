#include "student.h"
#include "manager.h"
#include "order.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::pmr::map;

Student::Student(int stu_id, std::string accout, std::string pwd)
{
    this->stu_id = stu_id;
    this->account = std::move(accout);
    this->pwd = std::move(pwd);
}

void Student::show_user_menu()
{
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|       1.Book room               |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|       2.My booking status       |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|       3.Check all booking       |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|       4.Cancle booking          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|       0.Logout                  |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "Please input function number: ";
}

void Student::orderable(int room_nums, std::vector< Order > &v_order)
{
    cout << "-----------Orderable Period List ↓-----------\n";
    for (int room_Id = 1; room_Id <= room_nums; room_Id++)
    {
        cout << "Computer Room -> " << room_Id << '\n';
        for (int weekday = 1; weekday <= static_cast< int >(Weekday::Friday);
             weekday++)
        {
            cout << Order::get_Weekday(static_cast< Weekday >(weekday))
                 << ":\n";
            for (int timeSlot = 1;
                 timeSlot <= static_cast< int >(TimeSlot::Night); timeSlot++)
            {
                bool orderable = true;
                for (const auto &ite : v_order)
                {
                    if (ite.room_Id == room_Id and ite.weekday == weekday and
                        ite.timeSlot == timeSlot and
                        ite.booking_status !=
                            static_cast< int >(Booking_status::Rejected))
                    {
                        orderable = false;
                        break;
                    }
                }
                if (orderable)
                {
                    cout << Order::getTimeSlotString(
                                static_cast< TimeSlot >(timeSlot))
                         << '\t';
                }
            }
            cout << '\n';
        }
    }
    cout << "-------------------------------------------------\n\n";
}

/**
 * @brief if this period already had a reservation return true
 *
 * @param room_Id
 * @param weekday
 * @param timeSlot
 * @param v_order
 * @return true
 * @return false
 */
auto Student::is_repeat(int room_Id, int weekday, int timeSlot,
                        std::vector< Order > &v_order) -> bool
{
    bool is_repeat = false;
    for (const auto &ite : v_order)
    {
        if (ite.room_Id == room_Id and ite.weekday == weekday and
            ite.timeSlot == timeSlot and
            ite.booking_status != static_cast< int >(Booking_status::Rejected))
        {
            is_repeat = true;
        }
    };
    return is_repeat;
}

// First check out alread existing orders to avoid repeat booking
auto Student::book_room(int room_nums, std::fstream &fs_order,
                        std::map< int, Order > &m_order) -> void
{
    std::vector< Order > v_order;
    if (not m_order.empty())
    {
        // copy order data from map into vector and print orderbale choice
        v_order.reserve(m_order.size());
        std::transform(m_order.begin(), m_order.end(),
                       std::back_inserter(v_order),
                       [](const std::pair< int, Order > &pair)
                       {
                           return pair.second;
                       });
        orderable(room_nums, v_order);
    } else
    {
        cout << "All period are free\n";
    }

    int room_Id = 0;
    int stu_Id = 0;
    std::string account;
    int weekday = 0;
    int timeSlot = 0;
    int booking_status = static_cast< int >(Booking_status::checking);
    int order_ID = 0;

    if (not m_order.empty())
    {
        // get the last order ID
        order_ID = std::prev(m_order.end())->first;
    }

    cout << "Which computer room would you booking?\n";
    cout << "1 -> Room 1 >> 50 computers\n";
    cout << "2 -> Room 2 >> 100 computers\n";
    cout << "3 -> Room 3 >> 200 computers\n";
    cout << "0 -> Return main menu\n";

    while (true)
    {
        room_Id = Manager::input_num();
        if (room_Id >= 1 and room_Id <= 3)
        {
            break;
        }
        if (room_Id == 0)
        {
            return;
        }
        cout
            << "Please input '1 ~ 3' for Room. Return Student menu press '0'\n";
    }

    cout << "Which day would you boooking?\n";
    cout << "1 -> Monday\n";
    cout << "2 -> Tuesday\n";
    cout << "3 -> Wednsday\n";
    cout << "4 -> Thursday\n";
    cout << "5 -> Friday\n";

    while (true)
    {
        weekday = Manager::input_num();
        if (weekday > 0 and weekday <= static_cast< int >(Weekday::Friday))
        {
            break;
        }
        if (weekday == 0)
        {
            return;
        }
        cout
            << "Please input '1 ~ 5' for weekday. Return Student menu press '0'\n";
    }

    cout << "Which period would you booking?\n";
    cout << "1 -> 8:30 - 10:00\n";
    cout << "2 -> 10:30 - 11:30\n";
    cout << "3 -> 14:00 - 15:30\n";
    cout << "4 -> 16:00 - 17:30\n";
    cout << "5 -> 19:00 - 21:00\n";

    while (true)
    {
        timeSlot = Manager::input_num();
        if (timeSlot > 0 and timeSlot <= static_cast< int >(TimeSlot::Night))
        {
            break;
        }
        if (timeSlot == 0)
        {
            return;
        }
        cout
            << "Please input '1 ~ 5' for period. Return student menu press '0'\n";
    }

    if (not v_order.empty())
    {
        if (is_repeat(room_Id, weekday, timeSlot, v_order))
        {
            cout << "There are already reservation during this period❌\n";
            return;
        }
    }

    Order_param order_param{
        .room_Id = room_Id,
        .stu_Id = this->stu_id,
        .account = this->account,
        .weekday = weekday,
        .timeSlot = timeSlot,
        .booking_status = booking_status,
    };
    order_ID++;
    m_order.emplace(
        order_ID,
        order_param);  // construct a order pair and push into order map
    fs_order << order_ID << ' ' << order_param.room_Id << ' '
             << order_param.stu_Id << ' ' << order_param.account << ' '
             << order_param.weekday << ' ' << order_param.timeSlot << ' '
             << order_param.booking_status << '\n';
    fs_order.flush();
    cout << "Order has already submite✅\nPlease wait for review\n";
}

void Student::show_order_info(const Order &order)
{
    cout << "--------------------------------------------------\n";
    cout << "Booker: " << order.account << " ID: " << order.stu_Id << '\n';
    cout << "Reserve Room-> " << order.room_Id << '\n';
    cout << "Reserve period: "
         << Order::get_Weekday(static_cast< Weekday >(order.weekday)) << ' '
         << Order::getTimeSlotString(static_cast< TimeSlot >(order.timeSlot))
         << '\n';
    cout << "Booking status: "
         << Order::get_BookingStatus(
                static_cast< Booking_status >(order.booking_status));
    cout << "---------------------------------------------\n\n";
}

/**
 * @brief Display current user's order info
 *
 * @param m_order
 */
void Student::check_booking_status(const std::map< int, Order > &m_order) const
{
    if (m_order.empty())
    {
        cout << "No order yet\n";
        return;
    }

    bool own_order = false;
    for (const auto &ite : m_order)
    {
        if (ite.second.stu_Id == this->stu_id)
        {
            own_order = true;
            cout << "Order ID: " << ite.first << '\n';
            show_order_info(ite.second);
        }
    };
    if (not own_order)
    {
        cout << "You haven't order yet\n";
    }
}

/**
 * @brief Display all order info
 *
 * @param m_order
 */
void Student::check_all_bookings(std::map< int, Order > &m_order)
{
    if (m_order.empty())
    {
        cout << "No order yet\n";
        return;
    }
    for (const auto &ite : m_order)
    {
        cout << "Order ID: " << ite.first << '\n';
        show_order_info(ite.second);
    };
}

void Student::cancel_booking(std::map< int, Order > &m_order,
                             std::fstream &fs_order) const
{
    bool have_order = false;
    for (auto &ite : m_order)
    {
        if (ite.second.stu_Id == this->stu_id)
        {
            cout << "Your order ID: " << ite.first << '\n';
            show_order_info(ite.second);
            have_order = true;
        }
    };
    if (have_order)
    {
        cout << "Which order would you cancel?\n";
        cout << "Order ID: ";
        int cancel_orderID = Manager::input_num();
        bool ownership = false;
        for (auto &ite : m_order)
        {
            if (ite.first == cancel_orderID and
                ite.second.stu_Id == this->stu_id)
            {
                ownership = true;
                m_order.erase(cancel_orderID);
                cout << "Cancel successfuly✅\n";
                break;
            }
        }

        // overwrite order file
        File_Operator::clean_file(fs_order, ORDER_FILE);
        for (auto &ite : m_order)
        {
            fs_order << ite.first << ' ' << ite.second.room_Id << ' '
                     << ite.second.stu_Id << ' ' << ite.second.account << ' '
                     << ite.second.weekday << ' ' << ite.second.timeSlot << ' '
                     << ite.second.booking_status << '\n';
            fs_order.flush();
        };

        if (not ownership)
        {
            cout << "You have no right to cancel this order❌\n";
        }
    } else
    {
        cout << "You haven't a order yet\n";
    }
}
