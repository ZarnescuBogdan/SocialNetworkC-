//
// Created by Bogdan Zarnescu on 11.05.2022.
//

#include "tests.h"
#include <cassert>
#include "../Domain/Array/Array.h"
#include "../Domain/BinaryTree/BinaryTree.h"
#include "../Domain/User/User.h"
#include "../Domain/Friendship/Friendship.h"
#include "../Domain/Message/Message.h"
#include "../Domain/Event/Event.h"
#include "../Repository/RepoUser/RepoUser.h"
#include "../Repository/RepoFriendship/RepoFriendship.h"
#include "../Repository/RepoMessage/RepoMessage.h"
#include "../Repository/RepoEvent/RepoEvent.h"
#include "../Service/ServiceUser/ServiceUser.h"
#include "../Service/ServiceFriendship/ServiceFriendship.h"
#include "../Service/ServiceMessage/ServiceMessage.h"
#include "../Service/ServiceEvent/ServiceEvent.h"

void testUserConstructor() {
    User user;
    assert(user.getId() == 0);
    assert(user.getFirstName().empty());
    assert(user.getLastName().empty());
    assert(user.getUsername().empty());
    assert(user.getAge() == 0);
}

void testUserConstructor2() {
    User user(1, "Bogdan", "Zarnescu", "bogdanzarnescu", 19);
    assert(user.getId() == 1);
    assert(user.getFirstName() == "Bogdan");
    assert(user.getLastName() == "Zarnescu");
    assert(user.getUsername() == "bogdanzarnescu");
    assert(user.getAge() == 19);
}

void testUserSetterGetter() {
    User user;
    user.setId(1);
    user.setFirstName("Bogdan");
    user.setLastName("Zarnescu");
    user.setUsername("bogdanzarnescu");
    user.setAge(19);
    assert(user.getId() == 1);
    assert(user.getFirstName() == "Bogdan");
    assert(user.getLastName() == "Zarnescu");
    assert(user.getUsername() == "bogdanzarnescu");
    assert(user.getAge() == 19);
}

void testFriendshipConstructor() {
    Friendship friendship;
    assert(friendship.getId() == 0);
    assert(friendship.getSender() == User());
    assert(friendship.getReceiver() == User());
}

void testFriendshipConstructor2() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan", 20);
    Friendship friendship(1, u1, u2);
    assert(friendship.getId() == 1);
    assert(friendship.getSender() == u1);
    assert(friendship.getReceiver() == u2);
}

void testFriendshipSetterGetter() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan", 20);
    Friendship friendship;
    friendship.setId(1);
    friendship.setSender(u1);
    friendship.setReceiver(u2);
    assert(friendship.getId() == 1);
    assert(friendship.getSender() == u1);
    assert(friendship.getReceiver() == u2);
}

void testMessageConstructor() {
    Message message;
    assert(message.getId() == 0);
    assert(message.getSender() == User());
    assert(message.getReceiver() == User());
    assert(message.getMsg().empty());
}

void testMessageConstructor2() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan", 20);
    Message message(1, u1, u2, "WOW!");
    assert(message.getId() == 1);
    assert(message.getSender() == u1);
    assert(message.getReceiver() == u2);
    assert(message.getMsg() == "WOW!");
}

void testMessageSetterGetter() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan", 20);
    Message message;
    message.setId(1);
    message.setSender(u2);
    message.setReceiver(u1);
    message.setMsg("WOW!");
    assert(message.getId() == 1);
    assert(message.getSender() == u2);
    assert(message.getReceiver() == u1);
    assert(message.getMsg() == "WOW!");
}

void testEventConstructor() {
    Event event;
    assert(event.getId() == 0);
    assert(event.getHost() == User());
    assert(event.getName().empty());
}

void testEventConstructor2() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu", 19);
    Event event(1, u1, "UNTOLD");
    assert(event.getId() == 1);
    assert(event.getHost() == u1);
    assert(event.getName() == "UNTOLD");
}

void testEventSetterGetter() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu", 19);
    Event event;
    event.setId(1);
    event.setHost(u1);
    event.setName("UNTOLD");
    assert(event.getId() == 1);
    assert(event.getHost() == u1);
    assert(event.getName() == "UNTOLD");
}

void testArray() {
    Array<User> array;
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan", 21);
    User u4(4, "Oana", "Stejeroiu", "oanafluture", 22);

    assert(array.arraySize() == 0);
    array.pushBack(u1);
    array.pushBack(u2);
    array.pushBack(u3);
    assert(array.arraySize() == 3);
    array.insert(2, u4);
    assert(array.arraySize() == 4);
    assert(array[0] == u1);
    assert(array[2] == u4);

    array.popBack();
    assert(array.arraySize() == 3);
    array.pushBack(u3);
    array.eraseIndex(1);
    assert(array.arraySize() == 3);
    assert(array[0] == u1);
    assert(array[1] == u4);
    array.eraseAll();
    assert(array.empty() == true);
}

void testBinaryTree() {
    BinaryTree<Message> binaryTree;
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu22", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan22", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan6", 21);
    User u4(2, "Oana", "Stejeroiu", "oanafluture4", 22);

    Message m1(1, u1, u2, "MATA");
    Message m2(2, u2, u1, "TACTU");
    Message m3(3, u2, u3, "SORTA");
    Message m4(4, u4, u2, "FRACTU");
    Message m5(5, u3, u1, "BUNATA");
    Message m6(6, u4, u1, "TATATU");

    assert(binaryTree.sizeBinaryTree() == 0);
    binaryTree.add(m2);
    binaryTree.add(m1);
    binaryTree.add(m3);
    binaryTree.add(m5);
    binaryTree.add(m4);
    assert(binaryTree.sizeBinaryTree() == 5);
    assert(binaryTree.searchElem(m2) == true);
    assert(binaryTree.searchElem(m6) == false);
    binaryTree.deleteElem(m2);
    assert(binaryTree.sizeBinaryTree() == 4);
    assert(binaryTree.searchElem(m2) == false);
    binaryTree.deleteElem(m2);
    assert(binaryTree.sizeBinaryTree() == 4);
}

void testRepoUser() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu22", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan22", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan6", 21);
    User u4(2, "Oana", "Stejeroiu", "oanafluture4", 22);

    RepoUser repo;
    assert(repo.getSize() == 0);
    repo.addUser(u1);
    repo.addUser(u2);
    repo.addUser(u3);
    assert(repo.getSize() == 3);
    assert(repo.getUserById(1) == u1);
    repo.modifyUser(u2, u4);
    assert(repo.getSize() == 3);
    assert(repo.getUserById(2) == u4);
    repo.deleteUser(u1);
    assert(repo.getSize() == 2);
}

void testRepoFriendship() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu22", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan22", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan6", 21);
    User u4(2, "Oana", "Stejeroiu", "oanafluture4", 22);

    Friendship f1(1, u1, u2);
    Friendship f2(2, u1, u3);
    Friendship f3(3, u2, u4);
    Friendship f4(4, u4, u1);

    RepoFriendship repoFriendship;
    assert(repoFriendship.getAllFriendships().arraySize() == 0);
    repoFriendship.addFriendship(f1);
    repoFriendship.addFriendship(f2);
    repoFriendship.addFriendship(f3);
    assert(repoFriendship.getAllFriendships().arraySize() == 3);
    assert(repoFriendship.getFriendshipById(1) == f1);
    assert(repoFriendship.getFriendshipById(2) == f2);
    repoFriendship.deleteFriendship(f2);
    assert(repoFriendship.getAllFriendships().arraySize() == 2);
    repoFriendship.addFriendship(f2);
    repoFriendship.addFriendship(f3);
    assert(repoFriendship.getAllFriendships().arraySize() == 4);
}

void testRepoMessage() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu22", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan22", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan6", 21);
    User u4(2, "Oana", "Stejeroiu", "oanafluture4", 22);

    Message m1(1, u1, u2, "Buna");
    Message m2(2, u2, u1, "Cf?");
    Message m3(3, u2, u3, "Bine");
    Message m4(4, u4, u2, "Hei");
    Message m5(5, u3, u1, "Ciao");
    Message m6(6, u4, u1, "Bafta in cupa!");

    RepoMessage repoMessage;
    repoMessage.deleteMessage(m1);
    repoMessage.addMessage(m2);
    repoMessage.addMessage(m1);
    repoMessage.addMessage(m3);
    repoMessage.addMessage(m5);
    repoMessage.addMessage(m4);
    repoMessage.addMessage(m6);
    assert(repoMessage.getSizeMessages() == 6);
    assert(repoMessage.searchMessage(m2) == true);
    assert(repoMessage.searchMessage(m6) == true);
    repoMessage.deleteMessage(m6);
    repoMessage.deleteMessage(m2);
    assert(repoMessage.getSizeMessages() == 4);
    assert(repoMessage.searchMessage(m6) == false);
    assert(repoMessage.searchMessage(m2) == false);
    repoMessage.deleteMessage(m3);
    repoMessage.deleteMessage(m4);
    repoMessage.deleteMessage(m5);
    repoMessage.deleteMessage(m1);
    assert(repoMessage.getSizeMessages() == 0);
}

void testRepoEvent() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu22", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan22", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan6", 21);
    User u4(2, "Oana", "Stejeroiu", "oanafluture4", 22);

    Event e1(1, u1, "UNTOLD");
    Event e2(2, u2, "NEVERSEA");
    Event e3(3, u3, "Electric Castle");
    Event e4(4, u4, "Hustle Festival");

    RepoEvent repoEvent;
    assert(repoEvent.getAllEvents().arraySize() == 0);
    repoEvent.addEvent(e1);
    repoEvent.addEvent(e2);
    repoEvent.addEvent(e3);
    assert(repoEvent.getAllEvents().arraySize() == 3);
    assert(repoEvent.getEventById(1) == e1);
    assert(repoEvent.getEventById(2) == e2);
    assert(repoEvent.getEventById(3) == e3);
    repoEvent.deleteEvent(e2);
    assert(repoEvent.getAllEvents().arraySize() == 2);
    repoEvent.deleteEvent(e1);
    assert(repoEvent.getAllEvents().arraySize() == 1);
}

void testServiceUser() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu22", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan22", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan6", 21);
    User u4(2, "Oana", "Stejeroiu", "oanafluture4", 22);

    RepoUser repoUser;
    ServiceUser serviceUser(repoUser);
    serviceUser.createUser(u1);
    serviceUser.createUser(u2);
    serviceUser.createUser(u3);

    assert(serviceUser.getUserById(1) == u1);
    assert(serviceUser.getUserById(2) == u2);
    assert(serviceUser.getUserById(3) == u3);
    assert(serviceUser.getAllUsers().arraySize() == 3);
    serviceUser.updateUser(2, u4);
    assert(serviceUser.getUserById(2) == u4);
    assert(serviceUser.getAllUsers().arraySize() == 3);
    serviceUser.deleteUser(3);
    assert(serviceUser.getAllUsers().arraySize() == 2);
}

void testServiceFriendship() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu22", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan22", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan6", 21);
    User u4(2, "Oana", "Stejeroiu", "oanafluture4", 22);

    Friendship f1(1, u1, u2);
    Friendship f2(2, u1, u3);
    Friendship f3(3, u2, u4);

    RepoFriendship repoFriendship;
    ServiceFriendship serviceFriendship(repoFriendship);
    assert(serviceFriendship.getAllFriendships().arraySize() == 0);
    serviceFriendship.createFriendship(f1);
    serviceFriendship.createFriendship(f2);
    serviceFriendship.createFriendship(f3);
    assert(serviceFriendship.getAllFriendships().arraySize() == 3);
    assert(serviceFriendship.getFriendshipById(1) == f1);
    assert(serviceFriendship.getFriendshipById(2) == f2);
    assert(serviceFriendship.getFriendshipById(3) == f3);
    serviceFriendship.deleteFriendship(3);
    assert(serviceFriendship.getAllFriendships().arraySize() == 2);
}

void testServiceMessage() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu22", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan22", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan6", 21);
    User u4(2, "Oana", "Stejeroiu", "oanafluture4", 22);

    Message m1(1, u1, u2, "Buna");
    Message m2(2, u2, u1, "Cf?");
    Message m3(3, u2, u3, "Bine");
    Message m4(4, u4, u2, "Hei");
    Message m5(5, u3, u1, "Ciao");
    Message m6(6, u4, u1, "Bafta in cupa!");

    RepoMessage repoMessage;
    ServiceMessage serviceMessage(repoMessage);
    serviceMessage.createMessage(m1);
    serviceMessage.createMessage(m2);
    serviceMessage.createMessage(m3);
    serviceMessage.createMessage(m4);
    serviceMessage.createMessage(m5);
    serviceMessage.createMessage(m6);
    serviceMessage.deleteMessage(m3);
    serviceMessage.deleteMessage(m5);
}

void testServiceEvent() {
    User u1(1, "Bogdan", "Zarnescu", "bogdanzarnescu22", 19);
    User u2(2, "Andreea", "Tamasan", "andreeatamasan22", 20);
    User u3(3, "Alexandru", "Topan", "alexandrutopan6", 21);
    User u4(2, "Oana", "Stejeroiu", "oanafluture4", 22);

    Event e1(1, u1, "UNTOLD");
    Event e2(2, u2, "NEVERSEA");
    Event e3(3, u3, "Electric Castle");
    Event e4(4, u4, "Hustle Festival");

    RepoEvent repoEvent;
    ServiceEvent serviceEvent(repoEvent);
    assert(serviceEvent.getAllEvents().arraySize() == 0);
    serviceEvent.createEvent(e1);
    serviceEvent.createEvent(e2);
    serviceEvent.createEvent(e3);
    serviceEvent.createEvent(e4);
    assert(serviceEvent.getAllEvents().arraySize() == 4);
    assert(serviceEvent.getEventById(1) == e1);
    assert(serviceEvent.getEventById(2) == e2);
    assert(serviceEvent.getEventById(3) == e3);
    assert(serviceEvent.getEventById(4) == e4);
    serviceEvent.deleteEvent(2);
    assert(serviceEvent.getAllEvents().arraySize() == 3);
}

void testAll() {
    testUserConstructor();
    testUserConstructor2();
    testUserSetterGetter();
    testFriendshipConstructor();
    testFriendshipConstructor2();
    testFriendshipSetterGetter();
    testMessageConstructor();
    testMessageConstructor2();
    testMessageSetterGetter();
    testEventConstructor();
    testEventConstructor2();
    testEventSetterGetter();
    testArray();
    testBinaryTree();
    testRepoUser();
    testRepoFriendship();
    testRepoMessage();
    testRepoEvent();
    testServiceUser();
    testServiceFriendship();
    testServiceMessage();
    testServiceEvent();
}
