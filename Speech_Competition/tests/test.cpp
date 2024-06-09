#include "file_operator.h"
#include "myhead.hpp"
#include "speechManager.h"

class Test
{
public:
   /*  speechManager spm;

    void test1()
    {
        for (auto &ite : spm.player_vector)
        {
            std::cout << ite.name << " " << ite.participation_time << " "
                      << ite.serial_num << " " << ite.final_score << endl;
        };
    }

    void test2()
    {
        spm.divide_group();
        cout << "---------------A------------------" << endl;
        for (auto &ite : spm.GroupA)
        {
            std::cout << ite.name << " " << ite.participation_time << " "
                      << ite.serial_num << " " << ite.final_score << endl;
        };
        cout << "---------------B------------------" << endl;
        for (auto &ite : spm.GroupB)
        {
            std::cout << ite.name << " " << ite.participation_time << " "
                      << ite.serial_num << " " << ite.final_score << endl;
        };
    }
    void test3()
    {
        spm.start_competition();
    } */

    void test4()
    {
        file_operator file_test;
        file_test.read_csv();
        
    }
};

auto main() -> int
{
    Test test;
    // test.test2();
    // test.test3();
    test.test4();
    return 0;
}