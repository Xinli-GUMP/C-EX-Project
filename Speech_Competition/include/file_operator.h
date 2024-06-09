#ifndef FILE_OPERATOR
#define FILE_OPERATOR

#include "player.h"
#include <cstdio>
#include <fstream>
#include <optional>
#include <vector>
#define FILE_PATH "../../data/"
class file_operator
{
private:
    std::fstream fst;
    bool is_exist;
    std::vector< Player > history_competition;
public:
    file_operator();
    ~file_operator();
    void write_csv(const std::vector< Player > &GroupFinals);
    auto read_csv() -> std::optional< decltype(history_competition) >;
    void clean_file();
};

#endif /* FILE_OPERATOR */
