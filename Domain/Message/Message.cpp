//
// Created by Bogdan Zarnescu on 22.05.2022.
//

#include <sstream>
#include "Message.h"

Message::Message() {
    this->id = 0;
    this->sender = User();
    this->receiver = User();
    this->msg = "";
}

Message::Message(int id1, User sender1, User receiver1, string msg1) {
    this->id = id1;
    this->sender = sender1;
    this->receiver = receiver1;
    this->msg = msg1;
}

Message::Message(Message &message) {
    this->id = message.id;
    this->sender = message.sender;
    this->receiver = message.receiver;
    this->msg = message.msg;
}

void Message::setId(int id1) {
    this->id = id1;
}

void Message::setSender(User sender1) {
    this->sender = sender1;
}

void Message::setReceiver(User receiver1) {
    this->receiver = receiver1;
}

void Message::setMsg(string msg1) {
    this->msg = msg1;
}

int Message::getId() {
    return this->id;
}

User Message::getSender() {
    return this->sender;
}

User Message::getReceiver() {
    return this->receiver;
}

string Message::getMsg() {
    return this->msg;
}

bool Message::operator==(const Message &message) {
    return ((this->id == message.id) and (this->sender == message.sender) and (this->receiver == message.receiver) and (this->msg == message.msg));
}

ostream &operator<<(ostream &ostream1, Message &message) {
    ostream1 << "Id: " << message.id << endl;
    ostream1 << "Sender user: " << message.sender << endl;
    ostream1 << "Receiver user: " << message.receiver << endl;
    ostream1 << "Message: " << message.msg << endl;
    ostream1 << "----------------------" << endl;
    return ostream1;
}

bool Message::operator>(const Message &message) {
    if(this->id > message.id) {
        return true;
    } else {
        return false;
    }
}

bool Message::operator<(const Message &message) {
    if(this->id < message.id) {
        return true;
    } else {
        return false;
    }
}

bool Message::operator!=(const Message &message) {
    if(this->id != message.id) {
        return true;
    } else {
        return false;
    }
}

Message &Message::operator=(const Message &message) {
    this->id = message.id;
    this->sender = message.sender;
    this->receiver = message.receiver;
    this->msg = message.msg;
    return *this;
}

Message::~Message() {
    this->id = 0;
    this->sender = User();
    this->receiver = User();
    this->msg = "";
}

Message::Message(string args) {
    this->fromString(args);
}

void Message::fromString(string args, char delimiter) {
    Array<string> attributes;
    stringstream ss(args);
    string attribute;
    while (getline(ss, attribute, delimiter)) {
        attributes.pushBack(attribute);
    }
    if(attributes.arraySize() == 12) {
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
        stringstream m(attributes[11]);
        string messages;
        getline(m, messages);
        this->sender = User(idSender, firstNameSender, lastNameSender, usernameSender, ageSender);
        this->receiver = User(idReceiver, firstNameReceiver, lastNameReceiver, usernameReceiver, ageReceiver);
        this->msg = messages;
    }
}
