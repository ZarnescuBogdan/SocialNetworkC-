//
// Created by Bogdan Zarnescu on 22.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_FRIENDSHIP_H
#define SDA_PROFIECT_FINAL_FRIENDSHIP_H

#include "../User/User.h"

class Friendship {
private:
    int id;
    User sender;
    User receiver;
public:
    Friendship();
    Friendship(int id1, User sender1, User receiver1);
    Friendship(Friendship &friendship);
    void setId(int id1);
    void setSender(User sender1);
    void setReceiver(User receiver1);
    int getId();
    User getSender();
    User getReceiver();
    Friendship &operator=(const Friendship &friendship);
    bool operator==(const Friendship &friendship);
    friend ostream &operator<<(ostream &ostream1, Friendship &friendship);
    ~Friendship();
    Friendship(string args);
    void fromString(string args, char delimiter = ',');
};


#endif //SDA_PROFIECT_FINAL_FRIENDSHIP_H
