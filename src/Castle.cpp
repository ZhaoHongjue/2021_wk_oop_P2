#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Castle.h"
#include "Room.h"
#include "Role.h"
using namespace std;

Castle::Castle()
{
	// 0
	int lobby_dire[4] = {1,-1,11,-1};
	castle.push_back(Room("lobby",lobby_dire));
	// 1
	int living_dire[4] = {2,-1,0,-1};
	castle.push_back(Room("living room",living_dire));
	// 2
	int stair1_dire[4] = {3,10,1,6};
	castle.push_back(Room("stair 1",stair1_dire));
	// 3
	int dine_dire[4] = {4,-1,2,-1};
	castle.push_back(Room("dining room",dine_dire));
	// 4 
	int wash1_dire[4] = {-1,-1,3,-1};
	castle.push_back(Room("washroom 1",wash1_dire));
	// 5
	int guest_dire[4] = {6,-1,-1,-1};
	castle.push_back(Room("guest bedroom",guest_dire));
	// 6
	int stair2_dire[4] = {7,2,5,-1};
	castle.push_back(Room("stair 2",stair2_dire));
	// 7
	int master_dire[4] = {8,-1,6,9};
	castle.push_back(Room("master bedroom",master_dire));
	// 8
	int wash2_dire[4] = {-1,-1,7,-1};
	castle.push_back(Room("washroom 2",wash2_dire));
	// 9
	int storage_dire[4] = {-1,7,-1,-1};
	castle.push_back(Room("storage",storage_dire));
	// 10
	int base_dire[4] = {-1,-1,-1,2};
	castle.push_back(Room("basement",base_dire));
	// 11
	int out_dire[4] = {0,-1,-1,-1};
	castle.push_back(Room("out",out_dire));

	//在指定合适的位置生成公主和怪兽
	int tmp[] = {4,8,9,5,10};
	srand((unsigned)time(NULL));
	int rand1, rand2;
	do {
		rand1 = rand()%(sizeof(tmp)/sizeof(tmp[0]));
		rand2 = rand()%(sizeof(tmp)/sizeof(tmp[0]));
	} while(rand1 == rand2);
	castle[tmp[rand1]].AddRole(Role("Princess",castle[tmp[rand1]].getName()));
	castle[tmp[rand2]].AddRole(Role("Monster",castle[tmp[rand2]].getName()));
}

//找到公主或怪兽所在的地方，找公主则tag为1，找怪兽则tag为0
string Castle::getRolePlace(int tag)
{
	int i;
	for(i = 0; i < castle.size(); i++) {
		if(tag) {
			if(castle[i].FindRole(Role("Princess"))!=-1) break;
		}
		else {
			if(castle[i].FindRole(Role("Monster"))!=-1) break;
		}
	}
	return castle[i].getName();
}

//根据房间名找地点
Room& Castle::getRoom(string place)
{
	vector<Room>::iterator it;
	for(it = castle.begin(); it < castle.end(); it++) {
		if(place == it->getName()) break;
	}
	return *it;
}

//根据房间编号找房间
Room& Castle::getRoom(int num)
{
	return castle[num];
}

//移动人物
void Castle::MvRole(Role role, int d)
{
	//判断人物在不在房间里
	vector<Room>::iterator it;
	int flag = 0;
	for(it = castle.begin(); it < castle.end(); it++) {
		if(role.whereis() == it->getName()) {flag = 1; break;}
	}

	if(!flag) {cout << "he is not in this room!" << endl; return; }
	else{
		//移动到对应方向
		int *dire = it->getDire();
		if(dire[d] != -1) {
			it->RmRole(role);
			castle[dire[d]].AddRole(role);
		}
		else cout << "You can't go to that direction!" << endl;
	}
}
