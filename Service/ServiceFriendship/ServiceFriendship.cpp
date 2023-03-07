//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#include "ServiceFriendship.h"

ServiceFriendship::ServiceFriendship() = default;

void ServiceFriendship::createFriendship(Friendship friendship) {
    this->repoFriendship.addFriendship(friendship);
}

void ServiceFriendship::deleteFriendship(int id) {
    Friendship friendship;
    friendship = this->repoFriendship.getFriendshipById(id);
    this->repoFriendship.deleteFriendship(friendship);
}

void ServiceFriendship::deleteAllFriendshipsForUser(int id) {
    Array<Friendship> friendshipsToDelete;
    for(int i = 0; i < this->repoFriendship.getAllFriendships().arraySize(); i++) {
        if(this->repoFriendship.getAllFriendships()[i].getSender().getId() == id or this->repoFriendship.getAllFriendships()[i].getReceiver().getId() == id) {
            friendshipsToDelete.pushBack(this->repoFriendship.getAllFriendships()[i]);
        }
    }
    for(int i = 0; i < friendshipsToDelete.arraySize(); i++) {
        this->repoFriendship.deleteFriendship(friendshipsToDelete[i]);
    }
}

Friendship ServiceFriendship::getFriendshipById(int id) {
    Friendship friendship;
    friendship = this->repoFriendship.getFriendshipById(id);
    return friendship;
}

Array<Friendship> ServiceFriendship::getAllFriendships() {
    return this->repoFriendship.getAllFriendships();
}

ServiceFriendship::~ServiceFriendship() = default;
