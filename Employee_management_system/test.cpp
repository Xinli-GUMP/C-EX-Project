#include <iostream>
#include <fstream>
#include <cstring>
#include "AbsWorker.h"
#include "Boss.h"
using namespace std;

// class AbsWorker
// {
// public:
//         int m_Id;
//         char m_Name[32];
//         char m_rank[32];

//         // AbsWorker()
//         // {
//         // }

//         // AbsWorker(int id, char name[32], char rank[32])
//         // {
//         //         this->m_Id = id;

//         // }
// };

// int main()
// {
//         // fstream f("./data/test.bin", ios::out | ios::binary | ios::app);
//         // AbsWorker worker = {1, "Alice", "老板"};
//         // f.write((const char *)&worker, sizeof(worker));

//         fstream f("./data/test.bin", ios::in | ios::binary);
//         f.seekg(0, f.end);
//         size_t size = f.tellg();
//         f.seekg(0, f.beg);
//         int count = size / sizeof(AbsWorker);
//         cout << count << endl;

//         // AbsWorker *workers[3]; // 声明一个指针数组

//         // for (int i = 0; i < 3; i++)
//         // {
//         //         workers[i] = new AbsWorker;                    // 为每个AbsWorker分配内存
//         //         f.read((char *)workers[i], sizeof(AbsWorker)); // 正确的大小使用
//         // }

//         // cout << sizeof(workers) << endl;

//         f.close();

//         return 0;
// }

// class test
// {
// public:
//         char m_name[32];

//         test(const char name[])
//         {
//                 // 使用strncpy确保不会溢出并且字符串结尾是'\0'
//                 strncpy(this->m_name, name, sizeof(m_name) - 1);
//                 this->m_name[sizeof(m_name) - 1] = '\0'; // 确保字符串以null终止
//         }

//         // 返回m_name的指针只读访问，不需要动态分配内存
//         const char *return_str() const
//         {
//                 return m_name;
//         }

//         char *aa()
//         {
//                 return (char *)"所发生的";
//         }

//         ~test()
//         {
//                 // 析构函数体为空，因为没有动态分配的资源需要释放
//         }
// };

// int main(int argc, char **argv)
// {
//         char name[] = "Alice";
//         test t1(name);

//         // 正确获取m_name的指针
//         const char *array = t1.return_str();
//         cout << array << endl;
//         // 不需要delete，因为没有new[]

//         cout << t1.aa() << endl;

//         return 0;
// }

// void write_txt(fstream &f)
// {
//     string str = "大发发发的防守打法是";

//     f << str << endl;
// }

// void read_txt()
// {
//     fstream f("./data/test.txt", ios::in);
//     string str;
//     if (!f.is_open())
//     {
//         cout << "open failed" << endl;
//         return;
//     }
//     while (std::getline(f, str))
//     {
//         cout << str << endl;
//     }
// }

int main(int argc, char const *argv[])
{
    cout << sizeof(AbsWorker) << '\n'
         << sizeof(Boss) << endl;
    return 0;
}
