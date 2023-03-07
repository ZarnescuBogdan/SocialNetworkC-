//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#include "RepoEvent.h"

RepoEvent::RepoEvent() = default;

void RepoEvent::addEvent(Event &event) {
    this->events.pushBack(event);
}

Event RepoEvent::getEventById(int id) {
    for(int i = 0; i < this->events.arraySize(); i++) {
        if(this->events[i].getId() == id) {
            return this->events[i];
        }
    }
    throw runtime_error("No event with given id was found!");
}

Array<Event> RepoEvent::getAllEvents() {
    return this->events;
}

void RepoEvent::deleteEvent(Event &event) {
    for(int i = 0; i < this->events.arraySize(); i++) {
        if(this->events[i].getId() == event.getId()) {
            this->events.eraseIndex(i);
        }
    }
}

RepoEvent::~RepoEvent() = default;
