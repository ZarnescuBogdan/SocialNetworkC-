//
// Created by Bogdan Zarnescu on 25.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_NETWORK_H
#define SDA_PROFIECT_FINAL_NETWORK_H

#include "../Service/ServiceUser/ServiceUser.h"
#include "../Service/ServiceFriendship/ServiceFriendship.h"
#include "../Service/ServiceMessage/ServiceMessage.h"
#include "../Service/ServiceEvent/ServiceEvent.h"
#include <fstream>

class Network {
private:
    ServiceUser serviceUser;
    ServiceFriendship serviceFriendship;
    ServiceMessage serviceMessage;
    ServiceEvent serviceEvent;
public:
    Network();
    Network(ServiceUser &serviceUser1,
            ServiceFriendship &serviceFriendship1,
            ServiceMessage &serviceMessage1,
            ServiceEvent &serviceEvent1): serviceUser(serviceUser1),
                                            serviceFriendship(serviceFriendship1),
                                            serviceMessage(serviceMessage1),
                                            serviceEvent(serviceEvent1) {}
    ~Network();
    void createUser(User user);
    Array<User> getAllUsers();
    void updateUser(int id, User newUser);
    void deleteUser(int id);
    Array<User> getAllFriendshipsByUser(int id);
    void addFriendship(int id, int idSender, int idReceiver, string msg);
    Array<Friendship> getAllFriendships();
    void deleteFriendship(int id);
    void addMessage(int id, int idSender, int idReceiver, string msg);
    BinaryTree<Message> getAllMessages();
    void deleteMessage(int id, int idSender, int idReceiver, string msg);
    void addEvent(int id, int idHost, string name);
    Array<Event> getAllEvents();
    void deleteEvent(int id);
};


#endif //SDA_PROFIECT_FINAL_NETWORK_H
