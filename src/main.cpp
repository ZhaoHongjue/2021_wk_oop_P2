#include <iostream>
#include <string>
#include "Role.h"
#include "Room.h"
using namespace std;

void test();
void prompt();

int main()
{
    test();
    return 0;
}

void test()
{
    Role Hero("Hero");
    Room test;
    cout << Hero << endl;
    cout << test << endl;
}

void prompt()
{
    cout << "Enter your command:" << endl;
}