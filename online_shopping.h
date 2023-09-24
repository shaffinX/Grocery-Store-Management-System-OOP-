#pragma once
#include<iostream>
#include"Inventory.h"
#include<fstream>
using namespace std;
class shopping {
public:
	int addtocart(string s, int price,int qnty)
	{
		ofstream fle("checkout.txt", ios::out|ios::app);
		fle << s << " " << price << " " << qnty << endl;

		fle.close();
		return (price * qnty);
	}
	int displayCatalog()
	{
		Islamabad objt;
		objt.displayIsbAll();
		string pr;
		int qnt,prc;
		cout << "Enter the product name.\n";
		cin >> pr;
		cout << "Enter the quantity.\n";
		cin >> qnt;
		ifstream file("Islamabad.bin", ios::binary | ios::in);
		while (file.read((char*)&objt, sizeof(objt)))
		{
			if (objt.getProduct() == pr) {
				prc = objt.getPrice();
			}
		}

		objt.Update_Item_Isb(pr, qnt);
		int t=addtocart(pr, prc, qnt);
		return t;
	}
	void payment(int ttl)
	{
		ifstream fll("checkout.txt", ios::in);
		string str;
		cout << "Product Price Quantity\n";
		while (!fll.eof()) {
			getline(fll, str);
			cout << str<<endl;
		}
		cout << "\ntotal = " << ttl<<endl;
		remove("checkout.txt");

		cout << "\n\n press (1) to  pay with jazzcash\npress (2) to pay with debit card\npress (3) to COD\n";
		int ctr;
		cin >> ctr;
		switch (ctr)
		{
		case 1:
			cin.get();
			cin.get();
			cout << "PAid amount = " << ttl << endl;
			break;
		case 2:
			cin.get();
			cin.get();
			cout << "PAid amount = " << ttl << endl;
			break;
		case 3:
			cin.get();
			cin.get();
			cout << "PAid amount = " << ttl +30<< endl;
		default:
			break;
		}

		string feedback;
		cout << "Write your feedback.\n";
		getline(cin, feedback);
		ofstream feedbk("feedback.txt", ios::out|ios::app);
		feedbk << feedback << endl;
		feedbk.close();
	}
};