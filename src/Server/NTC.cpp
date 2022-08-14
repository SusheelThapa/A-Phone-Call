#include <Server/NTC.hpp>

void NTCServer::init()
{
    /*Set the file size value to 0*/
    previous_server_file_size = 0;
    current_server_file_size = 0;
}

bool NTCServer::openServerFile()
{
    this->server_file_pointer.open(this->server_file_path, std::ios::in);

    if (server_file_pointer)
    {
        return true;
    }
    std::cerr << "Unable to open the server file" << std::endl;
    return false;
}

void NTCServer::closeServerFile()
{
    this->server_file_pointer.close();
}

bool NTCServer::openClientOneFile()
{
    this->client_one_file_pointer.open(this->client_one_file_path, std::ios::out);

    if (client_one_file_pointer)
    {
        return true;
    }

    std::cerr << "Unable to open the client file" << std::endl;
    return false;
}

void NTCServer::closeClientOneFile()
{
    this->client_one_file_pointer.close();
}

bool NTCServer::openClientTwoFile()
{
    this->client_two_file_pointer.open(this->client_two_file_path, std::ios::out);

    if (client_two_file_pointer)
    {
        return true;
    }

    std::cerr << "Unable to open the client file" << std::endl;
    return false;
}

void NTCServer::closeClientTwoFile()
{
    this->client_two_file_pointer.close();
}

bool NTCServer::isServerFileChanged()
{
    /*Opening client file*/
    bool file_open_status = this->openServerFile();

    /*Getting the total character of the file*/
    this->server_file_pointer.seekg(0, std::ios::end);

    /*Updating the value of file size*/
    this->previous_server_file_size = this->current_server_file_size;
    this->current_server_file_size = this->server_file_pointer.tellg();

    if (file_open_status)
    {
        if (this->previous_server_file_size != this->current_server_file_size)
        {
            this->closeServerFile();
            return true;
        }
    }

    this->closeServerFile();
    return false;
}

void NTCServer::sendMessageToClientOne(std::string message)
{
    this->openClientOneFile();

    client_one_file_pointer << message;

    std::cout << message;

    this->closeClientOneFile();
}

void NTCServer::sendMessageToClientTwo(std::string message)
{

    this->openClientTwoFile();

    std::cout << "The messsage receive by the server is " << message << "\n";

    client_two_file_pointer << message;

    this->closeClientTwoFile();
}

void NTCServer::updateLogMessage(std::string log_message)
{
    this->log_message_file_pointer << log_message;
}

void NTCServer::readMessage()
{
    this->openServerFile();

    std::getline(this->server_file_pointer, this->message);

    this->closeServerFile();
}

std::string NTCServer::getMessage()
{
    return this->message;
}

void NTCServer::clearServerFileContent()
{
    this->openServerFile();

    server_file_pointer << " ";

    this->closeServerFile();

    message.clear();
}