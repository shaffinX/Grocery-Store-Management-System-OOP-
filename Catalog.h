#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Catalog {
public:
	void create_list()
	{
		ofstream meat("meat.txt", ios::out|ios::app);
		meat.close();
		ofstream dairy("Dairy.txt", ios::out | ios::app);
		dairy.close();
		ofstream fruit("Fruit.txt", ios::out | ios::app);
		fruit.close();
		ofstream veg("Vegetable.txt", ios::out | ios::app);
		veg.close();
		ofstream snacks("Snacks.txt", ios::out | ios::app);
		snacks.close();
		ofstream spices("Spices.txt", ios::out | ios::app);
		spices.close();
		ofstream grains("Grains.txt", ios::out | ios::app);
		grains.close();
		ofstream prhy("PersonalHygiene.txt", ios::out | ios::app);
		prhy.close();
		ofstream hhold("HouseHold.txt", ios::out | ios::app);
		hhold.close();
	}

	void add_Product(const char* catagory,string supply)
	{
		ofstream file(catagory, ios::out | ios::app);
		file << supply << endl;
	}
	void remove_Product(const char* catagory, string supply)
	{
		string tempo;

		ifstream file(catagory, ios::in);
		ofstream temporary("nomedia2.txt",ios::out|ios::app);

		while (!file.eof())
		{
			file >> tempo;
			if (tempo != supply)
			{
				temporary << tempo << endl;
			}
		}

		temporary.close();
		file.close();
		remove("nomedia2.txt");
		rename("nomedia2.txt", catagory);
		
	}

	void displayCatalogItems()
	{
		create_list();
		string tempo;
		cout << "1. FOOD\n\tPerishable Products\n\t\tMeat:\n";
		ifstream meat("meat.txt", ios::in);
		while (getline(meat,tempo)) {
			cout << "\t\t\t" << tempo << endl;
		}
		meat.close();
		cout << "\t\tDairy:\n";
		ifstream dairy("Dairy.txt", ios::in);
		while (getline(dairy, tempo)) {
			cout << "\t\t\t" << tempo << endl;
		}
		dairy.close();
		cout << "\t\tFruit:\n";
		ifstream fruit("Fruit.txt", ios::in);
		while (getline(fruit, tempo)) {
			cout << "\t\t\t" << tempo << endl;
		}
		fruit.close();
		cout << "\t\tVegetable:\n";
		ifstream veg("Vegetable.txt", ios::in);
		while (getline(veg, tempo)) {
			cout << "\t\t\t" << tempo << endl;
		}
		veg.close();
		cout << "\tNon-Perishable Products:\n\t\tSnacks:\n";
		ifstream snacks("Snacks.txt", ios::in);
		while (getline(snacks, tempo)) {
			cout << "\t\t\t" << tempo << endl;
		}
		snacks.close();
		cout << "\t\tSpices:\n";
		ifstream spices("Spices.txt", ios::in);
		while (getline(spices, tempo)) {
			cout << "\t\t\t" << tempo << endl;
		}
		spices.close();
		cout << "\t\tGrains:\n";
		ifstream grains("Grains.txt", ios::in);
		while (getline(grains, tempo)) {
			cout << "\t\t\t" << tempo << endl;
		}
		grains.close();
		cout << "2. Personal-Hygiene:\n";
		ifstream phy("PersonalHygiene.txt", ios::in);
		while (getline(phy, tempo)) {
			cout << "\t" << tempo << endl;
		}
		phy.close();
		cout << "3. House-Hold Cleaning:\n";
		ifstream hhold("HouseHold.txt", ios::in);
		while (getline(hhold, tempo)) {
			cout << "\t" << tempo << endl;
		}
		hhold.close();
	}

};