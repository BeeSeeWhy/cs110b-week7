//Specification file for the Person class
#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person {
  private:
    std::string lastName;
    std::string firstName;
    std::string phone;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

  public:

    void setLastName(std::string);
    void setFirstName(std::string);
    void setPhone(std::string);
    void setStreet(std::string);
    void setCity(std::string);
    void setState(std::string);
    void setZip(std::string);

    string getFullName() const
    { return (lastName + ", " + firstName); }

    string getLastName() const
    { return lastName; }

    string getFirstName() const
    { return firstName; }

    string getPhone() const
    { return phone; }

    string getStreet () const
    { return street; }

    string getCity () const
    { return city; }

    string getState () const
    { return state; }

    string getZip () const 
    { return zip; }


};


#endif
