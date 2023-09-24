#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
class User {
private:
	char name[10];
	char password[10];
public:
	User()
	{
		string n = "";
		strcpy_s(this->name, n.c_str());
		strcpy_s(this->password, n.c_str());
	}
	User(string n,string p)
	{
		strcpy_s(this->name,n.c_str());
		strcpy_s(this->password, p.c_str());
	}
	void setName(string n) {
		strcpy_s(this->name, n.c_str());
	}
	void setPass(string p) {
		strcpy_s(this->password, p.c_str());
	}
	char* getName()
	{
		return name;
	}
	char* getPass()
	{
		return password;
	}
};