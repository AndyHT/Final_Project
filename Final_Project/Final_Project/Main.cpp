#include<iostream>
#include<string>
#include<fstream>
#define LENMEMBER sizeof(member)
#define LENGOODS sizeof(goods)
using namespace std;
class Settlement					//����
{
public:
	void getProduct();
	void countPrice();
	Settlement();
protected:
	struct goods{					//��Ʒ���ݿ�
		long identifi;
		string name;
		string orgin;
		float price;
		goods *left;
		goods *right;
	};
};
void Settlement::getProduct()			//�õ���Ʒ��Ϣ
{
	cout << "Please input product number";
	cin >> product.identifi;


}
class Update						//����
{
public:
	void inputPrduct();
	struct member* inputMember();
	void inputShoppingcard();
	void addProduct();
	void addMember();
	void deleteProduct();
	void deleteMember();
protected:
	struct member{					//��Ա���ݿ�
		string name;
		string sex;
		long phoneNumber;
		enum rank{ Regular, Silver, Golden }memRank;
		int point;
		member *next;
	};

	struct shoppingCard{			//���￨���ݿ�
		long identifi;
		float balance;
		shoppingCard *left;
		shoppingCard *right;
	}shopping;
};
class MemberSettlement :public Settlement			//��Ա����
{
public:
	void memberGetPrice();

};
struct member* Update::inputMember()					//�����Ա
{
	ifstream infile("member.txt");
	struct member *p1, *p2;
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
		p1 = p2;
	}
}
void Update::inputPrduct()					//������Ʒ
{
	ifstream("product.txt");
	goods *p1, *p2;
	goods *head;
	head = NULL;
	p1 = p2 = (struct goods*)malloc(LENGOODS);

}
void Update::inputShoppingcard()				//�����Ա����Ϣ
{
	ifstream infile("product.txt");
	while (infile>>)
}
void Update::addMember()					//������Ա
{

}
void Update::addProduct()					//������ƽ
{

}
void Update::deleteMember()					//ɾ����Ա
{

}
void Update::deleteProduct()				//ɾ����Ʒ
{

}
