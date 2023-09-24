#pragma once
#include <iostream>
#include"Admin.h"
#include"Customer.h"
#include"online_shopping.h"
#include"Manager.h"
#include"User.h"
using namespace std;
void menu()
{
	system("CLS");
	int entry1;
	cout << "--------------------------------\n";
	cout << "Enter (1)To join as join as Admin\nEnter (2)To join as Manager\nEnter (3)To join as Customer.\n";
	cin >> entry1;
	if (entry1 == 1) {
		bool login=false;
		int ent;
		system("CLS");
		cout << "ADMIN ACCESS....\n\n\n";		
		login = adminLogin();
		while (login == false) {
			cout << "Failed! incorrect username or password.\n";
			cin.get();
			cin.get();
			system("CLS");
			cout << "ADMIN ACCESS....\n\n\n";
			login = adminLogin();
		}
		cout << "Successfully Login into Admin.\n";
		cout << "press (1) to add manager.\npress (2) to remove spam customer.\npress (3) to Handle Catalog.\n";
		cin >> ent;
		if (ent == 1) {
			system("CLS");
			cout << "Press (1) to register Lahore manager.\nPress (2) to register Islamabad manager.\nPress (3) to register Karachi manager.\n";
			int chk;
			cin >> chk;
			switch (chk) {
			case 1:
				managerRegistrationLhr();
				cout << "Manager has been registered.\n";
				break;
			case 2:
				managerRegistrationLhr();
				cout << "Manager has been registered.\n";
				break;
			case 3:
				managerRegistrationKrc();
				cout << "Manager has been registered.\n";
				break;
			default:
				menu();
				break;
			}
			menu();
			
		}
		else if (ent == 2) {
			system("CLS");
			string tmpy;
			Admin il;
			il.displayCustomer();
			cout << "Enter Name to remove that spam.\n";
			cin >> tmpy;
			il.removeCustomer(tmpy);
			menu();
		}
		else if (ent == 3) {
			system("CLS");
			Admin i3;
			cout << "Press (1)to display Catalog\npress (2) to add products\npress (3) to remove products.\n";
			int chk;
			cin >> chk;
			if (chk == 1) {
				system("CLS");
				i3.displayCatalogItems();
				menu();
			}
			else if (chk == 2) {
				system("CLS");
				cout << "------------------------ADD a product in catalog-----------------\n\n";
				string pr;
				int a;
				cout << "Press (1)to enter Meat section.\npress (2)to enter Dairy section.\npress (3)to enter Fruit section.\npress (4)to enter Vegetable section.\npress (5)to enter Snack section.\npress (6)to enter spices section.\npress (7)to enter grain section.\npress (8)to enter personal Hygiene section.\npress (9)to enter House hold section.\n";
				cin >> a;
				switch (a) {
				case 1:
					cout << "Enter product name.\n";
					cin >> pr;
					i3.add_Product("meat.txt", pr);
					break;
				case 2:
					cout << "Enter product name.\n";
					cin >> pr;
					i3.add_Product("Dairy.txt", pr);
					break;
				case 3:
					cout << "Enter product name.\n";
					cin >> pr;
					i3.add_Product("Fruit.txt", pr);
					break;
				case 4:
					cout << "Enter product name.\n";
					cin >> pr;
					i3.add_Product("Vegetable.txt", pr);
					break;
				case 5:
					cout << "Enter product name.\n";
					cin >> pr;
					i3.add_Product("Snacks.txt", pr);
					break;
				case 6:
					cout << "Enter product name.\n";
					cin >> pr;
					i3.add_Product("Spices.txt", pr);
					break;
				case 7:
					cout << "Enter product name.\n";
					cin >> pr;
					i3.add_Product("Grains.txt", pr);
					break;
				case 8:
					cout << "Enter product name.\n";
					cin >> pr;
					i3.add_Product("PersonalHygiene.txt", pr);
					break;
				case 9:
					cout << "Enter product name.\n";
					cin >> pr;
					i3.add_Product("HouseHold.txt", pr);
					break;
				}
				menu();
			}
			else if (chk == 3) {
				system("CLS");
				cout << "-----------------DELETE A Product.-----------------\n\n";
				string pr;
				int a;
				cout << "Press (1)to enter Meat section.\npress (2)to enter Dairy section.\npress (3)to enter Fruit section.\npress (4)to enter Vegetable section.\npress (5)to enter Snack section.\npress (6)to enter spices section.\npress (7)to enter grain section.\npress (8)to enter personal Hygiene section.\npress (9)to enter House hold section.\n";
				cin >> a;
				switch (a) {
				case 1:
					cout << "Enter product name to delete.\n";
					cin >> pr;
					i3.remove_Product("meat.txt", pr);
					break;
				case 2:
					cout << "Enter product name to delete.\n";
					cin >> pr;
					i3.remove_Product("Dairy.txt", pr);
					break;
				case 3:
					cout << "Enter product name to delete.\n";
					cin >> pr;
					i3.remove_Product("Fruit.txt", pr);
					break;
				case 4:
					cout << "Enter product name to delete.\n";
					cin >> pr;
					i3.remove_Product("Vegetable.txt", pr);
					break;
				case 5:
					cout << "Enter product name to delete.\n";
					cin >> pr;
					i3.remove_Product("Snacks.txt", pr);
					break;
				case 6:
					cout << "Enter product name to delete.\n";
					cin >> pr;
					i3.remove_Product("Spices.txt", pr);
					break;
				case 7:
					cout << "Enter product name to delete.\n";
					cin >> pr;
					i3.add_Product("Grains.txt", pr);
					break;
				case 8:
					cout << "Enter product name to delete.\n";
					cin >> pr;
					i3.remove_Product("PersonalHygiene.txt", pr);
					break;
				case 9:
					cout << "Enter product name to delete.\n";
					cin >> pr;
					i3.remove_Product("HouseHold.txt", pr);
					break;
				}
				menu();
			}

		}
	
	}
	else if (entry1 == 2) {
		bool login;
		system("CLS");
		cout << "Manager ACCESS....\n\n\n";
		cout << "Press (1) to login Lahore manager.\nPress (2) to login Islamabad manager.\nPress (3) to login Karachi manager.\npress (4) to see feedbacks\n";
		int chk;
		cin >> chk;
		switch (chk) {
		case 1:
			login = false;
			login = managerLoginLhr();
			while (login == false) {
				cout << "Failed! incorrect username or password.\n";
				cin.get();
				cin.get();
				system("CLS");
				cout << "Manager ACCESS....\n\n\n";
				login = managerLoginLhr();
			}
			cout << "Successfully Login into Manager.\n";
			cin.get();
			cout << "Press (1) to View Inventory.\nPress (2) to add item to Inventory.\nPress (3) to Delete item from Inventory.\nPress (4) to Update Item in Inventory.\n";
			int x;
			cin >> x;
			switch (x) {
			case 1: {
				ManagerLhr i;
				i.displayLhrAll();
				cout << "Enter 1 to see other stores and 0 to go back.\n";
				int alp;
				cin >> alp;
				if (alp == 1) {
					ManagerIsb o;
					cout << "---------Islamabad Store--------\n";
					o.displayIsbAll();
					ManagerKrc kk;
					cout << "----------Karachi Store--------\n";
					kk.displayKrcAll();
					cin.get();
					cin.get();
				}
				else {
					menu();
				}
				break;
				}
			case 2:{
				string hh;
				int qun;
				int prc;
				cout << "Enter name of product.\n";
				cin >> hh;
				cout << "Enter Quantity.\n";
				cin >> qun;
				cout << "Enter price of product.\n";
				cin >> prc;
				ManagerLhr i1;
				i1.Add_Item_Lhr(hh, qun, prc);
				break;
				}
				
			case 3: {
				string np;
				cout << "Enter the name of product you want to delete.\n";
				cin >> np;
				ManagerLhr i2;
				i2.Delete_Item_Lhr(np);
				break;
				}
			case 4: {
				string np;
				cout << "Enter the name of product you want to update.\n";
				cin >> np;
				cout << "Enter the Qantity.\n";
				int qn;
				cin >> qn;
				ManagerLhr i3;
				i3.Update_Item_Lhr(np, qn);
				break;
				}

			}


			break;
		case 2:
			login = false;
			login = managerLoginIsb();
			while (login == false) {
				cout << "Failed! incorrect username or password.\n";
				cin.get();
				system("CLS");
				cout << "Manager ACCESS....\n\n\n";
				login = managerLoginIsb();
			}
			cout << "Successfully Login into Manager.\n";
			
			cin.get();
			cout << "Press (1) to View Inventory.\nPress (2) to add item to Inventory.\nPress (3) to Delete item from Inventory.\nPress (4) to Update Item in Inventory.\n";
			int xl;
			cin >> xl;
			switch (xl) {
			case 1: {
				ManagerIsb i;
				i.displayIsbAll();
				cout << "Enter 1 to see other stores and 0 to go back.\n";
				int alp1;
				cin >> alp1;
				if (alp1== 1) {
					ManagerLhr o;
					cout << "---------Lahore Store--------\n";
					o.displayLhrAll();
					ManagerKrc kk;
					cout << "----------Karachi Store--------\n";
					kk.displayKrcAll();
					cin.get();
					cin.get();
				}
				else {
					menu();
				}
				break;
				}
			case 2: {
				string hh;
				int qun;
				int prc;
				cout << "Enter name of product.\n";
				cin >> hh;
				cout << "Enter Quantity.\n";
				cin >> qun;
				cout << "Enter price of product.\n";
				cin >> prc;
				ManagerIsb i1;
				i1.Add_Item_Isb(hh, qun, prc);
				break;
				}

			case 3: {
				string np;
				cout << "Enter the name of product you want to delete.\n";
				cin >> np;
				ManagerIsb i2;
				i2.Delete_Item_Isb(np);
				break;
				}
			case 4: {
				string np;
				cout << "Enter the name of product you want to update.\n";
				cin >> np;
				cout << "Enter the Qantity.\n";
				int qn;
				cin >> qn;
				ManagerIsb i3;
				i3.Update_Item_Isb(np, qn);
				break;
					}
				}
			
			break;
		case 3:
			login = managerLoginKrc();
			while (login == false) {
				cout << "Failed! incorrect username or password.\n";
				cin.get();
				system("CLS");
				cout << "Manager ACCESS....\n\n\n";
				login = managerLoginKrc();
			}
			cout << "Successfully Login into Manager.\n";
			cin.get();
			cout << "Press (1) to View Inventory.\nPress (2) to add item to Inventory.\nPress (3) to Delete item from Inventory.\nPress (4) to Update Item in Inventory.\n";
			int xr;
			cin >> xr;
			switch (xr) {
			case 1: {
				ManagerKrc i;
				i.displayKrcAll();
				cout << "Enter 1 to see other stores and 0 to go back.\n";
				int alp2;
				cin >> alp2;
				if (alp2 == 1) {
					ManagerIsb o;
					cout << "---------Islamabad Store--------\n";
					o.displayIsbAll();
					ManagerLhr kk;
					cout << "----------Lahore Store--------\n";
					kk.displayLhrAll();
					cin.get();
					cin.get();
				}
				else {
					menu();
				}
				break;
				}
			case 2: {
				string hh;
				int qun;
				int prc;
				cout << "Enter name of product.\n";
				cin >> hh;
				cout << "Enter Quantity.\n";
				cin >> qun;
				cout << "Enter price of product.\n";
				cin >> prc;
				ManagerKrc i;
				i.Add_Item_Krc(hh, qun, prc);
				break;
				}

			case 3: {
				string np;
				cout << "Enter the name of product you want to delete.\n";
				cin >> np;
				ManagerKrc i;
				i.Delete_Item_Krc(np);
				break;
				}
			case 4: {
				string np;
				cout << "Enter the name of product you want to update.\n";
				cin >> np;
				cout << "Enter the Qantity.\n";
				int qn;
				cin >> qn;
				ManagerKrc i;
				i.Update_Item_Krc(np, qn);
				break;
				}

			}
			
		break;
		case 4: {
			ifstream feedb("feedback.txt", ios::in);
			string get;
			while (!feedb.eof()) {
				getline(feedb, get);
				cout << get << endl;
			}
			cin.get();
			cin.get();
			break;
		}
		default:
			menu();
			break;
		}
		menu();
	}
	else if (entry1 == 3) {
		
		int ent;
		system("CLS");
		cout << "Customer ACCESS....\n\n\n";
		cout << "Press (1) to Login.\nPress(2) to Register.\n";
		cin >> ent;
		if (ent == 1) {
			bool lgn=false;
			system("CLS");
			lgn=customerLogin();
			while (lgn == false) {
				cout << "Login failed!.\n";
				cin.get();
				cin.get();
				lgn = customerLogin();
			}
			cout << "Successfully Login in Customer.\n" << endl;
			cout << "press enter to shop\n";
			cin.get();
			cin.get();
			int nmbr = 1;
			shopping spr;
			int total=spr.displayCatalog();
			cout << "If you want to shop again press 0.\n";
			cin >> nmbr;
			while (nmbr < 1) {
				total += spr.displayCatalog();
				cout << "If you want to shop again press 0.\n";
				cin >> nmbr;
			}
			system("CLS");
			spr.payment(total);
			menu();
		}
		else if (ent == 2) {
			bool reeg;
			system("CLS");
			reeg=customerRegistration();
			while (reeg == false) {
				cin.get();
				cin.get();
				reeg = customerRegistration();
			}
			cout << "Customer has been registered.\n";
			menu();
		}

	}
	else {
		menu();
	}
}