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

    while (true)
    {

        /*Opening file for reading*/
        ifstream in_file(SERVER_FILE, ios::in);

        /*Seeking the file pointer to  last*/
        in_file.seekg(0, ios::end);

        /*Return the current position of file pointer*/
        int file_size = in_file.tellg();

        /*Change the value of file size*/
        previous_file_size = current_file_size;
        current_file_size = file_size;

        if (current_file_size != previous_file_size)
        {
            /*Clearing the screen*/
            system("clear");

            /*Reading the content of the file after reseting the file pointer*/
            in_file.seekg(0, ios::beg);
            std::getline(in_file, message);

            /*Printing out the message*/
            std::cout << "Message: " << message << "\n";

            /*Processing the content of files*/
            if (message == "CLIENTONECALL")
            {
                fstream client_one_file_pointer;
                client_one_file_pointer.open(CLIENT_ONE_FILE, ios::out);
                if (client_one_file_pointer)
                {
                    client_one_file_pointer << "INCOMINGCALL";

                    client_one_file_pointer.close();
                }
                else
                {
                    std::cout << "Error opening the file";
                }
            }
            else if (message == "CLIENTTWOCALL")
            {
                fstream client_two_file_pointer;

                client_two_file_pointer.open(CLIENT_TWO_FILE, ios::out);

                if (client_two_file_pointer)
                {
                    client_two_file_pointer << "INCOMINGCALL";

                    client_two_file_pointer.close();
                }
                else
                {
                    std::cout << "Error opening the file";
                }
            }
        }

        in_file.close();
    }
    return 0;
}