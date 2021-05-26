#include <iostream>
#include <string>
#include "Role.h"
#include "Room.h"
#include "Castle.h"
#include <vector>
using namespace std;

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    int a[4] = {10,4,5,7};
    Room lobby("lobby",a);
    Role Passersby("Passers-by",lobby.getName());
    lobby.AddRole(Passersby);
	lobby.AddRole(Role("Princess",lobby.getName()));
    cout << lobby << endl;
	cout << "------------------------------------" << endl;
	lobby.RmRole(Passersby);
	cout << lobby << endl;
	cout << "------------------------------------" << endl;
	Castle Cas;
	Cas.display();
}

