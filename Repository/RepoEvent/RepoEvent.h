//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_REPOEVENT_H
#define SDA_PROFIECT_FINAL_REPOEVENT_H

#include "../../Domain/Array/Array.h"
#include "../../Domain/Event/Event.h"

class RepoEvent {
private:
    Array<Event> events;
public:
    RepoEvent();
    void addEvent(Event &event);
    Event getEventById(int id);
    Array<Event> getAllEvents();
    void deleteEvent(Event &event);
    ~RepoEvent();
};


#endif //SDA_PROFIECT_FINAL_REPOEVENT_H
