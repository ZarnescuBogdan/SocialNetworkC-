//
// Created by Bogdan Zarnescu on 22.05.2022.
//

#include "RepoFriendship.h"

RepoFriendship::RepoFriendship() = default;

void RepoFriendship::addFriendship(Friendship &friendship) {
    this->friendships.pushBack(friendship);
}

Friendship RepoFriendship::getFriendshipById(int id) {
    for(int i = 0; i < this->friendships.arraySize(); i++) {
        if(this->friendships[i].getId() == id) {
            return this->friendships[i];
        }
    }
    throw runtime_error("No friendship with given id was found!");
}

Array<Friendship> RepoFriendship::getAllFriendships() {
    return this->friendships;
}

void RepoFriendship::deleteFriendship(Friendship &friendship) {
    for(int i = 0; i < this->friendships.arraySize(); i++) {
        if(this->friendships[i].getId() == friendship.getId()) {
            this->friendships.eraseIndex(i);
        }
    }
}

RepoFriendship::~RepoFriendship() = default;
