//
// Created by Bogdan Zarnescu on 25.05.2022.
//

#include "UI.h"

UI::UI() = default;

UI::~UI() = default;

void UI::runMenu() {
    bool ok = true;
    while (ok) {
        cout << "-----------Main menu-----------" << endl;
        cout << "1. User menu." << endl;
        cout << "2. Friendship menu." << endl;
        cout << "3. Message menu." << endl;
        cout << "4. Event menu." << endl;
        cout << "x. Close." << endl;
        cout << "-->";
        char option;
        cin >> option;
        switch (option) {
            case '1': {
                runMenuUser();
                break;
            }
            case '2': {
                runMenuFriendship();
                break;
            }
            case '3': {
                runMenuMessage();
                break;
            }
            case '4': {
                runMenuEvent();
                break;
            }
            case 'x': {
                ok = false;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}

void UI::runMenuUser() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "-----------USER-----------" << endl;
        cout << "1. Add user." << endl;
        cout << "2. Show all users." << endl;
        cout << "3. Update user." << endl;
        cout << "4. Delete user." << endl;
        cout << "5. Show all friends for a specified user." << endl;
        cout << "x. Exit." << endl;
        cout << "-->";
        char option;
        cin >> option;
        switch (option) {
            case '1': {
                this->addUser();
                break;
            }
            case '2': {
                this->showAllUsers();
                break;
            }
            case '3': {
                this->updateUser();
                break;
            }
            case '4': {
                this->deleteUser();
                break;
            }
            case '5': {
                this->showAllFriendsByUser();
                break;
            }
            case 'x': {
                ok = false;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}

void UI::runMenuFriendship() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "-----------FRIENDSHIP-----------" << endl;
        cout << "1. Add friendship." << endl;
        cout << "2. Show all friendships." << endl;
        cout << "3. Delete friendship." << endl;
        cout << "x. Exit." << endl;
        cout << "-->";
        char option;
        cin >> option;
        switch (option) {
            case '1': {
                this->addFriendship();
                break;
            }
            case '2': {
                this->showAllFriendships();
                break;
            }
            case '3': {
                this->deleteFriendship();
                break;
            }
            case 'x': {
                ok = false;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}

void UI::runMenuMessage() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "-----------MESSAGE-----------" << endl;
        cout << "1. Add message." << endl;
        cout << "2. Show all messages." << endl;
        cout << "3. Delete message." << endl;
        cout << "x. Exit." << endl;
        cout << "-->";
        char option;
        cin >> option;
        switch (option) {
            case '1': {
                this->addMessage();
                break;
            }
            case '2': {
                this->showAllMessages();
                break;
            }
            case '3': {
                this->deleteMessage();
                break;
            }
            case 'x': {
                ok = false;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}

void UI::runMenuEvent() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "-----------EVENT-----------" << endl;
        cout << "1. Add event." << endl;
        cout << "2. Show all events." << endl;
        cout << "3. Delete event." << endl;
        cout << "x. Exit." << endl;
        cout << "-->";
        char option;
        cin >> option;
        switch (option) {
            case '1': {
                this->addEvent();
                break;
            }
            case '2': {
                this->showAllEvents();
                break;
            }
            case '3': {
                this->deleteEvent();
                break;
            }
            case 'x': {
                ok = false;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}

void UI::addUser() {
    User user;
    cin >> user;
    this->network.createUser(user);
}

void UI::showAllUsers() {
    for(int i = 0; i < this->network.getAllUsers().arraySize(); i++) {
        cout << this->network.getAllUsers()[i] << endl;
    }
}

void UI::updateUser() {
    int id;
    cout << "Enter id for the user to be updated: ";
    cin >> id;
    User newUser;
    cin >> newUser;
    this->network.updateUser(id, newUser);
}

void UI::deleteUser() {
    int id;
    cout << "Enter id of user to be deleted: ";
    cin >> id;
    this->network.deleteUser(id);
}

void UI::showAllFriendsByUser() {
    int id;
    cout << "Enter id of user you want to see the friend list: ";
    cin >> id;
    for(int i = 0; i < this->network.getAllFriendshipsByUser(id).arraySize(); i++) {
        cout << this->network.getAllFriendshipsByUser(id)[i] << endl;
    }
}

void UI::addFriendship() {
    int id;
    cout << "Enter friendship id: ";
    cin >> id;

    int idSender;
    cout << "Enter sender id: ";
    cin >> idSender;

    int idReceiver;
    cout << "Enter receiver id: ";
    cin >> idReceiver;

    string msg;
    cout << "To accept the friend request, type 'accept':";
    getline(cin, msg);
    getline(cin, msg);

    this->network.addFriendship(id, idSender, idReceiver, msg);
}

void UI::showAllFriendships() {
    for(int i = 0; i < this->network.getAllFriendships().arraySize(); i++) {
        cout << this->network.getAllFriendships()[i] << endl;
    }
}

void UI::deleteFriendship() {
    int id;
    cout << "Enter id of friendship to be deleted: ";
    cin >> id;
    this->network.deleteFriendship(id);
}

void UI::addMessage() {
    int id;
    cout << "Enter message id: ";
    cin >> id;

    int idSender;
    cout << "Enter sender id: ";
    cin >> idSender;

    int idReceiver;
    cout << "Enter receiver id: ";
    cin >> idReceiver;

    string msg;
    cout << "Enter the message: ";
    getline(cin, msg);
    getline(cin, msg);
    this->network.addMessage(id, idSender, idReceiver, msg);
}

void UI::showAllMessages() {
    this->network.getAllMessages().show();
}

void UI::deleteMessage() {
    int id;
    cout << "Enter id of message to be deleted: ";
    cin >> id;

    int idSender;
    cout << "Enter id of sender to be deleted: ";
    cin >> idSender;

    int idReceiver;
    cout << "Enter id of receiver to be deleted: ";
    cin >> idReceiver;

    string msg;
    cout << "Enter message to be deleted: ";
    getline(cin, msg);
    getline(cin, msg);
    this->network.deleteMessage(id, idSender, idReceiver, msg);
}

void UI::addEvent() {
    int id;
    cout << "Enter event id: ";
    cin >> id;

    int idHost;
    cout << "Enter host id: ";
    cin >> idHost;

    string name;
    cout << "Enter event name: ";
    getline(cin, name);
    getline(cin, name);

    this->network.addEvent(id, idHost, name);
}

void UI::showAllEvents() {
    for(int i = 0; i < this->network.getAllEvents().arraySize(); i++) {
        cout << this->network.getAllEvents()[i] << endl;
    }
}

void UI::deleteEvent() {
    int id;
    cout << "Enter id of event to be deleted: ";
    cin >> id;
    this->network.deleteEvent(id);
}
