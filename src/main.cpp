#include <iostream>
#include <string>
#include "Role.h"
#include "Room.h"
using namespace std;

int main()
{
    Role Hero("Hero");
    Room test;
    cout << Hero << endl;
    cout << test << endl;
    return 0;
}