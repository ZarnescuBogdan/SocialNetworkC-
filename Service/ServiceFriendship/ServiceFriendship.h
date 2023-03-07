//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_SERVICEFRIENDSHIP_H
#define SDA_PROFIECT_FINAL_SERVICEFRIENDSHIP_H

#include "../../Repository/RepoFriendship/RepoFriendship.h"

class ServiceFriendship {
private:
    RepoFriendship repoFriendship;
public:
    ServiceFriendship();
    ServiceFriendship(RepoFriendship &repoFriendship1): repoFriendship(repoFriendship1) {}
    void createFriendship(Friendship friendship);
    void deleteFriendship(int id);
    void deleteAllFriendshipsForUser(int id);
    Friendship getFriendshipById(int id);
    Array<Friendship> getAllFriendships();
    ~ServiceFriendship();
};


#endif //SDA_PROFIECT_FINAL_SERVICEFRIENDSHIP_H
