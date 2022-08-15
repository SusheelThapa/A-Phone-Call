#include <iostream>

#include <Server/NTC.hpp>

int main()
{

    NTCServer server;

    server.updateLogMessage("Date: " + std::string(__DATE__) + "\n");
    server.updateLogMessage("Date: " + std::string(__TIME__) + "\n");

    while (true)
    {

        if (server.isServerFileChanged())
        {
            server.readMessage();

            /*Processing the content of files*/
            if (server.getMessage().substr(0, 13) == "CALLCLIENTTWO")
            {
                if (server.getMessage().substr(13, 11) == " 2222222222")
                {
                    server.sendMessageToClientTwo("CALLFROMCLIENTONE");
                    server.updateLogMessage("Client One is calling Client Two.\n");
                }
                else
                {
                    // server.sendMessageToClientOne("DIALPADNUMBERMACHEDWITHCLIENTTWO");
                    std::cout << "inside else of number checking" << std::endl;
                }
            }
            else if (server.getMessage() == "CALLCLIENTONE2222222222")
            {
                server.sendMessageToClientOne("CALLFROMCLIENTTWO");
                server.updateLogMessage("Client Two is calling Client One\n");
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