#include <cstdlib>
#include <iostream>
#include "person.h"
#include <string>
using namespace std;

void Person::setLastName(string lname) {
  /*if(lname.empty()) {
    cout << "Empty string" << endl;
    exit(EXIT_FAILURE);
  }
  else*/
    lastName = lname;
}

void Person::setFirstName(string fname) {
/*if(fname.empty()) {
    cout << "Empty string" << endl;
    exit(EXIT_FAILURE);
  }
  else*/
    firstName = fname;
}

void Person::setPhone(string telefono) {
/*if(telefono.empty()) {
    cout << "Empty string" << endl;
  }
  else*/
    phone = telefono;
}

void Person::setStreet(string calle) {
  /*if(calle.empty()){
    cout << "Empty string" << endl;
    exit(EXIT_FAILURE);
  }
  else*/
    street = calle;
}

void Person::setCity(string ciudad) {
  /*if(ciudad.empty()) {
    cout << "Empty string" << endl;
    exit(EXIT_FAILURE);
  }
  else*/
    city = ciudad;
}

void Person::setState(string estado) {
/*if(estado.empty()) {
    cout << "Empty string" << endl;
    exit(EXIT_FAILURE);
  }
  else*/
    state = estado;
}

void Person::setZip(string postal) {
  /*if(postal.empty()) {
    cout << "Empty string" << endl;
    exit(EXIT_FAILURE);
  }
  else*/
    zip = postal;
}
