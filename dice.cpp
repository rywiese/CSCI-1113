#include <iostream>
#include <cstdlib>

using namespace std;

int* startEndPairs(string s);

int main()
{
	srand(time(0)); // DO NOT WRITE THIS LINE AGAIN OR ANYWHERE ELSE
	cout << "What do you want to roll?  ";
	string s;
	getline(cin, s);
	int* pairs = startEndPairs(s); // DOTH NOT FORGET TO DELETE ME

	// here is what you have
	for(int i=1; i < pairs[0]; i+=2)
	{
		cout << "["<<pairs[i]<<","<<pairs[i+1]<<"]\n";
	}
}


int* startEndPairs(string s)
{
	// count how many '+'s or 'd's there are...
	int parts = 0;
	for(int i=0; i < static_cast<signed>(s.length()); i++)
	{
		if(s[i] == 'd' || s[i] == '+')
		{
			parts++;
		}
	}
	// ... so we can make the correct size array to store the info
	string* data = new string[2*parts];
	
	int index=0;
	unsigned d = s.find('d');
	unsigned p = s.find('+');
	while(d != static_cast<unsigned>(-1) || p != static_cast<unsigned>(-1))
	{
		bool dFirst = d < p;
		if(dFirst)
		{
			string before = s.substr(0,d); // part before the 'd' (should be just one number)
			// figure out what number is after 'd'
			int count = 0;
			bool foundDigit=false;					
			for(int i=0; i< static_cast<signed>(s.length()-d-1); i++)
			{
				if(isdigit(s[count+d+1]))
				{
					foundDigit=true;
				}
				if(!isdigit(s[count+d+1]) && foundDigit)
				{
					break;
				}
				count++;
			}
			string after = s.substr(d+1,count); //should be just the number after 'd'
			
			// store these two parts
			data[index] = before;
			data[index+1] = after;
			index+=2;
			
			
			// remove this part from the string s
			s = s.substr(d+count+1); // discard these two parts
		}
		else // same idea for the '+'
		{
			// figure out what number is after '+'
			int count = 0;					
			bool foundDigit=false;
			for(int i=0; i< static_cast<signed>(s.length()-p-1); i++)
			{
				if(isdigit(s[count+p+1]))
				{
					foundDigit=true;
				}
				if(!isdigit(s[count+p+1]) && foundDigit)
				{
					break;
				}
				count++;
			}
			string after = s.substr(p+1,count); //should be just the number after '+'

			// store this part
			data[index] = "+";
			data[index+1] = after;
			index+=2;
			
			
			// remove this part from the string s
			s = s.substr(p+count+1); // discard these two parts
		}
	
	// update d and p for next loop interation	
	d = s.find('d');
	p = s.find('+');

	}
	
	// now we need to figure out how many dice there are (as 2d4 is 2 dice)
	// we will treat "+2" as a dice that rolls [2,2]
	int diceCount = 0;
	for(int i=0; i < parts*2; i+=2)
	{
		if(data[i][0] == '+')
		{
			diceCount++;
		}
		else
		{
			diceCount+=atoi(data[i].c_str());
		}
	}
	
	int* dice = new int[diceCount*2+1]; // one extra to store the size
	dice[0] = diceCount*2+1; // put size in first index
	
	int ind=1; // index for the "dice" array (as not same as data array)
	for(int i=0; i < parts*2; i+=2)
	{
		// if we have a +, add a "Dice" that has a range of 0
		if(data[i][0] == '+')
		{
			dice[ind] = atoi(data[i+1].c_str());
			dice[ind+1] = atoi(data[i+1].c_str());
			
			ind+=2;
		}
		else // otherwise add however many of the dice requested
		{
			for(int j=0; j < atoi(data[i].c_str()); j++)
			{
				dice[ind] = 1;
				dice[ind+1] = atoi(data[i+1].c_str());
				
				ind += 2;
			}
		}
	}
	
	return dice;
}
