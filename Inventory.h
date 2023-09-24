#pragma once
#include<fstream>
#include<iostream>
using namespace std;
class Inventory {
private:
	int price;
	int quantity;
public:
	Inventory()
	{
		price = 0;
		quantity = 0;
	}
	Inventory(int p, int q) {
		setPrice(p);
		setQuantity(q);
	}
	void setPrice(int p)
	{
		price = p;
	}
	void setQuantity(int q)
	{
		quantity = q;
	}
	int getPrice()
	{
		return price;
	}
	int getQuantity()
	{
		return quantity;
	}
};
class Islamabad :public Inventory {
private:
	char nameOfProduct[20];
public:
	Islamabad() {
		string s = "";
		strcpy_s(this->nameOfProduct, s.c_str());
	}
	Islamabad(string x)
	{
		strcpy_s(this->nameOfProduct, x.c_str());
	}
	void setProduct(string x)
	{
		strcpy_s(this->nameOfProduct, x.c_str());
	}
	char* getProduct()
	{
		return nameOfProduct;
	}
	void displayIsb()
	{
		cout << nameOfProduct << " -> " << getPrice() << " --> Quantity = " << getQuantity()<<endl;
	}
	void Add_Item_Isb(string nm,int qn,int pr)
	{
		Islamabad i;
		i.setPrice(pr);
		i.setProduct(nm);
		i.setQuantity(qn);
		ofstream fileA("Islamabad.bin", ios::binary |ios::out| ios::app);
		fileA.write((char*)&i, sizeof(i));
		fileA.close();
	}
	void Update_Item_Isb(string n, int q)
	{
		Islamabad tmp;
		fstream myFile("Islamabad.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&tmp, sizeof(tmp))) {
			if (tmp.getProduct()==n) {
				tmp.setQuantity(q);
				int current = myFile.tellg();
				int oneblock = sizeof(tmp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&tmp, sizeof(tmp));
				cout << "Quantity Updated." << endl;
				myFile.close();
			}
		}
	}
	void Delete_Item_Isb(string name)
	{
		Islamabad tmp;
		fstream fileB("Islamabad.bin", ios::in | ios::out | ios::binary);
		ofstream File_temp("temp.bin", ios::app | ios::binary);
		while (fileB.read((char*)&tmp, sizeof(tmp))) {
			if (tmp.getProduct() != name) {
				File_temp.write((char*)&tmp, sizeof(tmp));
			}
			else {
				cout << "Object Deleted successfully." << endl;
			}
		}
		fileB.close();
		File_temp.close();
		remove("Islamabad.bin");
		rename("temp.bin", "Islamabad.bin");
	}
	void displayIsbAll()
	{
		Islamabad i;
		ifstream fileI("Islamabad.bin", ios::in | ios::binary);
		while (fileI.read((char*)&i, sizeof(i))) {
			i.displayIsb();
		}
		fileI.close();
	}
};
void saverIsb()
{
	Islamabad i;
	ofstream file("Islamabad.bin", ios::binary | ios::out | ios::app);
	file.write((char*)&i, sizeof(i));
	file.close();
}

class Lahore :public Inventory {
private:
	char nameOfProduct[20];
public:
	Lahore() {
		string s = "";
		strcpy_s(this->nameOfProduct, s.c_str());
	}
	Lahore(string x)
	{
		strcpy_s(this->nameOfProduct, x.c_str());
	}
	void setProduct(string x)
	{
		strcpy_s(this->nameOfProduct, x.c_str());
	}
	char* getProduct()
	{
		return nameOfProduct;
	}
	void displayLhr()
	{
		cout << nameOfProduct << " -> " << getPrice() << " --> Quantity = " << getQuantity() << endl;
	}
	void Add_Item_Lhr(string nm, int qn, int pr)
	{
		Islamabad i;
		i.setPrice(pr);
		i.setProduct(nm);
		i.setQuantity(qn);
		ofstream fileA("Lahore.bin", ios::binary | ios::out | ios::app);
		fileA.write((char*)&i, sizeof(i));
		fileA.close();
	}
	void Update_Item_Lhr(string n, int q)
	{
		Islamabad tmp;
		fstream myFile("Lahore.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&tmp, sizeof(tmp))) {
			if (tmp.getProduct() == n) {
				tmp.setQuantity(q);
				int current = myFile.tellg();
				int oneblock = sizeof(tmp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&tmp, sizeof(tmp));
				cout << "Quantity Updated." << endl;
				myFile.close();
			}
		}
	}
	void Delete_Item_Lhr(string name)
	{
		Islamabad tmp;
		fstream fileB("Lahore.bin", ios::in | ios::out | ios::binary);
		ofstream File_temp("temp.bin", ios::app | ios::binary);
		while (fileB.read((char*)&tmp, sizeof(tmp))) {
			if (tmp.getProduct() != name) {
				File_temp.write((char*)&tmp, sizeof(tmp));
			}
			else {
				cout << "Object Deleted successfully." << endl;
			}
		}
		fileB.close();
		File_temp.close();
		remove("Lahore.bin");
		rename("temp.bin", "Lahore.bin");
	}
	void displayLhrAll()
	{
		Lahore i;
		ifstream fileI("Lahore.bin", ios::in | ios::binary);
		while (fileI.read((char*)&i, sizeof(i))) {
			i.displayLhr();
		}
		fileI.close();
	}

};
void saverLhr()
{
	Islamabad i;
	ofstream file("Lahore.bin", ios::binary | ios::out | ios::app);
	file.write((char*)&i, sizeof(i));
	file.close();
}

class Karachi :public Inventory {
private:
	char nameOfProduct[20];
public:
	Karachi() {
		string s = "";
		strcpy_s(this->nameOfProduct, s.c_str());
	}
	Karachi(string x)
	{
		strcpy_s(this->nameOfProduct, x.c_str());
	}
	void setProduct(string x)
	{
		strcpy_s(this->nameOfProduct, x.c_str());
	}
	char* getProduct()
	{
		return nameOfProduct;
	}
	void displayKrc()
	{
		cout << nameOfProduct << " -> " << getPrice() << " --> Quantity = " << getQuantity() << endl;
	}
	void Add_Item_Krc(string nm, int qn, int pr)
	{
		Islamabad i;
		i.setPrice(pr);
		i.setProduct(nm);
		i.setQuantity(qn);
		ofstream fileA("Karachi.bin", ios::binary | ios::out | ios::app);
		fileA.write((char*)&i, sizeof(i));
		fileA.close();
	}
	void Update_Item_Krc(string n, int q)
	{
		Islamabad tmp;
		fstream myFile("Karachi.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&tmp, sizeof(tmp))) {
			if (tmp.getProduct() == n) {
				tmp.setQuantity(q);
				int current = myFile.tellg();
				int oneblock = sizeof(tmp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&tmp, sizeof(tmp));
				cout << "Quantity Updated." << endl;
				myFile.close();
			}
		}
	}
	void Delete_Item_Krc(string name)
	{
		Islamabad tmp;
		fstream fileB("Karachi.bin", ios::in | ios::out | ios::binary);
		ofstream File_temp("temp.bin", ios::app | ios::binary);
		while (fileB.read((char*)&tmp, sizeof(tmp))) {
			if (tmp.getProduct() != name) {
				File_temp.write((char*)&tmp, sizeof(tmp));
			}
			else {
				cout << "Object Deleted successfully." << endl;
			}
		}
		fileB.close();
		File_temp.close();
		remove("Karachi.bin");
		rename("temp.bin", "Karachi.bin");
	}
	void displayKrcAll()
	{
		Karachi i;
		ifstream fileI("Karachi.bin", ios::in | ios::binary);
		while (fileI.read((char*)&i, sizeof(i))) {
			i.displayKrc();
		}
		fileI.close();
	}
	
};
void saverkrc()
{
	Islamabad i;
	ofstream file("Karachi.bin", ios::binary | ios::out | ios::app);
	file.write((char*)&i, sizeof(i));
	file.close();
}


