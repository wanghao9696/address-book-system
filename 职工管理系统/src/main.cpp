#include<iostream>
#include"workerManger.h"

using namespace std;


int main(){
    cout << "project beginning!" << endl;

    // 实例化管理者对象
    WorkerManger test;

    // 调用展示菜单成员函数
    test.Show_Menu();

    return 0;
}