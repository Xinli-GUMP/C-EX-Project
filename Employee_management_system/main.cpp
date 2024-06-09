#include "WorkerManager.h"

int main()
{
    WorkerManager wm;

    int choice = 0;
    while (true)
    {
        wm.show_menu();
        cin >> choice;
        switch (choice)
        {
        case 0: // 退出系统
            wm.exit();
            return 0;
        case 1: // 添加职工
            wm.add_worker();
            break;
        case 2: // 显示职工
            wm.display_worker();
            break;
        case 3: // 删除职工
            wm.delete_worker();
            break;
        case 4: // 修改职工
            wm.modify_worker_info();
            break;
        case 5: // 查找职工
            wm.search_worker();
            break;
        case 6: // 排序职工
            wm.sort_worker_data();
            break;
        case 7: // 清空文件
            wm.clear_worker_data();
            break;
        default:
            // system("cls"); 有bug
            for (int i = 0; i < 10; i++)
            {
                cout << endl;
            }
            cout << "输入错误，请重新输入！" << endl;
            break;
        }
    }
}

// int main(int argc, char **argv)
// {
//     WorkerType *type_data;
//     type_data[0] = WorkerType::BossType;
//     type_data[1] = WorkerType::EmployeeType;

//     if (type_data[0] == WorkerType::BossType)
//     {
//         cout << "true";
//     }

//     system("pause");
//     return 0;
// }
