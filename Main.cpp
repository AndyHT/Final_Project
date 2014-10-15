//未完成部分：多次结算有问题；二叉树
//需修改内容：struct的封装
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
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
	int memNumber;//新增会员编号
	string name;
	string sex;
	long phoneNumber;
	string memRank;
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
	float getPrduct(struct goods *p);
	int pay_cash(float _price);
	int pay_visa(float _price);
	int pay_card(struct shoppingCard *p,float _price);
	void settleMember();
};
float Payment::getPrduct(struct goods *p)
{
	ofstream fileCalendar("calendar.txt");
	fileCalendar << "Expense Calendar" << endl;
	struct goods *p1, *p2;
	p1 = p2 = p;
	int TotalAmount = 0;
	float TotalPrice = 0;
	long _identifi;
	while (1)
	{
		cout << "Please input product Identification:";
		cin >> _identifi;
		if (0 == _identifi)
		{
			cout << "All products are record" << endl;
			break;
		}
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
	}
	cout << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
	fileCalendar << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
	fileCalendar.close();
	return(TotalPrice);
}
int Payment::pay_cash(float _price)
{
	cout << "Please intput the payment amount:";
	double _pay;
	cin >> _pay;
	if (_pay - _price < 0.0)
	{
		return 0;
	}
	cout << "The change:" << _pay - _price << endl;
	return 1;
}
int Payment::pay_visa(float _price)
{
	cout << "Please input visa number:";
	long visaNumber;
	cin >> visaNumber;
	cout << "Please input name:";
	string visaName;
	cin >> visaName;
	cout << "Pay completed" << endl;
	return 1;
}
int Payment::pay_card(struct shoppingCard *p,float _price)
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
class MemberPayment :public Payment			//会员结算派生类
{
public:
	float memberGetPrice(struct member *p_mem, struct goods *p_goods);

};//未完成！！！
float MemberPayment::memberGetPrice(struct member *p_mem,struct goods *p_goods)
{
	cout << "Please input your member number";
	int _memNum;
	cin >> _memNum;
	struct member *p_m1, *p_m2;
	struct goods *p_g1, *p_g2;
	int TotalAmount = 0;
	float TotalPrice = 0;
	ofstream fileCalendar("calendar.txt");
	fileCalendar << "Expense Calendar(regular)" << endl;
	p_m1 = p_m2 = p_mem;
	p_g1 = p_g2 = p_goods;
	while (_memNum!=p_m1->memNumber||NULL==p_m1)
	{
		p_m1 = p_m2->next;
		p_m2 = p_m1;
	}
	if (NULL == p_m1)
	{
		cout << "Member number input error" << endl;
	}
	if ("regular" == p_m1->memRank)
	{
		long _identifi;
		while (1)
		{
			cout << "Method of pay:regular" << endl;
			cout << "Please input product Identification:";
			cin >> _identifi;
			if (0 == _identifi)
			{
				cout << "All products are record" << endl;
				break;
			}
			cout << "Please input amount:";
			int _amount = 1;
			cin >> _amount;
			for (; p_g1->identifi != _identifi;)
			{
				p_g1 = p_g2->next;
				p_g2 = p_g1;
			}
			cout << "Product name:" << p_g1->name << "\tProduct orgin:" << p_g1->orgin << "\tProduct price:" << p_g1->price << endl;
			fileCalendar << "Product name:" << p_g1->name << "\tProduct orgin:" << p_g1->orgin << "\tProduct price:" << p_g1->price << endl;
			TotalAmount = TotalAmount + _amount;
			TotalPrice = _amount*p_g1->price + TotalPrice;
		}
		if (TotalPrice > 2000 && TotalPrice <= 5000)
		{
			TotalPrice = (TotalPrice - 2000)*0.95 + 2000;
		}
		if (TotalPrice > 5000)
		{
			TotalPrice = (TotalPrice - 5000)*0.9 + 5000;
		}
		else
		{
			;
		}
		cout << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
		fileCalendar << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
		fileCalendar.close();
		return(TotalPrice);
	}
	if ("silver" == p_m1->memRank)
	{
		long _identifi;
		while (1)
		{
			cout << "Method of pay:silver" << endl;
			cout << "Please input product Identification:";
			cin >> _identifi;
			if (0 == _identifi)
			{
				cout << "All products are record" << endl;
				break;
			}
			cout << "Please input amount:";
			int _amount = 1;
			cin >> _amount;
			for (; p_g1->identifi != _identifi;)
			{
				p_g1 = p_g2->next;
				p_g2 = p_g1;
			}
			cout << "Product name:" << p_g1->name << "\tProduct orgin:" << p_g1->orgin << "\tProduct price:" << p_g1->price << endl;
			fileCalendar << "Product name:" << p_g1->name << "\tProduct orgin:" << p_g1->orgin << "\tProduct price:" << p_g1->price << endl;
			TotalAmount = TotalAmount + _amount;
			TotalPrice = _amount*p_g1->price + TotalPrice;
		}
		if (TotalPrice > 1000 && TotalPrice<2000)
		{
			TotalPrice = (TotalPrice - 1000)*0.9 + 1000;
		}
		if (TotalPrice > 2000)
		{
			TotalPrice = (TotalPrice - 2000)*0.85 + 2000;
		}
		else
		{
			TotalPrice = TotalPrice*0.95;
		}
		cout << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
		fileCalendar << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
		fileCalendar.close();
		return(TotalPrice);
	}
	if ("gold" == p_m1->memRank)
	{
		long _identifi;
		while (1)
		{
			cout << "Method of pay:gold" << endl;
			cout << "Please input product Identification:";
			cin >> _identifi;
			if (0 == _identifi)
			{
				cout << "All products are record" << endl;
				break;
			}
			cout << "Please input amount:";
			int _amount = 1;
			cin >> _amount;
			for (; p_g1->identifi != _identifi;)
			{
				p_g1 = p_g2->next;
				p_g2 = p_g1;
			}
			cout << "Product name:" << p_g1->name << "\tProduct orgin:" << p_g1->orgin << "\tProduct price:" << p_g1->price << endl;
			fileCalendar << "Product name:" << p_g1->name << "\tProduct orgin:" << p_g1->orgin << "\tProduct price:" << p_g1->price << endl;
			TotalAmount = TotalAmount + _amount;
			if (p_g1->price > 10 && p_g1->price < 20)
			{
				TotalPrice = _amount*p_g1->price*0.95 + TotalPrice;
			}
			if (p_g1->price>20)
			{
				TotalPrice = _amount*p_g1->price*0.9 + TotalPrice;
			}
			else
				TotalPrice = _amount*p_g1->price + TotalPrice;
		}
		cout << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
		fileCalendar << "Total product amount:" << TotalAmount << "\tTotal price:" << TotalPrice << endl;
		fileCalendar.close();
		return(TotalPrice);
	}
}
struct member* Update::inputMember()					//导入会员函数
{
	ifstream fileMember("member.txt");
	struct member *p1, *p2, *p3;
	struct member *head;
	head = p3 = NULL;
	p1 = p2 = new member;
	head = p1;
	while (fileMember>>p1->name)
	{
		fileMember >> p1->sex;
		fileMember >> p1->phoneNumber;
		fileMember >> p1->memRank;
		fileMember >> p1->point;
		fileMember >> p1->memNumber;
		p2 = new member;
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
	ifstream fileProduct("product.txt");
	goods *p1, *p2, *p3;
	goods *head;
	head = p3 = NULL;
	p1 = p2 = new goods;
	head = p1;
	while (fileProduct >> p1->identifi)
	{
		fileProduct >> p1->name;
		fileProduct >> p1->orgin;
		fileProduct >> p1->price;
		p2 = new goods;
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
	ifstream fileCard("shoppingcard.txt");
	shoppingCard *p1, *p2,*p3;
	shoppingCard *head;
	head = p3 = NULL;
	p1 = p2 = new shoppingCard;
	head = p1;
	while (fileCard >> p1->identifi)
	{
		fileCard >> p1->balance;
		p2 = new shoppingCard;
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
	p1->next = new member;
	p = p1->next;
	cout << "Please input new member data";
	cout << "Please input name:";
	cin >> p->name;
	cout << "Please input sex";
	cin >> p->sex;
	cout << "Please input phone number";
	cin >> p->phoneNumber;
	//需要生成一个会员编号
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
	p1->next = new goods;
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
				delete p1;
				p1 = p = NULL;
				return 1;
			}
			if (NULL == p1->next&&p1->phoneNumber == d_phoneNumber)
			{
				delete p1;
				p3->next = NULL;
				p1 = p2 = NULL;
				return 1;
			}
			else
			{
				cout << "Input member data is wrong!" << endl;
				return 0;
			}
		}
		else
		{
			if (p1->phoneNumber == d_phoneNumber)
			{
				p3->next = p1->next;
				delete p1;//释放内存
				p1 = p2 = NULL;
				return 1;
			}
			else
			{
				cout << "Input member data is wrong!" << endl;
				return 0;
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
		cout << "All has stopped" << endl;
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
				delete p1;
				p1 = p = NULL;
				return 1;
			}
			if (NULL == p1->next&&p1->name == d_name)
			{
				delete p1;
				p3->next = NULL;
				p1 = p2 = NULL;
				return 1;
			}
			else
			{
				cout << "Input product data is wrong!" << endl;
				return 0;
			}
		}
		else
		{
			if (p1->name == d_name)
			{
				p3->next = p1->next;
				delete p1;//释放内存
				p1 = p2 = NULL;
				return 1;
			}
			else
			{
				cout << "Input product data is wrong!" << endl;
				return 0;
			}
		}

	}

}
int main()//会员结算还未插入
{
	cout << "***************************************************" << endl;
	cout << "****            超市结算系统                   ****" << endl;
	cout << "****                                           ****" << endl;
	cout << "***************************************************" << endl;
	Update update;
	member* p_member = NULL;
	goods* p_goods = NULL;
	shoppingCard* p_shopCard = NULL;
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
				  while (1)
				  {
					  Payment payMent;
					  float f_price;
					  int judgement;
					  f_price = payMent.getPrduct(p_goods);
					  cout << "Please input the method of payment:";
					  enum payMethod{ cash, visa, card, error }payMeth;
					  cin >> userOrder;
					  if ("0" == userOrder)
						  break;
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
								   judgement = payMent.pay_cash(f_price);
								   if (0 == judgement)
								   {
									   cout << "Cash pay failure" << endl;
								   }
					  }
						  break;
					  case visa:
					  {
								   judgement = payMent.pay_visa(f_price);
								   if (0 == judgement)
								   {
									   cout << "Visa pay failure" << endl;
								   }

					  }
						  break;
					  case card:
					  {
								   judgement = payMent.pay_card(p_shopCard, f_price);
								   if (0 == judgement)
								   {
									   cout << "Shoppingcard pay fauilure" << endl;
								   }
					  }
						  break;
					  default:
					  {
								 cout << "Error input" << endl;
					  }
						  break;
					  }
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