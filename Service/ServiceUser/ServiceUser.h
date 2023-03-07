//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_SERVICEUSER_H
#define SDA_PROFIECT_FINAL_SERVICEUSER_H

#include "../../Repository/RepoUser/RepoUser.h"

class ServiceUser {
private:
    RepoUser repoUser;
public:
    ServiceUser();
    ServiceUser(RepoUser &repoUser1): repoUser(repoUser1) {}
    void createUser(User user);
    User getUserById(int id);
    Array<User> getAllUsers();
    void updateUser(int id, User newUser);
    void deleteUser(int id);
    ~ServiceUser();
};


#endif //SDA_PROFIECT_FINAL_SERVICEUSER_H
