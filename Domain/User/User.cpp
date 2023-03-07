//
// Created by Bogdan Zarnescu on 11.05.2022.
//

#include <sstream>
#include "User.h"

User::User() {
    this->id = 0;
    this->firstName = "";
    this->lastName = "";
    this->username = "";
    this->age = 0;
}

User::User(int id1, string firstName1, string lastName1, string username1, int age1) {
    this->id = id1;
    this->firstName = firstName1;
    this->lastName = lastName1;
    this->username = username1;
    this->age = age1;
}

User::User(const User &user) {
    this->id = user.id;
    this->firstName = user.firstName;
    this->lastName = user.lastName;
    this->username = user.username;
    this->age = user.age;
}

void User::setId(int id1) {
    this->id = id1;
}

void User::setFirstName(string firstName1) {
    this->firstName = firstName1;
}

void User::setLastName(string lastName1) {
    this->lastName = lastName1;
}

void User::setUsername(string username1) {
    this->username = username1;
}

void User::setAge(int age1) {
    this->age = age1;
}

int User::getId() {
    return this->id;
}

string User::getFirstName() {
    return this->firstName;
}

string User::getLastName() {
    return this->lastName;
}

string User::getUsername() {
    return this->username;
}

int User::getAge() {
    return this->age;
}

User &User::operator=(const User &user) {
    this->id = user.id;
    this->firstName = user.firstName;
    this->lastName = user.lastName;
    this->username = user.username;
    this->age = user.age;
    return *this;
}

bool User::operator==(const User &user) {
    return ((this->firstName == user.firstName) and (this->lastName == user.lastName) and (this->username == user.username) and (this->age == user.age));
}

istream &operator>>(istream &istream1, User &user) {
    int id1;
    cout << "Enter user id: ";
    istream1 >> id1;

    string firstName1;
    cout << "Enter user first name: ";
    istream1 >> firstName1;

    string lastName1;
    cout << "Enter user last name: ";
    istream1 >> lastName1;

    string username1;
    cout << "Enter username: ";
    istream1 >> username1;

    int age1;
    cout << "Enter user age: ";
    istream1 >> age1;

    user.id = id1;
    user.firstName = firstName1;
    user.lastName = lastName1;
    user.username = username1;
    user.age = age1;
    return istream1;
}

ostream &operator<<(ostream &ostream1, User &user) {
    ostream1 << "Id: " << user.id << endl;
    ostream1 << "First name: " << user.firstName << endl;
    ostream1 << "Last name: " << user.lastName << endl;
    ostream1 << "Username: " << user.username << endl;
    ostream1 << "Age: " << user.age << endl;
    return ostream1;
}

User::~User() {
    this->id = 0;
    this->firstName = "";
    this->lastName = "";
    this->username = "";
    this->age = 0;
}

bool User::operator>(const User &user) {
    if(this->age > user.age) {
        return true;
    } else {
        return false;
    }
}

bool User::operator>=(const User &user) {
    if(this->age >= user.age) {
        return true;
    } else {
        return false;
    }
}

bool User::operator<(const User &user) {
    if(this->age < user.age) {
        return true;
    } else {
        return false;
    }
}

bool User::operator<=(const User &user) {
    if(this->age <= user.age) {
        return true;
    } else {
        return false;
    }
}

bool User::operator!=(const User &user) {
    if(this->age != user.age) {
        return true;
    } else {
        return false;
    }
}

User::User(string args) {
    this->fromString(args);
}

void User::fromString(string args, char delimiter) {
    Array<string> attributes;
    stringstream ss(args);
    string attribute;
    while(getline(ss, attribute, delimiter)) {
        attributes.pushBack(attribute);
    }
    if(attributes.arraySize() == 5) {
        stringstream i(attributes[0]);
        i >> this->id;
        stringstream fn(attributes[1]);
        fn >> this->firstName;
        stringstream ln(attributes[2]);
        ln >> this->lastName;
        stringstream un(attributes[3]);
        un >> this->username;
        stringstream a(attributes[4]);
        a >> this->age;
    }
}
