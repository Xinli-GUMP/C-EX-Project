#include "file_operator.h"
#include <filesystem>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

file_operator::file_operator()
{
    namespace fs = std::filesystem;  // 给filesysyem命名空间取个别名
    fs::path dir = FILE_PATH;
    if (!fs::exists(dir))  // 检查目录是否存在,不存在则创建
    {
        fs::create_directories(dir);
    }

    std::string file_name = FILE_PATH "/history.csv";
    fst.open(file_name, std::ios::out | std::ios::in | std::ios::app);
    is_exist = fst.is_open() && fs::file_size(file_name) != 0;
}

file_operator::~file_operator()
{
    fst.close();
}

void file_operator::write_csv(const std::vector< Player > &GroupFinals)
{
    for (const auto &ite : GroupFinals)
    {
        fst << ite.name << "," << ite.serial_num << ","
            << ite.participation_time << "," << ite.final_score << '\n';
    };
    is_exist = true;
}

auto file_operator::read_csv() -> std::optional< decltype(history_competition) >
{
    if (!is_exist)
    {
        return std::nullopt;
    }

    // read all chars into fileContent by istreambuf_iterator
    // std::string fileContent((std::istreambuf_iterator< char >(fst)),
    //                       std::istreambuf_iterator< char >());
    // create a In stream object to parse string
    // std::istringstream str_I_stream(fileContent);
    std::istringstream iss;
    std::string line;  // to accept every line data
    std::string name;
    int serial_num = 0;
    std::string time;
    float scores;
    while (std::getline(fst, line))
    {
        // pre-preocess string, something like remove space etc.
        std::erase(line, ' ');
        std::replace(line.begin(), line.end(), ',', ' ');
        iss.str(line);
        if (iss >> name >> serial_num >> time >> scores)
        {
            history_competition.emplace_back(name, serial_num, time, scores);
        } else
        {
            std::cout << "parse error\n";
        };
        iss.clear();
        iss.str("");  // to rest iss for new data
    }
    return history_competition;
}

void file_operator::clean_file()
{
    if (!is_exist)
    {
        std::cout << "No Record Yet\n";
        return;
    }
    std::cout << "Are you sure to clean the file?(Y/N): ";
    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        fst.close();
        std::string file_name = FILE_PATH "/history.csv";
        fst.open(file_name, std::ios::out | std::ios::trunc);
        fst.close();
        std::cout << "File is clean\n";
        fst.open(file_name, std::ios::out | std::ios::in | std::ios::app);
        std::cout << "file size is: " << std::filesystem::file_size(file_name)
                  << endl;
        is_exist = false;
    }
    std::cin.clear();
    std::cin.ignore(sizeof(std::string), '\n');
}