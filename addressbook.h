#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "person.h"
#include <string>


class Addressbook {
  private:
    int numOfElements;
    Person book[100];
  public:

    //void setBook();

    Addressbook();


    //add person
    void addPerson(std::string, std::string , std::string,
      std::string, std::string, std::string, std::string);

    int count();

    void editPerson(std::string, std::string, std::string,
      std::string, std::string, std::string, std::string);

    int getNumOfElements(int) const
    { return numOfElements; }

    void initializeBook();

    void setNumOfElements()
    { numOfElements = 100; }

    //remove person by matching first name
    bool removePerson(std::string);

    //remove person by matching first name and last name
    bool removePerson(std::string, std::string);

    //sort alphabetically by last name and print
    void sortByLastName();
};

#endif
