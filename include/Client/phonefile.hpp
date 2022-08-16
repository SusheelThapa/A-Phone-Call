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