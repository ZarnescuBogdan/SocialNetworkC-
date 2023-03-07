//
// Created by Bogdan Zarnescu on 15.05.2022.
//

#include "RepoUser.h"

RepoUser::RepoUser() = default;

void RepoUser::addUser(User &user) {
    this->users.pushBack(user);
}

User RepoUser::getUserById(int id) {
    for(int i = 0; i < this->users.arraySize(); i++) {
        if(this->users[i].getId() == id) {
            return this->users[i];
        }
    }
    throw runtime_error("No user with given id was found!");
}

Array<User> RepoUser::getAllUsers() {
    return this->users;
}

int RepoUser::getSize() {
    return this->users.arraySize();
}

void RepoUser::deleteUser(User &user) {
    for(int i = 0; i < this->users.arraySize(); i++) {
        if(this->users[i].getId() == user.getId()) {
            this->users.eraseIndex(i);
        }
    }
}

void RepoUser::modifyUser(User oldUser, User newUser) {
    for(int i = 0; i < this->getSize(); i++) {
        if(this->users[i].getId() == oldUser.getId()) {
            this->users[i] = newUser;
        }
    }
}

RepoUser::~RepoUser() = default;


