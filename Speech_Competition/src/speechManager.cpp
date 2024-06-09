#include "speechManager.h"
#include "myhead.hpp"
#include "player.h"
#include <algorithm>
#include <chrono>
#include <format>
#include <functional>
#include <iterator>
#include <thread>
#include <utility>
#include <vector>

void speechManager::initialize_player_vector()
{
    const int fist_player_id = 1001;
    const int last_player_id = 1012;
    for (auto i = fist_player_id; i <= last_player_id; i++)
    {
        player_vector.emplace_back(i);  // 调用Player的构造函数初始化选手信息
    };
}

void speechManager::show_Menu()
{
    std::cout << "********************************************" << std::endl;
    std::cout << "*************  欢迎参加演讲比赛 ************" << std::endl;
    std::cout << "*************  1.开始演讲比赛  *************" << std::endl;
    std::cout << "*************  2.查看往届记录  *************" << std::endl;
    std::cout << "*************  3.清空比赛记录  *************" << std::endl;
    std::cout << "*************  0.退出比赛程序  *************" << std::endl;
    std::cout << "********************************************" << std::endl;
    std::cout << std::endl;
}

void speechManager::show_player_info(const std::vector< Player > &player_vector)
{
    for (const auto &ite : player_vector)
    {
        std::cout
            << std::format(
                   "Name:{} NO:{} Partition time:{} first_score:{} Second score:{}",
                   ite.name, ite.serial_num, ite.participation_time,
                   ite.scores.first, ite.scores.second)
            << std::endl
            << std::endl;
    };
}

void speechManager::divide_group()
{
    for (const auto &ite : player_vector)
    {
        int groupA_num = 0;
        int groupB_num = 1;
        int lots = getRandomInt(
            groupA_num, groupB_num);  // draws a lots to decide which group
        const int group_size = 6;
        if (lots == groupA_num && GroupA.size() < group_size)
        {
            GroupA.push_back(ite);
        } else
        {
            GroupB.push_back(ite);
        }
    };
}

void speechManager::judge_scores(int progress,
                                 std::vector< Player > &player_vector)
{
    const float min_scores = 60.F;
    const float max_scores = 100.F;
    if (progress == 1)
    {
        for (auto &ite : player_vector)
        {
            ite.scores.first = getRandomFloat(min_scores, max_scores);
        };
    } else
    {
        for (auto &ite : player_vector)
        {
            ite.scores.second = getRandomFloat(min_scores, max_scores);
        };
    }
}

void speechManager::start_competition()
{
    initialize_player_vector();
    std::cout << "-----------Fisrt Speech Competition Start-------------"
              << std::endl;
    divide_group();  // randomly divide all player into group A and B
    for (int ite = 0; ite < 3; ite++)
    {
        // pause 3 second to simulate comptetition process
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Competition Continue·······" << std::endl;
    }
    // second judge scores for two group
    judge_scores(1, GroupA);
    judge_scores(1, GroupB);
    // use std::funciton to save a lambda expression
    std::function< bool(const Player &left, const Player &right) >
        compare_by_Fir_scores = [](const Player &left, const Player &right)
    {
        return left.scores.first > right.scores.first;  // decrease sort
    };

    std::sort(GroupA.begin(), GroupA.end(), compare_by_Fir_scores);
    std::sort(GroupB.begin(), GroupB.end(), compare_by_Fir_scores);
    std::cout << "First Speech Competition Finish" << std::endl;
    std::cout << "----------------ScoreBoard----------------" << std::endl;
    std::cout << "GroupA: " << std::endl;
    show_player_info(GroupA);
    std::cout << "GroupB: " << std::endl;
    show_player_info(GroupB);
    std::cout << "-------------------------------------------" << std::endl;
    int elimination = 3;
    for (auto ite = 0; ite < elimination; ite++)
    {  // eliminate 3 player in a group
        GroupA.pop_back();
        GroupB.pop_back();
    };
    // add top 3 to final group
    std::copy(GroupA.begin(), GroupA.end(), std::back_inserter(GroupFinals));
    std::copy(GroupB.begin(), GroupB.end(), std::back_inserter(GroupFinals));

    std::cout << "-----------final speech competition start-------------"
              << std::endl;
    for (int ite = 0; ite < 3; ite++)
    {
        // pause 3 second to simulate comptetition process
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "competition continue·······" << std::endl;
    }

    judge_scores(2, GroupFinals);
    for (auto &ite : GroupFinals)
    {
        ite.final_score = (ite.scores.first + ite.scores.second) / 2;
    }

    std::function< bool(const Player &left, const Player &right) >
        compare_by_Fin_scores = [](const Player &left, const Player &right)
    {
        return left.final_score > right.final_score;  // decrease sort
    };
    std::sort(GroupFinals.begin(), GroupFinals.end(), compare_by_Fin_scores);
    std::cout << "Final Speech Competition Finish" << std::endl;
    std::cout << "----------------ScoreBoard----------------" << std::endl;
    std::cout << "GroupFinals: " << std::endl;
    show_player_info(GroupFinals);
    std::cout << "-------------------------------------------" << std::endl;

    for (auto ite = 0; ite < elimination; ite++)
    {
        GroupFinals.pop_back();
    };
    std::cout << "✨✨✨✨✨✨Congratulations!✨✨✨✨✨✨" << std::endl;
    show_player_info(GroupFinals);
    // write data into file
    fo.write_csv(GroupFinals);
    m_history_competition.insert(m_history_competition.end(),
                                 GroupFinals.begin(), GroupFinals.end());
    // reset container
    player_vector.clear();
    GroupA.clear();
    GroupB.clear();
    GroupFinals.clear();
}

void speechManager::winner_display()
{
    int term_count = 0;
    for (auto &ite : m_history_competition)
    {
        // 3 winner per term
        if (term_count == 0 || term_count % 3 == 0 && term_count >= 3)
        {
            std::cout << "-------" << intToOrdinal(term_count / 3 + 1)
                      << " Term Speech Competition Winner------\n";
        }
        if (term_count == 0 || term_count % 3 == 0 && term_count >= 3)
        {
            std::cout << "The Champion: " << ite.name << ' ' << ite.final_score
                      << ' ' << ite.serial_num << ' ' << ite.participation_time
                      << std::endl;
            term_count++;
        } else if (term_count == 1 || term_count % 3 == 1 && term_count > 3)
        {
            std::cout << "The Runner: " << ite.name << ' ' << ite.final_score
                      << ' ' << ite.serial_num << ' ' << ite.participation_time
                      << std::endl;
            term_count++;
        } else
        {
            std::cout << "Second Runner: " << ite.name << ' ' << ite.final_score
                      << ' ' << ite.serial_num << ' ' << ite.participation_time
                      << std::endl
                      << std::endl;
            term_count++;
        }
    }
    std::cout << endl;
}
void speechManager::show_hist_comp()
{
    // fist read data in class Manager. if there are no data, then read csv
    // file
    if (!m_history_competition.empty())
    {
        winner_display();
    } else
    {
        // judge if csv file is empty
        if (auto optional_csv_data = fo.read_csv();
            optional_csv_data.has_value())
        {
            m_history_competition = optional_csv_data.value();
            winner_display();
        } else
        {
            std::cout << "No Record Yet\n";
            return;
        }
    }
}

void speechManager::clean_file()
{
    fo.clean_file();
    m_history_competition.clear();
}
void speechManager::exit()
{
    cout << "感谢使用!😘" << std::endl;
}
