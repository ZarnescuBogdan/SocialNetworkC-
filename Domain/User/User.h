//
// Created by Bogdan Zarnescu on 11.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_USER_H
#define SDA_PROFIECT_FINAL_USER_H

#include <string>
#include "../Array/Array.h"
#include <iostream>

using namespace std;

class User {
private:
    int id;
    string firstName;
    string lastName;
    string username;
    int age;
public:
    User();
    User(int id1, string firstName1, string lastName1, string username1, int age1);
    User(const User &user);
    void setId(int id1);
    void setFirstName(string firstName1);
    void setLastName(string lastName1);
    void setUsername(string username1);
    void setAge(int age1);
    int getId();
    string getFirstName();
    string getLastName();
    string getUsername();
    int getAge();
    User &operator=(const User &user);
    bool operator==(const User &user);
    bool operator>(const User &user);
    bool operator>=(const User &user);
    bool operator<(const User &user);
    bool operator<=(const User &user);
    bool operator!=(const User &user);
    friend istream &operator>>(istream &istream1, User &user);
    friend ostream &operator<<(ostream &ostream1, User &user);
    ~User();
    User(string args);
    void fromString(string args, char delimiter = ',');
};


#endif //SDA_PROFIECT_FINAL_USER_H
