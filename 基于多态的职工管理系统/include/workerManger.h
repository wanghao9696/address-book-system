#pragma once
#include <iostream>
#include<fstream>

#include"worker.h"

#define FILENAME "empFile.txt"

using namespace std;


class WorkerManger
{
public:

    // 构造函数
    WorkerManger();

    // 展示菜单函数
    void show_Menu();

    // 退出系统函数
    void exitSystem();

    // 增加职工
    void Add_Emp();

    // 保存职工信息
    void save();

    // 获取职工人数
    int get_EmpNum();

    // 初始化员工
    void init_Emp();

    // 显示职工
    void show_Emp();

    // 职工存在判断函数
    int isExit(int id);

    // 修改职工
    void mod_Emp();

    // 查找职工
    void find_Emp();

    // 排序职工
    void sort_Emp();

    // 清空文件
    void clear_File();

    // 删除职工
    void del_Emp();

    //析构函数
    ~WorkerManger();

    int m_EmpNum = 0; // 记录文件中的人数个数
    Worker ** m_EmpArray = NULL;

    bool m_FileIsEmpty; // 标志文件是否为空

};