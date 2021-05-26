#include <iostream>
#include "Castle.h"
#include "Room.h"
#include "Role.h"
using namespace std;

Castle::Castle()
{
	int lobby_dire[4] = {-1,1,2,-1};
	Room lobby("lobby",lobby_dire);
	lobby.AddRole(Role("Princess","lobby"));
	castle.push_back(lobby);

	int basement_dire[4] = {-1,-1,-1,0};
	castle.push_back(Room("basement",basement_dire));
}

void Castle::display()
{
	vector<Room>::iterator it;
	for(it = castle.begin(); it < castle.end(); it++) {
		cout << *it << endl;
	}
}
