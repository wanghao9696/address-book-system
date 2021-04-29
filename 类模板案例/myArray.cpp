#include"myArray.hpp"
#include<string>

void printIntArray(MyArray<int> & arr)
{
    for(int i=0; i<arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 测试内置数据类型
void test01()
{
    MyArray<int> array1(10);
    for(int i=0; i<10; i++)
    {
        array1.push_Back(i);
    }
    cout << "array1打印输出：" << endl;
    printIntArray(array1);
    cout << "array1的大小：" << array1.getSize() << endl;
    cout << "array1的容量：" << array1.getCapacity() << endl;

    cout << "----------------------" << endl;

    MyArray<int> array2(array1);
    array2.pop_Back();
    cout << "array2打印输出：" << endl;
    printIntArray(array2);
    cout << "array2的大小：" << array2.getSize() << endl;
    cout << "array2的容量：" << array2.getCapacity() << endl;
}

// 测试自定义数据类型
class Person
{
public:
    Person(){}
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
public:
    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> & personArr)
{
    for(int i=0; i<personArr.getSize(); i++)
    {
        cout << "姓名：" << personArr[i].m_Name << "  年龄：" << personArr[i].m_Age << endl;
    }
}

void test02()
{
    // 创建数组
    MyArray<Person> pArray(10);
    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);
    Person p4("d", 40);
    Person p5("e", 50);

    // 插入数据
    pArray.push_Back(p1);
    pArray.push_Back(p2);
    pArray.push_Back(p3);
    pArray.push_Back(p4);
    pArray.push_Back(p5);

    printPersonArray(pArray);

    cout << "pArray的大小：" << pArray.getSize() << endl;
    cout << "pArray的容量：" << pArray.getCapacity() << endl;
}

int main()
{
    test01();

    // test02();

    return 0;
}