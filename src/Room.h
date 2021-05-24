#ifndef _ROOM_H_
#define _ROOM_H_

using namespace std;

class Room {
private:
	string name;
	int dire[4];
public:
	Room();
	Room(string str, int* a);
	Room(const Room& room);
	~Room() {}

	friend ostream& operator<<(ostream& out, const Room& room) {
		out << room.name;
		return out;
	}
};

#endif
