//
// Created by Bogdan Zarnescu on 22.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_REPOFRIENDSHIP_H
#define SDA_PROFIECT_FINAL_REPOFRIENDSHIP_H

#include "../../Domain/Array/Array.h"
#include "../../Domain/Friendship/Friendship.h"

class RepoFriendship {
private:
    Array<Friendship> friendships;
public:
    RepoFriendship();
    void addFriendship(Friendship &friendship);
    Friendship getFriendshipById(int id);
    Array<Friendship> getAllFriendships();
    void deleteFriendship(Friendship &friendship);
    ~RepoFriendship();
};


#endif //SDA_PROFIECT_FINAL_REPOFRIENDSHIP_H
