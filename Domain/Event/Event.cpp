//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#include <sstream>
#include "Event.h"

Event::Event() {
    this->id = 0;
    this->host = User();
    this->name = "";
}

Event::Event(int id1, User host1, string name1) {
    this->id = id1;
    this->host = host1;
    this->name = name1;
}

Event::Event(Event &event) {
    this->id = event.id;
    this->host = event.host;
    this->name = event.name;
}

void Event::setId(int id1) {
    this->id = id1;
}

void Event::setHost(User host1) {
    this->host = host1;
}

void Event::setName(string name1) {
    this->name = name1;
}

int Event::getId() {
    return this->id;
}

User Event::getHost() {
    return this->host;
}

string Event::getName() {
    return this->name;
}

Event &Event::operator=(const Event &event) {
    this->id = event.id;
    this->host = event.host;
    this->name = event.name;
    return *this;
}

bool Event::operator==(const Event &event) {
    return ((this->host == event.host) and (this->name == event.name));
}

ostream &operator<<(ostream &ostream1, Event &event) {
    ostream1 << "Id: " << event.id << endl;
    ostream1 << "Host: " << event.host << endl;
    ostream1 << "Name: " << event.name << endl;
    ostream1 << "----------------------" << endl;
    return ostream1;
}

Event::~Event() {
    this->id = 0;
    this->host = User();
    this->name = "";
}

Event::Event(string args) {
    this->fromString(args);
}

void Event::fromString(string args, char delimiter) {
    Array<string> attributes;
    stringstream ss(args);
    string attribute;
    while(getline(ss, attribute, delimiter)) {
        attributes.pushBack(attribute);
    }
    if(attributes.arraySize() == 7) {
        int idHost, ageHost;
        string firstNameHost, lasNameHost, usernameHost;
        stringstream i(attributes[0]);
        i >> this->id;
        stringstream ih(attributes[1]);
        ih >> idHost;
        stringstream fnh(attributes[2]);
        fnh >> firstNameHost;
        stringstream lnh(attributes[3]);
        lnh >> lasNameHost;
        stringstream unh(attributes[4]);
        unh >> usernameHost;
        stringstream ah(attributes[5]);
        ah >> ageHost;
        stringstream n(attributes[6]);
        string name;
        getline(n, name);
        this->host = User(idHost, firstNameHost, lasNameHost, usernameHost, ageHost);
        this->name = name;
    }
}
