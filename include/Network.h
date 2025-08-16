#ifndef NETWORK_H
#define NETWORK_H

#include <unordered_map>
#include <memory>
#include <string>
#include "User.h"

class Network {
private:
    std::unordered_map<int, std::shared_ptr<User>> userRegistry;

public:
    void addUser(int id, const std::string& username, const std::string& email, const std::string& description);

    std::shared_ptr<User> findUser(int id) const;

    void deleteUser(int id);

    bool userExists(int id) const;

    void sendFriendRequest(int userId, int friendId);

    void acceptFriendRequest(int userId, int friendId);

    bool areFriends(int userId, int friendId) const;

    int getUserCount() const;

    void listAllUsers() const;
};

#endif