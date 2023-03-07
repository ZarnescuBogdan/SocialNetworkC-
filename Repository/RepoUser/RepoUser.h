//
// Created by Bogdan Zarnescu on 15.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_REPOUSER_H
#define SDA_PROFIECT_FINAL_REPOUSER_H

#include "../../Domain/Array/Array.h"
#include "../../Domain/User/User.h"

class RepoUser {
private:
    Array<User> users;
public:
    RepoUser();
    void addUser(User &user);
    User getUserById(int id);
    Array<User> getAllUsers();
    void modifyUser(User oldUser, User newUser);
    void deleteUser(User &user);
    int getSize();
    ~RepoUser();
};


#endif //SDA_PROFIECT_FINAL_REPOUSER_H
