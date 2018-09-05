#include <string>

using namespace std;

const int SIZE = 10000;

class Receipt {
private:
	string* items;
	int* prices;
	int position;
public:
	Receipt();
	Receipt(int length);
	~Receipt();
	void add(string name, int cost);
};

Receipt::Receipt()
{
	items = new string[SIZE];
	prices = new int[SIZE];
	position = 0;
	for(int i=0; i < SIZE; i++)
	{
		items[i] = "!Invalid!";
		prices[i] = -1;
	}
}

Receipt::Receipt(int length)
{
	items = new string[length];
	prices = new int[length];
	position = 0;
	for(int i=0; i < length; i++)
	{
		items[i] = "!Invalid!";
		prices[i] = -1;
	}
}

Receipt::~Receipt()
{
	delete [] items;
	delete [] prices;
}


void Receipt::add(string name, int cost)
{
	items[position] = name;
	prices[position] = cost;
	position++;
}
