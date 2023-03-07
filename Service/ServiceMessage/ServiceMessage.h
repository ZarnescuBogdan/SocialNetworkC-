//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_SERVICEMESSAGE_H
#define SDA_PROFIECT_FINAL_SERVICEMESSAGE_H

#include "../../Repository/RepoMessage/RepoMessage.h"

class ServiceMessage {
private:
    RepoMessage repoMessage;
public:
    ServiceMessage();
    ServiceMessage(RepoMessage &repoMessage1): repoMessage(repoMessage1) {}
    BinaryTree<Message> getAllMessages();
    void createMessage(Message message);
    void deleteMessage(Message message);
    ~ServiceMessage();
};


#endif //SDA_PROFIECT_FINAL_SERVICEMESSAGE_H
