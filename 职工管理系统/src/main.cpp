#include<iostream>
#include"workerManger.h"
#include"worker.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"

using namespace std;


int main(){
    cout << "project beginning!" << endl;

    // 实例化管理者对象
    WorkerManger test;

    int choice = 0;

    // 调用展示菜单成员函数
    test.show_Menu();

    while(true)
    {
        cout << "请输入你的选择：" << endl;
        cin >> choice;

        switch(choice)
        {
        case 0: // 退出系统
            test.exitSystem();
            break;
        case 1: // 增加职工
            test.Add_Emp();
            break;
        case 2: // 显示职工
            test.show_Emp();
            break;
        case 3: // 删除职工
            test.del_Emp();
            break;
        case 4: // 修改职工
            test.mod_Emp();
            break;
        case 5: // 查找职工
            test.find_Emp();
            break;
        case 6: // 排序职工
            test.sort_Emp();
            break;
        case 7: // 清空
            test.clear_File();
            break;
        
        default:
            break;
        }
    }

    return 0;
}