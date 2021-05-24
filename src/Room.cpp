#include <iostream>
#include "Room.h"
using namespace std;

Room::Room()
{
    name = "none";
    for(int i = 0; i < 4; i++) {
        dire[i] = 1;
    }
}

Room::Room(string str, int* a):name(str)
{
    for(int i = 0; i < 4; i++) {
        dire[i] = a[i];
    }
}

Room::Room(const Room& room)
{
    this->name = room.name;
    for(int i = 0; i < 4; i++) {
        this->dire[i] = room.dire[i];
    }
}