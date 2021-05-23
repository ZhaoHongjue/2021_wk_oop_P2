#ifndef _ROOM_H_
#define _ROOM_H_

using namespace std;

class Room {
private:
	string name;
public:
	Room() {};
	Room(string str):name(str) {}
	Room(const Room& room);
	~Room() {}

	friend ostream& operator<<(ostream& out, const Room& room);	
};

#endif
