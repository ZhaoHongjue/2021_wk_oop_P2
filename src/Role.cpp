#include <iostream>
#include <vector>
#include "Room.h"
#include "Role.h"
using namespace std;

Role::Role()
{
	name = "Passers-by";
	place = "none";
}

Role::Role(string str1, string str2):name(str1),place(str2) {}

Role::Role(const Role& role)
{
	name = role.name;
	place = role.place;
}

Role::~Role() {}

Role& Role::operator=(const Role& role)
{
	if(this != &role) {
		this->name = role.name;
	}
	return *this;
}

ostream& operator<<(ostream& out, const Role& role)
{
	out << role.name;
	return out;
}

