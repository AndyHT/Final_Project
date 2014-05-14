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
class Update						//�������ݿ���
{
public:
	struct goods* inputPrduct();
	struct member* inputMember();
	struct shoppingCard* inputShoppingcard();
	void addProduct();
	void addMember();
	void deleteProduct();
	void deleteMember();
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
void Update::addMember()					//������Ա����
{

}
void Update::addProduct()					//������Ʒ����
{

}
void Update::deleteMember()					//ɾ����Ա����
{

}
void Update::deleteProduct()				//ɾ����Ʒ����
{

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