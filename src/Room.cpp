#include <iostream>
#include "Room.h"
#include "Role.h"
#include <vector>
using namespace std;

// Default Constructor
Room::Room()
{
    name = "none";
    for(int i = 0; i < 4; i++) {
        dire[i] = 1;
    }
    cnt = 4;
    role_vec.clear();
}

//带参构造函数
Room::Room(string str, int* a):name(str)
{
    cnt = 0;
    for(int i = 0; i < 4; i++) {
        dire[i] = a[i];
        if(dire[i]) cnt++;
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

void Room::AddRole(Role role) 
{
    role_vec.push_back(role);
}

ostream& operator<<(ostream& out, Room& room) {
	out << "Welcome to the " << room.name <<". There are ";
    out << room.cnt <<  " exits as: ";
    int cnt_tmp = 0;
    for(int i = 0; i < 4; i++) {
        if(room.dire[i]) {
            cnt_tmp++;
            switch (i) {
                case 0: out << "east"; break;
                case 1: out << "down"; break;
                case 2: out << "west"; break;
                case 3: out << "up"; break;          
            }
            //cout << cnt_tmp << endl;
            if(cnt_tmp == room.cnt - 1) out << " and ";
            else if(cnt_tmp < room.cnt - 1) out << ", ";
        }
    }
    out << "." << endl; // << "Enter your command: ";
    if(!room.role_vec.empty()) {
        out << "In this room, you meet ";
        int size = room.role_vec.size();
        for(int i = 0; i < size; i++) {
            if(i < size - 2) out << room.role_vec[i].getName() << ", ";
            else if(i == size - 2) out << room.role_vec[i].getName() << " and ";
            else out << room.role_vec[i].getName() << ".";
        }
    } 
	return out;
}