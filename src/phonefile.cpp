#include "phonefile.hpp"

#include <iostream>

void PhoneFile::init()
{
    /*Set the file size value to 0*/
    previous_phone_file_size = 0;
    current_phone_file_size = 0;
}

/*
 * Check if size of client file has been changed or not
 * If it has been changed then it updated the file size
 * in our variable.
 */
bool PhoneFile::isClientFileSizeChanged()
{
    /*Opening client file*/
    bool file_open_status = this->openClientFile();

    /*Getting the total character of the file*/
    this->client_file.seekg(0, std::ios::end);

    /*Updating the value of file size*/
    this->previous_phone_file_size = this->current_phone_file_size;
    this->current_phone_file_size = this->client_file.tellg();

    if (file_open_status)
    {
        if (this->previous_phone_file_size != this->current_phone_file_size)
        {
            this->closeClientFile();
            return true;
        }
    }

    this->closeClientFile();
    return false;
}

bool PhoneFile::openServerFile()
{
    this->server_file.open(SERVERFILE, std::ios::out);

    if (server_file)
    {
        return true;
    }
    std::cerr << "Unable to open the server file" << std::endl;
    return false;
}

void PhoneFile::closeServerFile()
{
    this->server_file.close();
}

bool PhoneFile::openClientFile()
{
    this->client_file.open(this->client_file_path, std::ios::in);

    if (client_file)
    {
        return true;
    }

    std::cerr << "Unable to open the client file" << std::endl;
    return false;
}

void PhoneFile::closeClientFile()
{
    this->client_file.close();
}

PhoneFile::PhoneFile()
{

    init();
}

void PhoneFile::setClientFilePath(std::string client_file_path)
{
    this->client_file_path = client_file_path;
}

void PhoneFile::clearFileContent()
{
    this->client_file.open(this->client_file_path, std::ios::out);

    client_file << "";

    this->closeClientFile();
}

void PhoneFile::sendMessageToServer(std::string message)
{
    this->openServerFile();

    server_file << message << std::endl;

    this->closeServerFile();
}
void PhoneFile::readMessageFromServer()
{

    bool result = this->openClientFile();

    /*Reading the content of the file*/
    getline(this->client_file, this->message);

    this->closeClientFile();
}
std::string PhoneFile::receiveMessageFromServer()
{
    this->readMessageFromServer();

    return this->message;
}
