#ifndef _ROLE_H_
#define _ROLE_H_

using namespace std;

class Role {		
private:
	string name;
	string place;
public:
	Role();
	Role(string str1, string str2);
	Role(const Role& role);
	~Role();

	string getName() {return name;}
	string whereis() {return place;}
	void move(int num);

	bool operator==(const Role& role);
	friend ostream& operator<<(ostream& out, const Role& role);
	Role& operator=(const Role& role);
};

#endif
