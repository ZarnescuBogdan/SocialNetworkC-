//
// Created by Bogdan Zarnescu on 22.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_REPOMESSAGE_H
#define SDA_PROFIECT_FINAL_REPOMESSAGE_H

#include "../../Domain/BinaryTree/BinaryTree.h"
#include "../../Domain/Message/Message.h"

class RepoMessage {
private:
    BinaryTree<Message> messages;
public:
    RepoMessage();
    void addMessage(Message &message);
    BinaryTree<Message> getAllMessages();
    void deleteMessage(Message &message);
    bool searchMessage(Message &message);
    int getSizeMessages();
    ~RepoMessage();
};


#endif //SDA_PROFIECT_FINAL_REPOMESSAGE_H
