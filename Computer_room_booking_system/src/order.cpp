#include "order.h"

Order::Order(Order_param &order_param)
{
    this->stu_Id = order_param.stu_Id;
    this->room_Id = order_param.room_Id;
    this->account = order_param.account;
    this->weekday = order_param.weekday;
    this->timeSlot = order_param.timeSlot;
    this->booking_status = order_param.booking_status;
}

auto Order::get_Weekday(Weekday weekday) -> std::string
{
    switch (weekday)
    {
    case Weekday::Monday: return "Monday";
    case Weekday::Tuesday: return "Tuesday";
    case Weekday::Wednesday: return "Wednesday";
    case Weekday::Thursday: return "Thursday";
    case Weekday::Friday: return "Friday";
    default: return "Unkown Day";
    }
}

auto Order::getTimeSlotString(TimeSlot slot) -> std::string
{
    switch (slot)
    {
    case TimeSlot::Morning1: return "8:30 - 10:00";
    case TimeSlot::Morning2: return "10:30 - 11:30";
    case TimeSlot::Afternoon1: return "14:00 - 15:30";
    case TimeSlot::Afternoon2: return "16:00 - 17:30";
    case TimeSlot::Night: return "19:00 - 21:00";
    default: return "Unknown TimeSlot";
    }
}

auto Order::get_BookingStatus(Booking_status booking_status) -> std::string
{
    switch (booking_status)
    {
    case Booking_status::checking: return "Booking is checking🔔\n";
    case Booking_status::Rejected: return "Booking is rejected❌\n";
    case Booking_status::successful: return "Booking is successful✅\n";
    default: return "Unkown Booking\n";
    };
}