#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
    m_workerNnum = fo.file_worker_num(fo.fb);
    if (m_workerNnum == 0)
    {
        m_worker_array = nullptr;
    }
    else
    {
        fo.bin_read_worker();
        m_worker_array = fo.TW_tuple.worker_data;
        m_worker_type = fo.TW_tuple.type_data;
        cout << "------------读取完成-----------------" << endl;
    }
};

WorkerManager::~WorkerManager()
{
    fo.bin_write_worker(m_workerNnum, m_worker_type, m_worker_array); // 二进制数据写入

    delete[] m_id_array;
    delete[] m_worker_array;
    delete[] m_worker_type;
};

void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
    cout << "*********** 欢迎使用职工管理系统！**********" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "********************************************" << endl;
    cout << "请按功能键: " << endl;
};

/**
 * @brief 执行添加员工操作
 *
 */
void WorkerManager::add_worker()
{
    int add_num = 0;
    cout << "请输入要添加的员工数量: " << endl;
    while (!(cin >> add_num) || add_num < 0) // 避免因为输入字符给int型导致程序陷入无限循环错误
    {
        cout << "输入有误, 请重新输入(按0退出该功能): " << endl;
        cin.clear();          // 清除错误标志
        cin.ignore(99, '\n'); // 清除缓冲区
    }

    if (add_num == 0)
    {
        return;
    }

    int new_worker_num = m_workerNnum + add_num;

    m_id_array = new int[new_worker_num];                         // 维护一个职工编号数组来验证唯一性。
    WorkerType *new_work_type = new WorkerType[new_worker_num];   // 为新标识堆分配内存
    AbsWorker **new_work_array = new AbsWorker *[new_worker_num]; // 为新添加的员工分配内存
    if (m_worker_array != nullptr)                                // 判断是否已有数据
    {
        for (int i = 0; i < m_workerNnum; i++)
        {
            new_work_type[i] = m_worker_type[i];     // 填入原有标识
            new_work_array[i] = m_worker_array[i];   // 把原有数据填充进去
            m_id_array[i] = new_work_array[i]->m_Id; // 填入已有编号
        };
    }

    int add_worker_num = m_workerNnum; // 用于处理一次添加多个员工时, m_workerNum无法及时更新的问题
    for (int i = 0; i < add_num; i++)  // 添加新员工数据
    {
        int id = 0;
        char rank[32] = {};
        char name[32] = {};
        int choice = 0;
        bool id_in_array = false;
        cout << "请输入第" << m_workerNnum + i + 1 << "个员工编号:" << endl;
        // 验证职工编号唯一性
        while (true)
        {
            if (cin >> id)
            {
                if (add_worker_num == 0) // 如果为空, 第一次添加不做唯一性检验
                {
                    m_id_array[add_worker_num] = id;
                    add_worker_num++;
                    break;
                };

                id_in_array = false;
                for (int j = 0; j < add_worker_num; j++) // 不为空, 遍历已有编号
                {
                    if (id == m_id_array[j])
                    {
                        cout << "该编号已存在, 请重新输入:" << endl;
                        id_in_array = true; // 找到相同编号，需要重新输入
                        break;
                    }
                }
                if (!id_in_array)
                {
                    m_id_array[add_worker_num] = id;
                    add_worker_num++; // 因为添加了一位员工编号, 所以下一次遍历需要多一次
                    break;            // 没有发现重复的ID，可以跳出while循环
                }
            }
            else
            {
                cout << "编号输入有误, 请重新输入: ";
                cin.clear();          // 清除错误标志
                cin.ignore(99, '\n'); // 忽略输入直到下一行
            }
        };

        cout << "请输入员工姓名: " << endl;
        cin.ignore(99, '\n'); // 清除缓冲区
        cin.getline(name, 32);
        cout << "请输入员工级别: (1.员工 2.经理 3.老板)" << endl;
        cin >> choice;
        AbsWorker *worker = nullptr; // 尽管抽象类不能被直接实例化，你可以创建指向它的指针或引用，并使它们指向派生自该抽象类的具体类的实例。这是多态和接口编程中的常见做法。

        switch (choice)
        {
        case 1:
        {
            strncpy(rank, "员工", sizeof(rank) - 1);
            rank[sizeof(rank) - 1] = '\0'; // 确保以空字符结尾, 在C和C++中，以空字符（'\0'，ASCII码为0）结尾的字符数组被用来表示字符串。这个空字符作为字符串的结束标志，非常重要。它不是字符串的一部分，而是一个标记，用来告诉函数和操作字符串的其他代码，字符串在哪里结束。

            WorkerType type = WorkerType::EmployeeType; // 用枚举类标识类的类型
            new_work_type[m_workerNnum + i] = type;     // 存入新的类标识

            worker = new Employee(id, name, rank);     // 为新加员工分配内存
            new_work_array[m_workerNnum + i] = worker; // 存入新加员工
            fo.write_worker(*worker);                  // 写入文本文件
        }
        break;
        case 2:
        {
            strncpy(rank, "经理", sizeof(rank) - 1);
            rank[sizeof(rank) - 1] = '\0';
            WorkerType type = WorkerType::ManagerType; // 用枚举类标识类的类型
            new_work_type[m_workerNnum + i] = type;

            worker = new Manager(id, name, rank);
            new_work_array[m_workerNnum + i] = worker;
            fo.write_worker(*worker);
        }
        break;
        case 3:
        {
            strncpy(rank, "老板", sizeof(rank) - 1);
            rank[sizeof(rank) - 1] = '\0';
            WorkerType type = WorkerType::BossType; // 用枚举类标识类的类型
            new_work_type[m_workerNnum + i] = type;

            worker = new Boss(id, name, rank);
            new_work_array[m_workerNnum + i] = worker;
            fo.write_worker(*worker);
        }
        break;
        default:
            cout << "请输入正确的级别!" << endl;
            i--; // 员工级别输入错误, 所以添加失败, i自减1, 再来一遍循环。
            m_id_array[add_worker_num] = 0;
            add_worker_num--;     // 员工编号数组长度减一
            cin.clear();          // 清除错误标志
            cin.ignore(99, '\n'); // 清除缓冲区

            break;
        }
    };

    cout << "添加完成!" << endl;
    // delete[] m_worker_type;
    // delete[] m_worker_array;
    m_worker_array = new_work_array;
    m_workerNnum = new_worker_num;
    m_worker_type = new_work_type;
};

/**
 * @brief 显示职工
 *
 */
void WorkerManager::display_worker()
{
    cout << "---------------------------------职工信息---------------------------------------" << endl;
    if (m_workerNnum == 0)
    {
        cout << "职工数量为空, 请先添加职工!" << endl;
    }

    for (int i = 0; i < m_workerNnum; i++)
    {
        m_worker_array[i]->show_Info();
    };
    cout << "--------------------------------------------------------------------------------" << endl;
}

/**
 * @brief 删除职工
 *
 */
void WorkerManager::delete_worker()
{
    int deleted_id = 0;
    cout << "请输入要删除的员工编号(退出请按0):  ";
    while (!(cin >> deleted_id))
    {
        cout << "编号输入有误, 请再次输入:" << endl;
        cin.clear();
        cin.ignore(99, '\n');
    };

    for (int i = 0; i < m_workerNnum; i++)
    {
        if (deleted_id == 0)
        {
            return;
        }

        if (m_worker_array[i]->m_Id == deleted_id) // 先遍历找到要删除员工的编号
        {
            // 保存删除员工的信息，以便打印
            string deletedName = m_worker_array[i]->m_Name;
            string deletedRank = m_worker_array[i]->m_rank;

            for (int j = i; j < m_workerNnum - 1; j++) // 再把之后的员工数据向前挪一个位置覆盖。
            {
                m_worker_type[j] = m_worker_type[j + 1];
                m_worker_array[j] = m_worker_array[j + 1];
            };

            m_worker_array[m_workerNnum - 1] = nullptr; // 将最后一个元素置空, 数组长度减一。
            m_worker_type[m_workerNnum - 1] = WorkerType::None;
            m_workerNnum--;
            cout << "删除成功->编号: " << deleted_id << '\t' << "姓名: " << deletedName
                 << '\t' << "职级: " << deletedRank << endl;
            return;
        };
    };
    cout << "删除失败，未找到对应编号的员工!" << endl;
};

/**
 * @brief 修改职工信息
 *
 */
void WorkerManager::modify_worker_info()
{
    cout << "请输入要修改的职工编号(退出请按0): ";
    int modified_id = 0;
    while (!(cin >> modified_id))
    {
        cout << "请输入已有职工的编号!" << endl;
        cin.clear();
        cin.ignore(99, '\n');
    };

    for (int i = 0; i < m_workerNnum; i++)
    {
        if (modified_id == 0)
        {
            return;
        }

        if (modified_id == m_worker_array[i]->m_Id)
        {
            cout << "请输入要修改的字段(1. 姓名 2.职级): ";
            char name[32] = {};
            char rank[32] = {};
            int choice = 0;
            int choice_rank = 0;
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "请输入新的姓名: ";
                cin.ignore(99, '\n');
                cin.getline(name, 32);
                strncpy(m_worker_array[i]->m_Name, name, sizeof(name) - 1);
                name[sizeof(name) - 1] = '\0'; // 字符数组最后字符必须为空字符
                break;

            case 2:
                cout << "请输入新的职级(1. 员工 2. 经理 3. 老板): ";
                cin >> choice_rank;
                switch (choice_rank)
                {
                case 1:
                    strncpy(name, m_worker_array[i]->m_Name, sizeof(name) - 1);
                    m_worker_array[i] = nullptr;
                    strncpy(rank, "员工", sizeof(rank) - 1);
                    rank[sizeof(rank) - 1] = '\0';
                    m_worker_array[i] = new Employee(modified_id, name, rank);
                    m_worker_type[i] = WorkerType::EmployeeType;
                    fo.write_worker(*m_worker_array[i]);
                    break;
                case 2:
                    strncpy(name, m_worker_array[i]->m_Name, sizeof(name) - 1);
                    m_worker_array[i] = nullptr;
                    strncpy(rank, "经理", sizeof(rank) - 1);
                    rank[sizeof(rank) - 1] = '\0';
                    m_worker_array[i] = new Employee(modified_id, name, rank);
                    m_worker_type[i] = WorkerType::EmployeeType;
                    fo.write_worker(*m_worker_array[i]);
                    break;
                case 3:
                    strncpy(name, m_worker_array[i]->m_Name, sizeof(name) - 1);
                    m_worker_array[i] = nullptr;
                    strncpy(rank, "老板", sizeof(rank) - 1);
                    rank[sizeof(rank) - 1] = '\0';
                    m_worker_array[i] = new Employee(modified_id, name, rank);
                    m_worker_type[i] = WorkerType::EmployeeType;
                    fo.write_worker(*m_worker_array[i]);
                    break;
                default:
                    cout << "级别输入错误!" << endl;
                    break;
                }
            default:
                cout << "字段输入错误!" << endl;
                break;
            }
            return;
        }
    }
    cout << "未找到编号为--" << modified_id << "--的员工!" << endl;
};

/**
 * @brief 根据职工编号搜寻职工信息
 *
 */
void WorkerManager::search_worker()
{
    cout << "请输入要查找的职工编号(退出请按0): ";
    int serarch_id = 0;
    while (!(cin >> serarch_id))
    {
        cout << "编号输入有误! 请再次输入: ";
        cin.clear();
        cin.ignore(99, '\n');
    }

    for (int i = 0; i < m_workerNnum; i++)
    {
        if (serarch_id == 0)
        {
            return;
        }

        if (serarch_id == m_worker_array[i]->m_Id)
        {
            cout << "职工信息: " << endl;
            m_worker_array[i]->show_Info();
            return;
        }
    }
    cout << "查询失败，未找到对应编号的员工!" << endl;
};

/**
 * @brief 根据职工编号排序职工信息数据
 *
 */
void WorkerManager::sort_worker_data()
{
    cout << "升序/降序(1/2)(退出请按0): ";
    int choice = 0;
    while (!(cin >> choice))
    {
        cout << "输入有误! 请再次输入: ";
        cin.clear();
        cin.ignore(99, '\n');
    }
    switch (choice)
    {
    case 1: // 升序
    {
        for (int i = 0; i < m_workerNnum - 1; i++) // 用冒泡排序
        {
            for (int j = 0; j < m_workerNnum - i - 1; j++)
            {
                if (m_worker_array[j]->m_Id > m_worker_array[j + 1]->m_Id)
                {
                    AbsWorker *temp = m_worker_array[j];
                    m_worker_array[j] = m_worker_array[j + 1];
                    m_worker_array[j + 1] = temp;

                    WorkerType temp_type = m_worker_type[j];
                    m_worker_type[j] = m_worker_type[j + 1];
                    m_worker_type[j + 1] = temp_type;
                }
            };
        }
    };
    break;
    case 2: // 降序
    {
        for (int i = 0; i < m_workerNnum - 1; i++) // 用冒泡排序
        {
            for (int j = 0; j < m_workerNnum - i - 1; j++)
            {
                if (m_worker_array[j]->m_Id < m_worker_array[j + 1]->m_Id)
                {
                    AbsWorker *temp = m_worker_array[j];
                    m_worker_array[j] = m_worker_array[j + 1];
                    m_worker_array[j + 1] = temp;

                    WorkerType temp_type = m_worker_type[j];
                    m_worker_type[j] = m_worker_type[j + 1];
                    m_worker_type[j + 1] = temp_type;
                }
            };
        }
    };
    break;

    default:
        cout << "请按1或者2进行排序" << endl;
        break;
    }
};

/**
 * @brief 清空所有职工信息
 *
 */
void WorkerManager::clear_worker_data()
{
    cout << "确认要清空所有职工信息吗?" << endl
         << "确认请按Y(退出请按0): ";
    char choice = 'n';
    while (!(cin >> choice))
    {
        cout << "输入有误, 请再次输入: ";
        cin.clear();
        cin.ignore(99, '\n');
    }
    if (choice == '0')
    {
        return;
    }

    if (choice == 'Y' || choice == 'y')
    {
        m_worker_array = nullptr;
        m_id_array = nullptr;
        m_worker_type = nullptr;
        m_workerNnum = 0;
        cout << "职工信息清除完成" << endl;
    }
    else
    {
        cout << "放弃删除" << endl;
    }
};

/**
 * @brief 退出程序
 *
 */
void WorkerManager::exit()
{
    cout << "欢迎下次使用！😘" << endl;
    system("pause");
};
