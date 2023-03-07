//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_EVENT_H
#define SDA_PROFIECT_FINAL_EVENT_H

#include <iostream>
#include "../User/User.h"

using namespace std;

class Event {
private:
    int id;
    User host;
    string name;
public:
    Event();
    Event(int id1, User host1, string name1);
    Event(Event &event);
    void setId(int id1);
    void setHost(User host1);
    void setName(string name1);
    int getId();
    User getHost();
    string getName();
    Event &operator=(const Event &event);
    bool operator==(const Event &event);
    friend ostream &operator<<(ostream &ostream1, Event &event);
    ~Event();
    Event(string args);
    void fromString(string args, char delimiter = ',');
};


#endif //SDA_PROFIECT_FINAL_EVENT_H
