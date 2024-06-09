#ifndef PLAYER
#define PLAYER
#include "myhead.hpp"
#include <utility>

class Test;
class file_operator;
class speechManager;
class Player
{
    friend Test;
    friend file_operator;
    friend speechManager;
private:
    std::string name;
    int serial_num;
    std::string participation_time;
    std::pair< float, float > scores;
    float final_score;
public:  // 单个参数的构造函数需要使用explicit防止隐式转换, 例如说 Player
         // player(12.3), 这样不好。
    explicit Player(int serial_num)
    {
        this->name = getRandomName();
        this->participation_time = get_currentTime();
        this->serial_num = serial_num;
        scores = {0, 0};
        final_score = 0;
    };
    Player(string &name, int &serial_num, string &time, float &final_score)
    {
        this->name = name;
        this->serial_num = serial_num;
        this->participation_time = time;
        this->scores = {0, 0};
        this->final_score = final_score;
    }
};

#endif /* PLAYER */