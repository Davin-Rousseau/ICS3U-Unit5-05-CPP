// Copyright (c) 2019
//
// Created by: Davin Rousseau
// Created on: November 2019
// This program prints a mailing address in proper Canadian format

#include <iostream>
#include <string>

std::string MailingAddress(std::string recipientName,
                      std::string recipientAddress,
                      std::string recipientMunicipality,
                      std::string recipientProvince,
                      std::string recipientPostalCode,
                      std::string recipientApartmentNumber = "") {
    // This function makes a mailing address in proper format

    // Variables
    std::string postAddress;

    // Process
    if (recipientApartmentNumber.size() != 0) {
        postAddress = recipientName + "\n" + recipientApartmentNumber + \
                      + "-" + recipientAddress + "\n" + recipientMunicipality \
                      + " " + recipientProvince + "  " + recipientPostalCode;
    } else {
        postAddress = recipientName + "\n" + recipientAddress + "\n" + \
                      recipientMunicipality + " " + recipientProvince + \
                      "  " + recipientPostalCode;
    }
    return postAddress;
}

int main() {
    // This function collects mailing details then outputs a mailing address

    // Variables
    std::string userName;
    std::string userAddress;
    std::string question;
    std::string userMunicipality;
    std::string userProvince;
    std::string userPostalCode;
    std::string post;
    std::string userApartmentNumber = "";

    // Input
    std::cout << "Enter your full name: " << std::endl;
    std::getline(std::cin, userName);
    std::cout << "Enter your address (road & street number): "
              << std::endl;
    std::getline(std::cin, userAddress);
    std::cout << "Do you live in an apartment (y/n): " << std::endl;
    std::getline(std::cin, question);
    if (question == "y" || question == "yes") {
        std::cout << "Enter your apartment number: " << std::endl;
        std::getline(std::cin, userApartmentNumber);
    }
    std::cout << "Enter your city: " << std::endl;
    std::getline(std::cin, userMunicipality);
    std::cout << "Enter your province/territory (ex: ON for Ontario): "
              << std::endl;
    std::getline(std::cin, userProvince);
    std::cout << "Enter your postal code :" << std::endl;
    std::getline(std::cin, userPostalCode);;

    // Process
    if (userApartmentNumber != "") {
        post = MailingAddress(userName, userAddress, userMunicipality,
                              userProvince, userPostalCode,
                              userApartmentNumber);
    } else {
        post = MailingAddress(userName, userAddress, userMunicipality,
                              userProvince, userPostalCode);
    }

    // Output
    std::cout << "" << std::endl;
    std::cout << post << std::endl;
}
