#include<iostream>
#include<string>
#include<fstream>
#define LENMEMBER sizeof(member)
#define LENGOODS sizeof(goods)
using namespace std;
class Settlement					//结算
{
public:
	void getProduct();
	void countPrice();
	Settlement();
protected:
	struct goods{					//商品数据库
		long identifi;
		string name;
		string orgin;
		float price;
		goods *left;
		goods *right;
	};
};
void Settlement::getProduct()			//得到商品信息
{
	cout << "Please input product number";
	cin >> product.identifi;


}
class Update						//更新
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
		shoppingCard *left;
		shoppingCard *right;
	}shopping;
};
class MemberSettlement :public Settlement			//会员结算
{
public:
	void memberGetPrice();

};
struct member* Update::inputMember()					//导入会员
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
void Update::inputPrduct()					//导入商品
{
	ifstream("product.txt");
	goods *p1, *p2;
	goods *head;
	head = NULL;
	p1 = p2 = (struct goods*)malloc(LENGOODS);

}
void Update::inputShoppingcard()				//导入会员卡信息
{
	ifstream infile("product.txt");
	while (infile>>)
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

}
