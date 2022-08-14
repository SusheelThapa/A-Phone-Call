#pragma once

#include <string>
#include <fstream>
#include <iostream>

class NTCServer
{
    const std::string server_file_path = "Server/server.txt";
    const std::string client_one_file_path = "Client/One/client_one.txt";
    const std::string client_two_file_path = "Client/Two/client_two.txt";

    const std::string server_log_file_path = "Server/logs.log";

    std::fstream server_file_pointer;
    std::fstream client_one_file_pointer;
    std::fstream client_two_file_pointer;
    std::fstream log_message_file_pointer;

    int previous_server_file_size;
    int current_server_file_size;

    std::string message;

private:
    void init();

    bool openServerFile();

    void closeServerFile();

    bool openClientOneFile();

    void closeClientOneFile();

    bool openClientTwoFile();

    void closeClientTwoFile();

public:
    NTCServer()
    {
        log_message_file_pointer.open(this->server_log_file_path, std::ios::app);

        if(log_message_file_pointer.fail())
        {
            std::cout << "Failed to open the file";
        }

        init();
    }

    ~NTCServer()
    {
        log_message_file_pointer.close();
    }

    void readMessage();

    std::string getMessage();

    bool isServerFileChanged();

    void sendMessageToClientOne(std::string message);
    void sendMessageToClientTwo(std::string message);

    void updateLogMessage(std::string log_message);

    void clearServerFileContent();
};
