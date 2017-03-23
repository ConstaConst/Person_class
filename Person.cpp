
#include "Person.h"
#include <iostream>
#include <cstring>

using namespace std;

Person::Person(char* last_name, char* first_name, char* patronymic, char* address,
               const bool sex, const unsigned int education, const int year) :
last_name(nullptr),
first_name(nullptr),
patronymic(nullptr),
address(nullptr),
sex(sex),
education(education),
year_of_birth(year)
{
    if (last_name)
        change_str(&this->last_name, last_name);
    if (first_name)
        change_str(&this->first_name, first_name);
    if (patronymic)
       if (!change_str(&this->patronymic, patronymic))
           cout << "ERROR! No memory for name or part of name." << endl;

    if (address) {
        if(!change_str(&this->address, address))
            cout << "ERROR! No memory for address or part of address." << endl;
    }
}
Person::Person(const Person& rhs) :
sex(rhs.sex),
education(rhs.education),
year_of_birth(rhs.year_of_birth)
{
    change_str(&last_name, rhs.last_name);
    change_str(&first_name, rhs.first_name);
    if(!change_str(&patronymic, rhs.patronymic))
        cout << "ERROR! No memory for name or part of name." << endl;

    if(!change_str(&address, rhs.address))
        cout << "ERROR! No memory for address or part of address." << endl;
}
Person::~Person() {
    delete[] last_name;
    last_name = nullptr;
    delete[] first_name;
    first_name = nullptr;
    delete[] patronymic;
    patronymic = nullptr;
    delete[] address;
    address = nullptr;
}

const bool Person::set_name(char* last, char* first, char* patronymic) {
    if (last)
        if(!change_str(&this->last_name, last))
            return false;

    if (first)
        if(!change_str(&this->first_name, first))
            return false;

    if (patronymic)
        if(!change_str(&this->patronymic, patronymic))
            return false;

    return true;
}
const bool Person::set_address(char* address) {
    if (address)
        if(!change_str(&this->address, address))
            return false;
    return true;
}
void Person::set_sex(bool sex) {
    this->sex = sex;
}
void Person::set_education(unsigned int education) {
    this->education = education;
}
void Person::set_year_of_birth(int year) {
    year_of_birth = year;
}

const char* const Person::get_last_name() const {
    if (last_name)
        return last_name;
    return "";
}
const char* const Person::get_first_name() const {
    if (first_name)
        return first_name;
    return "\0";
}
const char* const Person::get_patronymic() const {
    if (patronymic)
        return patronymic;
    return "\0";
}
const char* const Person::get_address() const {
    if (address)
        return address;
    return "\0";
}
const bool Person::get_sex() const {
    return sex;
}
const unsigned Person::get_education() const {
    return education;
}
const int Person::get_year_of_birth() const {
    return year_of_birth;
}

void Person::show_last_name() const {
    if (last_name)
        cout << last_name;
}
void Person::show_first_name() const {
    if(first_name)
        cout << first_name;
}
void Person::show_patronymic() const {
    if(patronymic)
        cout << patronymic;
}
void Person::show_address() const {
    if(address)
        cout << address;
}
void Person::show_sex() const {
    if (sex)
        cout << "male";
    else
        cout << "female";
}
void Person::show_education() const {
    //why default case is needed
    switch (education) {
        case school: {
            cout << "school";
            break;
        }
        case college: {
            cout << "college";
            break;
        }
        case university: {
            cout << "university";
            break;
        }
    }
}
void Person::show_year_of_birth() const {
    cout << year_of_birth;
}

void Person::show_all() const {
    show_last_name();
    cout << " ";
    show_first_name();
    cout << " ";
    show_patronymic();
    cout << endl;
    show_address();
    cout << endl;
    show_sex();
    cout << endl;
    show_education();
    cout << endl;
    show_year_of_birth();
    cout << endl << endl;
}

const bool Person::change_str (char** pre_str, char* new_str) {
    if (*pre_str)
        delete [] *pre_str;
    size_t len = strlen(new_str) + 1;
    *pre_str = new char[len];
    if (!*pre_str)
        return false;
    memcpy(*pre_str, new_str, len);
    return true;
}

