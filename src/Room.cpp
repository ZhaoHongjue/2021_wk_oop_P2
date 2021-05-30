#include <iostream>
#include "Room.h"
#include "Role.h"
#include <vector>
using namespace std;

//默认构造函数
Room::Room()
{
    name = "none";
    for(int i = 0; i < 4; i++) {
        dire[i] = -1;
    }
    cnt = 0;
    role_vec.clear();
}

//带参构造函数
Room::Room(string str, int* a):name(str)
{
    cnt = 0;
    for(int i = 0; i < 4; i++) {
        dire[i] = a[i];
        if(dire[i] != -1) cnt++;
    }
    role_vec.clear();
}

//Room的拷贝构造函数
Room::Room(const Room& room)
{
    name = room.name;
    for(int i = 0; i < 4; i++) {
        dire[i] = room.dire[i];
    }
    cnt = room.cnt;
    role_vec.clear();
    for(int i = 0; i < room.role_vec.size(); i++) {
        role_vec.push_back(room.role_vec[i]);
    }
}

// 房间内增加成员
void Room::AddRole(Role role)
{
    if(FindRole(role) == -1) role_vec.push_back(role);
}

int Room::FindRole(Role role)
{
	int i = 0, flag = 0;
	for(i = 0;i < role_vec.size();i++) {
        if(role_vec[i] == role) {
            flag = 1;
            break;
        }
    } 
	if(flag) return i;
	else return -1;
}

//房间内删除成员
void Room::RmRole(Role role)
{	
	int i = FindRole(role);
	if(i != -1) {
        if(i == 0) role_vec.clear();
        else role_vec.erase(role_vec.begin()+i);
    }
}

//判断在当前房间里遇到了公主还是怪物
int Room::MeetRole()
{
    int ret = 0;
    for(int i = 0; i < role_vec.size();i++) {
        if(role_vec[i].getName() == "Monster") {
            ret = -1;
            break;
        }
        else if(role_vec[i].getName() == "Princess") {
            ret = 1;
            break;
        }
    }
    return ret;
}

//房间的出口信息
void Room::PlaceMsg()
{
    cout << "Now you are at the " << name <<" of this Castle. There are ";
    cout << cnt <<  " exits as: ";
    int cnt_tmp = 0;
    for(int i = 0; i < 4; i++) {
        if(dire[i] != -1) {
            cnt_tmp++;
            switch (i) {
				case 0: cout << "east"; break;
                case 1: cout << "down"; break;
                case 2: cout << "west"; break;
                case 3: cout << "up"; break;          
            }
            //cout << cnt_tmp << endl;
            if(cnt_tmp == cnt - 1) cout << " and ";
            else if(cnt_tmp < cnt - 1) cout << ", ";
        }
    }
    cout << "." << endl;
}

//房间的成员信息
void Room::RoleMsg(int MeetPrin)
{
    if(role_vec.size() > 1) {
        cout << "In this room, you meet ";
        int size = role_vec.size();
        for(int i = 0; i < size - 1; i++) {
            if(i < size - 3) cout << role_vec[i].getName() << ", ";
            else if(i == size - 3) cout << role_vec[i].getName() << " and ";
            else cout << role_vec[i].getName() << ".";
        }
    } 
    else {
        if(MeetPrin) cout << "There is nobody in this room except you and Princess.";
        else cout << "There is nobody in this room except you.";
    }
    cout << endl;
}