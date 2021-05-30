#include <iostream>
#include <string>
#include "Role.h"
#include "Room.h"
#include "Castle.h"
#include <vector>
using namespace std;

inline Role HeroInit();
int getCommand();

int main()
{
	Role Hero = HeroInit();
	Castle cas_map;
	int MeetPrin = 0;
	int MeetMons = 0;
	int isOut = 0;
	int MonsDie = 0;

	while(1) {
		Room room = cas_map.getRoom(Hero.whereis());
		// 输出房间基本信息
		room.PlaceMsg();
		room.RoleMsg(MeetPrin);

		// 遇到怪兽
		if(room.MeetRole() == -1) {
			if(Hero.getName() == "Weng Kai") {
				cout << "You meet the monster!" << endl;
				cout << "However, You are the teacher of the OOP, so you defeat it." << endl;
				cout << "Now you are safe." << endl;
				cas_map.getRoom(Hero.whereis()).RmRole(Role("Monster"));
				MonsDie = 1;
			}
			else MeetMons = 1;
		}
		// 遇到公主
		else if(room.MeetRole() == 1) {
			cout << "Princess decides to go with you. ";
			if(!MonsDie)cout << "Take care the MONSTER!";
			cout << endl;
			MeetPrin = 1;
			cas_map.getRoom(Hero.whereis()).RmRole(Role("Princess"));
		}

		if(room.getName() == "out" && MeetPrin) isOut = 1;
		if(MeetPrin && isOut || MeetMons) break;

		//得到指令
		int d = getCommand();
		int *dire = room.getDire();
		switch(d) {
			case -1: {	//输入错误
				cout << "Error Command!" << endl;
				continue;
			}
			break;
			case 4: {	//输入fuck
				cout << "Ok. Take it easy" << endl;
				cout << "The Princess is in the " << cas_map.getRolePlace(1) << endl;
				if(!MonsDie)cout << "The Monster is in the " << cas_map.getRolePlace(0) << endl;
			}
			break;
			case 5: {	//杀死怪兽
				cout << "You use your skill!" << endl;
				cout << "You kill the Monster! Now You are safe" << endl;
				cas_map.getRoom(cas_map.getRolePlace(0)).RmRole(Role("Monster"));
				MonsDie = 1;
			}
			break;
			default: {	//移动角色
				cas_map.MvRole(Hero,d);
				if(dire[d]!=-1) Hero.move(cas_map.getRoom(dire[d]).getName());
			}
			break;
		}
		cout << "-----------------------------------------------------------------------" << endl;
	}
	
	cout << "#######################################################################" << endl;
	if(MeetMons) {
		cout << "You meet a Monster! It attacks you! You are died. GAME OVER." << endl;
	}
	if(MeetPrin && isOut) {
		cout << "You save the Princess! Congratulations!" << endl;
	}
    return 0;
}

Role HeroInit()
{
	string name;
	cout << "please enter your name: "; 
	getline(cin, name);
	Role Hero(name, "lobby");
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Welcome, " << Hero << ". " << endl;
	cout << "Now you are going to save the Princess who is prisoned in this castle. " << endl;
	cout << "But you may meet the monster who can eat you." << endl;
	cout << "So, take care, and good luck." << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	return Hero;
}

int getCommand()
{
	string cmd;
	int ret;
	cout << "Enter your command: ";
	getline(cin,cmd);
	if(cmd == "go east") ret = 0;
	else if(cmd == "go down") ret = 1;
	else if(cmd == "go west") ret = 2;
	else if(cmd == "go up") ret = 3;
	else if(cmd == "fuck") ret = 4;
	else if(cmd == "DaLaBenBa" || cmd == "JOJO!") ret = 5;
	else ret = -1;
	return ret;
}