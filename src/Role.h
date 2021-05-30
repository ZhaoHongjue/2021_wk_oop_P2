#ifndef _ROLE_H_
#define _ROLE_H_

using namespace std;

class Role {		
private:
	string name;	//人物名称
	string place;	//地点
public:
	// 构造函数
	Role() {
		name = "Passers-by";
		place = "none";
	}
	Role(string str1, string str2):name(str1),place(str2) {};
	Role(string str):name(str) {place = "none";}
	Role(const Role& role) {
		name = role.name;
		place = role.place;
	}
	// 析构函数
	~Role() {}

	// 得到属性值
	string getName() {return name;}
	string whereis() {return place;}

	void move(string str) {place = str;}

	// 运算符重载
	bool operator==(const Role& role) {return name == role.name;}
	friend ostream& operator<<(ostream& out, const Role& role){
		out << role.name;
		return out;
	}

	Role& operator=(const Role& role) {
		if(this != &role) {
			this->name = role.name;
		}
		return *this;
	}
};

#endif
