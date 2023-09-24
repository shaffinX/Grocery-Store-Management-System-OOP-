#pragma once
#include <iostream>
#include<string>
#include"Manager.h"
#include"Stores.h"
#include"User.h"
#include"Catalog.h"
#include<fstream>
using namespace std;
class Admin:public User,public Store,public Catalog {
private:
	
public:
	Admin() {
		setName("admin");
		setPass("admin");
	}

};
bool adminLogin()
{
	Admin i;
	string name;
	string passw;
	cout << "Enter Username.\n";
	cin >> name;
	cout << "Enter Password.\n";
	cin >> passw;
	if (i.getName() == name && i.getPass() == passw) {
		return 1;
	}
	else {
		return 0;
	}
}
bool managerRegistrationIsb()
{
	ManagerIsb i;
	string name;
	string passw;
	cout << "Enter Username.\n";
	cin >> name;
	cout << "Enter Password.\n";
	cin >> passw;
	i.setName(name);
	i.setPass(passw);


	ofstream fileMi("ManagerDetailsIsb.bin", ios::out | ios::binary);
	fileMi.write((char*)&i, sizeof(i));
	fileMi.close();

	return 1;
}
bool managerRegistrationLhr()
{
	ManagerLhr i;
	string name;
	string passw;
	cout << "Enter Username.\n";
	cin >> name;
	cout << "Enter Password.\n";
	cin >> passw;
	i.setName(name);
	i.setPass(passw);


	ofstream fileM("ManagerDetailsLhr.bin", ios::out | ios::binary);
	fileM.write((char*)&i, sizeof(i));
	fileM.close();

	return 1;
}
bool managerRegistrationKrc()
{
	ManagerKrc i;
	string name;
	string passw;
	cout << "Enter Username.\n";
	cin >> name;
	cout << "Enter Password.\n";
	cin >> passw;
	i.setName(name);
	i.setPass(passw);


	ofstream fileM("ManagerDetailsKrc.bin", ios::out | ios::binary);
	fileM.write((char*)&i, sizeof(i));
	fileM.close();

	return 1;
}