#ifndef _ROOM_H_
#define _ROOM_H_

#include "Role.h"
#include <vector>
using namespace std;

class Room {
private: 
	string name;			// 房间名称	
	int cnt;				// 房间数目	
	int dire[4];			// 方向，0表示无此方向，数字代表对应的房间号
	vector<Role> role_vec;	// 人物列表
public:
	// 构造函数
	Room();
	Room(string str, int* a);
	Room(const Room& room);
	~Room() {}

	//返回房间的名字
	string getName() {return name;}
	int* getDire() {return dire;}
	
	void AddRole(Role role);	//在房间里增加成员
	void RmRole(Role role);		//删除成员
	int FindRole(Role role);	//查找成员
	int MeetRole();				//判断在当前房间里遇到了公主还是怪物

	void PlaceMsg();
	void RoleMsg(int MeetPrin);
};

#endif
