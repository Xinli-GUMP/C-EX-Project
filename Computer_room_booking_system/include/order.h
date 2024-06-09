#ifndef ORDER
#define ORDER

#include <string>

enum class Weekday
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
};

enum class TimeSlot
{
    Morning1 = 1,  // 8:30 - 10:00
    Morning2,      // 10:30 - 11:30
    Afternoon1,    // 14:00 - 15:30
    Afternoon2,    // 16:00 - 17:30
    Night,         // 19:00 - 21:00
};

enum class Booking_status
{
    checking,
    successful,
    Rejected,
};

struct Order_param
{
    int room_Id;
    int stu_Id;
    std::string account;
    int weekday;
    int timeSlot;
    int booking_status;
};

class Student;
class Teacher;
class Order
{
    friend Student;
    friend Teacher;
private:
    int room_Id;
    int stu_Id;
    std::string account;
    int weekday;
    int timeSlot;
    int booking_status;
public:
    explicit Order(Order_param &order_param);
    static auto get_Weekday(Weekday weekday) -> std::string;
    static auto getTimeSlotString(TimeSlot slot) -> std::string;
    static auto get_BookingStatus(Booking_status booking_status) -> std::string;
};

#endif /* ORDER */
