#include <iostream>
#include "UserInterface/UI.h"
#include "Tests/tests.h"

using namespace std;

int main() {
    cout << "Start tests!" << endl;
    testAll();
    cout << "End tests!" << endl;
    UI ui;
    ui.runMenu();
    //RepoUser repoUser;
    //RepoFriendship repoFriendship;
    //RepoMessage repoMessage;
    //RepoEvent repoEvent;
    //ServiceUser serviceUser(repoUser);
    //ServiceFriendship serviceFriendship(repoFriendship);
    //ServiceMessage serviceMessage(repoMessage);
    //ServiceEvent serviceEvent(repoEvent);
    //Network network(serviceUser, serviceFriendship, serviceMessage, serviceEvent);
    //UI ui(network);
    //ui.runMenu();
    return 0;
}
