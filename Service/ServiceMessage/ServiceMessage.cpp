//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#include "ServiceMessage.h"

ServiceMessage::ServiceMessage() = default;

void ServiceMessage::createMessage(Message message) {
    this->repoMessage.addMessage(message);
}

BinaryTree<Message> ServiceMessage::getAllMessages() {
    return this->repoMessage.getAllMessages();
}

void ServiceMessage::deleteMessage(Message message) {
    this->repoMessage.deleteMessage(message);
}


ServiceMessage::~ServiceMessage() = default;
