#include "addressbook.h"
#include <cstdlib>
#include <iostream>
#include "person.h"
#include <string>
using namespace std;

Addressbook::Addressbook() {
  for(int i = 0; i < numOfElements; i++) {
    book[i].setLastName("");
    book[i].setFirstName("");
    book[i].setPhone("");
    book[i].setStreet("");
    book[i].setCity("");
    book[i].setState("");
    book[i].setZip("");
  }
}


int Addressbook::count() {
  int count = 0;
  string empty = "";
  for(int i = 0; i < numOfElements; i++) {
    if(book[i].getLastName() != empty)
      count++;
  }
  return count;
}

void Addressbook::addPerson(string fname, string lname, string phone,
  string street, string city, string state, string zip) {
    int add = Addressbook::count();
    //cout << add << endl;
    book[add].setFirstName(fname);
    book[add].setLastName(lname);
    book[add].setPhone(phone);
    book[add].setStreet(street);
    book[add].setCity(city);
    book[add].setState(state);
    book[add].setZip(zip);

    //cout << book[add].getFirstName();
  }

void Addressbook::editPerson(string fname, string lname, string phone,
  string street, string city, string state, string zip) {
    string last_name;
    char choice;
    cout << "Enter Last Name of Person to Edit: ";
    getline(cin, last_name);

    for(int i = 0; i < numOfElements; i++) {
      if(book[i].getLastName() == last_name) {
        do {
          cout << "Is " << book[i].getFullName() << endl;
          cout << "the correct entry to edit? (Y or N) ";
          cin >> choice;
        } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
        if(choice == 'Y' || choice == 'y') {
          cout << endl;
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
          getline(cin, zip);
          book[i].setLastName(lname);
          book[i].setFirstName(fname);
          book[i].setPhone(phone);
          book[i].setStreet(street);
          book[i].setCity(city);
          book[i].setState(state);
          book[i].setZip(zip);
        }
      }
    }
}

void Addressbook::initializeBook() {
  book[0].setLastName("Sioux");
  book[0].setFirstName("Siouxsie");
  book[0].setPhone("702-555-5555");
  book[0].setStreet("3570 S Las Vegas Blvd");
  book[0].setCity("Las Vegas");
  book[0].setState("Nevada");
  book[0].setZip("89109");

  book[1].setLastName("Addams");
  book[1].setFirstName("Morticia");
  book[1].setPhone("415-666-1313");
  book[1].setStreet("13 Funston Street");
  book[1].setCity("San Francisco");
  book[1].setState("California");
  book[1].setZip("94129");

  book[2].setLastName("Bates");
  book[2].setFirstName("Norman");
  book[2].setPhone("323-555-5555");
  book[2].setStreet("1070 272nd Street, Aldergrove, BC V4W 2P8, Canada");
  book[2].setCity("Aldergrove");
  book[2].setState("British Columbia, Canada");
  book[2].setZip("V4W 2P8");
}

bool Addressbook::removePerson(string fname) {
    char choice;
    int peopleCount = Addressbook::count();
    bool status = false;
    for(int i = 0; i < numOfElements; i++) {
      if(book[i].getFirstName() == fname) {
        do {
          cout << "Is " << book[i].getFullName() << endl;
          cout << "the correct entry to remove? (Y or N) ";
          cin >> choice;
        } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

        if(choice == 'Y' || choice == 'y') {
          int remove = i;
          status = true;
          book[i].setLastName("");
          book[i].setFirstName("");
          book[i].setPhone("");
          book[i].setStreet("");
          book[i].setCity("");
          book[i].setState("");
          book[i].setZip("");

          string empty = "";
          int j;
          for (i = 0; i < numOfElements - 1; i++) {
            int minValue = i;
            for (j = i + 1; j < numOfElements; j++) {
              if (book[j].getLastName() != empty)
                minValue = j;
            }
            Person temp;
            temp = book[i];
            book[i] = book[minValue];
            book[minValue] = temp;
          }
        }
      }
    }
    return status;
}

bool Addressbook::removePerson(string fname, string lname) {
    char choice;
    int peopleCount = Addressbook::count();
    bool status = false;
    for(int i = 0; i < numOfElements; i++) {
      if(book[i].getFirstName() == fname && book[i].getLastName() == lname) {
        do {
          cout << "Is " << book[i].getFullName() << endl;
          cout << "the correct entry to remove? (Y or N)";
          cin >> choice;
        } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

        if(choice == 'Y' || choice == 'y') {
          status = true;
          book[i].setLastName("");
          book[i].setFirstName("");
          book[i].setPhone("");
          book[i].setStreet("");
          book[i].setCity("");
          book[i].setState("");
          book[i].setZip("");

          string empty = "";
          int j;
          for (i = 0; i < numOfElements - 1; i++) {
            int minValue = i;
            for (j = i + 1; j < numOfElements; j++) {
              if (book[j].getLastName() != empty)
                minValue = j;
            }
            Person temp;
            temp = book[i];
            book[i] = book[minValue];
            book[minValue] = temp;
          }
        }
      }
    }

  return status;
}

void Addressbook::sortByLastName() {
  int peopleCount = Addressbook::count();
  int i, j;
  for (i = 0; i < peopleCount - 1; i++) {
    int minValue = i;
    for (j = i + 1; j < peopleCount; j++) {
      if (book[j].getLastName() < book[minValue].getLastName())
        minValue = j;
    }
    Person temp;
    temp = book[i];
    book[i] = book[minValue];
    book[minValue] = temp;
  }

  for (i = 0; i < peopleCount; i++) {
    cout << endl;
    cout << book[i].getFullName() << endl;
    cout << book[i].getPhone() << endl;
    cout << book[i].getStreet() << endl;
    cout << book[i].getCity() << ", " << book[i].getState() << " " << book[i].getZip() << endl;
    cout << endl;
  }
}
