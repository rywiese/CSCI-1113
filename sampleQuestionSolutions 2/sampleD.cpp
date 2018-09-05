#include <iostream>
#include <string>

using namespace std;

const int SIZE = 10000;

class CheckOutItem{
private:
	string item;
	int price;
public:
	CheckOutItem();
	CheckOutItem(string name, int cost);
	friend ostream& operator<<(ostream& out, CheckOutItem good);
};

CheckOutItem::CheckOutItem()
{
	item = "!Invalid!";
	price = -1;
}

CheckOutItem::CheckOutItem(string name, int cost)
{
	item = name;
	price = cost;
}

ostream& operator<<(ostream &out, CheckOutItem good)
{
	out << "(" << good.item << ", " << good.price << ")";
	return out;
}

class Receipt {
private:
	CheckOutItem* list;
	int position;
public:
	Receipt();
	Receipt(int length);
	~Receipt();
	void add(string name, int cost);
};

Receipt::Receipt()
{
	position = 0;
	list = new CheckOutItem[SIZE];
	for(int i=0; i < SIZE; i++)
	{
		list[i] = CheckOutItem();
	}
}

Receipt::Receipt(int length)
{
	position = 0;
	list = new CheckOutItem[length];
	for(int i=0; i < length; i++)
	{
		list[i] = CheckOutItem();
	}
}

Receipt::~Receipt()
{
	delete [] list;
}

void Receipt::add(string name, int cost)
{
	CheckOutItem makinIt = CheckOutItem(name,cost);
	list[position] = makinIt;
	position++;
}
