#pragma once

#include <fstream>

#define SERVERFILE "Server/server.txt"

class ClientFile
{
private:
    std::fstream server_file;
    std::fstream client_file;

    std::string client_file_path;

    std::string message;

    int current_client_file_size;
    int previous_client_file_size;

private:
    bool init();

    bool openServerFile();

    bool closeServerFile();

    bool openClientFile();

    bool closeClientFile();

public:
    ClientFile(std::string client_file_path);

    bool isClientFileSizeChanged();

    void readMessageFromServer();

    void sendMessageToServer(std::string message);

    std::string receiveMessageFromServer();
    
    bool clearFileContent();
};