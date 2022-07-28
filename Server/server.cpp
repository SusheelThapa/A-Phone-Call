#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#define SERVER_FILE "Server/server.txt"
#define CLIENT_ONE_FILE "Client/One/client_one.txt"
#define CLIENT_TWO_FILE "Client/Two/client_two.txt"

using namespace std;

int main()
{
    string message;

    int current_file_size = 0;
    int previous_file_size = 0;

    /*Opening server file for reading*/
    ifstream server_file;

    /*File object to write on client file*/
    fstream client_two_file_pointer;
    fstream client_one_file_pointer;

    while (true)
    {
        /*Open the server file*/
        server_file.open(SERVER_FILE, ios::in);

        /*Seeking the file pointer to  last*/
        server_file.seekg(0, ios::end);

        /*Return the current position of file pointer*/
        int file_size = server_file.tellg();

        /*Change the value of file size*/
        previous_file_size = current_file_size;
        current_file_size = file_size;

        if (current_file_size != previous_file_size)
        {
            /*Clearing the screen*/
            // system("clear");

            /*Reading the content of the file after reseting the file pointer*/
            server_file.seekg(0, ios::beg);
            std::getline(server_file, message);

            /*Printing out the message*/
            std::cout << "Message: " << message << "\n";

            /*Processing the content of files*/
            if (message == "CALLCLIENTTWO")
            {
                client_two_file_pointer.open(CLIENT_TWO_FILE, ios::out);
                if (client_two_file_pointer)
                {
                    client_two_file_pointer << "CALLFROMCLIENTONE";
                }
                else
                {
                    std::cout << "Error opening the file";
                }
            }
            else if (message == "CALLCLIENTONE")
            {

                client_one_file_pointer.open(CLIENT_ONE_FILE, ios::out);

                if (client_one_file_pointer)
                {
                    client_one_file_pointer << "CALLFROMCLIENTTWO";
                }
                else
                {
                    std::cout << "Error opening the file";
                }
            }
            else if (message == "CALLDECLINEDBYCLIENTTWO")
            {
                client_one_file_pointer.open(CLIENT_ONE_FILE, ios::out);
                if (client_one_file_pointer)
                {
                    client_one_file_pointer << "CALLDECLINEDFROMCLIENTONE";
                }
                else
                {
                    std::cout << "Error opening the file";
                }
            }
            else if (message == "CALLDECLINEDBYCLIENTONE")
            {

                client_two_file_pointer.open(CLIENT_TWO_FILE, ios::out);

                if (client_two_file_pointer)
                {
                    client_two_file_pointer << "CALLDECLINEDFROMCLIENTONE";
                }
                else
                {
                    std::cout << "Error opening the file";
                }
            }
            else if (message == "CALLRECEIVEDBYCLIENTONE")
            {

                client_two_file_pointer.open(CLIENT_TWO_FILE, ios::out);

                if (client_two_file_pointer)
                {
                    client_two_file_pointer << "CALLRECEIVEDBYCLIENTONE";
                }
                else
                {
                    std::cout << "Error opening the file";
                }
            }
            else if (message == "CALLRECEIVEDBYCLIENTTWO")
            {

                client_one_file_pointer.open(CLIENT_ONE_FILE, ios::out);

                if (client_one_file_pointer)
                {
                    client_one_file_pointer << "CALLRECEIVEDBYCLIENTTWO";
                }
                else
                {
                    std::cout << "Error opening the file";
                }
            }
            client_two_file_pointer.close();
            client_one_file_pointer.close();
        }

        server_file.close();
    }
    return 0;
}