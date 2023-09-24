#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include"Inventory.h"
#include"User.h"
using namespace std;
class ManagerIsb:public User,public Islamabad {
private:
	
public:
	ManagerIsb() {
	}
	ManagerIsb(string n, string p) {
		setName(n);
		setPass(p);
	}
	

};
class ManagerLhr :public User, public Lahore {
private:

public:
	ManagerLhr() {
	}
	ManagerLhr(string n, string p) {
		setName(n);
		setPass(p);
	}


};
class ManagerKrc :public User, public Karachi {
private:

public:
	ManagerKrc() {
	}
	ManagerKrc(string n, string p) {
		setName(n);
		setPass(p);
	}


};
bool managerLoginIsb()
{
	ManagerIsb i;
	string name;
	string passw;
	cout << "Enter Username.\n";
	cin >> name;
	cout << "Enter Password.\n";
	cin >> passw;
	ifstream fileM("ManagerDetailsIsb.bin", ios::binary | ios::in);
	while (fileM.read((char*)&i, sizeof(i))) {
		if (i.getName() == name && i.getPass() == passw) {
			fileM.close();
			return 1;
		}
	}
	fileM.close();
	return false;
}
bool managerLoginLhr()
{
	ManagerLhr i;
	string name, n;
	string passw, p;
	cout << "Enter Username.\n";
	cin >> name;
	cout << "Enter Password.\n";
	cin >> passw;
	ifstream fileM("ManagerDetailsLhr.bin", ios::binary | ios::in);
	while (fileM.read((char*)&i, sizeof(i))) {
		if (i.getName() == name && i.getPass() == passw) {
			fileM.close();
			return 1;
		}
	}
	fileM.close();
	return false;
}
bool managerLoginKrc()
{
	ManagerKrc i;
	string name, n;
	string passw, p;
	cout << "Enter Username.\n";
	cin >> name;
	cout << "Enter Password.\n";
	cin >> passw;
	ifstream fileM("ManagerDetailsKrc.bin", ios::binary | ios::in);
	while (fileM.read((char*)&i, sizeof(i))) {
		if (i.getName() == name && i.getPass() == passw) {
			fileM.close();
			return 1;
		}
	}
	fileM.close();
	return false;
}