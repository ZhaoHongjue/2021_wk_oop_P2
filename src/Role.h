#ifndef _ROLE_H_
#define _ROLE_H_

using namespace std;

class Role {		
private:
	string name;
public:
	Role();
	Role(string str);
	Role(const Role& role);
	~Role();

	friend ostream& operator<<(ostream& out, const Role& role);
};

#endif
