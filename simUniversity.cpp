#include <iostream>
#include <string>
#include "map.cpp"
#include "player.cpp"

using namespace std;

// the current time (0:00  - 23:59)
int dayTime = 8;

// you, the player
Player player;

// some useful functions...
void clearScreen();
void displayTime();
bool updatePlayer();

int main() 
{
	// hey! its a map
	Map world;

	// player needs to know about the map
	player = Player(world);

	// not over yet!
	bool gameOver = false;

	while(!gameOver)
	{
		// methods names should be informative enough
		clearScreen();
		player.displayMap();
		player.displayStats();
		displayTime();
		// get the action after showing a list of options
		char action = player.requestAction();
		cout << "\n";
		// find out the effects of that action
		player.doAction(action, dayTime);

		// process what happened and end the game if we lose
		gameOver = updatePlayer();

		// wait so the person can
		cout << "(Press enter to advance an hour)";
		string temp;
		getline(cin, temp);
	}

	// ruh roh
	cout << "Game Over!\n";
	return 0;
}

void displayTime()
{
	// display the time
	cout << "Current time: "<<dayTime<<":00.  \n";

	// add an hour (and loop so 24:00 -> 0:00)
	dayTime = (dayTime+1)%24;
}


bool updatePlayer()
{

	// default: keep on player
	bool gameOver = false;

	// all work and no play...
	if(player.getEntertainment() == 0)
	{
		cout << "Your life is sapped of color and you become a mindless cog in the population.\n";
		gameOver = true;
	}
	// dum dum dummmm!
	else if(player.getSmartness() == 0)
	{
		cout << "You drop out of college and are forced to drive taxis for the rest of your life.\n";
		gameOver = true;
	}

	return gameOver;
}

// hack!
void clearScreen()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
