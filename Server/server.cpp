#include <iostream>
#include <fstream>
#include <stdlib.h>

#define SERVER_FILE "Server/server.txt"
#define CLIENT_ONE_FILE "../Client/One/client_one.txt"
#define CLIENT_Two_FILE "../Client/Two/client_two.txt"

using namespace std;

int main()
{

    while (true)
    {
        system("clear");

        /*Opening file for reading*/
        ifstream in_file(SERVER_FILE, ios::in);

        in_file.seekg(0, ios::end);
        int file_size = in_file.tellg();

        if (file_size > 0)
        {
            /*Reading the content of the file*/

            std::cout << "File has " << file_size << " bytes\n";
            /*Processing the content of files*/
        }

        in_file.close();
    }
    return 0;
}