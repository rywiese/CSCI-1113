#ifndef MAP_CPP
#define MAP_CPP

#include <string>
#include <iostream>

using namespace std;

class Room {
private:
    // letters outline where the location is
    char mapLetter;

    // locations are rectangles....
    int topLeftX;
    int topLeftY;
    int bottomRightX;
    int bottomRightY;

    // all good things have a name, right?
    string roomName;

    // constructor to make a room!  need all the above information
public:
	Room();
	Room(string name, char symbol, int tlx, int tly, int brx, int bry);
    // Below: get functions to get all the information about a room

    string getName();
    char getLetter();
    int getTopLeftX();
    int getTopLeftY();
    int getBottomRightX();
    int getBottomRightY();
};

Room::Room()
{
	roomName="The Void";
	mapLetter='?';
	topLeftX=-1;
	topLeftY=-1;
	bottomRightX=-1;
	bottomRightY=-1;
}	

Room::Room(string name, char symbol, int tlx, int tly, int brx, int bry)
{
	roomName=name;
	mapLetter=symbol;
	topLeftX=tlx;
	topLeftY=tly;
	bottomRightX=brx;
	bottomRightY=bry;
}

string Room::getName()
{
	return roomName;
}

char Room::getLetter()
{
	return mapLetter;
}

int Room::getTopLeftX()
{
	return topLeftX;
}

int Room::getTopLeftY()
{
	return topLeftY;
}

int Room::getBottomRightX()
{
	return bottomRightX;
}

int Room::getBottomRightY()
{
	return bottomRightY;
}


/* ABOVE ROOM */
/* BELOW MAP */

class Map {
private:
    // size of the world
    static const int MAX_ROWS = 20;
    static const int MAX_COLUMNS = 40;

    // characters for blank space and you, the player
    static const char BLANK = ' ';
    static const char PLAYER = 'Y';

    // stores all the characters on the world
    char grid[MAX_ROWS][MAX_COLUMNS];
    
    // list of the possible locations to go to
    Room mapRooms[100];
    int usedRooms;

    // current place you are
    Room currentLocation;
    void generateMap();
    
public:
    Map();
    void addRoom(Room r);
    void displayMap();    // this simply shows the map on the screen...
    Room getPlayerLocation();
    int getLocations(Room changeMe[100]); // copies rooms into changeMe, returns the size
    void moveToRoom(Room destination);


};

Map::Map()
{
	usedRooms = 0;
	
	// initialize the map to be blank
	for(int i=0; i < MAX_ROWS; i++)
	{
		for(int j=0; j < MAX_COLUMNS; j++)
		{
			grid[i][j] = BLANK;
		}
	}

	// make 3 rooms
	Room outside("Outside", 'O', 0,0, 39,19);
	Room university("University", 'U', 5,5, 15,15);
	Room dorm("Dorm", 'D', 25,5, 30,10);

	// add them to our arrayList
	addRoom(outside);
	addRoom(university);
	addRoom(dorm);

	// start out in your room
	currentLocation = dorm;
	moveToRoom(currentLocation);

	// generate the map (rooms)
	generateMap();
}

void Map::addRoom(Room r)
{
	mapRooms[usedRooms] = r;
	usedRooms++;
}

void Map::generateMap()
{
	// for all the rooms we have in our list...
	for(int i=0; i < usedRooms; i ++)
	{
		Room place = mapRooms[i];
		// Fill in top and bottom of rectangle with characters
		for(int i = place.getTopLeftX(); i <= place.getBottomRightX(); i++)
		{
			grid[place.getTopLeftY()][i] = place.getLetter();
			grid[place.getBottomRightY()][i] = place.getLetter();
		}
		// fill in left and right side...
		for(int i = place.getTopLeftY(); i <= place.getBottomRightY(); i++)
		{
			grid[i][place.getTopLeftX()] = place.getLetter();
			grid[i][place.getBottomRightX()] = place.getLetter();
		}
	}
}

// this simply shows the map on the screen...
void Map::displayMap()
{
	for(int i=0; i < MAX_ROWS; i++)
	{
		for(int j=0; j < MAX_COLUMNS; j++)
		{
			cout << " " << grid[i][j];
		}
		cout << endl;
	}
}

// get where we are
Room Map::getPlayerLocation()
{
	return currentLocation;
}

// get the possible locations to go to
int Map::getLocations(Room changeMe[100])
{
	for(int i=0; i < usedRooms; i++)
	{
		changeMe[i] = mapRooms[i];
	}
	
	return usedRooms;
}

// update the map so the player symbol moves to the a new location
void Map::moveToRoom(Room destination)
{
	// if were somewhere before
	if(currentLocation.getTopLeftY() != -1) // if this is false, the room does not exist
	{
		// remove the mark from the center of the previous location
		grid[currentLocation.getTopLeftY() + (currentLocation.getBottomRightY() - currentLocation.getTopLeftY())/2]
				[currentLocation.getTopLeftX() +(currentLocation.getBottomRightX() - currentLocation.getTopLeftX())/2]
				= BLANK;
	}

	// update where we are
	currentLocation = destination;

	// add player mark to center of new location
	grid[currentLocation.getTopLeftY() + (currentLocation.getBottomRightY() - currentLocation.getTopLeftY())/2]
			[currentLocation.getTopLeftX() + (currentLocation.getBottomRightX() - currentLocation.getTopLeftX())/2]
			= PLAYER;			
			
}
#endif
