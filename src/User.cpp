#include "../include/User.h"
#include "../include/Network.h"

User::User() {
    this->id = 0;
    this->name = "";
    this->surname = "";
    this->email = "";
    this->password = "";
}

User::User (int id, std::string name, std::string surname, std::string email, std::string password) {
    if (isValidId(id)) {
        throw std::runtime_error("ID is invalid");
    }
    if (!isValidEmail(email)) {
        throw std::invalid_argument("Email is invalid");
    }
    if (!isValidPassword(password)) {
        throw std::invalid_argument("The password is invalid, it must contain at least 8 characters");
    }
    setId(id);
    setName(name);
    setSurname(surname);
    setEmail(email);
    setPassword(password);
}

void User::setPassword(std::string password) {
    this->password = password;
}

void User::setName(std::string name) {
    this->name = name;
}

void User::setSurname(std::string surname) {
    this->surname = surname;
}

void User::setEmail(std::string email) {
    this->email = email;
}

void User::setId(int id) {
    this->id = id;
}

int User::getId() const {
    return this->id;
}

std::string User::getName() const {
    return this->name;
}

std::string User::getSurname() const {
    return this->surname;
}

std::string User::getEmail() const {
    return this->email;
}

std::string User::getPassword() const {
    return this->password;
}

void User::print() const {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Surname: " << getSurname() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    std::cout << "Password: " << getPassword() << std::endl;
}

void User::deleteAccount() {
    setId(0);
    setName("");
    setSurname("");
    setEmail("");
    setPassword("");
}

void User::changePassword(std::string newPassword) {
    setPassword(newPassword);
}

void User::changeEmail(std::string newEmail) {
    setEmail(newEmail);
}

void User::changeName(std::string newName) {
    setName(newName);
}

void User::changeSurname(std::string newSurname) {
    setSurname(newSurname);
}

void User::changeAll(std::string newName, std::string newSurname, std::string newEmail, std::string newPassword) {
    setName(newName);
    setSurname(newSurname);
    setEmail(newEmail);
    setPassword(newPassword);
}

bool User::isValidId(int id) {
    return id < 0;
}

bool User::isValidEmail(const std::string& email) {
    return email.find('@') != std::string::npos;
}

User::~User() {
    deleteAccount();
}