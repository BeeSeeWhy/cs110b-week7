#include "addressbook.h"
#include <cstdlib>
#include "person.h"
#include <iostream>
#include <string>
using namespace std;

int menuChoice();

void addPerson(Addressbook &myContactBook) {
  string lname, fname, phone, street, city, state, zip;
  cout << endl;
  cout << "Enter first name : ";
  getline(cin, fname);

  cout << "Enter last name : ";
  getline(cin,lname);

  cout << "Enter phone number : ";
  getline(cin, phone);

  cout << "Enter number and street of address : ";
  getline(cin, street);

  cout << "Enter city of address : ";
  getline(cin, city);

  cout << "Enter state of address : ";
  getline(cin, state);

  cout << "Enter zip code : ";
  getline(cin, zip);

  myContactBook.addPerson(fname, lname, phone, street, city, state, zip);
  myContactBook.sortByLastName();
}

void editPerson(Addressbook &myContactBook) {
  string fname, lname, phone, street, city, state, zip;
  /*cout << endl;
  cout << "Enter the new first name: ";
  getline(cin, fname);

  cout << "Enter the new last name: ";
  getline(cin, lname);

  cout << "Enter the new phone: ";
  getline(cin, phone);

  cout << "Enter the new street address: ";
  getline(cin, street);

  cout << "Enter the new city: ";
  getline(cin, city);

  cout << "Enter the new state: ";
  getline(cin, state);

  cout << "Enter the new zip: ";
  getline(cin, zip);*/

  myContactBook.editPerson(fname, lname, phone, street, city, state, zip);
  myContactBook.sortByLastName();
}

void removePerson(Addressbook &myContactBook) {
  string fname, lname;
  int choice;
  cout << endl;
  cout << "1. Search by First Name" << endl;
  cout << "2. Search by First and Last Name" << endl;
  cout << "3. Go Back To Main Menu" << endl;
  cin >> choice;
  cin.ignore();

  switch (choice) {
    case 1 :  cout << "Enter First Name: ";
              getline(cin, fname);
              if (myContactBook.removePerson(fname))
                cout << "Removed" << endl;
              break;
    case 2 :  cout << "Enter First Name: ";
              getline(cin, fname);

              cout << "Enter Last Name: ";
              getline(cin, lname);
              if (myContactBook.removePerson(fname, lname))
                cout << "Removed" << endl;
              break;
  }
}

void menu(Addressbook &myContactBook) {
  myContactBook.sortByLastName();

  //menu and user choice
    int choice;
    do {
      choice = menuChoice();
      switch (choice) {
        case 1 :    addPerson(myContactBook);
                    break;
        case 2 :    removePerson(myContactBook);
                    break;
        case 3 :    editPerson(myContactBook);
                    break;
        case 4 :    myContactBook.sortByLastName();
                    break;
      }
   } while (choice != 5);
}

int menuChoice () {
  int choice;
  do {
    cout << endl;
    cout << "1. Add New Entry" << endl;
    cout << "2. Delete An Entry" << endl;
    cout << "3. Edit An Entry" << endl;
    cout << "4. List All Entries" << endl;
    cout << "5. Quit Program" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;
    cin.ignore();
  } while (!(choice > 0 && choice < 6));

  return choice;
}

int main () {

  Addressbook myContactBook;
  myContactBook.setNumOfElements();
  myContactBook.initializeBook();
  //const int numOfElements = 100;

  menu(myContactBook);

  return 0;
}
