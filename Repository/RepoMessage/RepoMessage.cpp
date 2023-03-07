//
// Created by Bogdan Zarnescu on 22.05.2022.
//

#include "RepoMessage.h"
#include "../../Domain/BinaryTree/BinaryTreeNode.h"

RepoMessage::RepoMessage() = default;

void RepoMessage::addMessage(Message &message) {
    this->messages.add(message);
}

BinaryTree<Message> RepoMessage::getAllMessages() {
    return this->messages;
}

void RepoMessage::deleteMessage(Message &message) {
    this->messages.deleteElem(message);
}

bool RepoMessage::searchMessage(Message &message) {
    return this->messages.searchElem(message);
}

int RepoMessage::getSizeMessages() {
    return this->messages.sizeBinaryTree();
}

RepoMessage::~RepoMessage() = default;
