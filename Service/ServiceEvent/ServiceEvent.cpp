//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#include "ServiceEvent.h"

ServiceEvent::ServiceEvent() = default;

void ServiceEvent::createEvent(Event event) {
    this->repoEvent.addEvent(event);
}

void ServiceEvent::deleteEvent(int id) {
    Event event;
    event = this->repoEvent.getEventById(id);
    this->repoEvent.deleteEvent(event);
}

Event ServiceEvent::getEventById(int id) {
    Event event;
    event = this->repoEvent.getEventById(id);
    return event;
}

Array<Event> ServiceEvent::getAllEvents() {
    return this->repoEvent.getAllEvents();
}

ServiceEvent::~ServiceEvent() = default;
