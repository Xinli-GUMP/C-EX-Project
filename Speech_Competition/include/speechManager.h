#ifndef SPEECHMANAGER
#define SPEECHMANAGER
#include "file_operator.h"
#include "player.h"
#include <vector>

class Test;
class speechManager
{
    friend Test;
private:
    std::vector< Player > player_vector;
    std::vector< Player > GroupA;
    std::vector< Player > GroupB;
    std::vector< Player > GroupFinals;
    std::vector< Player > m_history_competition;
    file_operator fo;
public:
    void initialize_player_vector();
    static void show_Menu();
    static void show_player_info(const std::vector< Player > &player_vector);
    void divide_group();
    void start_competition();
    static void judge_scores(int progress,
                             std::vector< Player > &player_vector);

    void winner_display();
    void show_hist_comp();
    void clean_file();
    static void exit();
};
#endif