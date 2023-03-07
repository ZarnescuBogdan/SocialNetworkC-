//
// Created by Bogdan Zarnescu on 22.05.2022.
//

#include <sstream>
#include "Friendship.h"

Friendship::Friendship() {
    this->id = 0;
    this->sender = User();
    this->receiver = User();
}

Friendship::Friendship(int id1, User sender1, User receiver1) {
    this->id = id1;
    this->sender = sender1;
    this->receiver = receiver1;
}

Friendship::Friendship(Friendship &friendship) {
    this->id = friendship.id;
    this->sender = friendship.sender;
    this->receiver = friendship.receiver;
}

void Friendship::setId(int id1) {
    this->id = id1;
}

void Friendship::setSender(User sender1) {
    this->sender = sender1;
}

void Friendship::setReceiver(User receiver1) {
    this->receiver = receiver1;
}

int Friendship::getId() {
    return this->id;
}

User Friendship::getSender() {
    return this->sender;
}

User Friendship::getReceiver() {
    return this->receiver;
}

ostream &operator<<(ostream &ostream1, Friendship &friendship) {
    ostream1 << "Id: " << friendship.id << endl << endl;
    ostream1 << "Sender user: " << friendship.sender << endl;
    ostream1 << "Receiver user: " << friendship.receiver << endl;
    ostream1 << "----------------------" << endl;
    return ostream1;
}

Friendship::~Friendship() {
    this->id = 0;
    this->sender = User();
    this->receiver = User();
}

bool Friendship::operator==(const Friendship &friendship) {
    return ((this->sender == friendship.sender) and (this->receiver == friendship.receiver));
}

Friendship &Friendship::operator=(const Friendship &friendship) {
    this->id = friendship.id;
    this->sender = friendship.sender;
    this->receiver = friendship.receiver;
    return *this;
}

Friendship::Friendship(string args) {
    this->fromString(args);
}

void Friendship::fromString(string args, char delimiter) {
    Array<string> attributes;
    stringstream ss(args);
    string attribute;
    while (getline(ss, attribute, delimiter)) {
        attributes.pushBack(attribute);
    }
    if(attributes.arraySize() == 11) {
        int idSender, ageSender, idReceiver, ageReceiver;
        string firstNameSender, lastNameSender, usernameSender, firstNameReceiver, lastNameReceiver, usernameReceiver;
        stringstream i(attributes[0]);
        i >> this->id;
        stringstream is(attributes[1]);
        is >> idSender;
        stringstream fns(attributes[2]);
        fns >> firstNameSender;
        stringstream lns(attributes[3]);
        lns >> lastNameSender;
        stringstream uns(attributes[4]);
        uns >> usernameSender;
        stringstream as(attributes[5]);
        as >> ageSender;
        stringstream ir(attributes[6]);
        ir >> idReceiver;
        stringstream fnr(attributes[7]);
        fnr >> firstNameReceiver;
        stringstream lnr(attributes[8]);
        lnr >> lastNameReceiver;
        stringstream unr(attributes[9]);
        unr >> usernameReceiver;
        stringstream ar(attributes[10]);
        ar >> ageReceiver;
        this->sender = User(idSender, firstNameSender, lastNameSender, usernameSender, ageSender);
        this->receiver = User(idReceiver, firstNameReceiver, lastNameReceiver, usernameReceiver, ageReceiver);
    }
}
