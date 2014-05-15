#include<iostream>
#include<string>
#include<fstream>
#define LENMEMBER sizeof(member)
#define LENGOODS sizeof(goods)
#define LENSHOPPINGCARD sizeof(shoppingCard)
using namespace std;
struct goods{					//��Ʒ���ݿ�struct
	long identifi;
	string name;
	string orgin;
	float price;
	goods *next;
};
class Settlement					//������
{
public:
	void getProduct();
	void countPrice_cash();
	void countPrice_visa();
	void countPrice_card();
	Settlement();
};
void Settlement::getProduct()			//�õ���Ʒ��Ϣ����
{
	cout << "Please input product Identification";
	long _identifi;
	cin >> _identifi;
	}
class Update						//�������ݿ���(completed)
{
protected:
	struct member{					//��Ա���ݿ�struct
		string name;
		string sex;
		long phoneNumber;
		enum rank{ Regular, Silver, Golden }memRank;
		int point;
		member *next;
	};
	struct shoppingCard{			//���￨���ݿ�struct
		long identifi;
		float balance;
		shoppingCard *next;

	};
public:
	struct goods* inputPrduct();
	struct member* inputMember();
	struct shoppingCard* inputShoppingcard();
	void addProduct(struct goods *p);
	void addMember(struct member *p);
	int deleteProduct(struct goods *p);
	int deleteMember(struct member *p);

};
class MemberSettlement :public Settlement			//��Ա����������
{
public:
	void memberGetPrice();

};
struct member* Update::inputMember()					//�����Ա����
{
	ifstream infile("member.txt");
	struct member *p1, *p2, *p3;
	struct member *head;
	head = NULL;
	p1 = p2 = (struct member*)malloc(LENMEMBER);
	head = p1;
	while (infile>>p1->name)
	{
		infile >> p1->sex;
		infile >> p1->phoneNumber;
		infile >> p1->memRank;
		infile >> p1->point;
		p2 = (struct member*)malloc(LENMEMBER);
		p1->next = p2;
		p3 = p1;
		p1 = p2;
	}
	p3->next = NULL;
	p1 = p2 = NULL;
	return (head);					//Ϊ�η���ֵ�����뺯��������ƥ��
}
struct goods* Update::inputPrduct()					//������Ʒ����
{
	ifstream infile("product.txt");
	goods *p1, *p2, *p3;
	goods *head;
	head = NULL;
	p1 = p2 = (struct goods*)malloc(LENGOODS);
	head = p1;
	while (infile >> p1->identifi)
	{
		infile >> p1->name;
		infile >> p1->orgin;
		infile >> p1->price;
		p2 = (struct goods*)malloc(LENGOODS);
		p1->next = p2;
		p3 = p1;
		p1 = p2;
	}
	p3->next = NULL;
	p1 = p2 = NULL;
	return (head);
}
struct shoppingCard* Update::inputShoppingcard()				//�����Ա����Ϣ����
{
	ifstream infile("product.txt");
	shoppingCard *p1, *p2,*p3;
	shoppingCard *head;
	head = NULL;
	p1 = p2 = (struct shoppingCard*)malloc(LENSHOPPINGCARD);
	head = p1;
	while (infile>>p1->identifi)
	{
		infile >> p1->balance;
		p2 = (struct shoppingCard*)malloc(LENSHOPPINGCARD);
		p1->next = p2;
		p3 = p1;
		p1 = p2;
	}
	p3->next = NULL;
	p1 = p2 = NULL;
	return (head);

}
void Update::addMember(struct member *p)					//������Ա����
{
	struct member *p1,*p2;
	p1 = p2 = p;
	while (p1->next != NULL)
	{
		p1 = p2->next;
		p2 = p1;
	}
	p1->next = (struct member*)malloc(LENMEMBER);
	p = p1->next;
	cout << "Please input new member data";
	cout << "Please input name:";
	cin >> p->name;
	cout << "Please input sex";
	cin >> p->sex;
	cout << "Please input phone number";
	cin >> p->phoneNumber;
	p->point = 0;
	p->next = NULL;
	p1 = p2 = NULL;
}
void Update::addProduct(struct goods *p)					//������Ʒ����
{
	struct goods *p1, *p2;
	p1 = p2 = p;
	while (p1->next != NULL)
	{
		p1 = p2->next;
		p2 = p1;
	}
	p1->next = (struct goods*)malloc(LENGOODS);
	p = p1->next;
	cout << "Please input new product data";
	cout << "Please input identification";
	cin >> p->identifi;
	cout << "Please input name";
	cin >> p->name;
	cout << "Please input orgin";
	cin >> p->orgin;
	cout << "Please input price";
	cin >> p->price;
	p->next = NULL;
	p1 = p2 = NULL;
}
int Update::deleteMember(struct member *p)					//ɾ����Ա����
{
	struct member *p1, *p2, *p3;
	p1 = p2 = p3 = p;
	cout << "Please input delete member name";
	string d_name;
	cin >> d_name;
	cout << "Please input delete member phone number";
	long d_phoneNumber;
	cin >> d_phoneNumber;
	cout << "Warning,data will be deleted!Input no will be stopped";
	string order;
	cin >> order;
	if ("no" == order)
	{
		cout << "All has stopped";
		return 1;

	}
	else
	{
		int i = 0;
		for ( ; p1->name != d_name;i++)
		{
			if (0 == i)
			{
				p1 = p2->next;
				p2 = p1;
			}
			else
			{
				p3 = p1;
				p1 = p2->next;
				p2 = p1;
			}
		}
		if (0 == i||NULL==p1->next)
		{
			if (0==i&&p1->phoneNumber == d_phoneNumber)
			{
				p2 = p3 = p1->next;
				free(p1);
				p1 = p = NULL;
			}
			if (NULL == p1->next&&p1->phoneNumber == d_phoneNumber)
			{
				free(p1);
				p3->next = NULL;
				p1 = p2 = NULL;
			}
			else
			{
				cout << "Input member data is wrong!" << endl;
			}
		}
		else
		{
			if (p1->phoneNumber == d_phoneNumber)
			{
				p3->next = p1->next;
				free(p1);//�ͷ��ڴ�
				p1 = p2 = NULL;
			}
			else
			{
				cout << "Input member data is wrong!" << endl;
			}
		}

	}
}
int Update::deleteProduct(struct goods *p)				//ɾ����Ʒ����
{
	struct goods *p1, *p2, *p3;
	p1 = p2 = p3 = p;
	cout << "Please input delete product identification";
	long d_identifi;
	cin >> d_identifi;
	cout << "Please input delete product name";
	string d_name;
	cin >> d_name;
	cout << "Warning,data will be deleted!Input no will be stopped";
	string order;
	cin >> order;
	if ("no" == order)
	{
		cout << "All has stopped";
		return 1;

	}
	else
	{
		int i = 0;
		for (; p1->identifi != d_identifi; i++)
		{
			if (0 == i)
			{
				p1 = p2->next;
				p2 = p1;
			}
			else
			{
				p3 = p1;
				p1 = p2->next;
				p2 = p1;
			}
		}
		if (0 == i || NULL == p1->next)
		{
			if (0 == i&&p1->name == d_name)
			{
				p2 = p3 = p1->next;
				free(p1);
				p1 = p = NULL;
			}
			if (NULL == p1->next&&p1->name == d_name)
			{
				free(p1);
				p3->next = NULL;
				p1 = p2 = NULL;
			}
			else
			{
				cout << "Input product data is wrong!" << endl;
			}
		}
		else
		{
			if (p1->name == d_name)
			{
				p3->next = p1->next;
				free(p1);//�ͷ��ڴ�
				p1 = p2 = NULL;
			}
			else
			{
				cout << "Input product data is wrong!" << endl;
			}
		}

	}

}
int main()
{
	cout << "***************************************************" << endl;
	cout << "****            ���н���ϵͳ                   ****" << endl;
	cout << "****                                           ****" << endl;
	cout << "***************************************************" << endl;
	cout << "����help�س���ð�����Ϣ������count�������ϵͳ" << endl;
	enum order{help,count,error}_order;
	string userOrder;
	cin >> userOrder;
	if (userOrder == "help")
		_order = help;
	if (userOrder == "count")
		_order = count;
	else
		_order = error;
	switch (_order)
	{
	case help:
	{
			  cout << "0";
	}
		break;
	case count:
	{
			  cout << "1";
	}
		break;
	default:
	{
			   cout << "Error";
	}
		break;
	}
	return 0;
}