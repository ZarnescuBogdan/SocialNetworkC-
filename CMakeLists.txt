cmake_minimum_required(VERSION 3.21)
project(SDA_Profiect_final)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDA_Profiect_final main.cpp Domain/User/User.cpp Domain/User/User.h Domain/Array/Array.h Tests/tests.h Tests/tests.cpp Repository/RepoUser/RepoUser.cpp Repository/RepoUser/RepoUser.h Domain/BinaryTree/BinaryTree.h Domain/BinaryTree/BinaryTreeNode.h Domain/Friendship/Friendship.cpp Domain/Friendship/Friendship.h Repository/RepoFriendship/RepoFriendship.cpp Repository/RepoFriendship/RepoFriendship.h Domain/Message/Message.cpp Domain/Message/Message.h Repository/RepoMessage/RepoMessage.cpp Repository/RepoMessage/RepoMessage.h Domain/Event/Event.cpp Domain/Event/Event.h Repository/RepoEvent/RepoEvent.cpp Repository/RepoEvent/RepoEvent.h Service/ServiceUser/ServiceUser.cpp Service/ServiceUser/ServiceUser.h Service/ServiceFriendship/ServiceFriendship.cpp Service/ServiceFriendship/ServiceFriendship.h Service/ServiceMessage/ServiceMessage.cpp Service/ServiceMessage/ServiceMessage.h Service/ServiceEvent/ServiceEvent.cpp Service/ServiceEvent/ServiceEvent.h Network/Network.cpp Network/Network.h UserInterface/UI.cpp UserInterface/UI.h)
