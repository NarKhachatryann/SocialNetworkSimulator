#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
    private:
        int id;
        std::string name;
        std::string surname;
        std::string email;
        std::string password;
    public:

    
    User();
    User(int id, std::string name, std::string surname, std::string email, std::string password);
    ~User();
    

    int getId() const;
    std::string getName() const;
    std::string getSurname() const;
    std::string getEmail() const;
    std::string getPassword() const;

    void setId(int id);
    void setName(std::string name);
    void setSurname(std::string surname);
    void setEmail(std::string email);
    void setPassword(std::string password);

    bool isValidId(int id);    
    bool isValidEmail(const std::string& email);
    bool isValidPassword(const std::string& password);
    bool findUser(int id) const;

    void print() const;
    void deleteAccount();
    void changePassword(std::string newPassword);
    void changeEmail(std::string newEmail);
    void changeName(std::string newName);
    void changeSurname(std::string newSurname);
    void changeAll(std::string newName, std::string newSurname, std::string newEmail, std::string newPassword);

};

#endif