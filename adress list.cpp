#include<iostream>
using namespace std; 
#include<string>
#define MAX 100

void showMeu()
{	cout<<"************************"<<endl;
	cout<<"******1.添加联系人******"<<endl;
	cout<<"******2.显示联系人******"<<endl;
	cout<<"******3.删除联系人******"<<endl;
	cout<<"******4.查找联系人******"<<endl;
	cout<<"******5.修改联系人******"<<endl;
	cout<<"******6.清空联系人******"<<endl;
	cout<<"******0.退出通讯录******"<<endl;
	cout<<"************************"<<endl;
}


struct person {
	string name;
	int sex;
	int age;
	string phone;
	string adress;
};

struct addresslist{
	struct person addrelist[MAX];
	int size;
};

void addperson(struct addresslist *abs)
{	
	if(abs->size == MAX)
	{
		cout<<"通讯录已满，无法再继续添加"<<endl;
		return;
		
	}else
	{
		cout<<"请输入联系人姓名："<<endl;
		string name;
		cin>>name;
		abs->addrelist[abs->size].name=name;


		cout<<"请输入联系人性别："<<endl;
		cout<<"1代表男生  2代表女生"<<endl;
		int sex=0;
	
		while(1)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
			abs->addrelist[abs->size].sex=sex;
			break;
			}
			cout<<"输入有误，请重新输入"<<endl;
		}
		
		cout<<"请输入联系人年龄："<<endl;
		int age;
		cin>>age;
		abs->addrelist[abs->size].age=age;

		cout<<"请输入联系人电话："<<endl;
		string phone;
		cin>>phone;
		abs->addrelist[abs->size].phone=phone;

		cout<<"请输入联系人地址："<<endl;
		string adress;
		cin>>adress;
		abs->addrelist[abs->size].adress=adress;
	
		abs->size++;
		cout<<"添加成功！"<<endl;
	
		system("pause");//请按任意键继续
		system("cls");//清屏
	}
}

void showperson(struct addresslist *abs)
{
	int i=0;
	if(abs->size == 0)
	{
		cout<<"通讯录记录为空"<<endl;
	}
	else
	{
		for(i=0;i<abs->size;i++)
		{
			cout<<"姓名："<<abs->addrelist[i].name<<"\t";
			cout<<"性别："<<((abs->addrelist[i].sex==1)?"男":"女")<<"\t";
			cout<<"年龄："<<abs->addrelist[i].age<<"\t";
			cout<<"电话："<<abs->addrelist[i].phone<<"\t";
			cout<<"地址："<<abs->addrelist[i].adress<<endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}


int isexist(struct addresslist *abs,string name)
{
	int i;
	for(i=0;i<abs->size;i++)
	{
		if(abs->addrelist[i].name == name)
		{
			return i;
		}	
	}	
	return -1;
}

void deleteperson(struct addresslist *abs)
{
	cout<<"请输入要删除联系人："<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	
	if(ret != -1)
	{
		for(int i=ret;i<abs->size;i++)
		{
			abs->addrelist[i].name=abs->addrelist[i+1].name;
			abs->size--;
			cout<<"删除成功！"<<endl;
		}
	}else
	{
		cout<<"查无此人！"<<endl;
	}
	
	system("pause");//请按任意键继续
	system("cls");//清屏
}
void findperson(struct addresslist *abs)
{
	cout<<"请输入要查找联系人姓名："<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	//cout<<"查看是否有人："<<ret<<endl;
	if(ret != -1)
	{
			cout<<"姓名："<<abs->addrelist[ret].name<<"\t";
			cout<<"性别："<<((abs->addrelist[ret].sex==1)?"男":"女")<<"\t";
			cout<<"年龄："<<abs->addrelist[ret].age<<"\t";
			cout<<"电话："<<abs->addrelist[ret].phone<<"\t";
			cout<<"地址："<<abs->addrelist[ret].adress<<endl;
	}
	else
	{
		cout<<"查无此人！"<<endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}
void modifyperson(struct addresslist *abs)

{
	cout<<"请输入要修改的联系人姓名："<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	
	if(ret != -1)
	{
		cout<<"请输入修改后联系人姓名："<<endl;
		string name;
		cin>>name;
		abs->addrelist[ret].name=name;


		cout<<"请输入修改后联系人性别："<<endl;
		cout<<"1代表男生  2代表女生"<<endl;
		int sex=0;
	
		while(1)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
			abs->addrelist[ret].sex=sex;
			break;
			}
			cout<<"输入有误，请重新输入"<<endl;
		}
		cout<<"请输入修改后联系人年龄："<<endl;
		int age;
		cin>>age;
		abs->addrelist[ret].age=age;

		cout<<"请输入修改后联系人电话："<<endl;
		string phone;
		cin>>phone;
		abs->addrelist[ret].phone=phone;

		cout<<"请输入修改后联系人地址："<<endl;
		string adress;
		cin>>adress;
		abs->addrelist[ret].adress=adress;
	
		cout<<"修改成功！"<<endl;
	
		system("pause");//请按任意键继续
		system("cls");//清屏
	}else
	{
		cout<<"查无此人！"<<endl;
	}
	
	system("pause");//请按任意键继续
	system("cls");//清屏
}
void clearPerson(struct addresslist *abs)
{
	abs->size =0;
	cout<<"通讯录已清空！"<<endl;
	system("pause");//请按任意键继续
	system("cls");//清屏
}


int main()
{

	struct addresslist ss;
	ss.size=0;

	while(1)
	{
	showMeu();
	int select=0;
	cout<<"请选择操作："<<endl;
	cin>>select;
	switch (select)
	{
	case 1:
		addperson(&ss);
		break;
	case 2:
		showperson(&ss);
		break;
	case 3:
		deleteperson(&ss);
		break;
	case 4:
		findperson(&ss);
		break;
	case 5:
		modifyperson(&ss);
		break;
	case 6:
		
		{
			cout<<"确定要清空么？确定请输入1"<<endl;
			int num;
			while(1)
			{
				cin>>num;
				if(num==1)
				{
					clearPerson(&ss);
					break;
				}
					cout<<"请重新输入："<<endl;
			}
			
		}	
		break;

	case 0:
		{
			cout<<"欢迎下次使用"<<endl;
			system("pause");
			return 0;//结束这个函数
			break;
		}
		default:
		break;
	}
	}
	system("pause");
	return 0;
}

