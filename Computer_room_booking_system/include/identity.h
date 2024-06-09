#ifndef IDENTITY
#define IDENTITY
#include <string>

class Manager;
class Identity
{
    friend Manager;
protected:
    std::string account;
    std::string pwd;
public:
    virtual void show_user_menu() = 0;
};

#endif /* IDENTITY */
