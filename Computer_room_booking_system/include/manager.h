#ifndef MANAGER
#define MANAGER
#include "file_operator.h"
#include "identity.h"
#include <memory>
#include <string>

class Manager
{
private:
    File_Operator file_operator;
    std::unique_ptr< Identity > identity;
public:
    Manager() = default;
    static void show_main_menu();
    static auto input_num() -> int;
    auto check_identity(int identity_type, int &m_id, std::string &account,
                        std::string &pwd) const -> bool;
    void Student_Login();
    void Teacher_Login();
    void Admin_Login();
    void admin_manager_menu(std::unique_ptr< Identity > &identity_ptr);
    void student_manager_menu(std::unique_ptr< Identity > &identity_ptr);
    void teacher_manager_menu(std::unique_ptr< Identity > &identity_ptr);
};

#endif /* MANAGER */
