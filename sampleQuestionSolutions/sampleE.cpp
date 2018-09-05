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
	friend ostream& operator<<(ostream& out, CheckOutItem item);
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

ostream& operator<<(ostream& out, CheckOutItem item)
{
	out << "(" << item.item << ", " << item.price << ")";
	//               ^^ maybe not the best naming...
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


int main()
{
	Receipt a;
	Receipt b;
	
	
	Receipt temp;
	temp = a;
	a = b;
	b = temp;
	// this works, but you MUST be careful that these lines DO NOT copy the lists.
	// instead, they mearly copy the pointers to the lists
	
	// this means if we did temp.add(), it would appear in b's list as well
	// Yet, the position variable between temp and b are NOT shared
	
	// thus there are 2 position variables between b and temp, yet only one list
	// this will also segmentation fault, as the deconstructor will attempt to delete both temp and b's lists, and thus delete it twice
}
