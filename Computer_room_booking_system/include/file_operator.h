#ifndef FILE_OPERATOR
#define FILE_OPERATOR

#include "admin.h"
#include "order.h"
#include "student.h"
#include "teacher.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>

#define DATA_DIR     "../../data"
#define ADMIN_FILE   "../../data/admin.txt"
#define STUDENT_FILE "../../data/student.txt"
#define TEACHER_FILE "../../data/teacher.txt"
#define ROOM_FILE    "../../data/computerRoom.txt"
#define ORDER_FILE   "../../data/order.txt"

class Manager;
class File_Operator
{
    friend Manager;
private:
    std::fstream fs_admin;
    std::fstream fs_stu;
    std::fstream fs_techer;
    std::fstream fs_room;
    std::fstream fs_order;
    std::vector< Admin > v_admin;
    std::vector< Student > v_student;
    std::vector< Teacher > v_teacher;
    std::map< int, int > m_room;
    std::map< int /*Order_id*/, Order > m_Order;
public:
    File_Operator();
    ~File_Operator();
    void read_data();
    void read_stu_data();
    void read_teacher_data();
    void read_admin_data();
    void read_room_data();
    void read_order_data();
    static void clean_file(std::fstream &fst, const std::string &file_path);
    static auto stringToHex(const std::string &input) -> std::string;
    static auto hexToString(const std::string &hexInput) -> std::string;
};

#endif /* FILE_OPERATOR */
