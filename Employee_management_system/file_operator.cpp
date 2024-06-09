#include "file_operator.h"

/**
 * @brief 构造
 *
 */
file_operator::file_operator(/* args */)
{
    namespace fs = std::filesystem; // 给filesysyem命名空间取个别名
    fs::path dir = "./data/";
    if (!fs::exists(dir)) // 检查目录是否存在,不存在则创建
    {
        fs::create_directories(dir);
    }
    // f.open("../data/WorkerData.txt", ios::out | ios::app); // 调试用
    f.open("./data/WorkerData.txt", ios::out | ios::app);
    if (!f.is_open())
    {
        cout << "txt文件打开失败!" << endl;
        return;
    };

    // 二进制打开
    fs::path bin_path = "./data/WorkerData.bin";
    if (!fs::exists(bin_path)) // 如果文件不存在则创建然后关闭。
    {
        fb.open(bin_path, ios::out | ios::binary);
        fb.close();
    }
    // fb.open("../data/WorkerData.bin", ios::in | ios::binary); //调试用
    fb.open(bin_path, ios::in | ios::binary);
    if (!fb.is_open())
    {
        cout << "bin文件打开失败。" << endl;
    };
};

/**
 * @brief 析构
 *
 */
file_operator::~file_operator()
{
    f.close();
    fb.close();

    // cout << "文件操作类析构" << endl;
};

/**
 * @brief 写入文本文件
 *
 * @param worker
 */
void file_operator::write_worker(AbsWorker &worker)
{
    f << worker.get_id() << '\t' << worker.get_rank() << '\t' << worker.get_name() << '\t' << worker.get_task() << endl;
};

/**
 * @brief 二进制写入
 *
 * @param workerNum
 * @param type
 * @param worker
 */
void file_operator::bin_write_worker(int workerNum, WorkerType *type, AbsWorker **worker)
{
    fb.close();
    // fb.open("../data/WorkerData.bin", ios::out | ios::binary | ios::trunc); // 覆写方式打开, 调试用
    fb.open("./data/WorkerData.bin", ios::out | ios::binary | ios::trunc);
    if (!fb.is_open())
    {
        cout << "WorkerData文件打开失败。" << endl;
        return;
    };
    for (int i = 0; i < workerNum; i++)
    {
        fb.write((const char *)&type[i], sizeof(WorkerType));              // 先写入类的类型, 以便于在读取时判断该用哪个子类接收。
        fb.write((const char *)&worker[i]->m_Id, sizeof(worker[i]->m_Id)); // 再写入类数据
        fb.write((const char *)&worker[i]->m_Name, sizeof(worker[i]->m_Name));
        fb.write((const char *)&worker[i]->m_rank, sizeof(worker[i]->m_rank));
    };
    // cout << "二进制写入完成" << endl;
};

/**
 * @brief 读取二进制文件
 *
 * @return AbsWorker**
 */
void file_operator::bin_read_worker()
{
    int worker_num = file_worker_num(fb);
    TW_tuple.type_data = new WorkerType[worker_num];
    TW_tuple.worker_data = new AbsWorker *[worker_num];
    for (int i = 0; i < worker_num; i++)
    {
        int id = 0;
        char name[32] = {};
        char rank[32] = {};
        WorkerType type;
        fb.read((char *)&type, sizeof(WorkerType)); // 先读取类型
        switch (type)                               // 判断类型
        {
        case WorkerType::BossType:
            fb.read((char *)&id, sizeof(id));
            fb.read(name, sizeof(name));
            fb.read(rank, sizeof(rank));
            TW_tuple.type_data[i] = WorkerType::BossType;
            TW_tuple.worker_data[i] = new Boss(id, name, rank);
            break;

        case WorkerType::EmployeeType:
            fb.read((char *)&id, sizeof(id));
            fb.read(name, sizeof(name));
            fb.read(rank, sizeof(rank));
            TW_tuple.type_data[i] = WorkerType::EmployeeType;
            TW_tuple.worker_data[i] = new Employee(id, name, rank);
            break;

        case WorkerType::ManagerType:
            fb.read((char *)&id, sizeof(id));
            fb.read(name, sizeof(name));
            fb.read(rank, sizeof(rank));
            TW_tuple.type_data[i] = WorkerType::ManagerType;
            TW_tuple.worker_data[i] = new Manager(id, name, rank);
            break;
        default:
            TW_tuple.worker_data[i] = nullptr; // 读取失败置为空
            break;
        }
    };
};

/**
 * @brief 计算二进制文件内类的个数
 *
 * @param f
 * @return int
 */
int file_operator::file_worker_num(fstream &f)
{
    f.seekg(0, f.end);
    size_t size = f.tellg();
    f.seekg(0, f.beg);
    int worker_num = size / 72; // 文件的大小除以单个对象的大小得到对象个数
    return worker_num;
}