//
// Created by Bogdan Zarnescu on 22.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_MESSAGE_H
#define SDA_PROFIECT_FINAL_MESSAGE_H

#include "../User/User.h"

class Message {
private:
    int id;
    User sender;
    User receiver;
    string msg;
public:
    Message();
    Message(int id1, User sender1, User receiver1, string msg1);
    Message(Message &message);
    void setId(int id1);
    void setSender(User sender1);
    void setReceiver(User receiver1);
    void setMsg(string msg1);
    int getId();
    User getSender();
    User getReceiver();
    string getMsg();
    Message &operator=(const Message &message);
    bool operator==(const Message &message);
    bool operator>(const Message &message);
    bool operator<(const Message &message);
    bool operator!=(const Message &message);
    friend ostream &operator<<(ostream &ostream1, Message &message);
    ~Message();
    Message(string args);
    void fromString(string args, char delimiter = ',');
};


#endif //SDA_PROFIECT_FINAL_MESSAGE_H
