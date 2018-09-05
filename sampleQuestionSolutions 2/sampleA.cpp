#include <string>

using namespace std;

const int SIZE = 10000;

class Receipt {
private:
	string items[SIZE];
	int prices[SIZE];
	int position;
public:
	Receipt();
	void add(string name, int cost);
};

Receipt::Receipt()
{
	position = 0;
	for(int i=0; i < SIZE; i++)
	{
		items[i] = "!Invalid!";
		prices[i] = -1;
	}
}

void Receipt::add(string name, int cost)
{
	items[position] = name;
	prices[position] = cost;
	position++;
}
