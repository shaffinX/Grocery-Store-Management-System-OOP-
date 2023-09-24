#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Customer.h"
using namespace std;
class Store {
public:
    void displayCustomer()
    {
        Customer temporary;
        ifstream fileC("CustomerDetails.bin", ios::binary| ios::in);
        while (fileC.read((char*)&temporary, sizeof(temporary))) {
            cout << temporary.getName() << endl;
        }
        fileC.close();
    }
	void removeCustomer(string n)
	{
        Customer temporary;
        fstream FileRm("CustomerDetails.bin", ios::in | ios::out | ios::binary);
        ofstream FileRm_temp("nomedia.bin", ios::app | ios::binary);
        while (FileRm.read((char*)&temporary, sizeof(temporary))) {
            if (temporary.getName() != n) {
                FileRm_temp.write((char*)&temporary, sizeof(temporary));
            }
            else {
                cout << "Object Deleted. Successfully!!!!" << endl;
            }
        }
        FileRm.close();
        FileRm_temp.close();
        remove("CustomerDetails.bin");
        rename("nomedia.bin", "CustomerDetails.bin");
	}
};