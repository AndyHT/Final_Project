#include<iostream>
#include<string>
#include<fstream>
#define LENMEMBER sizeof(member)
#define LENGOODS sizeof(goods)
#define LENSHOPPINGCARD sizeof(shoppingCard)
using namespace std;
/*
struct goods{					//商品数据库
	long identifi;
	string name;
	string orgin;
	float price;
	goods *next;
};
class Settlement					//结算
{
public:
	void getProduct();
	void countPrice_cash();
	void countPrice_visa();
	void countPrice_card();
	Settlement();
};
void Settlement::getProduct()			//得到商品信息
{
	cout << "Please input product Identification";
	long _identifi;
	cin >> _identifi;
	}
class Update						//更新数据库
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
	struct member{					//会员数据库
		string name;
		string sex;
		long phoneNumber;
		enum rank{ Regular, Silver, Golden }memRank;
		int point;
		member *next;
	};

	struct shoppingCard{			//购物卡数据库
		long identifi;
		float balance;
		shoppingCard *next;

	};
};
class MemberSettlement :public Settlement			//会员结算
{
public:
	void memberGetPrice();

};
struct member* Update::inputMember()					//导入会员
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
}
void Update::inputPrduct()					//导入商品
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
}
void Update::inputShoppingcard()				//导入会员卡信息
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
}
void Update::addMember()					//新增会员
{

}
void Update::addProduct()					//新增铲平
{

}
void Update::deleteMember()					//删除会员
{

}
void Update::deleteProduct()				//删除商品
{

}*/
int main()
{
	cout << "***************************************************" << endl;
	cout << "****            超市结算系统                   ****" << endl;
	cout << "****                                           ****" << endl;
	cout << "***************************************************" << endl;
	cout << "输入help回车获得帮助信息，输入count进入结算系统" << endl;
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