//未完成部分：会员结算，多次结算
//需修改内容：struct的封装
//Bug:enum如何使用
#include<iostream>
#include<string>
#include<fstream>
#define LENMEMBER sizeof(member)
#define LENGOODS sizeof(goods)
#define LENSHOPPINGCARD sizeof(shoppingCard)
using namespace std;
struct goods{					//商品数据库struct
	long identifi;
	string name;
	string orgin;
	float price;
	goods *next;
};
struct member{					//会员数据库struct
	string name;
	string sex;
	long phoneNumber;
	enum rank{ Regular, Silver, Golden }memRank;
	int point;
	member *next;
};
struct shoppingCard{			//购物卡数据库struct
	long identifi;
	float balance;
	shoppingCard *next;

};
class Payment					//结算类
{
public:
	double getPrduct(struct goods *p);
	int pay_cash(double _price);
	int pay_visa(double _price);
	int pay_card(struct shoppingCard *p,double _price);
	void settleMember();
};
double Payment::getPrduct(struct goods *p)
{
	ofstream fileCalendar;
	fileCalendar.open("calendar.txt", ios::out, 0);
	fileCalendar << "Expense Calendar" << endl;
	struct goods *p1, *p2;
	p1 = p2 = p;
	int TotalAmount = 0;
	long double TotalPrice = 0;
	while (1)
	{
		cout << "Please input product Identification:";
		long _identifi;
		cin >> _identifi;
		cout << "Please input amount:";
		int _amount = 1;
		cin >> _amount;
		for ( ; p1->identifi != _identifi; )
		{
			p1 = p2->next;
			p2 = p1;
		}
		cout << "Product name:" << p1->name << "\tProduct orgin:" << p1->orgin << "\tProduct price:" << p1->price << endl;
		fileCalendar << "Product name:" << p1->name << "\tProduct orgin:" << p1->orgin << "\tProduct price:" << p1->price << endl;
		TotalAmount = TotalAmount + _amount;
		TotalPrice = _amount*p1->price + TotalPrice;
		if (0 == _identifi)
			break;
	}
	cout << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
	fileCalendar << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
	fileCalendar.close();
	return(TotalPrice);
}
int Payment::pay_cash(double _price)
{
	cout << "Please intput the payment amount:";
	double _pay;
	cin >> _pay;
	if (_pay - _price < 0)
	{
		return 0;
	}
	cout << "The change:" << _pay - _price << endl;
	return 1;
}
int Payment::pay_visa(double _price)//未完成！！！
{
	cout << "Please input visa number:";
	long visaNumber;
	cin >> visaNumber;
	cout << "Please input name:";
	string visaName;
	cin >> visaName;

}
int Payment::pay_card(struct shoppingCard *p,double _price)
{
	cout << "Please input shopping card number:";
	long _shopCardNum;
	cin >> _shopCardNum;
	struct shoppingCard *p1, *p2;
	p1 = p2 = p;
	for (; p1->identifi != _shopCardNum;)
	{
		p1 = p2->next;
		p2 = p1;
	}
	if (p1->balance >= _price)
	{
		p1->balance = p1->balance - _price;
	}
	else
	{
		cout << "Balance has not enough" << endl;
		cout << "Please chance other method to pay" << endl;
		return 0;
	}
	cout << "Pay completed!" << endl;
	return 1;
}
class Update						//更新数据库类(completed)
{

public:
	struct goods* inputPrduct();
	struct member* inputMember();
	struct shoppingCard* inputShoppingcard();
	void addProduct(struct goods *p);
	void addMember(struct member *p);
	int deleteProduct(struct goods *p);
	int deleteMember(struct member *p);

};
class MemberSettlement :public Payment			//会员结算派生类
{
public:
	void memberGetPrice();

};//未完成！！！
struct member* Update::inputMember()					//导入会员函数
{
	ifstream fileMember;
	fileMember.open("member.txt", ios::in, 1);
	struct member *p1, *p2, *p3;
	struct member *head;
	head = NULL;
	p1 = p2 = (struct member*)malloc(LENMEMBER);
	head = p1;
	while (fileMember>>p1->name)
	{
		fileMember >> p1->sex;
		fileMember >> p1->phoneNumber;
		fileMember >> p1->memRank;   //enum如何使用！！！
		fileMember >> p1->point;
		p2 = (struct member*)malloc(LENMEMBER);
		p1->next = p2;
		p3 = p1;
		p1 = p2;
	}
	p3->next = NULL;
	p1 = p2 = NULL;
	fileMember.close();
	return (head);
}
struct goods* Update::inputPrduct()					//导入商品函数
{
	ifstream fileProduct;
	fileProduct.open("product.txt", ios::in, 1);
	goods *p1, *p2, *p3;
	goods *head;
	head = NULL;
	p1 = p2 = (struct goods*)malloc(LENGOODS);
	head = p1;
	while (fileProduct >> p1->identifi)
	{
		fileProduct >> p1->name;
		fileProduct >> p1->orgin;
		fileProduct >> p1->price;
		p2 = (struct goods*)malloc(LENGOODS);
		p1->next = p2;
		p3 = p1;
		p1 = p2;
	}
	p3->next = NULL;
	p1 = p2 = NULL;
	fileProduct.close();
	return (head);
}
struct shoppingCard* Update::inputShoppingcard()				//导入会员卡信息函数
{
	ifstream fileCard;
	fileCard.open("shoppingcard.txt", ios::in, 1);
	shoppingCard *p1, *p2,*p3;
	shoppingCard *head;
	head = NULL;
	p1 = p2 = (struct shoppingCard*)malloc(LENSHOPPINGCARD);
	head = p1;
	while (fileCard >> p1->identifi)
	{
		fileCard >> p1->balance;
		p2 = (struct shoppingCard*)malloc(LENSHOPPINGCARD);
		p1->next = p2;
		p3 = p1;
		p1 = p2;
	}
	p3->next = NULL;
	p1 = p2 = NULL;
	fileCard.close();
	return (head);
}
void Update::addMember(struct member *p)					//新增会员函数
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
void Update::addProduct(struct goods *p)					//新增产品函数
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
int Update::deleteMember(struct member *p)					//删除会员函数
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
				free(p1);//释放内存
				p1 = p2 = NULL;
			}
			else
			{
				cout << "Input member data is wrong!" << endl;
			}
		}

	}
}
int Update::deleteProduct(struct goods *p)				//删除商品函数
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
				free(p1);//释放内存
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
	cout << "****            超市结算系统                   ****" << endl;
	cout << "****                                           ****" << endl;
	cout << "***************************************************" << endl;
	Update update;
	member* p_member;
	goods* p_goods;
	shoppingCard* p_shopCard;
	p_member=update.inputMember();
	p_goods=update.inputPrduct();
	p_shopCard=update.inputShoppingcard();
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
	    		  Payment payMent;
				  double dou_price;
				  int judgement;
				  dou_price=payMent.getPrduct(p_goods);
				  cout << "Please input the method of payment:";
				  enum payMethod{cash,visa,card,error}payMeth;
				  cin >> userOrder;
				  if ("cash" == userOrder)
				  {
					  payMeth = cash;
				  }
				  if ("visa" == userOrder)
				  {
					  payMeth = visa;
				  }
				  if ("card" == userOrder)
				  {
					  payMeth = card;
				  }
				  else
					  payMeth = error;
				  switch (payMeth)
				  {
				  case cash:
				  {
							   judgement=payMent.pay_cash;
							   if (0 == judgement)
							   {
								   cout << "Cash pay failure" << endl;
							   }
				  }
					  break;
				  case visa:
				  {
							   judgement=payMent.pay_visa(dou_price);
							   if (0 == judgement)
							   {
								   cout << "Visa pay failure" << endl;
							   }
							   
				  }
					  break;
				  case card:
				  {
							   judgement = payMent.pay_card(p_shopCard, dou_price);
							   if (0 == judgement)
							   {
								   cout << "Shoppingcard pay fauilure" << endl;
							   }
				  }
					  break;
				  case error:
				  {
								cout << "Error" << endl;
				  }
					  break;
				  }
	}
		break;
	default:
	{
			   cout << " Input error" << endl;
	}
		break;
	}
	cout << "There is your expense calendar:" << endl;
	system("calendar.txt");
	return 0;
}