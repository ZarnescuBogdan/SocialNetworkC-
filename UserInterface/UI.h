//
// Created by Bogdan Zarnescu on 25.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_UI_H
#define SDA_PROFIECT_FINAL_UI_H

#include "../Network/Network.h"

class UI {
private:
    Network network;
public:
    UI();
    UI(Network &network1): network(network1) {}
    ~UI();
    void runMenu();
    void runMenuUser();
    void runMenuFriendship();
    void runMenuMessage();
    void runMenuEvent();
    void addUser();
    void showAllUsers();
    void updateUser();
    void deleteUser();
    void showAllFriendsByUser();
    void addFriendship();
    void showAllFriendships();
    void deleteFriendship();
    void addMessage();
    void showAllMessages();
    void deleteMessage();
    void addEvent();
    void showAllEvents();
    void deleteEvent();
};


#endif //SDA_PROFIECT_FINAL_UI_H
