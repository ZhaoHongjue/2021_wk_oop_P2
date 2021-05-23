#include <iostream>
#include "Role.h"
using namespace std;

Role::Role(const Role& role) 
{
	this-> name = role.name;
}

