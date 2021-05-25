#ifndef _ROOM_H_
#define _ROOM_H_

#include "Role.h"
#include <vector>
using namespace std;

class Room {
private:
	// 房间名称
	string name;	
	// 房间数目
	int cnt;		
	// 方向，0表示无此方向，数字代表对应的房间号
	int dire[4];
	vector<Role> role_vec;
public:
	Room();
	Room(string str, int* a);
	Room(const Room& room);
	~Room() {}

	//返回房间的名字
	string getName() {return name;}
	//在房间里增加成员
	void AddRole(Role role);

	friend ostream& operator<<(ostream& out, Room& room);
};

#endif
