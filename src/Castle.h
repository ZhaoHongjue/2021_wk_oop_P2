#ifndef _CASTLE_H_
#define _CASTLE_H_

#include <vector>
#include "Room.h"
#include "Role.h"
using namespace std;

class Castle {
private:
	vector<Room> castle;
public:
	Castle();
	~Castle() {}
	void display();
};

#endif
