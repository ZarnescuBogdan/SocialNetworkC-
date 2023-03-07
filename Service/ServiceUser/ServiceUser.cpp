//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#include "ServiceUser.h"

ServiceUser::ServiceUser() = default;

void ServiceUser::createUser(User user) {
    this->repoUser.addUser(user);
}

User ServiceUser::getUserById(int id) {
    return this->repoUser.getUserById(id);
}

Array<User> ServiceUser::getAllUsers() {
    return this->repoUser.getAllUsers();
}

void ServiceUser::updateUser(int id, User newUser) {
    User oldUser = this->repoUser.getUserById(id);
    this->repoUser.modifyUser(oldUser, newUser);
}

void ServiceUser::deleteUser(int id) {
    User user = this->repoUser.getUserById(id);
    this->repoUser.deleteUser(user);
}

ServiceUser::~ServiceUser() = default;
