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
	
	
	//Receipt temp;
	//temp = a;
	//a = b;
	//b = temp;
	// this works, but you MUST be careful that these lines DO NOT copy the lists.
	// instead, they mearly copy the pointers to the lists
	
	// this means if we did temp.add(), it would appear in b's list as well
	// Yet, the position variable between temp and b are NOT shared
	
	// thus there are 2 position variables between b and temp, yet only one list
	
	
	Receipt* ptr1;
	Receipt* ptr2;
	
	ptr1 = &a;
	ptr2 = &b;
	
	// swap!
	Receipt* tempPtr;
	tempPtr = ptr1;
	ptr1 = ptr2;
	ptr2 = tempPtr;
	
	// As these are pointers, the issue above never happens
	// temp and b are pointing to the same thing, so they are sharing
	// however, they are sharing EVERYTHING (thus only 1 position and 1 list between the two of them)
}
