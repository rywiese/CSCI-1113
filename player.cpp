#ifndef PLAYER_CPP
#define PLAYER_CPP

#include <iostream>
#include "map.cpp"
using namespace std;


class Player
{
private:
    // character has 3 stats: entertainment, energy and smartness
    Map world;
    int entertainment;
    int energy;
    int smartness;
	
public:
    Player();
    Player(Map world);
    int removeSmartness(int amount);
    void doAction(char action, int time);
    int addSmartness(int amount);
    int removeEnergy(int amount);
    int getSmartness();
    int addEnergy(int amount);
    int getEnergy();
    int removeEntertainment(int amount);
    int addEntertainment(int amount);
    int getEntertainment();
    void displayStats();
    void travel();
    char requestAction();
    void displayMap();

};

// Tell them where they are and what actions they can take (and ask them as the method says)
char Player::requestAction()
{
	// get where you are
	Room location = world.getPlayerLocation();

	// display where you are
	cout << "You are at the " + location.getName() + ".\n";

	// if at uni
	if(location.getName().compare("University") == 0)
	{
		cout << "Do you want to (A)ttend class or (S)leep through lecture?\n";
	}
	// if at dorm
	else if(location.getName().compare("Dorm") == 0)
	{
		cout << "Do you want to (S)leep, do (H)omeowrk or (W)atch some YouTube?\n";
	}
	// if outside
	else if(location.getName().compare("Outside") == 0)
	{
		cout << "Do you want to (S)ocialize or (P)lay Rugby?\n";
	}
	// if you are not in any of the above, we have a problem
	else
	{
		cout << "You are lost in the abyss...\n";
	}
	// they can also change locations by 'G'
	cout << "Do you want to (G)o to a different location?\n";

	// let them enter a choice
	string answer;
	getline(cin,answer);

	// if they entered something, give back the first character (capitalized)
	if(answer.length() > 0)
	{
		return toupper(answer[0]);
	}
	// otherwise they just hit enter (trying to crash me!), so they do nothing
	else
	{
		return ' ';
	}
}


// chage locations
void Player::travel()
{
	// destionations the names of possible destinations
	Room destinations[100];

	// to do this, we need to copy in each name manually
	int roomCount = world.getLocations(destinations);

	// show the possible destinations
	cout << "Where do you want to travel to: (";
	if(roomCount>0)
	{
		cout << destinations[0].getLetter();
	}
	for(int i=1; i < roomCount; i++)
	{
		cout << ", " << destinations[i].getLetter(); 
	}
	cout <<")?\n";

	// read from the keyboard where they want to go
	string response;
	getline(cin, response);
	// if they didn't enter anything (shame on them) they go nowhere
	if(response.length() == 0)
	{
		cout << "You go nowhere...\n";
		return;
	}
	// otherwise pull out the first character
	char r = toupper(response[0]);

	// find the room that matches this character
	Room destination;
	for(int i=0; i < roomCount; i++)
	{
		Room place = destinations[i];
		if(place.getLetter() == r)
		{
			destination = place;
		}
	}

	// if we didnt find the room, they entered a bad character!
	if(destination.getBottomRightX() == -1 ) // not a valid room
	{
		cout << "Invalid location, you go nowhere...\n";
	}
	// otherwise go to that location
	else
	{
		cout << "You go to " + destination.getName() + ".\n";
		world.moveToRoom(destination);            
	}
}

// display stats... yes what the methods says it does...
void Player::displayStats()
{
	cout << "Current stats are: ";
	cout << "Energy = " << energy <<", ";
	cout << "Entertainment = " << entertainment <<", ";
	cout << "Smartness = " << smartness <<".\n";
}


// start out at 70 in each stat
Player::Player()
{
	entertainment = 70;
	energy = 70;
	smartness = 70;
}
	
// hopefully you exist in a world...
Player::Player(Map world)
{
	entertainment = 70;
	energy = 70;
	smartness = 70;

	Player::world = world;
}

// list of possible actions....
void Player::doAction(char action, int time)
{
	// get where we are
	Room location = world.getPlayerLocation();
	string locationName = location.getName();

	// keep track of the effects of our actions...
	int entertainmentChange = 0;
	int energyChange = 0;
	int smartnessChange = 0;

	// long list of options below based on time/location! yay if/else
	if(action == 'G')
	{
		travel();
		energyChange = removeEnergy(4);
	}
	else if(locationName.compare("University") == 0)
	{
		if(8 < time && time < 16)
		{
			if(action == 'S')
			{
				cout << "You put your head down and snore very loudly.\n";
				energyChange = addEnergy(10);
				smartnessChange = addSmartness(1);
				entertainmentChange = removeEntertainment(2);
			}
			else if(action == 'A')
			{
				cout << "You take copious notes and pay close attention to the material.\n";
				energyChange = removeEnergy(4);
				smartnessChange = addSmartness(3);
				entertainmentChange = removeEntertainment(8);
			}
			else
			{
				cout << "Bad command, you do nothing for an hour.\n";
				energyChange = removeEnergy(2);
				entertainmentChange = removeEntertainment(2);
			}
		}
		else
		{
			cout << "There are no classes in session, you waste an hour of your time.\n";
			energyChange = removeEnergy(4);
			entertainmentChange = removeEntertainment(3);
		}
	}
	else if(locationName.compare("Dorm") == 0)
	{
		if(action == 'S')
		{
			if(8 < time && time < 20)
			{
				cout << "Since you are diurnal, you get an hour of unrestful sleep.\n";
				energyChange = addEnergy(4);
				entertainmentChange = removeEntertainment(5);
			}
			else
			{
				cout << "You get a good hour of sleep.\n";
				energyChange = addEnergy(10);
				entertainmentChange = removeEntertainment(5);
			}
		}
		else if(action == 'H')
		{
			cout << "You break out the books and pound through some problems.\n";
			energyChange = removeEnergy(3);
			smartnessChange = addSmartness(3);
			entertainmentChange = removeEntertainment(20);
		}
		else if(action == 'W')
		{
			cout << "OMG!! CATS!!!!\n";
			energyChange = removeEnergy(2);
			smartnessChange = removeSmartness(1);
			entertainmentChange = addEntertainment(20);
		}
		else
		{
			cout << "You stare at the ceiling for an hour...\n";
			energyChange = removeEnergy(1);
			entertainmentChange = removeEntertainment(3);
		}
	}
	else if(locationName.compare("Outside") == 0)
	{
		if(action == 'S')
		{
			cout << "Party hard!\n";
			energyChange = removeEnergy(8);
			entertainmentChange = addEntertainment(8);
		}
		else if(action == 'P')
		{
			if(8 < time && time < 20)
			{
				cout << "You run for almost an hour straight (when not flattened on the ground).\n";
				energyChange = removeEnergy(15);
				smartnessChange = removeSmartness(1);
				entertainmentChange = addEntertainment(12);
			}
			else
			{
				cout << "It is too dark and you end up falling flat on your face.\n";
				energyChange = removeEnergy(6);
				smartnessChange = removeSmartness(3);
				entertainmentChange = removeEntertainment(1);
			}
		}
		else
		{
			cout << "You wander around outside for an hour.\n";
			energyChange = removeEnergy(6);
			smartnessChange = removeSmartness(1);
			entertainmentChange = addEntertainment(3);
		}
	}
	else
	{
		cout << "You are currently lost, which is not a lot of fun\n";
		energyChange = removeEnergy(2);
		entertainmentChange = removeEntertainment(2);
	}

	// end list of actions based on time/location

	// tell the user the effects of actions
	cout << "From your actions changed your stats by... ";
	cout << "Energy: " << energyChange << ", ";
	cout << "Entertainment: " << entertainmentChange << ", ";
	cout << "Smartness: " << smartnessChange << ".\n";
}        



// !!! WARNING !!! proceed past here at your own risk
// below are methods for adding, removing and getting the value the 3 stats

// get the value of entertainment
int Player::getEntertainment()
{
	return entertainment;
}
// adds amount to "entertainment" and returns the change
int Player::addEntertainment(int amount)
{
	// remember the old value
	int oldEntertainment = entertainment;

	// add the entertainment amount
	entertainment = entertainment + amount;

	// don't let entertainment go over 100
	entertainment = min(entertainment, 100);

	return entertainment - oldEntertainment;
}

//subtracts amount from "entertainment" and returns the change
int Player::removeEntertainment(int amount)
{
	// remember the old value
	int oldEntertainment = entertainment;

	// add the entertainment amount
	entertainment = entertainment - amount;

	// don't let entertainment go under 0
	entertainment = max(entertainment, 0);

	return entertainment - oldEntertainment;
}

// get the value of energy
int Player::getEnergy()
{
	return energy;
}

// adds amount to "energy" and returns the change
int Player::addEnergy(int amount)
{
	// remember the old value
	int oldEnergy = energy;

	// add the energy amount
	energy = energy + amount;

	// don't let energy go over 100
	energy = min(energy, 100);

	return energy - oldEnergy;
}


// get the value of entertainment
int Player::getSmartness()
{
	return smartness;
}


//subtracts amount from "energy" and returns the change
int Player::removeEnergy(int amount)
{
	// remember the old value
	int oldEnergy = energy;

	// add the energy amount
	energy = energy - amount;

	// don't let energy go under 0
	energy = max(energy, 0);

	return energy - oldEnergy;
}
// adds amount to "smartness" and returns the change
int Player::addSmartness(int amount)
{
	// remember the old value
	int oldSmartness = smartness;

	// add the smartness amount
	smartness = smartness + amount;

	// don't let smartness go over 100
	smartness = min(smartness, 100);

	return smartness - oldSmartness;
}


//subtracts amount from "smartness" and returns the change
int Player::removeSmartness(int amount)
{
	// remember the old value
	int oldSmartness = smartness;

	// add the smartness amount
	smartness = smartness - amount;

	// don't let smartness go under 0
	smartness = max(smartness, 0);

	return smartness - oldSmartness;
}

// shows the map to the screen
void Player::displayMap()
{
	// cannot do this directly as map is private
	world.displayMap();
}

#endif
