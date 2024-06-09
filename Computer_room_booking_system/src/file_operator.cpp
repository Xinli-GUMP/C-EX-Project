#include "file_operator.h"
#include "order.h"
#include <filesystem>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

File_Operator::File_Operator()
{
    if (!std::filesystem::exists(DATA_DIR))
    {
        std::filesystem::create_directory(DATA_DIR);
    }
    fs_admin.open(ADMIN_FILE, std::ios::out | std::ios::in | std::ios::app);
    fs_stu.open(STUDENT_FILE, std::ios::out | std::ios::in | std::ios::app);
    fs_techer.open(TEACHER_FILE, std::ios::out | std::ios::in | std::ios::app);
    fs_room.open(ROOM_FILE, std::ios::out | std::ios::in | std::ios::app);
    fs_order.open(ORDER_FILE, std::ios::out | std::ios::in | std::ios::app);
    int sys_ID = 0;
    std::string sys_Account("Alice");
    std::string sys_pwd("36149");
    v_admin.emplace_back(sys_ID, sys_Account, sys_pwd);

    read_data();
}

File_Operator::~File_Operator()
{
    fs_admin.close();
    fs_stu.close();
    fs_techer.close();
    fs_room.close();
    fs_order.close();
    // std::cout << "Files closed\n";
}

/**
 * @brief read  data and construct containers
 *
 */
void File_Operator::read_data()
{
    read_admin_data();
    read_stu_data();
    read_teacher_data();
    read_room_data();
    read_order_data();
}

void File_Operator::read_stu_data()
{
    if (std::filesystem::file_size(STUDENT_FILE) !=
        0U)  // 0U 是无符号整形, 用于防止隐式转换
    {
        int m_id;
        std::string account;
        std::string pwd;
        std::string line;
        while (std::getline(fs_stu, line))
        {
            std::istringstream iss(line);
            if (iss >> m_id >> account >> pwd)
            {
                v_student.emplace_back(m_id, account,
                                       File_Operator::hexToString(pwd));
            } else
            {
                std::cout << "Student account data Parse error\n";
                iss.clear();
            }
        }
        fs_stu.clear();  // Reading all lines cause file_status becoming EOF.
                         // Explicitly call fstream.clear() to let fill can be
                         // written continuously
    }
}

void File_Operator::read_teacher_data()
{
    if (std::filesystem::file_size(TEACHER_FILE) !=
        0U)  // 0U 是无符号整形, 用于防止隐式转换
    {
        int m_id;
        std::string account;
        std::string pwd;
        std::string line;
        while (std::getline(fs_techer, line))
        {
            std::istringstream iss(line);
            if (iss >> m_id >> account >> pwd)
            {
                v_teacher.emplace_back(m_id, account,
                                       File_Operator::hexToString(pwd));
            } else
            {
                std::cout << "Teacher account data Parse error\n";
                iss.clear();
            }
        }
        fs_techer.clear();
    }
}

void File_Operator::read_admin_data()
{
    if (std::filesystem::file_size(ADMIN_FILE) !=
        0U)  // 0U 是无符号整形, 用于防止隐式转换
    {
        int m_id;
        std::string account;
        std::string pwd;
        std::string line;
        while (std::getline(fs_admin, line))
        {
            std::istringstream iss(line);
            if (iss >> m_id >> account >> pwd)
            {
                v_admin.emplace_back(m_id, account,
                                     File_Operator::hexToString(pwd));
            } else
            {
                std::cout << "Admin account data Parse error\n";
                iss.clear();
            }
        }
    }
}

void File_Operator::read_room_data()
{
    if (std::filesystem::file_size(ROOM_FILE) != 0U)
    {
        int roomID = 0;
        int computer_nums = 0;
        // use operator >> to read data. The advantage is simple but the
        // disadvantages are if having errors in the half of reading, reading
        // process will pause result in reading unfinished and you can't modify
        // contents too.
        while (fs_room >> roomID >> computer_nums)
        {
            m_room.emplace(roomID, computer_nums);
        }
    }
}

void File_Operator::read_order_data()
{
    if (std::filesystem::file_size(ORDER_FILE) != 0U)
    {
        int order_ID = 0;
        int room_ID = 0;
        int stu_ID = 0;
        std::string account;
        int weekday = 0;
        int timeSlot = 0;
        int booking_status = 0;

        std::string line;
        while (std::getline(fs_order, line))
        {
            std::istringstream iss(line);
            if (iss >> order_ID >> room_ID >> stu_ID >> account >> weekday >>
                timeSlot >> booking_status)
            {
                Order_param order_param{.room_Id = room_ID,
                                        .stu_Id = stu_ID,
                                        .account = account,
                                        .weekday = weekday,
                                        .timeSlot = timeSlot,
                                        .booking_status = booking_status};
                m_Order.emplace(order_ID, order_param);
            } else
            {
                std::cout << "Order data prase error\n";
                iss.clear();
            }
        }
        /*   // 检查流的状态
          if (fs_order.eof())
          {
              std::cout << "到达文件末尾。" << std::endl;
          } else if (fs_order.fail())
          {
              std::cerr << "读取失败。" << std::endl;
          } else if (fs_order.bad())
          {
              std::cerr << "不可恢复的错误。" << std::endl;
          } */
        fs_order.clear();
    }
}

void File_Operator::clean_file(std::fstream &fst, const std::string &file_path)
{
    if (not fst.is_open())
    {
        fst.open(file_path, std::ios::out | std::ios::trunc);
    } else
    {
        fst.close();
        fst.open(file_path, std::ios::out | std::ios::trunc);
    }
}

// 将字符串转换为十六进制加密密码
// 字符 '1' 的 ASCII 值是 49。
// 49 的十六进制表示是 0x31
auto File_Operator::stringToHex(const std::string &input) -> std::string
{
    std::stringstream hexStream;
    hexStream << std::hex << std::setfill('0');
    for (unsigned char per_c : input)
    {
        hexStream << std::setw(2) << static_cast< int >(per_c);
    }
    return hexStream.str();
}

// 将十六进制字符串转换回原始字符串
auto File_Operator::hexToString(const std::string &hexInput) -> std::string
{
    if (hexInput.length() % 2 != 0)
    {
        // 十六进制输入应该是偶数长度
        throw std::runtime_error("Invalid input length for password string.");
    }
    std::string output;
    size_t len = hexInput.length();

    const int num_base{16};
    for (size_t i = 0; i < len; i += 2)
    {
        std::string byteString = hexInput.substr(i, 2);
        char byte =
            static_cast< char >(std::stoi(byteString, nullptr, num_base));
        output.push_back(byte);
    }
    return output;
}
