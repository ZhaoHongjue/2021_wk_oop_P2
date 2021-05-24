#include <iostream>
#include "Role.h"
using namespace std;

Role::Role()
{
	name = "Passers-by";
}

Role::Role(string str):name(str) {}
Role::Role(const Role& role)
{
	name = role.name;
}

Role::~Role() {}

ostream& operator<<(ostream& out, const Role& role)
{
	out << role.name;
	return out;
}

