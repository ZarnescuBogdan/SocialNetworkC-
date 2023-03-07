//
// Created by Bogdan Zarnescu on 25.05.2022.
//

#include "Network.h"

Network::Network() {
    string line;
    ifstream myFileUsers("../TextFiles/Users.txt");
    while (getline(myFileUsers, line)) {
        User user(line);
        this->serviceUser.createUser(user);
    }
    ifstream myFileFriendships("../TextFiles/Friendships.txt");
    while (getline(myFileFriendships, line)) {
        Friendship friendship(line);
        this->serviceFriendship.createFriendship(friendship);
    }
    ifstream myFileMessages("../TextFiles/Messages.txt");
    while (getline(myFileMessages, line)) {
        Message message(line);
        this->serviceMessage.createMessage(message);
    }
    ifstream myFileEvents("../TextFiles/Events.txt");
    while (getline(myFileEvents, line)) {
        Event event(line);
        this->serviceEvent.createEvent(event);
    }
}

Network::~Network() = default;

void Network::createUser(User user) {
    this->serviceUser.createUser(user);
}

Array<User> Network::getAllUsers() {
    return this->serviceUser.getAllUsers();
}

void Network::updateUser(int id, User newUser) {
    this->serviceUser.updateUser(id, newUser);
}

void Network::deleteUser(int id) {
    this->serviceUser.deleteUser(id);
    this->serviceFriendship.deleteAllFriendshipsForUser(id);
}

void Network::addFriendship(int id, int idSender, int idReceiver, string msg) {
    if(strcmp(msg.c_str(), "accept") == 0) {
        User sender = this->serviceUser.getUserById(idSender);
        User receiver = this->serviceUser.getUserById(idReceiver);
        Friendship friendship(id, sender, receiver);
        this->serviceFriendship.createFriendship(friendship);
    }
}

Array<Friendship> Network::getAllFriendships() {
    return this->serviceFriendship.getAllFriendships();
}

void Network::deleteFriendship(int id) {
    this->serviceFriendship.deleteFriendship(id);
}

void Network::addMessage(int id, int idSender, int idReceiver, string msg) {
    User sender = this->serviceUser.getUserById(idSender);
    User receiver = this->serviceUser.getUserById(idReceiver);
    Message message(id, sender, receiver, msg);
    this->serviceMessage.createMessage(message);
}

BinaryTree<Message> Network::getAllMessages() {
    return this->serviceMessage.getAllMessages();
}

void Network::deleteMessage(int id, int idSender, int idReceiver, string msg) {
    User sender = this->serviceUser.getUserById(idSender);
    User receiver = this->serviceUser.getUserById(idReceiver);

    Message message(id, sender, receiver, msg);

    this->serviceMessage.deleteMessage(message);
}

void Network::addEvent(int id, int idHost, string name) {
    User host = this->serviceUser.getUserById(idHost);
    Event event(id, host, name);
    this->serviceEvent.createEvent(event);
}

Array<Event> Network::getAllEvents() {
    return this->serviceEvent.getAllEvents();
}

void Network::deleteEvent(int id) {
    this->serviceEvent.deleteEvent(id);
}

Array<User> Network::getAllFriendshipsByUser(int id) {
    Array<User> users;
    for(int i = 0; i < this->serviceFriendship.getAllFriendships().arraySize(); i++) {
        if(this->serviceFriendship.getAllFriendships()[i].getSender().getId() == id) {
            users.pushBack(this->serviceFriendship.getAllFriendships()[i].getReceiver());
        } else if(this->serviceFriendship.getAllFriendships()[i].getReceiver().getId() == id) {
            users.pushBack(this->serviceFriendship.getAllFriendships()[i].getSender());
        }
    }
    return users;
}
