#include<iostream>
#include<string>

#define MAX 1000

using namespace std;

void showMenu(){
    cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

struct Person{
	string m_name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks{
	struct Person personArray[MAX];
	int m_Size;
};

void addPerson(Addressbooks *abs){
	// 定义添加联系人信息的函数
	if(abs->m_Size == MAX){
		cout<<"通讯录已满，无法继续添加联系人！"<<endl;
	}
	else{
		string name;
		cout<<"请输入联系人姓名：\n"<<endl;
		cin>>name;
		abs->personArray[abs->m_Size].m_name = name;

		cout<<"请输入联系人性别：\n"<<endl;
		cout<<"1——男：\n"<<endl;
		cout<<"2——女：\n"<<endl;

		int sex = 0;
		cin>>sex;
		abs->personArray[abs->m_Size].m_Sex = sex;

		cout<<"请输入联系人年龄：\n"<<endl;
		int age = 0;
		cin>>age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout<<"请输入联系人电话：\n"<<endl;
		string number;
		cin>>number;
		abs->personArray[abs->m_Size].m_Phone = number;

		cout<<"请输入联系人地址：\n"<<endl;
		string address;
		cin>>address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size += 1;

		cout<<"联系人添加成功！\n";
		system("pause");
		system("cls");
	}
}

int isExist(Addressbooks *abs, string name){
	for(int i = 0; i < abs->m_Size; i++){
		if(abs->personArray[i].m_name == name){
			return i;
		}
	}
	return -1;
}

void delPerson(Addressbooks *abs){
	cout<<"请输入要删除的联系人姓名："<<endl;
	string name;
	cin>>name;
	int ret = isExist(abs, name);
	if(ret == -1){
		cout<<"不存在要删除的联系人！\n";
	}
	else{
		for(int i = ret; i < abs->m_Size; i++){
			abs->personArray[i] = abs->personArray[i+1];
		}
		abs->m_Size -= 1;
		cout<<"删除成功！\n";
	}
	system("pause");
	system("cls");
}

void showPerson(Addressbooks *abs){
	if(abs->m_Size == 0){
		cout<<"当前通讯录为空！\n";
	}
	else{
		for(int i = 0; i < abs->m_Size; i++){
			cout<<"姓名："<<abs->personArray[i].m_name <<"\n";
			cout<<"性别："<<abs->personArray[i].m_Sex <<"\n";
			cout<<"年龄："<<abs->personArray[i].m_Age <<"\n";
			cout<<"电话："<<abs->personArray[i].m_Phone <<"\n";
			cout<<"住址："<<abs->personArray[i].m_Addr <<"\n";
		}
	}
	system("pause");
	system("cls");
}

void serchPerson(Addressbooks *abs){
	cout<<"请输入要查找的联系人：\n";
	string name;
	cin>>name;
	int ret = isExist(abs, name);
	if(ret == -1){
		cout<<"查无此人！\n";
	}
	else{
		cout<<"姓名："<<abs->personArray[ret].m_name <<"\n";
		cout<<"性别："<<abs->personArray[ret].m_Sex <<"\n";
		cout<<"年龄："<<abs->personArray[ret].m_Age <<"\n";
		cout<<"电话："<<abs->personArray[ret].m_Phone <<"\n";
		cout<<"住址："<<abs->personArray[ret].m_Addr <<"\n";
	}
	system("pause");
	system("cls");
}

void changePerson(Addressbooks *abs){
	cout<<"请输入要修改的联系人姓名：\n";
	string name;
	cin>>name;
	int ret = isExist(abs, name);
	if(ret == -1){
		cout<<"不存在此联系人!\n";
	}
	else{
		string name2;
		cout<<"请输入修改后的姓名：";
		cin>>name2;
		abs->personArray[ret].m_name = name2;

		string number;
		cout<<"请输入修改后的电话：";
		cin>>number;
		abs->personArray[ret].m_Phone = number;

		string address;
		cout<<"请输入修改后的地址：";
		cin>>address;
		abs->personArray[ret].m_Addr = address;

		cout<<"修改成功！\n"<<endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(Addressbooks *abs){
	cout<<"请确认是否清空通讯录(yes)！\n";
	string sure;
	cin>>sure;
	if(sure == "yse"){
		abs->m_Size = 0;
		cout<<"通讯录已清空！\n";
	}
	else{
		showMenu();
	}
}

int main() {
	Addressbooks abs; // 创建通讯录
	abs.m_Size = 0; // 初始化通讯录人数为0

	int select = 0;

	while (true)
	{
		showMenu();

		cin >> select;
		
		switch (select)
		{
		case 1:  //添加联系人
			addPerson(&abs);
			break;
		case 2:  //显示联系人
			showPerson(&abs);
			break;
		case 3:  //删除联系人
			delPerson(&abs);
			break;
		case 4:  //查找联系人
			serchPerson(&abs);
			break;
		case 5:  //修改联系人
			changePerson(&abs);
			break;
		case 6:  //清空联系人
			clearPerson(&abs);
			break;
		case 0:  //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");

	return 0;
}