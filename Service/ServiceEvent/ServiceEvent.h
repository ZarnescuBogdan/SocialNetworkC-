//
// Created by Bogdan Zarnescu on 24.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_SERVICEEVENT_H
#define SDA_PROFIECT_FINAL_SERVICEEVENT_H

#include "../../Repository/RepoEvent/RepoEvent.h"

class ServiceEvent {
private:
    RepoEvent repoEvent;
public:
    ServiceEvent();
    ServiceEvent(RepoEvent &repoEvent1): repoEvent(repoEvent1) {}
    void createEvent(Event event);
    void deleteEvent(int id);
    Event getEventById(int id);
    Array<Event> getAllEvents();
    ~ServiceEvent();
};


#endif //SDA_PROFIECT_FINAL_SERVICEEVENT_H
