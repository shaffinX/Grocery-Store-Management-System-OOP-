#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include <stdlib.h>
#include"User.h"
using namespace std;
class Customer:public User {
private:
	char cnicC[14];
	char gender[8];
	char phNo[12];
	char address[50];
public:
	Customer()
	{
		string tm="";
		strcpy_s(this->cnicC, tm.c_str());
		strcpy_s(this->gender, tm.c_str());
		strcpy_s(this->phNo, tm.c_str());
		strcpy_s(this->address, tm.c_str());
	}
	Customer(string n, string cn, string pss, string gnd, string ph, string adrs) {
		setName(n);
		setCnic(cn);
		setPass(pss);
		setGender(gnd);
		setPhoneNo(ph);
		setAddress(adrs);
	}

	
	void setCnic(string cn)
	{
		strcpy_s(this->cnicC, cn.c_str());
	}
	
	void setGender(string gnd) {
		strcpy_s(this->gender, gnd.c_str());
	}
	void setPhoneNo(string ph) {
		strcpy_s(this->phNo, ph.c_str());
	}
	void setAddress(string adrs) {
		strcpy_s(this->address, adrs.c_str());
	}
	
	char* getCnic()
	{
		return cnicC;
	}
	char* getPhoneNo()
	{
		return phNo;
	}
	char* getAddress()
	{
		return address;
	}
	char* getGender()
	{
		return gender;
	}
};

bool customerRegistration()
{

	string name;
	string cnic;
	string passw;
	string gender;
	string phNo;
	string address;


	Customer signup;
	cout << "Please enter your name\n";
	cin >> name;
	signup.setName(name);
	cout << "Enter your Password(9 characters)\n";
	cin >> passw;
	cout << "Please reenter Password to ensure\n";
	cin >> passw;
	int countChar = passw.size();
	while (countChar != 9) {
		cout << "Password should be 9 places long please re-enter.\n";
		cin >> passw;
		countChar = passw.size();
	}
	bool uc = false;
	for (int i = 0; i < 9; i++) {
		if ((passw[i] >= 65) && (passw[i] <= 90)) {
			for (int j = 0; j < 9; j++) {
				if (passw[j] >= 48 && passw[j] <= 57) {
					uc = true;
				}
			}
		}
	}
	while (uc == false) {
		cout << "Password should contain one upper character and one digit.\n";
		cin >> passw;
		for (int i = 0; i < 9; i++) {
			if ((passw[i] >= 65) && (passw[i] <= 90)) {
				for (int j = 0; j < 9; j++) {
					if (passw[j] >= 48 && passw[j] <= 57) {
						uc = true;
					}
				}
			}
		}
	}
	signup.setPass(passw);

	cout << "Enter your CNIC.\n";
	cin >> cnic;

	signup.setCnic(cnic);
	cout << "Enter Your Gender (male/female).\n";
	cin >> gender;
	signup.setGender(gender);
	cout << "Enter your phone number.\n";
	cin >> phNo;
	signup.setPhoneNo(phNo);

	cout << "Enter your Address.\n";
	cin >> address;
	signup.setAddress(address);

	Customer tempo;
	ifstream fileC("CustomerDetails.bin", ios::binary | ios::in);
	while (fileC.read((char*)&tempo, sizeof(tempo))) {
		if (tempo.getCnic() == cnic) {
			cout << "CNIC matched re-enter.\n";
			fileC.close();
			return 0;
		}
	}
	fileC.close();

	

	ofstream fileCr("CustomerDetails.bin", ios::binary | ios::out | ios::app);
	if (fileCr.write((char*)&signup, sizeof(signup))) {
		cout << "ss\n";
	}
	fileCr.close();
	
	return true;
}

bool customerLogin()
{
	string name,n;
	string passw,p;

	cout << "Enter Username.\n";
	cin >> name;
	cout << "Enter Password.\n";
	cin >> passw;

	ifstream fileC("CustomerDetails.bin", ios::binary | ios::in);
	Customer tempo;
	while (fileC.read((char*)&tempo, sizeof(tempo))) {
		if (tempo.getName() == name && tempo.getPass() == passw) {
			fileC.close();
			return 1;
		}
	}
	fileC.close();
	return false;
}