/*

C++ Object Oriented Programming Final Project
Dept. of Electronics and Computer Engineering

Author : Susheel Thapa Saurav Kumar Mahato
Class : BCT CD 090 BCT CD 079
Semester : Third Semester

Filename : phonefile.cpp
Categories : C++ Header File
Description : It is used to handle all the file that are being used by the phone app.
*/

#pragma once

#include <fstream>

#define SERVERFILE "Server/server.txt"

class PhoneFile
{
private:
    std::fstream server_file;
    std::fstream client_file;

    std::string client_file_path;

    std::string message;

    int current_phone_file_size;
    int previous_phone_file_size;

private:
    void init();

    bool openServerFile();

    void closeServerFile();

    bool openClientFile();

    void closeClientFile();

public:
    PhoneFile();

    void setClientFilePath(std::string client_file_path);

    bool isClientFileSizeChanged();

    void readMessageFromServer();

    void sendMessageToServer(std::string message);

    std::string receiveMessageFromServer();

    void clearFileContent();
};