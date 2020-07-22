#include<iostream>
using namespace std; 
#include<string>
#define MAX 100

void showMeu()
{	cout<<"************************"<<endl;
	cout<<"******1.�����ϵ��******"<<endl;
	cout<<"******2.��ʾ��ϵ��******"<<endl;
	cout<<"******3.ɾ����ϵ��******"<<endl;
	cout<<"******4.������ϵ��******"<<endl;
	cout<<"******5.�޸���ϵ��******"<<endl;
	cout<<"******6.�����ϵ��******"<<endl;
	cout<<"******0.�˳�ͨѶ¼******"<<endl;
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
		cout<<"ͨѶ¼�������޷��ټ������"<<endl;
		return;
		
	}else
	{
		cout<<"��������ϵ��������"<<endl;
		string name;
		cin>>name;
		abs->addrelist[abs->size].name=name;


		cout<<"��������ϵ���Ա�"<<endl;
		cout<<"1��������  2����Ů��"<<endl;
		int sex=0;
	
		while(1)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
			abs->addrelist[abs->size].sex=sex;
			break;
			}
			cout<<"������������������"<<endl;
		}
		
		cout<<"��������ϵ�����䣺"<<endl;
		int age;
		cin>>age;
		abs->addrelist[abs->size].age=age;

		cout<<"��������ϵ�˵绰��"<<endl;
		string phone;
		cin>>phone;
		abs->addrelist[abs->size].phone=phone;

		cout<<"��������ϵ�˵�ַ��"<<endl;
		string adress;
		cin>>adress;
		abs->addrelist[abs->size].adress=adress;
	
		abs->size++;
		cout<<"��ӳɹ���"<<endl;
	
		system("pause");//�밴���������
		system("cls");//����
	}
}

void showperson(struct addresslist *abs)
{
	int i=0;
	if(abs->size == 0)
	{
		cout<<"ͨѶ¼��¼Ϊ��"<<endl;
	}
	else
	{
		for(i=0;i<abs->size;i++)
		{
			cout<<"������"<<abs->addrelist[i].name<<"\t";
			cout<<"�Ա�"<<((abs->addrelist[i].sex==1)?"��":"Ů")<<"\t";
			cout<<"���䣺"<<abs->addrelist[i].age<<"\t";
			cout<<"�绰��"<<abs->addrelist[i].phone<<"\t";
			cout<<"��ַ��"<<abs->addrelist[i].adress<<endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//����
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
	cout<<"������Ҫɾ����ϵ�ˣ�"<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	
	if(ret != -1)
	{
		for(int i=ret;i<abs->size;i++)
		{
			abs->addrelist[i].name=abs->addrelist[i+1].name;
			abs->size--;
			cout<<"ɾ���ɹ���"<<endl;
		}
	}else
	{
		cout<<"���޴��ˣ�"<<endl;
	}
	
	system("pause");//�밴���������
	system("cls");//����
}
void findperson(struct addresslist *abs)
{
	cout<<"������Ҫ������ϵ��������"<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	//cout<<"�鿴�Ƿ����ˣ�"<<ret<<endl;
	if(ret != -1)
	{
			cout<<"������"<<abs->addrelist[ret].name<<"\t";
			cout<<"�Ա�"<<((abs->addrelist[ret].sex==1)?"��":"Ů")<<"\t";
			cout<<"���䣺"<<abs->addrelist[ret].age<<"\t";
			cout<<"�绰��"<<abs->addrelist[ret].phone<<"\t";
			cout<<"��ַ��"<<abs->addrelist[ret].adress<<endl;
	}
	else
	{
		cout<<"���޴��ˣ�"<<endl;
	}
	system("pause");//�밴���������
	system("cls");//����
}
void modifyperson(struct addresslist *abs)

{
	cout<<"������Ҫ�޸ĵ���ϵ��������"<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	
	if(ret != -1)
	{
		cout<<"�������޸ĺ���ϵ��������"<<endl;
		string name;
		cin>>name;
		abs->addrelist[ret].name=name;


		cout<<"�������޸ĺ���ϵ���Ա�"<<endl;
		cout<<"1��������  2����Ů��"<<endl;
		int sex=0;
	
		while(1)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
			abs->addrelist[ret].sex=sex;
			break;
			}
			cout<<"������������������"<<endl;
		}
		cout<<"�������޸ĺ���ϵ�����䣺"<<endl;
		int age;
		cin>>age;
		abs->addrelist[ret].age=age;

		cout<<"�������޸ĺ���ϵ�˵绰��"<<endl;
		string phone;
		cin>>phone;
		abs->addrelist[ret].phone=phone;

		cout<<"�������޸ĺ���ϵ�˵�ַ��"<<endl;
		string adress;
		cin>>adress;
		abs->addrelist[ret].adress=adress;
	
		cout<<"�޸ĳɹ���"<<endl;
	
		system("pause");//�밴���������
		system("cls");//����
	}else
	{
		cout<<"���޴��ˣ�"<<endl;
	}
	
	system("pause");//�밴���������
	system("cls");//����
}
void clearPerson(struct addresslist *abs)
{
	abs->size =0;
	cout<<"ͨѶ¼����գ�"<<endl;
	system("pause");//�밴���������
	system("cls");//����
}


int main()
{

	struct addresslist ss;
	ss.size=0;

	while(1)
	{
	showMeu();
	int select=0;
	cout<<"��ѡ�������"<<endl;
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
			cout<<"ȷ��Ҫ���ô��ȷ��������1"<<endl;
			int num;
			while(1)
			{
				cin>>num;
				if(num==1)
				{
					clearPerson(&ss);
					break;
				}
					cout<<"���������룺"<<endl;
			}
			
		}	
		break;

	case 0:
		{
			cout<<"��ӭ�´�ʹ��"<<endl;
			system("pause");
			return 0;//�����������
			break;
		}
		default:
		break;
	}
	}
	system("pause");
	return 0;
}

