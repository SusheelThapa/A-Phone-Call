#include <iostream>

#include <Server/NTC.hpp>

int main()
{

    NTCServer server;

    server.updateLogMessage("Date: " + std::string(__DATE__) + "\n");
    server.updateLogMessage("Date: " + std::string(__TIME__) + "\n");

    /*Setting the number of the client one and client two*/
    std::string client_one_number = "1111111111";
    std::string client_two_number = "2222222222";

    while (true)
    {

        if (server.isServerFileChanged())
        {
            server.readMessage();

            /*Processing the content of files*/
            if (server.getMessage().substr(0, 13) == "CALLCLIENTTWO")
            {
                if (server.getMessage().substr(14, 11) == client_two_number)
                {
                    server.sendMessageToClientTwo("CALLFROMCLIENTONE" + client_one_number);
                    server.updateLogMessage("Client One is calling Client Two.\n");
                }
                else
                {
                    server.sendMessageToClientOne("NUMBERUNMATCHED");
                }
            }
            else if (server.getMessage().substr(0, 13) == "CALLCLIENTONE")
            {
                if (server.getMessage().substr(14, 11) == client_one_number)
                {
                    server.sendMessageToClientOne("CALLFROMCLIENTTWO" + client_two_number);
                    server.updateLogMessage("Client Two is calling Client One\n");
                }
                else
                {
                    std::cout << "Number doesn't match with that of client two" << std::endl;
                }
            }
            else if (server.getMessage() == "CALLDECLINEDBYCLIENTTWO")
            {
                server.sendMessageToClientOne("CALLDECLINEDFROMCLIENTTWO");
                server.updateLogMessage("Client Two has declined the call from Client One\n");
            }
            else if (server.getMessage() == "CALLDECLINEDBYCLIENTONE")
            {
                server.sendMessageToClientTwo("CALLDECLINEDFROMCLIENTONE");
                server.updateLogMessage("Client Two has declined the call from Client Two\n");
            }
            else if (server.getMessage() == "CALLRECEIVEDBYCLIENTONE")
            {
                server.sendMessageToClientTwo("CALLRECEIVEDFROMCLIENTONE");
                server.updateLogMessage("Client Two had received the call from Client One\n");
            }
            else if (server.getMessage() == "CALLRECEIVEDBYCLIENTTWO")
            {
                server.sendMessageToClientOne("CALLRECEIVEDFROMCLIENTTWO");
                server.updateLogMessage("Client Two had received the call from Client Two\n");
            }
            else if (server.getMessage() == "CALLENDEDBYCLIENTONE")
            {
                server.sendMessageToClientTwo("CALLENDEDFROMCLIENTONE");
                server.updateLogMessage("Call has been ended by Client One\n");
            }
            else if (server.getMessage() == "CALLENDEDBYCLIENTTWO")
            {
                server.sendMessageToClientOne("CALLENDEDFROMCLIENTTWO");
                server.updateLogMessage("Call has been ended by Client Two\n");
            }

            else if (server.getMessage() == "AUDIOMESSAGESENDBYCLIENTONE")
            {
                server.sendMessageToClientTwo("AUDIOMESSAGESENDFROMCLIENTONE");
                server.updateLogMessage("Audio message has been sent from client one\n");
            }
            else if (server.getMessage() == "AUDIOMESSAGESENDBYCLIENTTWO")
            {
                server.sendMessageToClientOne("AUDIOMESSAGESENDFROMCLIENTTWO");
                server.updateLogMessage("Audio message has been sent from client two\n");
            }

            server.clearServerFileContent();
        }
    }
    return 0;
}